#include <iostream>
using namespace std;
template < class T1,class T2>
class Node{
    public:
        T1 info;
        T2 others;
};

template <class d_type>
void heapify(d_type arr[],int i, int n){
    
    int index = 2 * i + 1;
    bool flag = true;
    while (index <= n-1 && flag){
        if (index < n-1 && arr[index].info < arr[index + 1].info){
            index = index + 1;
        }
        if (arr[index].info > arr[i].info){
            swap(arr[index], arr[i]);
        }
        else 
            flag = false;
    }
}

template <class Type>
void Heap_Sort(Type arr[], int n){
    for (int i = (n/2 - 1); i >= 0; i --){
        heapify<Type>(arr, i, n);
    }
    for (int i = n-1; i > 0; i--){
        swap(arr[0], arr[i]);
        heapify<Type>(arr, 0, i);
    }
}

template <class Type>
void show(Type arr[], int n){
    for (int i = 0; i < n; i++){
        cout << "a[" << i << "].info = " << arr[i].info << endl;
        cout << "a[" << i << "].other = " << arr[i].others << endl;
        cout << endl;
    }
    cout << endl;
}

int main(){
    // Node <float, float>arr[5];
    int n = 5;
    Node <float, float>*arr = new Node<float, float>[n];
    arr[0].info = 90.2;
    arr[0].others = 9.5;

    arr[1].info = 70.4;
    arr[1].others = 7.5;

    arr[2].info = 20.6;
    arr[2].others = 2.5;

    arr[3].info = 30.1;
    arr[3].others = 3.5;

    arr[4].info = 80.7;
    arr[4].others = 8.5;

    Heap_Sort<Node<float,float>>(arr, n);
    show<Node<float,float>>(arr, n);
    return 0;
}