/**
 * Proiectarea Algoritmilor, 2014
 * Lab 4: Backtracking si optimizari
 * Task 2: Sudoku - Backtracking + AC-3
 *
 * @author 	Stefan Ruseti
 * @email	stefan.ruseti@gmail.com
 */
#include <iostream>
#include <fstream>
#include "Cell.h"
#include <vector>
#include <list>
#include <queue>

using namespace std;

struct Arc {
    Cell *c1, *c2;

    Arc(Cell *c1, Cell *c2) : c1(c1), c2(c2) {
    }
};


int bktCounter = 0;
int solutionCounter = 0;

/**
 * Metoda care intoarce o copie deep (un ArrayList nou ce contine copii ale
 * obiectelor) a ArrayList-ului trimis ca parametru
 */
vector<Cell *> makeListCopy(vector<Cell *> cells) {

    vector<Cell *> result = vector<Cell *>(cells.size());
    for (unsigned int i = 0; i < cells.size(); i++) {
        result[i] = cells[i]->clone();
    }
    return result;
}

/**
 * Intoarce true daca (c1, c2) apartine listei de arce
 *
 */
bool areRelated(Cell *c1, Cell *c2) {
    if (c1->getRow() == c2->getRow()) {
        return true;
    }
    if (c1->getColumn() == c2->getColumn()) {
        return true;
    }
    if (c1->getRow() / 3 == c2->getRow() / 3
            && c1->getColumn() / 3 == c2->getColumn() / 3) {
        return true;
    }

    return false;
}

/**
 * Intoarce true daca valorile de pe casutele c1 si c2 sunt valide
 *
 */
bool areValid(Cell *c1, Cell *c2) {
    return !areRelated(c1, c2) || c1->getValue() != c2->getValue();
}



/**
 * Implementarea functiei de Verifica(Xk, Xm) - actualizeaza domeniul lui c1
 * si pastreaza valorile care au un corespondent in c2 care sa satisfaca
 * restrictiile - intoarce true daca domeniul variabilei c1 a suferit
 * modificari
 */
bool check(Cell *c1, Cell *c2) {
    bool deleted = false;

    // TODO 1: Pentru fiecare valoare din domeniul variabilei c1
    // verifica daca exista o valoare valida in domeniul lui c2
    for (list<int>::iterator it1 = c1->getPossibleValues ().begin (); it1 != c1->getPossibleValues ().end (); it1++) {
        int found = 0;
        for (list<int>::iterator it2 = c2->getPossibleValues ().begin (); it2 != c2->getPossibleValues ().end (); it2++) {
            if (areValid(new Cell (c1->getRow (), c1->getColumn (), (*it1)),
                         new Cell (c2->getRow (), c2->getColumn (), (*it2)))) {
                found = 1;
            }
        }
        if (!found) {
            c1->removeFromDomain ((*it1));
            deleted = true;
        }
    }
    return deleted; // intoarcem true daca s-au sters valori
}

/**
 * Metoda care aplica agloritmul AC3 pe variabilele primite in lista cells
 * Intoarce true daca un domeniu al vreunei variabile a devenit gol
 */
bool doAC3(vector<Cell *> cells) {

    queue<Arc> q;
    // TODO 2: Initializare coada cu multimea arcelor
    for (vector<Cell *>::iterator it1 = cells.begin (); it1 != cells.end (); it1++) {
        for (vector<Cell *>::iterator it2 = cells.begin (); it2 != cells.end (); it2++) {
            if (areRelated (*it1, *it2) && (*it1) != (*it2)) {
                Arc *a = new Arc ((*it1), (*it2));
                q.push (*a);
            }
        }
    }
    // TODO 3: Cat timp mai exista arce de verificat in coada,
    // extrage primul arc si verifica domeniile folosind functia check de mai sus

    // While arcs still exists
    while (!q.empty ()) {
        // Extract first
        Arc first = q.front ();
        q.pop ();

        // Check using method
        if (check (first.c1, first.c2) == true) {
            // Return true if domain is now empty
            if (!first.c1->getDomainSize ())
                return true;
            for (vector<Cell *>::iterator it2 = cells.begin (); it2 != cells.end (); it2++) {
                if (areRelated (first.c1, *it2) && first.c1 != (*it2)) {
                    Arc *a = new Arc ((*it2), first.c1);
                    q.push (*a);
                }
            }
        }
    }
    return false;

}

void destroyCells(vector<Cell *> *cells) {
    for (unsigned int i = 0; i < cells->size(); i++) {
        delete (*cells)[i];
    }
    cells->clear();
}

void printGrid(vector<Cell *> cells) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (cells[i * 9 + j]->getValue() == 0) {
                cout<<" ";
            } else {
                cout<<cells[i * 9 + j]->getValue();
            }
            cout<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

/**
 * Implementarea backtracking + AC-3 simplu
 *
 */
int doBKT(vector<Cell *> cells, int row, int column) {

    bktCounter++; // incrementam numarul total de intrari in recursivitate
    //TODO 4: Testam daca am completat tot si afisam solutia]

    if (row < 9 && cells[row * 9 + column]->getValue () != 0) {
        column++;
        if (column == 9) {
            row++;
            column = 0;
        }
    }

    if (row == 9) {
        printGrid (cells);
        solutionCounter++;
        return 1;
    }

    // Aplicam algoritmul AC3 pe variabilele din lista queens
    if (doAC3(cells)) {
        destroyCells(&cells);
        return 1;
    }

    // TODO 5: Aplicam backtracking pe valorile ramase in domeniul variabilei curente.
    // Atentie! va trebui sa folosim o copie a listei cells la intrarea in recursivitate.
    // Daca folosim direct functia setValue pe lista originala queens, la intoarcerea din
    // recursivitate vom pierde celelalte valori din domeniul variabilei pe care iteram.
    // Hint: folositi functia makeListCopy
    for (int i = 1; i <= 9; i++) {
        cells[row * 9 + column]->setValue (i);
        if (doBKT (makeListCopy (cells), row, column)) {
            return 1;
        }
    }
    return 0;
}


int main() {
    ifstream fin("sudoku.in");
    vector<Cell *> cells(81);
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++) {
            int value;
            fin >> value;
            if (value == 0) {
                cells[i * 9 + j] = new Cell(i, j);
            } else {
                cells[i * 9 + j] = new Cell(i, j, value);
            }
        }
    bktCounter = 0;
    solutionCounter = 0;

    doBKT(cells, 0, 0);

    cout << "Numar de intrari in recursivitare :" << bktCounter << endl;
    cout << "Numar de solutii gasite: " << solutionCounter << endl;
    return 0;
}



