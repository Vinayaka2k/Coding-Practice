#include<bits/stdc++.h>
using namespace std;

int findMedian(vector<int>& arr, int l, int h){
    int mid = l+(h-l)/2;
    //cout << " mid : " << mid;
    if((h-l) % 2 == 0){
        return arr[mid];
    }
    else{
       return (arr[mid] + arr[mid+1]) / 2;
    }
}

int getMedian(vector<int>& arr1, vector<int>& arr2, int l1, int h1, int l2, int h2){
    //cout << l1 << "," << h1 << " " << l2 << "," << h2;
    // if(l1 == h1)
    //     return (arr1[l1] + arr2[l2]) / 2;
    if(l1+1 == h1){
        // cout << l1 << "," << h1 << " " << l2 << "," << h2 << endl;
        // cout << arr1[l1] << "," << arr1[h1] << " " << arr2[l2] << "," << arr2[h2] << endl;
        return (max(arr1[l1], arr2[l2]) + min(arr1[h1], arr2[h2])) / 2;
        }
    int mid1 = l1+(h1-l1)/2;
    int mid2 = l2+(h2-l2)/2;

    int m1 = findMedian(arr1, l1, h1);
    int m2 = findMedian(arr2, l2, h2);
    
    if(m1 == m2)
        return m1;
    else if(m2>m1){
        if((h1-l1) %2 == 0)
            return getMedian(arr1, arr2, mid1, h1, l2, mid2);
        else
            return getMedian(arr1, arr2, mid1, h1, l2, mid2+1);
    }
    else{
        if((h1-l1) %2 == 0)
            return getMedian(arr1, arr2, l1, mid1, mid2, h2);
        else
            return getMedian(arr1, arr2, l1, mid1+1, mid2, h2);
    }
}
int main(){
    vector<int> arr1 = {1,3,24,28,55};
    vector<int> arr2 = {12,32,61,78,90};
    int n = arr1.size();
    cout << getMedian(arr1, arr2, 0, n-1, 0, n-1);
}