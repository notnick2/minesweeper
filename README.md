# Minesweeper Game in C

## Introduction

Welcome to the Minesweeper game implemented in C! This classic game provides a challenging and strategic experience as you uncover tiles while avoiding hidden mines. This version is designed to be a simple yet engaging console-based Minesweeper game.

## Features

- **User-Friendly Interface**: A clean and intuitive console interface for a seamless gaming experience.
- **Grid Size Customization**: Adjust the size of the game board according to your preference.
- **Random Mine Placement**: Mines are placed randomly on the board, providing a unique challenge each time you play.

## How to Play

1. **Compile the Code**: Use a C compiler to compile the `minesweeper.c` file. For example:
   ```bash
   gcc minesweeper.c -o minesweeper
   ```

2. **Run the Game**: Execute the compiled file to start the game.
   ```bash
   ./minesweeper
   ```

3. **Winning or Losing**: The game is won by uncovering all safe tiles without hitting a mine. If you uncover a mine, the game is lost.



## Customization

- **Adjust Grid Size**: In the source code, you can modify the `ROWS` and `COLS` constants to change the dimensions of the game board.
- **Change Mine Density**: The `MINES` constant determines the percentage of cells that contain mines. Adjust this value for easier or more challenging games.

## Dependencies

No external libraries are required to run this Minesweeper game.

## Contribution

Contributions are welcome! If you find any bugs or have suggestions for improvements, feel free to open an issue or submit a pull request.

## License

This Minesweeper game is open-source and released under the [MIT License](LICENSE).

Enjoy playing Minesweeper!
