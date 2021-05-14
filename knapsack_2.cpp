// knapsack_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/

#include <iostream>
#include <vector>

// returns the maximum value that can be put in a knapsack of capacity max_cap
int knapsack(int max_cap, const std::vector<int>& weights, const std::vector<int>& values, int nth_item)
{
    // base case
    if (nth_item == 0 || max_cap == 0)
        return 0;
    // if weight of nth_item is more than knapsack capacity max_cap,
    // then this item caanot be included in the optimal solution
    if (weights[nth_item - 1] > max_cap)
        return knapsack(max_cap, weights, values, nth_item - 1);
    else
        // otherwise return the maximum of two cases:
        // [1] nth item included
        // [2] nth item excluded
        return
            std::max(
                knapsack(max_cap - weights[nth_item - 1], weights, values, nth_item - 1) + values[nth_item - 1],
                knapsack(max_cap, weights, values, nth_item - 1)
            );
}

void run_knapsack(void)
{
    std::cout << "-----------------------------------\n";
    std::cout << "   brute-force knapsack problem!\n";
    std::cout << "-----------------------------------\n";
    std::cout << "profits = { 60, 100, 120 }\n";
    std::cout << "weights = { 10, 20, 30 }\n";

    std::vector<int> profits = { 60, 100, 120 };
    std::vector<int> weights = { 10, 20, 30 };

    int max_profit{};
    max_profit = knapsack(50, weights, profits, profits.size());
    std::cout << "Total knapsack profit ---> " << max_profit << std::endl;
}

int main()
{
    run_knapsack();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
