#include<iostream>
using namespace std;

void insertion_sort(int arr[], int n){

	int a, j;
	for (int i = 0; i < n-1; i++){
		a = arr[i + 1];
		for (j = i + 1; j > 0 && a < arr[j-1]; j--){
			arr[j] = arr[j-1];
		}
		if (j <= i)
			arr[j] = a;

	}
}
void print(int arr[], int n){
        for (int i = 0; i < n; i++)
                cout << arr[i] << " ";
        cout << endl;
}

int main(){
        int n;
        cout << "Enter array size :";
        cin >> n;
        int *arr = (int *)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++){
                cout << "Enter Integer Element : ";
                cin >> arr[i];
        }
        cout << endl << "Before Sort :" << endl;
        print(arr, n);
        insertion_sort(arr, n);
        cout << "After Insertion sort : " << endl;
        print(arr, n);
        return 0;
}

