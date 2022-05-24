# include <iostream>
# include <cstring>
using namespace std;

int m[50][50];

int Matrix_Chain_Mul_Dyn(int arr[], int i, int j){
    if (i == j)
        m[i][j] = 0;

    else if(m[i][j] != -1)
        return m[i][j];

    else{
        m[i][j] = INT32_MAX;
        int k;
        for (k = i; k < j; k ++){
            m[i][j] = min(m[i][j], Matrix_Chain_Mul_Dyn(arr, i, k) + Matrix_Chain_Mul_Dyn(arr, k+1, j) + arr[i-1]*arr[k]*arr[j]);
        }
    }
    return m[i][j];
}

int Matrix_Chain_Mul(int arr[], int i, int j){
    if (i == j)
        return 0;
    else {
        int k, cost = INT32_MAX;
        for (k = i; k < j; k ++){
            cost = min( cost, Matrix_Chain_Mul(arr, i, k) + Matrix_Chain_Mul(arr, k + 1, j) + arr[i-1]*arr[k]*arr[j]);
        }
        return cost;
    }
}

int main(){

    memset(m, -1, sizeof(m));
    int arr1[] = {10, 20, 50, 1, 100};
    int arr[] = {4, 10, 3, 12, 20, 7};
    int n = 5;
    cout << Matrix_Chain_Mul(arr1, 1, 4) << endl;
    cout << Matrix_Chain_Mul(arr, 1, n) << endl;
    cout << "Dynamic Programing :" << endl;
    cout << Matrix_Chain_Mul_Dyn(arr1, 1, 4) << endl;
    memset(m, -1, sizeof(m));
    cout << Matrix_Chain_Mul_Dyn(arr, 1, n) << endl;
    return 0;
}