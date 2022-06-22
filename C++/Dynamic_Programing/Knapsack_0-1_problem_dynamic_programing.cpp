#include <iostream>
using namespace std;

void Knapsack(int weight[], int profit[], int capacity, int n){
    int W[n + 1][capacity  + 1];
    int item_include[n+1];

    for (int i = 0; i <= n; i ++){
        for (int j = 0; j <= capacity; j++){
            if (i == 0 || j == 0)
                W[i][j] = 0;
            else if(j >= weight[i-1]){
                W[i][j] = max(W[i-1][j], profit[i-1] + W[i-1][j - weight[i-1]]);
            }
            else {
                W[i][j] = W[i-1][j];
            }
        }
    }

    int j = capacity;
    for (int i = n; i >= 0; i --){
        
        if (W[i][j] == W[i-1][j]){
            item_include[i] = 0;
        }
        else {
            item_include[i] = 1;
            j = j - weight[i-1];
        }
    }
    
    cout << "Item Include : ";
    for (int i = 1; i <= n; i++){
        cout << item_include[i] << " ";
    }
    cout << endl;

    cout << "Max Profit :" << W[n][capacity] << endl;
}

int main() {
    int n = 4;
    int capacity = 8;
    int profit[] = {2, 3, 4, 1};
    int weight[] = {3, 4, 5, 6};

    Knapsack(weight, profit, capacity, n);
    return 0;
}