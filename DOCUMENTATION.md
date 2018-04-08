# LPCGraphics Library

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

- A section of code beginning `__INTERACTION_FUNCTIONS__` and ending with `__INTERACTION_FUNCTIONS_END__`. This will contain only specific **interaction function**.

- Your `main()`, with at least one call to the `startGraphics()` function inside it.
These are explained further below.

### Interaction Functions

Between the `__INTERACTION_FUNCTIONS__` and `__INTERACTION_FUNCTIONS_END__` symbols, you can have one or more of the following **interaction functions**.

If `#define USE_INTERACTION_FUNCTIONS` is included before `#include "lpcgraphics.h"`, these functions will control the way the graphics window behaves. If you comment out the `#define USE_INTERACTION_FUNCTIONS` line, these functions will essentially be ignored.

The prototype of each interaction function is listed below, along with an explanation of what it does.

- `void setup();`<br />
The contents of this function will run **exactly once** when the graphics window is first created.
    
- `void draw();`<br />
The contents of this function will run **repeatedly** after the graphics window is open, until it is closed. The rate at which the draw() function happens can be controlled -- see [Controlling Frame Rate](#controlling-frame-rate) below.
    
- **more interaction functions needed here!!**

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

Colors - background, fill, stroke

4 systems for specifying color
 - 1 int between 0-255
 - 3 ints
 - hex
 - name
 
## Drawing Commands

Here are all of drawing commands supported by this library:

 -  ..
 -  ..
 - sdfsdf
 
## Mouse

To check the current state of the mouse, you can use these three functions:

- `int mouseX();`<br />
returns the current X position of the mouse within the window.

- `int mouseY();`<br />
returns the current Y position of the mouse within the window.

- `bool mouseDown();`<br />
returns whether the mouse button is currently down.
   
## Keys

When writing code inside the `keyPressed()` or `keyReleased()` interaction functions, the current key is stored in a variable named **`keyCode`**.

ADD EXAMPLE OF CHECKING HERE!

## Window Dimensions

The current window dimensions are always available in variables named **`width`** and **`height`**.
