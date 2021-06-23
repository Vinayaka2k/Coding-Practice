// Subarray Product Less Than K
// https://leetcode.com/problems/subarray-product-less-than-k/

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int end, prod, cnt=0, n = nums.size();
        for(int st=0; st<n; ++st){
            end = st;
            prod = nums[st];
            while(end<n && prod<k){
                ++cnt; ++end;
                if(end<n)
                    prod *= nums[end];
            }
        }
        return cnt;
    }
};


class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1)
            return 0;
        int n = nums.size();
        int left =0, right =0;
        int cnt=0;
        int prod=1;
        while(right<n){
            prod*=nums[right];
            while(prod>=k){
                prod /= nums[left];
                ++left;
            }
            cnt += (right-left)+1;
            right++;
        }
        return cnt;
    }
};
