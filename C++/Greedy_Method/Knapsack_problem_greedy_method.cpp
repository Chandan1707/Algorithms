#include <iostream>
#include <algorithm>
using namespace std;

struct Node{
    int weight;
    int profit;
    Node(int weight, int profit){

        this->weight = weight;
        this->profit = profit;
    }
};

bool cmp(struct Node a, struct Node b){
    float c = (float)(a.profit / a.weight);
    float d = (float)(b.profit / b.weight);

    return c > d;
}

float Knapsack(Node arr[], int n, int Capacity){

    float total_profit = 0.0;
    float capacity = (float)Capacity;
    sort(arr, arr + n, cmp);
    for (int i = 0; i < n; i ++){

        if (arr[i].weight < capacity){

            capacity -= arr[i].weight;
            total_profit += arr[i].profit;
        }
        else {

            total_profit += (capacity / arr[i].weight) * arr[i].profit;
            capacity = 0;
            break;
        }
    }
    return total_profit;
}

int main () {

    int n = 4;
    int capacity = 60;
    Node arr[] = {
        {10, 100},
        {40, 280},
        {20, 120},
        {24, 120}
    };

    cout << "Maximum profit :" << Knapsack(arr, n, capacity) << endl;
    return 0;
}