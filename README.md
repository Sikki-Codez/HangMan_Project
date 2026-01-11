# Hangman: Country Edition

### Description
A C++ console game challenging players to guess countries from a hardcoded list of 195 nations. Includes a randomized selection engine, input validation to prevent repeated guesses, and a strict mistake counter capped at 10 attempts before game over.

### Features
* **Global Database:** Randomly selects from 195 countries.
* **Input Validation:** Detects and blocks repeated letter guesses.
* **Mistake Counter:** Tracks incorrect attempts with a hard limit of 10.
* **Dynamic Display:** Updates the hidden word (e.g., `_ _ _ _`) in real-time.

### How to Run
1.  Ensure you have a C++ compiler (like G++) installed.
2.  Compile the code:
    ```bash
    g++ Hangman.cpp -o hangman
    ```
3.  Run the executable:
    * **Windows:** `.\hangman.exe`
    * **Mac/Linux:** `./hangman`
