# sudoku-solver-cpp

A C++ Sudoku solver using **backtracking**. Takes an unsolved 9×9 board and fills in all valid solutions.

## How It Works

1. Find the next empty cell
2. Try digits 1–9
3. Check row, column, and 3×3 box constraints
4. Recurse — backtrack if stuck

## Build & Run

```bash
make
./sudoku
```

Or compile manually:

```bash
g++ -std=c++17 -O2 -o sudoku "Sudoku Solver.cpp"
./sudoku
```

## License

MIT
