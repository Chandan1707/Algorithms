# include <iostream>
using namespace std;

void print_Knight(int **arr, int m, int n){
    cout << "Souution :" << endl;
    for (int i = 0; i < m; i ++){
        for (int j = 0; j < n; j ++){
            if (arr[i][j] <= 9)
                cout << "0" << arr[i][j] << " ";
            else
                cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(int **arr, int row, int col, int m, int n){
    if (row >= 0 && col >= col && row < m && col < n && arr[row][col] == -1){
        return true;
    }
    return false;
}

bool Knight_tour(int **arr, int row, int col, int m, int n, int count){

    if (count == m*n){
        return true;
    }
    if (isSafe(arr, row, col, m, n)){
        arr[row][col] = count;
        count++;
        if (Knight_tour(arr, row-2, col-1, m, n, count)){
            return true;
        }
        if (Knight_tour(arr, row-2, col+1, m, n, count)){
            return true;
        }
        if (Knight_tour(arr, row-1, col-2, m, n, count)){
            return true;
        }
        if (Knight_tour(arr, row-1, col+2, m, n, count)){
            return true;
        }
        if (Knight_tour(arr, row+1, col+2, m, n, count)){
            return true;
        }
        if (Knight_tour(arr, row+1, col-2, m, n, count)){
            return true;
        }
        if (Knight_tour(arr, row+2, col-1, m, n, count)){
            return true;
        }
        if (Knight_tour(arr, row+2, col+1, m, n, count)){
            return true;
        }
        arr[row][col] = -1;
        return false;
    }
    return false;
}

int main(){
    int count = 0;
    int m = 10;
    int n = 10;
    int **arr = new int*[m];
    
    for (int i = 0; i < m; i++){
        arr[i] = new int[n];
    }
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            arr[i][j] = -1;
        }
    }
    Knight_tour(arr, 0, 0, m, n, count);
    print_Knight(arr, m, n);
    return 0;
}