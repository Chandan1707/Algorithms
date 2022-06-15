#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

void heapify(int*,int i,int);
void heap_sort(int*,int);
void getdata(int *,int);
void display(int*,int);
void swap(int*, int*);

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int a[],int i,int n){
	int index = 2 * i + 1;
    int temp;
    int flag = 1;

    while (index <= n-1 && flag) {
        if (index < n-1 && a[index] < a[index + 1]) {
            index += 1;
        }
        if (a[i] < a[index]){
            swap(&a[i], &a[index]);
        }
        else {
            flag = 0;
        }
        i = index;
        index = 2 * index + 1;
    }
}

void heap_sort(int a[],int n){
	int i;
    for (i = n/2 - 1; i >= 0; i --){
        heapify(a, i, n);
    }
	for (i = n-1; i > 0; i --){
        swap(&a[0], &a[i]);
        heapify(a, 0, i);
    }
}

void getdata(int a[],int n){
	int i;
    printf("\nEnter %d Integer : \n", n);
    for (i = 0; i < n; i++)
        scanf("%d",&a[i]);
}
void display(int a[],int n){
    int i;
	printf("\nValues are : ");
    for (i = 0; i < n; i ++){
        printf("%d  ", a[i]);
    }
    printf("\n");
}
int main(){
    int i, n, *a;
	printf("Enter array size :");
	scanf("%d",&n);
    a = (int*)malloc(n * sizeof(int));

    getdata(a, n);

    printf ("Before Sort :");
    display(a, n);

	heap_sort(a,n);

    printf("\nAfter sort :");
    display(a, n);
    return 0;
}