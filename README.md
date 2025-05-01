# GlassKit

## Overview

GlassKit is my personal graphics playground in C++/OpenGL, powered by GLFW, GLAD, and my own utilities. It’s where I prototype shapes, experiment with shaders, and test textures as I refine my skills.
![image](https://github.com/user-attachments/assets/e9d29a47-661b-4774-b266-8214c69de5ea)
![image](https://github.com/user-attachments/assets/b9ec58b2-3d17-496b-8950-82aa421f6470)

---

## Key Features

- **Lightweight setup** with GLFW & GLAD
- **Hot-reloadable shaders** for rapid experimentation
- **Custom texture loader** supporting PNG and JPEG formats
- **Basic shape rendering**: squares, cubes, spheres
- **Framebuffer utilities** for post-processing effects (e.g., bloom, blur)

---

## Prerequisites

- A C++17 (or newer) compiler
- CMake 3.10 or higher
- Git (for cloning submodules, if any)

---

## Building & Running

1. Clone this repository:
   ```bash
   git clone https://github.com/unrays/GlassKit.git
   cd GlassKit
   ```
2. Create a build directory and compile:
   ```bash
   mkdir build && cd build
   cmake ..
   make
   ```
3. Run the executable:
   ```bash
   ./GlassKit
   ```

---

## Usage

- Modify shader files in the `shaders/` directory; they will reload automatically while the app is running.
- Explore the code under `src/` to understand and extend the architecture.

---

## Contributing

I’m finishing my second year of computer science studies, and every bit of feedback helps me improve. Feel free to:

- Open an issue to report bugs or suggest new ideas
- Submit a pull request to add features or enhancements
- Share shader examples or graphics tips

Thank you for your support—I appreciate every suggestion and take them to heart.

---

## License

This project is licensed under the MIT License. See the `LICENSE` file for details.
