# Code_Alpha_Sukodu_Solver

## Overview

This is a simple **Sudoku Solver** application written in C++ that can solve Sudoku puzzles automatically. The user can either choose a predefined Sudoku puzzle or input their own puzzle manually. The program uses a backtracking algorithm to solve the Sudoku and displays the solution.

## Features

- **Predefined Sudoku Puzzle**: The application provides a default Sudoku puzzle that you can solve.
- **Manual Input**: Users can enter their own Sudoku puzzle by inputting 81 digits separated by spaces (0 represents empty cells).
- **Backtracking Algorithm**: The Sudoku puzzle is solved using the backtracking algorithm.
- **Dynamic Grid Display**: The grid is displayed in a readable format, with visual separators between the 3x3 subgrids.
- **Color-Coded Console Output**: The output is color-coded to differentiate between various sections (rules, grid, etc.).
- **Input Validation**: The program checks if the entered grid is valid and if it can be solved.

## Technical Highlights

- **Backtracking Algorithm**: 
    - The `Sudoku_solved()` function implements the backtracking algorithm to solve the Sudoku puzzle. It tries filling in numbers from 1 to 9 in empty cells and recursively attempts to solve the puzzle.
    - The `check_empty()` function ensures that a number can only be placed in a cell if it doesn't violate the Sudoku rules (no duplicate numbers in the same row, column, or 3x3 subgrid).
  
- **Grid Input Handling**:
    - The grid can be input manually using the `inputstr()` function, which takes a string of 81 space-separated digits and fills the grid accordingly. The program uses the `getline()` function to read the entire input line as a string and then processes it into individual digits using a `stringstream`.
    - **Technical Highlight**: `getline(cin, input)` is used here to capture the entire line of input, which allows the user to enter all digits at once.

- **Grid Display**:
    - The `print_grid()` function displays the Sudoku grid in a visually formatted manner, ensuring 3x3 subgrids are separated with " | " and rows/columns are well-spaced.

## How to Run

1. **Clone the Repository**:
   First, clone the repository to your local machine.
   ```bash
   git clone https://github.com/yourusername/sudoku-solver.git
   cd sudoku-solver
