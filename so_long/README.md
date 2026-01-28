# so\_long

## Introduction

**so\_long** is a graphical project developed as part of the 42 curriculum. The goal is to create a small 2D tile-based game using the **MiniLibX** graphics library. The project focuses on fundamental concepts such as file parsing, data validation, event handling, rendering, and memory management in C.

The player navigates through a map, collects all collectibles, and reaches the exit while respecting strict rules defined by the subject.

---

## Project Objectives

The main objectives of this project are:

- Understanding and using the MiniLibX graphics library
- Creating and managing a graphical window
- Handling keyboard events
- Parsing and validating external input (map files)
- Implementing deterministic game logic
- Ensuring proper memory allocation and cleanup

---

## Map Format and Rules

The game map is provided as a file with the `.ber` extension. The program validates the map before launching the game. If the map does not comply with the rules, the program exits with an error.

### Mandatory Map Rules

- The map must be rectangular
- The map must be fully surrounded by walls (`1`)
- The map must contain:
  - Exactly one player (`P`)
  - Exactly one exit (`E`)
  - At least one collectible (`C`)
- Only authorized characters are allowed
- All collectibles and the exit must be reachable from the player position

### Map Characters

| Character | Meaning                  |
| --------- | ------------------------ |
| `1`       | Wall                     |
| `0`       | Empty space              |
| `P`       | Player starting position |
| `C`       | Collectible              |
| `E`       | Exit                     |

### Bonus Map Characters

| Character | Meaning            |
| --------- | ------------------ |
| `X`       | Enemy (bonus only) |

Bonus characters are validated and handled only in the bonus part and do not affect the mandatory implementation.

---

## Map Validation Strategy

The project performs validation in two phases:

1. **Static validation**

   - Rectangular shape check
   - Wall enclosure verification
   - Character whitelist validation
   - Counting required elements (player, exit, collectibles)

2. **Path validation (Flood Fill)**

   - A copy of the map is created
   - A flood-fill algorithm starts from the player position
   - Ensures that all collectibles and the exit are reachable

The original map is never modified during validation.

---

## Game Rules and Logic

- The player moves one tile per input
- Movement into walls is forbidden
- Each valid movement increments a move counter
- Collectibles are removed when the player steps on them
- The exit becomes accessible only after all collectibles are collected
- The game ends successfully when the player reaches the exit with zero collectibles remaining

---

## Rendering

- The game uses tile-based rendering
- Each map character corresponds to a texture loaded via MiniLibX
- The entire map is rendered on window creation
- In the bonus part, rendering is updated continuously to support animations

---

## Controls

### Mandatory

| Key        | Action        |
| ---------- | ------------- |
| `W` or `↑` | Move up       |
| `A` or `←` | Move left     |
| `S` or `↓` | Move down     |
| `D` or `→` | Move right    |
| `ESC`      | Exit the game |

### Bonus

| Key | Action           |
| --- | ---------------- |
| `R` | Restart the game |

---

## Compilation and Execution

### Mandatory Part

```bash
make
./so_long maps/example.ber
```

### Bonus Part

```bash
make bonus
./so_long_bonus maps/example.ber
```

---

## Bonus Implementation

The bonus part is implemented in separate source files and headers. The mandatory code is reused without modification.

Bonus features include:

- Sprite animations using a frame-based animation loop
- Animated player and/or collectibles
- Dedicated bonus input handling
- Extended rendering loop

All bonus-specific logic is isolated to avoid impacting the mandatory implementation.

---

## Project Structure

```
so_long/
├── Libft/                 # Custom C standard library
├── get_next_line/         # Line-by-line file reading utility
├── map/                   # Map files used for testing
│   ├── *.ber
│
├── textures/              # XPM textures and animation frames
│
├── bonus/                 # Bonus implementation (animations, enemies)
│   ├── main_bonus.c
│   ├── draw_bonus.c
│   ├── handle_keypress_bonus.c
│   ├── animation_bonus.c
│   ├── animation_utils_bonus.c
│   ├── animation_factor.c
│   ├── map_validation_bonus.c
│   └── so_long_bonus.h
│
├── draw.c                 # Mandatory rendering logic
├── flood_fill.c           # Flood-fill path validation
├── main.c                 # Mandatory entry point
├── map.c                  # Map parsing
├── map_utils.c            # Map helper functions
├── map_validation.c       # Mandatory map validation
├── move.c                 # Player movement logic
├── textures.c             # Texture loading and management
├── so_long.h              # Mandatory header
├── Makefile
└── README.md
```

**Note:** The project depends on the MiniLibX graphics library, which must be installed separately according to the 42 environment. The library itself is not included in this repository.

---

## Error Handling

The program prints an error message and exits in the following cases:

- Invalid map format or rule violation
- Failure to open or read the map file
- Memory allocation failure
- MiniLibX initialization or resource loading failure

---

## Memory Management

- All allocated memory is freed before program termination
- MiniLibX resources (images, window, display) are properly destroyed
- No memory leaks are expected in normal execution paths

---

## Author

lkyaw

---

## Disclaimer

This project was developed as part of the 42 curriculum and strictly follows the constraints and requirements described in the official subject.

