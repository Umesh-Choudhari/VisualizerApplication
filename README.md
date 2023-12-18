# CAGD Algorihtms
 
## Overview
This project is a graphical application developed in C++ using the Qt framework with OpenGL for rendering. Its primary goal is to function as a visualization tool to demonstrate working of algorithms like SymmetricDDA,sutherland Cohen, hermite and bezier curve. The project is organized into three main components, each fulfilling a distinct role in achieving the desired functionality.
 
### 1. Geometry Library (Geometry.lib)
   - `Point3D.h` and `Point3D.cpp`: Definitions and implementations for points.
 
   - `Line.h` and `Line.cpp`: Definitions and implementations for lines.
 
   - `Rectanglee.h` and `Rectanglee.cpp`: Definitions and implementations for Rectangle.
 
   - **Exported as DLL:** The Geometry Library is exported as a Dynamic Link Library (DLL), promoting reusability in other projects.
 
### 2. Algorithm Library (Algorithm.lib)
   - `SutherlandCohenAlgorithm.h` and `SutherlandCohenAlgorithm.cpp`: Implementation of the Sutherland-Cohen Line Clipping Algorithm which takes line, window as a input and return cliped line.

   - `SymmetricDDA.h` and `SymmetricDDA.cpp`: Implementation of the SymmetricDDA line drawing  Algorithm which takes coordinates of points as input and return the line on grid.

   - `Hermite.h` and `Hermite.cpp`: Implementation of the Hermite curve drawing Algorithm which takes four points as input and return a curve passing through four points.

   - `Bezier.h` and `Bezier.cpp`: Implementation of the Bezier curve drawing Algorithm which takes four points as input and return a curve passing through two end points.
 
   
 
### 3. SymmetricDDAandSutherLandCohen (VisualizerApp)
   - `SymmetricDDAandSutherLandCohen.h` and `SymmetricDDAandSutherLandCohen.cpp`: GUI components are implemented in these files.
 
   - `OpenGLWindow.h` and `OpenGLWindow.cpp`: Responsible for handling OpenGL rendering.
 
   - **User Interface (UI):** Provides users with the ability to input line coordinates and window dimensions.
   
   - **Functionality:** 
   - Upon clicking the "Clip Line" button, the application renders the clipped line within the specified window.
   - Upon clicking the "Draw Line" button, the application renders the input line.
   - Upon clicking the "Hermite Curve" button, the application renders the curve which is passing through four control points.
   - Upon clicking the "Bezier Curve" button, the application renders the curve which is passing through two end control points.
 
### 4. Main Program (main.cpp)
   - `main.cpp`: Entry point for the application, initializes and runs the graphical line clipping tool.
