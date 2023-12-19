# Sutherland-Cohen Line Clipping Algorithm
 
## Overview
This project is a graphical application developed in C++ using the Qt framework with OpenGL for rendering. Its primary goal is to function as a visualization tool for clipping lines within a rectangular window. 
 

### 2. Files
   - `SutherlandAndCohenAlgo.h` and `SutherlandAndCohenAlgo.cpp`: Implementation of the Sutherland-Cohen Line Clipping Algorithm.

   - `lineDrawingBySutherlandCohen()` function takes line as input add the cliped line coordinates to the vector.
 
   - **Responsibility:** The core clipping algorithm processes user input, including a line and rectangular window dimensions, and computes the clipped line.
 
   - **Extensibility:** The Algorithm Library is designed to support various clipping techniques.
 
   - **User Interface (UI):** Provides users with the ability to input line coordinates and window dimensions.
   
   - **Functionality:** Upon clicking the "Clip line" button, the application renders the clipped line within the specified window.
 
### 3. Main Program (main.cpp)
   - `main.cpp`: Entry point for the application, initializes and runs the graphical line clipping tool.
