# 🪨 Rock Paper Scissors – C++ Console Game

A simple and fun **Rock, Paper, Scissors** game implemented in C++ where the player competes against the computer over multiple rounds. The game keeps track of the number of wins, losses, draws, and announces the overall winner at the end.

---

## 🎮 Gameplay Overview

- The player is prompted to enter their name and how many rounds to play.
- In each round:
  - The player chooses between Rock, Paper, or Scissors.
  - The computer randomly selects a choice.
  - The winner of the round is determined based on classic rules.
- After all rounds:
  - A summary is displayed showing round count, wins, losses, draws, and the game winner.
  - Color changes in the console indicate the result:
    - 🟢 Player wins: Green background
    - 🔴 Computer wins: Red background
    - 🟠 Draw: Orange background

---

## 📂 Features

- Input validation and user-friendly prompts
- Colored end screen using `system("color")`
- Structs for organized round and game tracking
- Enum usage for choices and outcomes
- Random number generation for computer choices
- Replay option without restarting the program

---

## 🧠 Concepts Demonstrated

- `enum`, `struct`
- Functions and modular programming
- Loops and conditionals
- Pointers and references (`&`)
- Random number generation with `rand()`
- Basic terminal color manipulation (`system("color")`)
- Game logic flow and result aggregation

---

## 🔧 How to Compile and Run

### ✅ Prerequisites:

- C++ compiler (e.g., g++, clang++)

### 💻 Compile the code:

```bash
g++ rockpapersscissors.cpp -o rockpapersscissors
```
