# Country Hangman 🌍

A feature-rich C++ console game where players test their geography knowledge by guessing the names of 195 countries. This project demonstrates the use of string manipulation, arrays, and game state management in C++.

## 📝 Description

This is a classic Hangman game tailored for geography enthusiasts. The program randomly selects a country from a comprehensive dataset of 195 nations. As the player guesses letters, the game provides visual feedback through dynamic ASCII art that builds the gallows with every mistake.

**Key Logic:**
- **Dynamic Drawing:** Uses a state-mapping system to render the hangman figure based on the mistake count.
- **Input Validation:** Prevents users from guessing the same letter twice.
- **Smart Formatting:** Automatically reveals spaces for multi-word countries (e.g., "United Kingdom") to improve playability.

## 🎮 Features

* **Massive Dataset:** Includes 195 countries (from Afghanistan to Zimbabwe).
* **Visual Progression:** 11 distinct stages of ASCII art (from empty gallows to game over).
* **10-Life System:** Players are allowed 10 mistakes before the game ends.
* **Duplicate Protection:** The game remembers guessed letters and warns the player without penalizing them.
* **Randomization:** Uses `srand(time(0))` to ensure a different country every time you play.

## 🚀 How to Run

### Prerequisites
You need a C++ compiler (like G++ or Clang) installed on your system.

### Compilation
Open your terminal or command prompt and run:

```bash
g++ main.cpp -o hangman
