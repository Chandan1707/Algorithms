#include <iostream>
using namespace std;
int a[50] = {-1};
// using recursion
int fib_rec(int n){
    /*
    Time Complexity : 
        T(n) = T(n-1) + T(n-2) + c 
    
    this function take O(2^n) time
    */
    if (n == 0 ||n == 1)
        return n;
    return fib_rec(n-1) + fib_rec(n-2);
}
// using dynamic programing
int fib(int n){
    // T(n) = T(n-1) + c
    // this function will take O(n) time 
    if (a[n] == -1){
        if (n == 0 || n == 1)
            a[n] = n;
        else
            a[n] = fib(n-1) + fib(n-2);
    }
    return a[n];
}
int main(){
    for (int i = 0; i < 50; i++)
        a[i] = -1;
    cout << "Fibonacchi of 40 th term :" << fib_rec(40) << endl;
    cout << "Fibonacchi of 40 th term :" << fib(40) << endl;
    return 0;
}