// Include the Adapta lib
#include <libadapta-1/adapta.h>

// Include a compatibility header
// This allows us to use libAdwaita functions and class names
// and thus to write code which works with both libraries.
//#include "adapta_compat.h"
#include <libadapta-1/adw-compat.h>

typedef struct {
    AdwApplication *app;
    AdwApplicationWindow *win;
} MyApp;

static void activate_cb(AdwApplication *app, gpointer user_data);
static void create_window(AdwApplication *app);

int main(int argc, char *argv[]) {
    MyApp *my_app = g_new0(MyApp, 1);
    int status;

    // Initialize GTK
    gtk_init();

    // Create application
    my_app->app = adw_application_new("com.example.adapta", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(my_app->app, "activate", G_CALLBACK(activate_cb), my_app);

    // Run application
    status = g_application_run(G_APPLICATION(my_app->app), argc, argv);

    // Cleanup
    g_object_unref(my_app->app);
    g_free(my_app);

    return status;
}

static void activate_cb(AdwApplication *app, gpointer user_data) {
    create_window(app);
}

static void create_window(AdwApplication *app) {
    // Main window
    GtkWidget *window = adw_application_window_new(GTK_APPLICATION(app));
    gtk_window_set_title(GTK_WINDOW(window), "C libAdapta example");
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);

    // Create a split view
    AdwNavigationSplitView *split_view = ADW_NAVIGATION_SPLIT_VIEW(adw_navigation_split_view_new());
    adw_navigation_split_view_set_min_sidebar_width(split_view, 200);
    adw_navigation_split_view_set_max_sidebar_width(split_view, 300);

    // Create a sidebar
    GtkBox *sidebar_box = GTK_BOX(gtk_box_new(GTK_ORIENTATION_VERTICAL, 0));
    GtkListBox *listbox = GTK_LIST_BOX(gtk_list_box_new());
    gtk_widget_add_css_class(GTK_WIDGET(listbox), "navigation-sidebar");
    gtk_list_box_set_selection_mode(listbox, GTK_SELECTION_SINGLE);

    AdwActionRow *row = ADW_ACTION_ROW(adw_action_row_new());
    adw_preferences_row_set_title(ADW_PREFERENCES_ROW(row), "Page");
    gtk_list_box_append(listbox, GTK_WIDGET(row));

    gtk_box_append(sidebar_box, GTK_WIDGET(listbox));

    AdwToolbarView *sidebar_toolbar = ADW_TOOLBAR_VIEW(adw_toolbar_view_new());
    adw_toolbar_view_add_top_bar(sidebar_toolbar, GTK_WIDGET(adw_header_bar_new()));
    adw_toolbar_view_set_content(sidebar_toolbar, GTK_WIDGET(sidebar_box));

    // Create the navigation pages with child widgets
    AdwNavigationPage *sidebar_page = ADW_NAVIGATION_PAGE(
        adw_navigation_page_new(GTK_WIDGET(sidebar_toolbar), "Sidebar"));

    // Create the content page
    GtkBox *content_box = GTK_BOX(gtk_box_new(GTK_ORIENTATION_VERTICAL, 0));
    AdwStatusPage *status_page = ADW_STATUS_PAGE(adw_status_page_new());
    adw_status_page_set_title(status_page, "C libAdapta Example");
    adw_status_page_set_description(status_page,
        "Split navigation view, symbolic icon and a calendar widget to feature the accent color.");
    adw_status_page_set_icon_name(status_page, "document-open-recent-symbolic");

    GtkBox *box = GTK_BOX(gtk_box_new(GTK_ORIENTATION_VERTICAL, 12));
    GtkCalendar *calendar = GTK_CALENDAR(gtk_calendar_new());

    gtk_box_append(box, GTK_WIDGET(status_page));
    gtk_box_append(box, GTK_WIDGET(calendar));
    gtk_box_append(content_box, GTK_WIDGET(box));

    AdwToolbarView *content_toolbar = ADW_TOOLBAR_VIEW(adw_toolbar_view_new());
    adw_toolbar_view_add_top_bar(content_toolbar, GTK_WIDGET(adw_header_bar_new()));
    adw_toolbar_view_set_content(content_toolbar, GTK_WIDGET(content_box));

    AdwNavigationPage *content_page = ADW_NAVIGATION_PAGE(
        adw_navigation_page_new(GTK_WIDGET(content_toolbar), "Page"));

    // Set up the split view
    adw_navigation_split_view_set_sidebar(split_view, sidebar_page);
    adw_navigation_split_view_set_content(split_view, content_page);

    // Set window content
    adw_application_window_set_content(ADW_APPLICATION_WINDOW(window), GTK_WIDGET(split_view));

    // Show the window
    gtk_window_present(GTK_WINDOW(window));
}