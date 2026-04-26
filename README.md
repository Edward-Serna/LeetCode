<img height="55px" src="https://upload.wikimedia.org/wikipedia/commons/c/c2/LeetCode_Logo_2.png"/>


Personal C++ workspace for daily LeetCode problems and practice, built with CMake and C++20.

## Project Structure
```
LeetCode/
├── CMakeLists.txt    # Configuration Outline
├── Dailies/          # C++ Problems [Easy], [Medium], [Hard]
│   ├── [Date]/       # Detailed problems (15min+)
│   │   ├── main.cpp
│   │   └── problem.md
│   └── ...
├── Practice/         # Quick challenge (10-20min)
│   ├── 1-TwoSum.cpp  # File header with Hyperlink
│   └── ...
└── JavaScript/       # Additional lessions
    ├── Lesson1.js
    └── ...
```

- **Dailies/** – One folder per day (`M_DD_YY`), each with a `main.cpp` solution and a `problem.md` description. 
  Some days include a `resources/` subfolder with reference images.
- **Practice/** - Standalone `.cpp` files for revisiting classic problems, named by LeetCode number and title.
- **JavaScript/** - JS scratch files for exploring LeetCode's JavaScript track.

## Building

Requires **CMake 3.20+** and a **C++20** compiler.

```bash
cmake -S . -B build
cmake --build build
```

CMake auto-discovers all folders — no edits needed when adding a new day or practice file.

**Daily executables** are prefixed with `Daily_`:

```bash
./build/Debug/Daily_4_26_26
```

**Practice executables** are prefixed with `Practice_`:

```bash
./build/Debug/Practice_1_TwoSum
```

## Adding a New Day

1. Create a folder under `Dailies/` using the `M_DD_YY` format (e.g. `4_27_26`).
2. Add a `main.cpp` with your solution.
3. Optionally add a `problem.md` with the problem statement and a `resources/` folder for any images.
4. Re-run `cmake --build build` — the new target is picked up automatically.

## Adding a Practice File

Drop a `.cpp` file into `Practice/` named by LeetCode number and title (e.g. `42-TrappingRainWater.cpp`). It will be built automatically on the next CMake run.