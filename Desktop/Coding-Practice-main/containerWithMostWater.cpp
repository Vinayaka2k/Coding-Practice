// Container With Most Water
// https://leetcode.com/problems/container-with-most-water/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int area; int max_area = INT_MIN;
        int i=0, j=n-1;
        while(i<j){
            area = min(height[i], height[j]) * (j-i);
            if(area > max_area)
                max_area = area;
            if(height[i] < height[j])
                i++;
            else
                j--;
        }
        return max_area;
    }
};