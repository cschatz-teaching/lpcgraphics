# LPCGraphics Library

- [Overview](#overview)
    - [Creating a Window](#creating-a-window)
    - [Applying Commands To a Window](#applying-commands-to-a-window)
    - [Refreshing the Display](#refreshing-the-display)
    - [Creating a Color](#creating-a-color)
- [Other Graphics Commands](#other-graphics-commands)
    - [Drawing Shapes](#drawing-shapes)
    - [Drawing Text](#drawing-text)
    - [Drawing an Image](#drawing-an-image)
- [User Input Commands](#user-input-commands)
    - [Mouse Input](#mouse-input)
    - [Keyboard Input](#keyboard-input)
- [Controlling Timing](#controlling-timing)

## Overview

The LPCGraphics Library allows the inclusion of simple graphics commands within a normal C++ program. To use it,
you need a specially-prepared project (see the CS1 course homepage), as well as `#include "LPCGraphics.h"` at the top
of any .cpp file that uses graphics commands.

### Creating a Window

To do any graphics commands, you first need a window. A window is actually a **type** of variable.
The command to create a window is shown below, with `mywindow` as the name of a window variable I am
creating in this particular case.

```c++
GraphicsWindow mywindow(600, 400, "My Graphics Window");
```

The three arguments are:
* The window width
* The window height
* The window title (which will be displayed in the title bar)

### Applying Commands To a Window

Once a window has been created, **ALL** graphics commands are **methods** (functions that apply to an object),
so they are always called in the format below. (`mywindow` represents the name of any window variable
that has already been created, and `GraphicsCommand` represents one of the graphics commands from the list
further down in this document.)

```c++
mywindow.GraphicsCommand(argument1, argument2,  ... );
```

### Refreshing the Display

To enable smooth animation and better performance, when you draw something to a window,
**It does not actually appear yet**. You must tell a window to refesh its appearance explictly,
with the `Refresh()` command:

```c++
mywindow.Refresh()
```
### Creating a Color

Color in the LPCGraphics library is also a **type** of variable that can be created. To create a Color 
variable, use the pattern below:

```c++
Color mycolor(255, 255, 255);
```

The three arguments must be numbers from 0 to 255. These represent amounts of red, green and blue.
The example above makes `mycolor` a Color variable representing white because all three color components
are at their maximum value.

## Other Graphics Commands

All other commands that can be applied to a window are listed below, as function prototypes. In general,
the parameters should be self explanatory, but I have given some additional information and clarification
in a few places.

### Drawing Shapes

- `void DrawRectangle(int x, int y, int width, int height, Color color, bool filled = false);`
- `void DrawCircle(int x, int y, int radius, Color color, bool filled = false);`
- `void DrawEllipse(int x, int y, int xradius, int yradius, Color color, bool filled = false);`
- `void DrawLine(int x1, int y1, int x2, int y2, Color color);`
    - (x1, y1) and (x2, y2) are the endpoints of the line.

### Drawing Text

- `void DrawString(string str, int x, int y, Color color, int fontsize = 13);`
    - This draws the given string directly on a graphics window.

### Drawing an Image

**_NOTE: At the moment, the only image formats that work are BMP. (Sorry!)_**

- `void DrawImage(string imageFileName, int x, int y, int width = 0, int height = 0);`  
    - The given imageFileName must be inside the "Images" folder inside the project folder.

## User Input Commands

The commands listed below are used to get information from the mouse and keyboard.

### Mouse Input

- `void WaitForMouseDown();`
    - This pauses the program until the mouse button is pressed down. 
    - If the button is already down, no pause happens.

- `void WaitForMouseUp();`
    - This pauses the program until the mouse button is pressed up. 
    - If the button is already up, no pause happens.

- `int MouseX();`
    - This returns the current X position of the mouse pointer within the window.

- `int MouseY();`
    - This returns the current Y position of the mouse pointer within the window.

- `bool MouseIsDown();`
    - This returns true/false to indicate whether the mouse button is currently down. 
    
### Keyboard Input

- `char WaitForKeyPress();`
    - This pauses the program until the user pressed a key in the graphics window, then returns which key was pressed.

- `bool KeyPressed(string key);`
    - This returns true/false to indicate if the given key is currently being pressed.
    - For arrow keys, use "up", "down", "left" or "right" as the argument.
    - For other keys, use a one-letter-long string such as "w" or "d".

### Controlling Timing

- `void Pause(double duration);`
    - This pauses the program for the given duration, in seconds.
