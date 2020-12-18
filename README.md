# RAISE THE TERRAIN

## What is it?

This is my first project using SDL2 to create a window and draw stuff in it. The objective is simple: create a C program that takes a file ([see examples here](https://github.com/Yagomfh/Raise_the_terrain/tree/main/input_examples)) as an argument and draws a 3D grid with the altitudes written in the file.

## How to use it?

**1) Download it:**

```
$ git clone https://github.com/Yagomfh/Raise_the_terrain
```

**2) Modify the input_file_example or create your OWN_FILE:**

Go to input_file if you want to use pre-built models:

```
$ cd Raise_the_terrain/input_files
$ cp FILE_NAME ../
```

Create your own with the following format:

```
120 60 40 60 20 -20 -80 -120
40 20 30 30 -10 -40 -90 -110
20 30 10 06 -6 -20 -26 -90
00 -6 10 10 -6 -20 -20 -40
-20 -20 -18 -14 -40 -20 -20 -30
-10 -10 -10 -10 -8 -20 -20 -30
20 10 10 10 10 04 10 -10
30 24 24 22 20 18 14 16
```

Each number corresponds to the altitude 'z' at the point (x, y)

**3) Compile it**

```
$ gcc `sdl2-config --cflags` `sdl2-config --libs` -Wall -Werror -Wextra -pedantic *.c -o terrain
```

**4) Run it:**

In order to run it make sure you have SDL2 installed in your computer. 
[SDL2 Installation](https://wiki.libsdl.org/Installation)

```
$ ./terrain INPUT_FILE_NAME
```

**5) Quit it:**

Press `ESC`

## Main feature:

**1) Rotate**

Clockwise: `RIGHT-ARROW`
Counter-closckwise: `LEAFT-ARROW`

**2) Altitud modifier**

Higher: `UP-ARROW`
Lower: `DOWN-ARROW`

## Visual example:

![](https://drive.google.com/uc?id=10wa87VrX9TqrAkC7UJdnn1VHWIUV6PmN)

## Author

[Yago Martinez-Falero Hein](https://github.com/Yagomfh)
