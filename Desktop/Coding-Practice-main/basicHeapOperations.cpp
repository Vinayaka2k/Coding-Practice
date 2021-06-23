#include<bits/stdc++.h>
using namespace std;

void swap(int *x, int *y){
    int t = *x;
    *x = *y;
    *y = t;
}

class MinHeap{
    int heap_size;
    int capacity;
    int* harr;
    public :
        MinHeap(int c);
        void insertElement(int ele);
        int parent(int i);
        int getMin();
        int extractMin();
        void decreaseKey(int i, int val);
        void minHeapify(int i);
        int leftChild(int i);
        int rightChild(int i);
        void deleteKey(int i);
};

MinHeap :: MinHeap(int c){
    heap_size = 0;
    capacity = c;
    harr = (int*)malloc(sizeof(int) * capacity);
}

int MinHeap :: parent(int i){
    return (i-1)/2;
}

int MinHeap :: leftChild(int i){
    return 2*i+1;
}

int MinHeap :: rightChild(int i){
    return 2*i+2;
}

void MinHeap :: insertElement(int ele){
    if(heap_size>capacity)
        return;

    harr[heap_size] = ele;
    int i = heap_size;
    heap_size++;

    while(i!=0 && harr[parent(i)] > harr[i]){
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
}

int MinHeap :: getMin(){
    if(heap_size == 0)
        return -1;
    return harr[0];
}

void MinHeap :: decreaseKey(int i, int val){
    harr[i] = val;
    while(i!=0 && harr[parent(i)] > harr[i]){
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
}

void MinHeap :: minHeapify(int i){
    int left = leftChild(i);
    int right = rightChild(i);
    int smallest = i;
    if(left < heap_size && harr[left] < harr[smallest])
        smallest = left;
    if(right < heap_size && harr[right] < harr[smallest])
        smallest = right;
    if(smallest != i){
        swap(&harr[i], &harr[smallest]);
        minHeapify(smallest);
    }
}

int MinHeap :: extractMin(){
    int root = harr[0];
    swap(&harr[0] , &harr[heap_size-1]);
    heap_size--;
    minHeapify(0);
    return root;
}

void MinHeap :: deleteKey(int i){
    decreaseKey(i, INT_MIN);
    extractMin();
}


int main(){
    MinHeap m(11);
    m.insertElement(3);
    m.insertElement(2);
    m.insertElement(1);
    m.insertElement(15);
    m.insertElement(5);
    m.insertElement(4);
    m.insertElement(45);

    cout << m.extractMin();
    cout << m.getMin();

    m.decreaseKey(2, 1);

    cout << m.getMin();
}