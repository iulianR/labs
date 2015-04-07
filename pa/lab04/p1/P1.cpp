/**
 * Proiectarea Algoritmilor, 2014
 * Lab 4: Backtracking si optimizari
 * Task 1: Sudoku - Simple Backtracking
 *
 * @author 	Stefan Ruseti
 * @email	stefan.ruseti@gmail.com
 */
#include <iostream>
#include <fstream>

using namespace std;

int bktCounter = 0;
int solutionCounter = 0;
int grid[9][9];

/**
 * Intoarce true daca cifra adaugata la pozitia (row, column)
 * nu contrazice cifrele deja completate
 * 
 */
bool isValid(int grid[9][9], int row, int column) {
    for (int i = 0; i < 9; i++)
        if (i != column && grid[row][i] != 0 && grid[row][i] == grid[row][column])
            return false;
    for (int i = 0; i < 9; i++)
        if (i != row && grid[i][column] != 0 && grid[i][column] == grid[row][column])
            return false;
    for (int i = (row / 3) * 3; i < (row / 3 + 1) * 3; i++)
        for (int j = (column / 3) * 3; j < (column / 3 + 1) * 3; j++)
            if ((i != row || j != column) &&
                    grid[i][j] != 0 && grid[i][j] == grid[row][column])
                return false;

    return true;
}

void printGrid(int grid[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (grid[i][j] == 0) cout << " ";
            else cout << grid[i][j];
            cout << " ";
        }
        cout<<endl;
    }
    cout<<endl;
}

/**
 * Implementarea backtracking-ului simplu
 * 
 */
int doBKT(int grid[9][9], int row, int column) {

    bktCounter++; // incrementam numarul total de intrari in recursivitate

    // TODO 2: Implementarea algoritmului de backtracking simplu
    // TODO 3: Afisarea tuturor solutiilor gasite
    // TODO 4: Incrementarea variabilei solutionCounter pentru fiecare solutie

    while (row < 9 && grid[row][column] != 0) {
        column++;
        if (column == 9) {
            row++;
            column = 0;
        }
    }

    /* Found solution (both row and column are 9 and all boxes are filled) */
    if (row == 9) {
        printGrid (grid);
        solutionCounter++;
        return 1;
    }

    /* Try each value */
    for (int i = 1; i <= 9; i++) {
        grid[row][column] = i;
        if (isValid (grid, row, column) && doBKT (grid, row, column)) {
                return 1;
        }
    }

    /* Reset the element and return false */
    grid[row][column] = 0;
    return 0;

}

int main() {
    ifstream fin("sudoku.in");

    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            fin>>grid[i][j];
    bktCounter = 0;
    solutionCounter = 0;

    doBKT(grid, 0, 0);

    cout<<"Numar de intrari in recursivitare :"<<bktCounter<<endl;
    cout<<"Numar de solutii gasite: "<<solutionCounter<<endl;
    return 0;
}



