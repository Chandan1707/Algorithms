#include <iostream>
#include <string.h>
using namespace std;
void LCS(char *a, char *b, int m, int n){
    // int **lcs = new int*[m+1];
    // for (int i = 0; i < m+1; i++){
    //     *lcs = new int[n+1];
    // }
    int lcs[m+1][n+1];
    
    for (int i = 0; i <= m; i++){
        for (int j = 0; j <= n; j ++){
            if (i == 0 || j == 0)
                lcs[i][j] = 0;
            else if (a[i-1] == b[j-1]){
                lcs[i][j] = 1 + lcs[i-1][j-1];
            }
            else {
                lcs[i][j] = max(lcs[i][j-1], lcs[i-1][j]);
            }
        }
    }
    int index = lcs[m][n];
    char lcs_arr[index + 1];
    lcs_arr[index] = '\0';
    int i = m;
    int j = n;
    while (i > 0 && j > 0){
        if (a[i-1] == b[j-1]){
            lcs_arr[index-1] = a[i-1];
            index --;
            i --;
            j --;
        }

        else if (lcs[i-1][j] > lcs[i][j-1]){
            i--;
        }
        else {
            j --;
        }
    }
    cout << "LCS of str1 and str2 :" <<  lcs_arr;
}

int main(){

    char str1[] = "chandan";
    char str2[] = "tanusree";
    int m = strlen(str1);
    int n = strlen(str2);
    LCS(str1, str2, m, n);
    cout << endl;
}

