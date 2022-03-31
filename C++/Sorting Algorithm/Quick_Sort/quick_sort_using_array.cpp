#include<iostream>
using namespace std;

int partition(int arr[], int lower_bound, int upper_bound){
	
	int mid = (lower_bound + upper_bound) / 2;
	int pivot = arr[mid];
	int i = lower_bound;
	int j = upper_bound;

	swap(arr[mid], arr[lower_bound]);

	while (i < j){
		while (arr[i] <= pivot)
			i ++;
		while (arr[j] > pivot)
			j --;
	if (i < j)
		swap(arr[i], arr[j]);
	}
	swap(arr[lower_bound], arr[j]);
	return j;
}

void quick_sort(int arr[], int lower_bound, int upper_bound){
	if (lower_bound < upper_bound){
		int p = partition(arr, lower_bound, upper_bound);
		quick_sort(arr, lower_bound, p);
		quick_sort(arr, p + 1, upper_bound);
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
		cout << "Enter Element : ";
		cin >> arr[i];
	}
	cout << endl << "Before Sort :" << endl;
	print(arr, n);
	quick_sort(arr, 0, n-1);
	cout << "After sort : " << endl;
	print(arr, n);
	return 0;
}
