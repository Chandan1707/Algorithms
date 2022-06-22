# include <iostream>
using namespace std;

int Knapsack(int weight[], int profit[], int n, int capacity) {
    if (capacity == 0 || n == 0)
        return 0;
    if (capacity < weight[n-1])
        return Knapsack(weight, profit, n-1, capacity);
    else {
        return max((profit[n-1] + Knapsack(weight, profit, n-1, capacity-weight[n-1])),
                Knapsack(weight, profit, n-1, capacity));
    }
}

int main () {
    int n = 3;
    int capacity = 50;
    int weight[] = {10, 20, 30};
    int profit[] = {60, 100, 120};
    int res = Knapsack(weight, profit, n, capacity);
    cout << "Total Profit : " << res << endl;
    return 0;
}