#include <fstream>
#include <iostream>
#include <vector>
#include "vector_io.h"

// Maximum number of bills to be payed
#define MAX_NO 666013

enum programming_method {
    greedy,
    dynamic_programing
};

std::vector<int> give_change_greedy(std::vector<int>& bills, int sum)
{
    std::vector<int> sol(bills.size(), 0);

    // TODO Dati restul folosind o modalitate greedy.
    int p = bills.size() - 1;
    while (sum > 0) {
        while (bills[p] > sum) {
            p--;
        }
        sum -= bills[p];
        sol[p]++;
    }

    return sol;
}

std::vector<int> give_change_pd(std::vector<int>& bills, int sum)
{
    std::vector<int> sol(bills.size(), 0);

    // TODO Gasiti recurenta care calculează min_bills(sum)
    // Unde min_bills(sum) este numărul minim de bancnote pentru
    // a plăti suma sum.
    std::vector<int> min_bills(sum + 1, MAX_NO);
    std::vector<int> from(sum + 1, 0);

    min_bills[0] = 0;
    for (int i = 1; i <= sum; i++) {
        int count = MAX_NO;
        for (unsigned int j = 0; j < bills.size(); j++) {
            if (i - bills[j] >= 0 && count > min_bills[i - bills[j]]) {
                count = min_bills[i - bills[j]];
                from[i] = j;
            }
        }

        if (count < MAX_NO) {
            min_bills[i] = count + 1;
        }
        else {
            min_bills[i] = MAX_NO;
        }
    }

    while (sum > 0) {
        sol[from[sum]] = min_bills[sum];
        sum -= from[sum] * bills[from[sum]];
    }

    return sol;
}

void test_case(int sum, std::vector<int>& bills, programming_method method)
{
    std::vector<int> sol;
    if (method == greedy) {
        sol = give_change_greedy(bills, sum);
    } else {
        sol = give_change_pd(bills, sum);
    }

    std::cout << "In bancnote, " << sum << " este:" << std::endl;

    for (unsigned int j = 0; j < bills.size(); j ++) {
        std::cout << sol[j] << " x " << bills[j] << "$" << std::endl;
    }
    std::cout << std::endl << std::endl;

}

void test(std::vector<int> t_g, std::vector<int> t_pd, std::vector<int> bills_pd)
{
    std::vector<int> bills_g;
    bills_g.push_back(1); bills_g.push_back(5); bills_g.push_back(10);
    bills_g.push_back(50); bills_g.push_back(100);

    std::cout << "==== Test Greedy ====" << std::endl << std::endl;

    for (unsigned int i = 0; i < t_g.size(); i++) {
        test_case(t_g[i], bills_g, greedy);
    }

    std::cout << "==== Test Programare Dinamica ====" << std::endl << std::endl;

    for (unsigned int i = 0; i < t_pd.size(); i++) {
        test_case(t_pd[i], bills_pd, dynamic_programing);
        std::cout << "Varianta greedy ar fi dat:" << std::endl;
        test_case(t_pd[i], bills_pd, greedy);
    }
}

int main(void)
{
    std::ifstream f("date.in");
    std::vector<int> bills_pd, t_g, t_pd;

    f >> t_g;
    f >> bills_pd;
    f >> t_pd;
    test(t_g, t_pd, bills_pd);

    return 0;
}
