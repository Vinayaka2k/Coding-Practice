class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left=0, right, sum=0, min_length=INT_MAX, n=nums.size();
        if(n==0)
            return 0;
        for(right=0; right<n; ++right){
            sum += nums[right];
        while(sum >= target){
            min_length = min(min_length, right-left+1);
            sum -= nums[left];
            ++left;
            }
        }
        return min_length == INT_MAX? 0:min_length;
    }
};