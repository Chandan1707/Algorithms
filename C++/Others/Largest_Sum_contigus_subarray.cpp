#include <iostream>
using namespace std;
int largest_sum_contigus_subarray(int arr[], int n){
    int max_so_far = 0;
    int max_ending_hare = 0;
    for (int i = 0; i < n; i ++){
        max_so_far = max_so_far + arr[i];
        if (max_so_far < 0)
            max_so_far = 0;
        if (max_ending_hare < max_so_far)
            max_ending_hare = max_so_far;
    }
    return max_ending_hare;
}
int main(){
    int arr[] = {-2, -3, 4, -1, -2, 5, 1, -3};
    cout << "largest sum contigus subarray :" << largest_sum_contigus_subarray(arr, 8) << endl;
    return 0;
}