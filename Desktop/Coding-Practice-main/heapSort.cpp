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

void buildHeap(int* arr, int n){
    for(int i=n/2-1; i>=0; --i)
        maxHeapify(arr, i, n);
}


void printArray(int* arr, int n){
    for(int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

void heapSort(int* arr, int n){
    buildHeap(arr, n);
    cout << "After buildHeap :  ";
    printArray(arr, n);
    for(int i=n-1; i>0; --i){
        swap(&arr[0], &arr[i]);
        maxHeapify(arr, 0, i);
        cout << "i = " << i << "    : " ;
        printArray(arr, n);
    }
}

int main(){
    int n = 5;
    int arr[] = {4,10,3,5,1};
    heapSort(arr, n);
}