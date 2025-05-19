# Introduction

This repository provides examples for libAdapta:

- Applications in various languages
- Themes
- Information and utilities

Note: libAdapta apps look and feel the same as libAdwaita apps by default. To distinguish them, load a theme which support libAdapta and make sure the app is themed properly.

# Python app

![image](https://github.com/user-attachments/assets/be24a9a1-03d0-4c76-902c-3bd5afbac2a2)

A python application is available at https://github.com/xapp-project/libadapta-examples/blob/master/apps/python_app.py.

It's just a simple app with a sidebar and a few widgets.

To run it:

```
python3 ./python_app.py
```

# C app

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
