#include <iostream>
using namespace std;
# define M 3
# define N 3

int min_val(int a, int b, int c){
    if (a < b)
        return a < c ? a : c;
    else   
        return b < c ? b : c;
}


int minCostPath(int cost[M][N], int m, int n){
    int min[m+1][n+1];
    min[0][0] = cost[0][0];
    for (int i = 1; i <= m; i++)
        min[i][0] = cost[i][0] + min[i-1][0];
    for (int i = 1; i <= n; i++)
        min[0][i] = cost[0][i] + min[0][i-1];
    
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            min[i][j] = cost[i][j] + min_val(min[i-1][j-1], min[i][j-1], min[i-1][j]);
        }
    }
    return min[m][n];
}


int main(){
    int cost[][N] = {
        {1, 2, 3},
        {4, 8, 2},
        {1, 5, 3}
    };
    cout << "Min Cost :" << minCostPath(cost, 2, 2) << endl;
}