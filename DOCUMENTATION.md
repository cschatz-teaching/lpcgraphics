# LPCGraphics Library - Documentation

- [Overview](#overview)
    - [Interaction Functions](#interaction-functions)
    - [Starting and Stopping Graphics](#starting-and-stopping-graphics)
    - [Controlling Frame Rate](#controlling-frame-rate)
- [Colors](#colors)
- [Drawing Commands](#drawing-commands)
- [Mouse](#mouse)
- [Keys](#keys)
- [Window Dimensions](#window-dimensions)

## Overview

The LPCGraphics Library allows the inclusion of simple graphics commands within a normal C++ program. To use it,
you need one of the specially-prepared projects in this repository.

The project comes with a main.cpp that is already set up correctly to use the library. There are several elements that must be in place. First, at the top, you should have these lines in order:

```c++
#define USE_INTERACTION_FUNCTIONS
#include "lpcgraphics.h"
```

The code in the program then consists of two sections, which must be in this order:

- A section of code beginning `__INTERACTION_FUNCTIONS__` and ending with `__INTERACTION_FUNCTIONS_END__`. This will contain only specific **interaction functions**.

- Your `main()`, with at least one call to the `startGraphics()` function inside it.

These are explained further below.

### Interaction Functions

Between the `__INTERACTION_FUNCTIONS__` and `__INTERACTION_FUNCTIONS_END__` symbols, you can have one or more of the following **interaction functions**.

If `#define USE_INTERACTION_FUNCTIONS` is included before `#include "lpcgraphics.h"`, these functions will control the way the graphics window behaves. If you comment out the `#define USE_INTERACTION_FUNCTIONS` line, these functions will be ignored by the graphics system.

The prototype of each interaction function is listed below, along with an explanation of what it does.

- `void setup();`<br />
This function will run **exactly once** when the graphics window is first created.
    
- `void draw();`<br />
This function will run **repeatedly** after the graphics window is open, until it is closed. The rate at which the draw() function happens can be controlled -- see [Controlling Frame Rate](#controlling-frame-rate) below.
    
- `void mousePressed()`<br />
This function will run whenever the primary mouse button is pressed down.

- `void mouseReleased()`<br />
This function will run whenever the primary mouse button is released.

- `void keyPressed()`<br />
This function will run whenever a key has been pressed. See [Keys](#keys) for more information.

- `void keyReleased()`<br />
This function will run whenever a key has been pressed. See [Keys](#keys) for more information.

### Starting and Stopping Graphics

In your `main()`, you can control the starting and stopping of graphics with these functions:

- `void startGraphics(int width, int height, string title);`<br />
This creates the graphics window with the given dimensions and title. If `USE_INTERACTION_FUNCTIONS` is active, this will also begin the use of any interaction functions you have specified in the file.
    
- `void stopGraphics();`<br />
This closes the graphics window. Any interaction functions will no longer have any effect after this.
    
- `void waitForClose();`<br />
Calling this function will wait until the user themselves closes the graphics window. While it is waiting, any interaction functions will continue working, but `waitForClose()` itself will not end until the window is closed.

### Controlling Frame Rate

- `void frameRate(double rate)`<br />
Call this function to set the rate at which the `draw()` function runs. The default is 30 times per second.

## Colors

### Creating/Specifying Colors

The most basic command related to color in this library is the creation of an individual *color variable*:

`Color mycolor(... argument(s) ...)`;

This would create a variable named `mycolor` representing a specific color. The argument(s) may be specified 
with any of these 4 options:

- Grayscale: A single int from 0 to 255, representing a grayscale color between pure black and pure white
- RGB: Three ints, each from 0 to 255, representing amounts of red, green and blue
- Hex: A string beginning with "#" followed by 3 or 6 characters using the [hex triplet format](https://en.wikipedia.org/wiki/Web_colors#Hex_triplet)
- Name: A string representing the English name of a color, using one of the standard [CSS color names](https://www.w3schools.com/cssref/css_colors.asp).

For example, here are several color variables being created:

```c++
Color colorA(128); 
Color colorB(255, 0, 0);
Color colorC("#a076dc");
Color colorD("#afa");
Color colorE("CornflowerBlue");
```

### Using Colors

Commands that make use of colors are listed below. For all of these commands, the argument(s) can have the same format as any of the systems listed above, or can be an existing color variable.

- `void background(...);`<br />
Fills the entire screen with the given color.

- `void fillColor(...);`<br />
Set the **fill color** to the given color. This is used to fill the inside of any shapes drawn after this command runs.

- `void strokeColor(...);`<br />
Set the **stroke color** to the given color. This is used to fill the outline of any shapes, or any lines, drawn after this command runs.

- `void noFill();`<br />
Sets the fill color "off", so that any shapes drawn after this command runs have no fill color at all.

- `void noStroke();`<br />
Sets the stroke color "off", so that any shapes drawn after this command runs have no stroke color at all.

## Drawing Commands

Here are all of drawing commands supported by this library:

- `void ellipse(int centerX, int centerY, int w, int h);`<br />
Draws an ellipse with its center at (*centerX, centerY*), with *w* and *h* as the width and height of the ellipse.
 
- `void line(int x1, int y1, int x2, int y2);`<br />
Draws a line, using the current stroke color, from the location (*x1, y1*) to the location (*x2, y2*).

- `void point(int x, int y);`
Draws a point, using the current stroke color, at location (*x, y*).
 
- `void rect(int x, int y, int w, int h);`<br />
Draws a rectangle whose upper left corner is at location (*x, y*), with width *w* and height *h*.

- `void quad(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);`<br />
Draws a quadrilateral (i.e. a 4-sided polygon), using the 8 arguments given as 4 *x,y* pairs.
The edges of the shape will be connected between vertices in the order given.

- `void triangle(int x1, int y1, int x2, int y2, int x3, int y3);`<br />
Draws a triangle whose three vertices are (*x1, y1*), (*x2, y2*) and (*x3, y3*).

- `void text(string s, int x, int y, int fontSize);`
Draws the string *s* onto the graphics window, using the current fill color, using font size *fontSize*
and placing the text so the upper-left corner of its bounding box is at location (*x, y*).

- `void image(Image img, int x, int y);`<br />
`void image(Image img, int x, int y, int width, int height);`<br />
`void image(Image img, int x, int y, double angle);`<br />
The functions all draw an image at a given (*x, y*) position. Optionally, you can specify a width and height (otherwise it will be drawn with its original dimensions), or a rotation angle.
    - To create an Image variable, use a command in this form:<br />
    `Image imageVariable = loadImage(imageFileName)`<br />
    The image file name must correspond to a **BMP format file** (only!) that is inside the **images** folder within your project.

## Mouse

To check the current state of the mouse, you can use these three functions:

- `int mouseX();`<br />
Returns the current X position of the mouse within the window.

- `int mouseY();`<br />
Returns the current Y position of the mouse within the window.

- `bool mouseDown();`<br />
Returns whether the mouse button is currently down.
   
## Keys

When writing code inside the `keyPressed()` or `keyReleased()` interaction functions, the current key is stored in a variable named **`keyCode`**. To determine which key was pressed (or released), compare `keyCode` to one of the values listed
here: [Key Code Constants](./KeyCodeConstants.md)

## Window Dimensions

The current window dimensions are always available in variables named **`width`** and **`height`**.
