#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int threeElementMaximum(int first, int second, int third){
        return max(max(first, second), third);
    }
    
    int sumCrossingMiddle(vector<int>& arr, int l, int m, int r){
        int sum=0; int leftMaxSum=INT_MIN; int rightMaxSum = INT_MIN;
        for(int i=m; i>=0; --i){
            sum += arr[i];
            if(sum>leftMaxSum)
                leftMaxSum = sum;
        } 
        sum=0;
        for(int i=m+1; i<=r; ++i){
            sum += arr[i];
            if(sum>rightMaxSum)
                rightMaxSum = sum;
        }
        return threeElementMaximum(leftMaxSum, rightMaxSum, leftMaxSum+rightMaxSum);
    }
    
    int MSS(vector<int>& arr, int l, int r){
        if(l == r)
            return arr[l];
        
        if(l+1 == r)
            return threeElementMaximum(arr[l], arr[r], arr[l]+arr[r]);
        
        int m = l+(r-l)/2;
        return threeElementMaximum(
                   MSS(arr, l, m), 
                   MSS(arr, m+1, r), 
                   sumCrossingMiddle(arr, l, m, r)
        );
    }
    
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        return MSS(nums, 0, n-1);
    }
};