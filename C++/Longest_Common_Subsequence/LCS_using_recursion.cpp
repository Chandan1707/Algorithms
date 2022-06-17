#include <iostream>
using namespace std;

int LCS(char *a, char *b, int i, int j){
    if (a[i] == '\0' || b[j] == '\0')
        return 0;
    if (a[i] == b[j])
        return (1 + LCS(a, b, i + 1, j + 1));
    else
        return max(LCS(a, b, i, j + 1), LCS(a, b, i + 1, j));
}


int main(){

    char str1[] = "chandan";
    char str2[] = "tanusree";
    cout << "LCS of str1 and str2 :" << LCS(str1, str2, 0, 0);
    cout << endl;
}