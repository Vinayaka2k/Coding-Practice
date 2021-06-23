// 3 Sum
// https://leetcode.com/problems/3sum/


class Solution {
public:
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort( nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        int target, start, end, sum;
        for(int i=0; i<n; ++i){
            if(i!=0 && nums[i]==nums[i-1])
                continue;
            target = -nums[i];
            start = i+1;
            end = n-1;
            while(start < end){
            sum = nums[start]+nums[end];
            if(sum == target){
                vector<int> v = {nums[start], nums[end], -target};
                res.push_back(v);
                while(start<end && nums[start]==nums[start+1])
                    ++start;
                while(start<end && nums[end]==nums[end-1])
                    --end;
                ++start; --end;
            }
            else if(sum < target)
                start++;
            else
                end--;
            }
        }
        return res;
    }
};