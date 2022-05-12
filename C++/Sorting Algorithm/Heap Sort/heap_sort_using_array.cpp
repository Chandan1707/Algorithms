#include<iostream>
using namespace std;

void heapify(int arr[], int index, int n){
    int i = 2 * index + 1;
    bool flag = true;
    while (i <= n-1 and flag){
        if (i < n-1 and arr[i] < arr[i + 1])
            i ++;
        if (arr[index] < arr[i])
            swap(arr[i], arr[index]);
        else
            flag = false;

        index = i;
        i = 2 * index + 1;
    }
}

void max_heap(int arr[], int n){
    for (int i = (n/2 - 1); i >= 0; i --)
        heapify(arr, i, n);
    
}

void heap_sort(int arr[], int n){
    max_heap(arr, n);
    while (n > 1){
        swap(arr[0], arr[n-1]);
        n -= 1;
        heapify(arr, 0, n);
    }
}

void print(int arr[], int n){
    for (int i = 0; i < n; i ++)
        cout << arr[i] << " ";
    cout << endl;
}

int main(){
    int *arr;
    int n;
    cout << "Enter array size :";
    cin >> n;
    arr = (int *)malloc(n * sizeof(int));
    for(int i = 0; i < n; i ++){
        cout << "Enter an Integer Element :";
        cin >> arr[i];
    }
    cout << endl << "Before Sort :" << endl;
    print(arr, n);
    cout << endl << "After sort :" << endl;
    heap_sort(arr, n);
    print(arr, n);
}