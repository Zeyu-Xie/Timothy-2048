# Timothy 2048

🎮 A colorful terminal-based 2048 game written in C++ by Zeyu Xie.

Timothy-2048 is a lightweight, visually enhanced version of the classic [2048 game](<https://en.wikipedia.org/wiki/2048_(video_game)>) that runs entirely in your terminal. It features colorful tile rendering, import/export functionality, and interactive save/load features.

## 🚀 Features

- Colorful terminal rendering using ANSI codes
- Fully keyboard-controlled: use arrow keys to move
- Save and load game state using JSON files
- Compact and readable source code written in modern C++
- Built-in start animation and help/version screens

## 🧩 Build Instructions

### Requirements

- C++23 compiler (e.g. `clang++`, `g++`)
- Unix-like environment (Linux/macOS/WSL)
- Terminal with ANSI color support

### Compile

```bash
mkdir -p build
clang++ -Wall -O2 -std=c++23 -o build/timothy-2048 src/main.cpp
```

> Ensure that your `include` and `src` folders are correctly structured as in the project.

## 🕹️ Usage

```bash
./timothy-2048 [options]
```

### Options

| Option            | Description                                  |
| ----------------- | -------------------------------------------- |
| `-h`, `--help`    | Show help message and exit                   |
| `-v`, `--version` | Show version information and exit            |
| `-i <file>`       | Import a saved game state from a JSON file   |
| `-o <file>`       | Export the game state to a JSON file on exit |

## 💡 Examples

```bash
./timothy-2048
```

Start a fresh game with default 4×4 board.

```bash
./timothy-2048 --import save.json
```

Resume game from a previous save.

```bash
./timothy-2048 -i save.json -o result.json
```

Import on start and export automatically on exit.

```bash
./timothy-2048 --version
```

Display version information.

## 🎮 Controls

| Key        | Action                    |
| ---------- | ------------------------- |
| Arrow keys | Move tiles (↑ → ↓ ←)      |
| `S` / `s`  | Save current game to file |
| `Q` / `q`  | Quit the game             |

## 📂 Project Structure

```
.
├── include/
│   ├── characters.hpp
│   ├── clearConsole.hpp
│   ├── formats.hpp
│   ├── GameBoard.hpp
│   └── utils.hpp
├── src/
│   └── main.cpp
└── build/ (generated)
```

## 📤 Save Format

Game states are saved in a simple JSON format containing:

- Board size `N`
- Step count
- Current board array
- History of operations

## 📬 Feedback

Enjoy the game? Found a bug or want to suggest improvements?

📧 Contact: [xie.zeyu20@gmail.com](mailto:xie.zeyu20@gmail.com)

## 📝 License

This project is licensed under the **GNU General Public License v3.0 (GPLv3)**.

You are free to use, modify, and distribute this software under the terms of the GPLv3.

This project also uses [nlohmann/json](https://github.com/nlohmann/json), which is licensed under the [MIT License](https://opensource.org/licenses/MIT).

## 🌈 Preview

Start screen animation includes colorful ASCII art with high-res Unicode blocks (▀▄).

**Have fun playing in the terminal!**
