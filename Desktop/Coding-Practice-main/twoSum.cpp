// Two Sum
// https://leetcode.com/problems/two-sum/submissions/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        vector<int> res;
        for(int i=0; i<nums.size(); ++i){
            auto it = m.find(nums[i]);
            if(it != m.end()){
               res.push_back(it->second);
                res.push_back(i);
            }
            m.insert({target-nums[i], i});
        }
        return res;
    }
};