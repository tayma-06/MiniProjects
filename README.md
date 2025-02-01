# Tic-Tac-Toe Game

## Introduction
This is a simple console-based Tic-Tac-Toe game written in C++. The game offers two modes:
1. **Single Player Mode** – Play against an AI.
2. **Multiplayer Mode** – Play against another player.

## Features
- Choose a custom character to represent Player X and Player O.
- AI opponent in single-player mode.
- Tracks scores of both players.
- Option to play multiple rounds.
- Detects wins, losses, and draws.

## How to Play
1. Run the program.
2. Choose game mode:
   - Press `1` for Single Player mode.
   - Press `2` for Multiplayer mode.
   - Press `3` to exit.
3. In Multiplayer mode, both players enter custom characters.
4. In Single Player mode, Player X selects a custom character, and AI is assigned `A`.
5. The game board is displayed with numbers (1-9) indicating positions.
6. Players take turns entering a number (1-9) to place their mark.
7. The game checks for a winner or a draw after each move.
8. The score is updated, and players can choose to play again.

## Game Controls
- **Input a number (1-9)** to place a mark on the board.
- **Enter 'y' or 'Y'** to play again after a round.
- **Enter any other key** to quit after a round.

## How to Compile and Run
1. Open a terminal or command prompt.
2. Compile the code using g++:
   ```bash
   g++ -o tic_tac_toe ticTacToe.cpp
   ```
3. Run the executable:
   ```bash
   ./tic_tac_toe   # For Linux/Mac
   tic_tac_toe.exe  # For Windows
   ```

## Dependencies
- C++ compiler (g++, clang, or MSVC)

## Future Improvements
- Improve AI strategy.
- Add a graphical user interface.
- Implement networked multiplayer mode.

## Author
**Khadiza Sultana**

## License
This project is open-source and free to use for educational purposes.

