#include <iostream>
using namespace std;

int min(int a, int b, int c){
    if (a < b)
        return a < c ? a : c;
    else   
        return b < c ? b : c;
}

int minCostPath(int arr[3][3], int m, int n){
    if (m < 0 || n < 0)
        return INT32_MAX;
    if (m == 0 && n == 0)
        return arr[m][n];
    else 
        return min(minCostPath(arr, m-1, n), minCostPath(arr, m, n-1), minCostPath(arr, m-1, n-1)) + arr[m][n];
}

int main(){
    int cost[][3] = {
        {1, 2, 3},
        {4, 8, 2},
        {1, 5, 3}
    };
    cout << "Min Cost :" << minCostPath(cost, 2, 2) << endl;
}