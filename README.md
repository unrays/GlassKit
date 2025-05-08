# Glyzr
I'm not very proud of my architecture, it's viable for an experiment but it's definitely not something I would present as a technical showcase of my own.
## Overview

Glyzr is my personal graphics playground in C++/OpenGL, powered by GLFW, GLAD, and my own utilities. It’s where I prototype shapes, experiment with shaders, and test textures as I refine my skills.

---

![Glyzr Demo](https://github.com/user-attachments/assets/4632399f-f180-47f6-b88c-08a827d72992)

---

## Prerequisites

- A C++17 (or newer) compiler
- CMake 3.10 or higher
- Git (for cloning submodules, if any)

---

## Building & Running

1. Clone this repository:
   ```bash
   git clone https://github.com/unrays/Glyzr.git
   cd Glyzr
   ```
2. Create a build directory and compile:
   ```bash
   mkdir build && cd build
   cmake ..
   make
   ```
3. Run the executable:
   ```bash
   ./Glyzr
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

Thank you for your support! I appreciate every suggestion and take them to heart.

---

## License

This project is licensed under the MIT License. See the `LICENSE` file for details.
