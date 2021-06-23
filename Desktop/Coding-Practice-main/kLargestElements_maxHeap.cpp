#include<bits/stdc++.h>
using namespace std;

void swap(int* x, int* y){
    int t=*x;
    *x = *y;
    *y = t;
}

void maxHeapify(int* arr, int i, int n){
    int left = 2*i+1;
    int right = 2*i+2;
    int largest = i;

    if(left<n && arr[left]>arr[largest])
        largest = left;
    if(right<n && arr[right]>arr[largest])
        largest = right;
    if(largest != i)
    {
        swap(&arr[i], &arr[largest]);
        maxHeapify(arr, largest, n);
    }
}

int extractMax(int* arr, int n){
    int root = arr[0];
    swap(&arr[0], &arr[n]);
    maxHeapify(arr, 0, n);
    return root;
}

void buildHeap(int* arr, int n){
    for(int i=n/2-1; i>=0; --i)
        maxHeapify(arr, i, n);
}

void printArray(int* arr, int n){
    for(int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

void kLargest(int* arr, int n, int k){
    int arr_size = n;
    buildHeap(arr, n);
    cout << "After buildHeap :  ";
    printArray(arr, n);
    for(int i=0; i<k; ++i){
        --n;
        int root = extractMax(arr, n);
        cout << root << endl;
        cout << "i = " << i << "    : " ;
        printArray(arr, arr_size);
    }
}

int main(){
    int n = 7;
    int k = 3;
    int arr[] = {1, 23, 12, 9, 30, 2, 50};
    kLargest(arr, n, k);
}