# LPCGraphics Library

- [Overview](#overview)
- [Controlling Frame Rate](#controlling-frame-rate)
- [Colors](#colors)
- [Drawing Commands](#drawing-commants)
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

## Interaction Functions

Between the `__INTERACTION_FUNCTIONS__` and `__INTERACTION_FUNCTIONS_END__` symbols, you can have one or more of the following **interaction functions**. If `#define USE_INTERACTION_FUNCTIONS` is included before `#include "lpcgraphics.h"`, these functions will control the way the graphics window behaves. (If you comment out the `#define USE_INTERACTION_FUNCTIONS` line, these functions will essentially be ignored.) The prototype of each interaction function is listed below, along with an explanation of what it does.

- `void setup();`
    - The contents of this function will run **exactly once** when the graphics window is first created.
- `void draw();`
    - The contents of this function will run **repeatedly** after the graphics window is open, until it is closed. The rate at which the draw() function happens can be controlled -- see [Controlling Frame Rate](#controlling-frame-rate) below.

## The `startGraphics` Function


### Applying Commands To a Window

Once a window has been created, **ALL** graphics commands are **methods** (functions that apply to an object),
so they are always called in the format below. (`mywindow` represents the name of any window variable
that has already been created, and `GraphicsCommand` represents one of the graphics commands from the list
further down in this document.)

```c++
mywindow.GraphicsCommand(argument1, argument2,  ... );
```
## Controlling Frame Rate


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
