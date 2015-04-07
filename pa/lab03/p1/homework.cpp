#include "vector_io.h"

#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

//Un task de tema este definita ca deadline si punctele castigate in urma
//rezolvarii sale
struct HomeWorkTask {
    int deadline;
    int points;
};

const HomeWorkTask no_task = { -1, -1 };

//Citire scriere pentru HomeWork

std::istream& operator>>(std::istream& stream, HomeWorkTask& hw)
{
    stream >> hw.deadline >> hw.points;
    return stream;
}

std::ostream& operator<<(std::ostream& stream, const HomeWorkTask& hw)
{
    if (hw.deadline == -1 && hw.points == -1) {
        stream << "liber";
        return stream;
    }
    stream << "(d: " << hw.deadline << ", p: " << hw.points << ")";
    return stream;
}

//Sfarsit de IO

bool operator<(const HomeWorkTask& a, const HomeWorkTask& b)
{
    return (a.points > b.points);
}

// bool operator==(const HomeWorkTask& a, const HomeWorkTask& b)
// {
//     if (a.points == b.points)
//         return true;

//     return false;
// }

//Intoarce planificarea temelor pentru un set de task-uri
//
//@homework: vector cu task-urile ce trebiue rezolvate
//@last_day: ultima zi in care pot fi rezolvate task-uri
std::vector<HomeWorkTask> get_planning(std::vector<HomeWorkTask> tasks,
                                       int last_day)
{
    //TODO adaugati in planning pe indicele i, task-ul care se va rezolva
    //in ziua i. Daca nu se va rezolva niciun task, adaugati valoarea no_task
    std::vector<HomeWorkTask> planning(last_day + 1, no_task);

    std::sort (tasks.begin(), tasks.end());
    //TODO porniti planificarea de la ultima zi si adaugati tema care
    //maximizeaza numarul total de puncte obtinute.

    for (int i = last_day; i >= 0; i--) {
        for (unsigned int j = 0; j < tasks.size(); j++) {
            if (tasks[j].deadline >= i) {
                planning[i] = tasks[j];
                tasks.erase (tasks.begin() + j);
                break;
            }
        }
    }

    return planning;
}

void test_case(std::vector<HomeWorkTask>& tasks, int last_day)
{
    std::cout << "##############" << std::endl;
    std::cout << "Pentru ";
    std::cout << tasks << std::endl;
    std::cout << std::endl << "Planificarea este:" << std::endl;
    std::vector<HomeWorkTask> planning = get_planning(tasks, last_day);
    for (unsigned int d = 0; d < planning.size(); d++) {
        std::cout << "Ziua " << d << ": " << planning[d] << std::endl;
    }
    std::cout << std::endl;
}

int main(void)
{
    std::ifstream f("date.in");
    //Teste
    std::vector<HomeWorkTask> tasks;
    int last_day;
    int no_tests;
    f >> no_tests;
    while (no_tests--) {
        f >> last_day;
        f >> tasks;
        test_case(tasks, last_day);
    }
    return 0;
}

