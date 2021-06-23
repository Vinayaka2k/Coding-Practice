class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        vector<int> res;
        unordered_map<int,int> m;
        int n = nums2.size();
        for(int i=0; i<n; ++i){
            while(!s.empty() && nums2[i]>s.top()){
                m[s.top()] = nums2[i];
                s.pop();
            }
            s.push(nums2[i]);
        }
        
    while(!s.empty()){
        m[s.top()] = -1;
        s.pop();
        }
        
    for(int i=0; i<nums1.size(); ++i){
        res.push_back(m[nums1[i]]);
        }
    return res;
    }
};