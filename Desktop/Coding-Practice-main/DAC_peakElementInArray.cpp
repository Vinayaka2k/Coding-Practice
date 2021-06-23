#include<bits/stdc++.h>
using namespace std;

int getPeakElement(vector<int>& arr, int n){
    int l = 0;
    int h = n-1;
    while(l<=h){
        int mid = l+(h-l)/2;
        bool greaterThanLeft = true;
        bool greaterThanRight = true;
        if(mid-1 >= 0){
            if(arr[mid] >= arr[mid-1])
                greaterThanLeft = true;
            else
                greaterThanLeft = false;
        }
        if(mid+1 < n){
            if(arr[mid] >= arr[mid+1])
                greaterThanRight = true;
            else
                greaterThanRight = false;
        }
        if(greaterThanLeft && greaterThanRight)
            return mid;
        else if(!greaterThanRight)
            l = mid+1;
        else
            h = mid-1;
    }
}

int main(){
    vector<int> arr = {1,3,20,4,1,0};
    int n = arr.size();
    cout << getPeakElement(arr, n);
}