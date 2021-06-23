#include<bits/stdc++.h>
using namespace std;

int getClosest(int x, int y, int target){
    int diff_x, diff_y;
    if(x>target)
        diff_x = x-target;
    else
        diff_x = target-x;

    if(y>target)
        diff_y = y-target;
    else
        diff_y = target-y;

    if(diff_x > diff_y)
        return y;
    return x;
}

int closestNumber(vector<int>& arr, int l, int h, int target){
    if(l == h)
        return arr[l];
    if(l+1 == h)
        return getClosest(arr[l], arr[h], target);
    int mid = l+(h-l)/2;
    if(arr[mid] == target)
        return mid;
    else if(arr[mid] > target)
        return closestNumber(arr, l, mid, target);
    else 
        return closestNumber(arr, mid, h, target); 
}

int main(){
    vector<int> arr = {1,2,4,5,6,6,8,9};
    int target = 11;
    int n = arr.size();
    cout << closestNumber(arr, 0, n-1, target);
}