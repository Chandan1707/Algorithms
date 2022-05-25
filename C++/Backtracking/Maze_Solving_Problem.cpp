#include <iostream>
using namespace std;

void print_maze(int **arr, int m, int n){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
bool isSafe(int arr[][10], int row, int col, int m, int n, int ** solve){
    if (row >= 0 && col >= 0 && row < m && col < n && arr[row][col] == 1 && solve[row][col] != 1)
        return true;
    return false;

}
bool Maze_Slove(int arr[][10], int **solve, int row, int col, int m, int n){
    
    if (isSafe(arr, row, col, m, n, solve)){
        solve[row][col] = 1;
        if (Maze_Slove(arr, solve, row, col+1, m, n)){
            return true;
        }
        if (Maze_Slove(arr, solve, row+1, col, m, n)){
            return true;
        }
        if (Maze_Slove(arr, solve, row, col-1, m, n)){
            return true;
        }
        if (Maze_Slove(arr, solve, row-1, col, m, n)){
            return true;
        }

        if (row >= m-1 && col >= n-1){
        return true;
        }

        solve[row][col] = 0;
        return false;
    }
    return false;
}
void manage_maze(int m, int n){
    int **solve = new int*[m];
    for (int i = 0; i < m; i++){
        solve[i] = new int[n];
    }
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            solve[i][j] = 0;
        }
    }
    int arr[10][10] = {
                { 1, 0, 0, 0, 0, 0, 1, 1, 1, 1},
                { 1, 1, 1, 1, 1, 0, 1, 0, 1, 1},
                { 1, 1, 1, 0, 1, 0, 1, 1, 1, 1},
                { 1, 0, 1, 0, 1, 0, 1, 0, 0, 1},
                { 1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
                { 1, 0, 0, 0, 1, 0, 1, 0, 1, 0},
                { 1, 0, 1, 1, 1, 0, 1, 0, 1, 0},
                { 1, 0, 1, 0, 0, 0, 1, 0, 1, 1},
                { 0, 1, 1, 1, 1, 1, 1, 0, 1, 1},
                { 1, 1, 1, 1, 0, 0, 0, 0, 1, 1}
    };
    Maze_Slove(arr, solve, 0, 0, m, n);
    print_maze(solve, m, n);
}

int main(){
    int m = 10;
    int n = 10;
    
    manage_maze(m, n);
    return 0;
}