// mergeIntervals
// https://leetcode.com/problems/merge-intervals/

class Solution {
public:
    static bool comparatorFunc(const vector<int>& v1, const vector<int>& v2){
        return v1[0]<v2[0];
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comparatorFunc);
        vector<int> interval(2);
        int i=1;
        vector<vector<int>> res;
        int n = intervals.size();
        interval = intervals[0]; 
        while(i<n){
            if(interval[1] >= intervals[i][0]){
                if(interval[1] < intervals[i][1])
                    interval[1] = intervals[i][1];
            }
            else{
                res.push_back(interval);
                interval = intervals[i];
            }    
            ++i;
        }
        res.push_back(interval);
        return res;
    }
};