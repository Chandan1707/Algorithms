#include <iostream>
using namespace std;
int count = 1;

bool isPlace(char **arr, int row, int col, int n){
    //row check
    for (int i = 0; i < n; i++){
        if (arr[row][i] == 'Q')
            return false;
    }

    // column check
    for (int i = 0; i < n; i++)
        if (arr[i][col] == 'Q')
            return false;
    
    // left - top
    for (int i = row, j = col; i >= 0 && j >= 0; i--,j --){
        if (arr[i][j] == 'Q')
            return false;
    }
    
    // right - top
    for (int i = row, j = col; i >= 0 && j < n; i--, j++){
        if (arr[i][j] == 'Q')
            return false;
    }

    // left - down
    for (int i = row, j = col; i <n && j >= 0; i++, j--){
        if (arr[i][j] == 'Q')
            return false;
    }

    // right - down
    for (int i = row, j = col; i < n && j < n; i++,j ++){
        if (arr[i][j] == 'Q')
            return false;
    }

    return true;
}

void Queen_Solve(char **arr, int row, int n){
    if (row == n){
        cout <<"Solution No :"<< count << endl;
        for (int i = 0; i < n; i++){
            cout << "\t";
            for (int j = 0; j < n; j++){
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
        count ++;
        return;
    }
    for (int i = 0; i < n && row < n;i ++){
        if (isPlace(arr, row, i, n)){
            arr[row][i] = 'Q';
            Queen_Solve(arr, row + 1, n);
            arr[row][i] = '_';
            
        }
    }
}

void N_Queen(int n){
    char ** arr = new char*[n];
    for (int i = 0; i < n; i++)
        arr[i] = new char[n];

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            arr[i][j] = '_';
    }
    Queen_Solve(arr,0,n);
}

int main(){
    int n;
    cout << "Enter Number of Queen :";
    cin >> n;
    N_Queen(n);
    cout << "complete" << endl;
    return 0;
}