#include <iostream>
using namespace std;

int count = 1;

bool is_Place(int arr[9][9], int row, int col, int val){
    // row and column check
    for (int i = 0; i < 9; i++){
        if (arr[row][i] == val)
            return false;
        
        if (arr[i][col] == val)
            return false;
    }
    // block check
    int r = (row / 3) * 3;
    int c = (col / 3) * 3;
    for (int i = r; i < r+3; i++){
        for (int j = c; j < c +3; j++){
            if (arr[i][j] == val)
                return false;
        }
    }
    return true;
}

void Suduku(int arr[][9], int row, int col){

    if (row == 8 && col == 8){
        cout << "Solution :"<< count << endl;
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++)
                cout << arr[i][j] << " ";
            cout << endl;
        }
        cout << endl;
        count ++;
        return;
    }
    if (arr[row][col] == -1){
        for (int i = 1; i < 10; i++){
            if(is_Place(arr, row, col, i)){
                arr[row][col] = i;
                if (col == 8){
                    Suduku(arr, row+1,0);
                }
                else{
                    Suduku(arr, row, col + 1);
                }
                arr[row][col] = -1;
            }
        }
    }
    else {
        if (col == 8){
            Suduku(arr, row+1,0);
        }
        else{
            Suduku(arr, row, col + 1);
        }
    }
}

int main (){
    int arr[9][9] ={{ 5, 3,-1,-1, 7,-1,-1,-1,-1},
                    { 6,-1,-1, 1, 9, 5,-1,-1,-1},
                    {-1, 9, 8,-1,-1,-1,-1, 6,-1},
                    { 8,-1,-1,-1, 6,-1,-1,-1, 3},
                    { 4,-1,-1, 8,-1, 3,-1,-1, 1},
                    { 7,-1,-1,-1, 2,-1,-1,-1, 6},
                    {-1, 6,-1,-1,-1,-1, 2,-1, 8},
                    {-1,-1,-1, 4, 1, 9,-1,-1, 5},
                    {-1,-1,-1,-1, 8,-1,-1, 7, 9}
                };

    Suduku(arr, 0, 0);
    return 0;
}