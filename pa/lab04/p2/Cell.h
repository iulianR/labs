#ifndef __CELL_H__
#define __CELL_H__

#include <list>
#include <cstring>

using namespace std;

class Cell {
private:
    bool domain[9];
    int row, column, value, domainSize;


public:

    Cell(int row, int column) : row(row), column(column), value(0){
        for (int i = 0; i < 9; i++)
            domain[i] = true;
        domainSize = 9;
    }

    Cell(int row, int column, int value) : row(row), column(column), value(value){
        for (int i = 0; i < 9; i++)
            domain[i] = false;
        domain[value - 1] = true;
        domainSize = 1;
    }

    /**
     * @return the row
     */
    int getRow() {
        return row;
    }

    /**
     * @return the column
     */
    int getColumn() {
        return column;
    }

    /**
     * @return the value
     */
    int getValue() {
        return value;
    }

    /**
     * @param value the value to set
     */
    void setValue(int value) {
        this->value = value;
        for (int i = 0; i < 9; i++)
            domain[i] = false;
        domain[value - 1] = true;
        domainSize = 1;
    }

    /**
     * @return the domainSize
     */
    int getDomainSize() {
        return domainSize;
    }

    void removeFromDomain(int value) {
        if (domain[value - 1]) {
            domain[value - 1] = false;
            domainSize--;
        }
    }

    list<int> getPossibleValues() {
        list<int> result;
        for (int i = 0; i < 9; i++)
            if (domain[i]) result.push_back(i + 1);
        return result;
    }

    Cell *clone() {
        Cell *cell;
        if (value == 0) cell = new Cell(row, column);
        else cell = new Cell(row, column, value);
        memcpy(cell->domain, domain, 9);
        cell->domainSize = domainSize;
        return cell;
    }

    virtual ~Cell() {
    }

    
};

#endif

