# Introduction

This repository provides examples for libAdapta:

- Applications in various languages
- Themes
- Information and utilities

Note: libAdapta apps look and feel the same as libAdwaita apps by default. To distinguish them, load a theme which support libAdapta and make sure the app is themed properly.

# Themes

All a theme needs to support libAdapta is a libadapta-1.5 directory with a few CSS files inside of it.

## Mint-Y-Aqua-Adapta

Here's an example: https://github.com/xapp-project/libadapta-examples/tree/master/themes/Mint-Y-Aqua-Adapta

To test it:

- Place the `Mint-Y-Aqua-Adapta` folder in your `~/.themes/` (or `/usr/share/themes`) directory.
- Set it as your GTK theme

Note how all the colors are defined in `defaults-light.css` and `defaults-dark.css`.

The window controls are defined at the bottom of `base.css`.

`base-hc.css` corresponds to the High Contrast GTK mode, so this is left untouched.

# Apps

## Python app

![image](https://github.com/user-attachments/assets/be24a9a1-03d0-4c76-902c-3bd5afbac2a2)

A python application is available at https://github.com/xapp-project/libadapta-examples/blob/master/apps/python_app.py.

It's just a simple app with a sidebar and a few widgets.

To run it:

```
python3 ./python_app.py
```

Note how it loads the Adap module as Adw. This allows its code to be compatible with both libAdwaita and libAdapta.

## C app

![Image](https://github.com/user-attachments/assets/1ab1ff8a-e3ef-4c52-8633-87a1aaf2b0fb)

The same application is available in C at https://github.com/xapp-project/libadapta-examples/blob/master/apps/c_app.c.

Make sure you've got `gcc`, `libgtk-4-dev` and `libadapta-1-dev` installed.

To compile it run:

```
gcc c_app.c -o c_app `pkg-config --cflags --libs gtk4` `pkg-config --cflags --libs libadapta-1` -Wall`
```

And then run it with:

```
./c_app
```

Note how it includes the adw-compat.h header. This allows its code to be compatible with both libAdwaita and libAdapta.