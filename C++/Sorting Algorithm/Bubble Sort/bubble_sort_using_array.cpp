#include<iostream>
using namespace std;

void bubble_sort(int arr[], int n){
	bool flag = true;
	for (int i = 0; i < n-1 && flag; i++){
		flag = false;
		for(int j = 0; j < n-1-i; j++){
			if (arr[j] > arr[j+1]){
				swap(arr[j], arr[j+1]);
				flag = true;
			}
		}
	}
}
void print(int arr[], int n){
	for (int i = 0; i < n; i ++)
		cout << arr[i] << " ";
	cout << endl;
}

int main(){
	int n;
	cout<< "Enter size of array :" ;
	cin >> n;
	int *arr = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i ++){
		cout << "Enter array element :" ;
		cin >> arr[i];
	}
	cout << "Before Sort :" ;
	print(arr, n);
	cout << "After sort :" ;
	bubble_sort(arr,n);
	print(arr, n);
}
