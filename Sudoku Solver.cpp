#include <iostream>

#define EMPTY 0
#define N 9

struct Sudoku
{
    
Sudoku() {
    std::cout << "Use digits 1 - 9, as empty character use 0.\nEnter your sudoku : \n" << std::endl;
    for (size_t i = 0; i < N; ++i)
        for (size_t j = 0; j < N; ++j)
            std::cin >> field[i][j];
}

bool have_empty_spots(int & row, int & col) {
    for (row = 0; row < N; ++row)
        for (col = 0; col < N; ++col)
            if (field[row][col] == EMPTY)
                return true;
    return false;
}

bool is_member_uniq(int rowIndex = 0, int colIndex = 0, int value = 0) {
    for (int j = 0; j < N; ++j)
        if (field[rowIndex][j] == value && j != colIndex)
            return false;
    for (int i = 0; i < N; ++i)
        if (field[i][colIndex] == value && i != rowIndex)
            return false;
    for (int i = (rowIndex / 3) * 3; i < (rowIndex / 3) * 3 + 3; ++i)
        for (int j = (colIndex / 3) * 3; j < (colIndex / 3) * 3 + 3; ++j)
            if (field[i][j] == value && i != rowIndex && j != colIndex)
                return false;
    return true;
}

bool sudoku_solver()
{
    int row, col;
    if (!have_empty_spots(row, col))
        return true;
    for (int num = 1; num <= N; ++num)
        if (is_member_uniq(row, col, num)){
            field[row][col] = num;
            if (sudoku_solver())
                return true;
            field[row][col] = EMPTY;
        }
    return false;
}


void output() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j)
            std::cout << field[i][j] << " ";
        std::cout << std::endl;
    }
}


int field[N][N] = {};
};


int main()
{
    // Constructor fills sudoku
    Sudoku sudoku;

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (sudoku.field[i][j] != EMPTY)
                if (!sudoku.is_member_uniq(i, j, sudoku.field[i][j])){
                    std::cout << "Cannot be solved";
                    return 0;
                }


    if (!sudoku.sudoku_solver()) {
        std::cout << "Cannot be solved";
        return 0;
    }
    else {
        std::cout << "\nSolved Sudoku : \n\n";
        sudoku.output();
    }
    
    std::cin.get();
    std::cin.get();
    
    return 0;
}
