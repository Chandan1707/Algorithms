#include<iostream>
using namespace std;
void merge(int arr[], int lower_bound, int mid, int upper_bound){

	int *temp_arr = (int*)malloc((upper_bound + 1) * sizeof(int));
	for ( int i = lower_bound; i <= upper_bound; i ++){
		temp_arr[i] = arr[i];
	}
	int i = lower_bound;
	int j = mid + 1;
	int k = lower_bound;

	while (i <= mid and j <= upper_bound){
		if (temp_arr[i] < temp_arr[j])
			arr[k++] = temp_arr[i++];
		else 
			arr[k++] = temp_arr[j++];	
	}	
	while (i <= mid)
		arr[k++] = temp_arr[i++];
	while (j <= upper_bound)
		arr[k++] = temp_arr[j++];

	free(temp_arr);
}
void merge_sort(int arr[], int lower_bound, int upper_bound){
	if (lower_bound < upper_bound){
		int mid = (lower_bound + upper_bound) / 2;
		merge_sort(arr, lower_bound, mid);
		merge_sort(arr, mid + 1, upper_bound);
		merge(arr, lower_bound, mid, upper_bound);
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
	merge_sort(arr, 0, n-1);
	cout << "After sort : " << endl;
	print(arr, n);
	return 0;
}
