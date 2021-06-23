#include<bits/stdc++.h>
using namespace std;

void swap(int* x, int* y){
    int t=*x;
    *x = *y;
    *y = t;
}

void minHeapify(int*harr, int i, int n){
    int left = 2*i+1;
    int right = 2*i+2;
    int smallest = i;
    if(left < n && harr[left] < harr[smallest])
        smallest = left;
    if(right < n && harr[right] < harr[smallest])
        smallest = right;
    if(smallest != i){
        swap(&harr[i], &harr[smallest]);
        minHeapify(harr, smallest, n);
    }
}

int extractMin(int* arr, int n){
    int root = arr[0];
    swap(&arr[0], &arr[n]);
    minHeapify(arr, 0, n);
    return root;
}

void buildHeap(int* arr, int n){
    for(int i=n/2-1; i>=0; --i)
        minHeapify(arr, i, n);
}

void printArray(int* arr, int n){
    for(int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

int kthSmallest(int* arr, int n, int k){
    int arr_size = n;
    int root;
    buildHeap(arr, n);
    cout << "After buildHeap :  ";
    printArray(arr, n);
    for(int i=0; i<k; ++i){
        --n;
        root = extractMin(arr, n);
        cout << "i = " << i << "    : " ;
        printArray(arr, arr_size);
    }
    return root;
}

int main(){
    int n = 7;
    int k = 4;
    int arr[] = {1, 23, 12, 9, 30, 2, 50};
    cout << kthSmallest(arr, n, k);
}