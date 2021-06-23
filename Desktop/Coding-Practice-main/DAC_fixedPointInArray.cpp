#include<bits/stdc++.h>
using namespace std;

int fixedPoint(vector<int>& arr, int n){
    int l=0; int h=n-1;
    while(l <= h){
        int mid = l+(h-l)/2;
        if(arr[mid] == mid)
            return mid;
        else if(arr[mid] < mid)
            l = mid+1;
        else
            h = mid-1;
    }
    return -1;
}

int main(){
    vector<int> arr = {-10, -5, 3, 4, 7, 9};
    int n = arr.size();
    cout << fixedPoint(arr, n);
}