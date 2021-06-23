class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> map;
        int index;
        int max_length = 0;
        int n = s.length();
        if(n == 0)
            return 0;
        
        for(int left=0, right=0; right<n; ++right){
            if(map.find(s[right]) != map.end()){
                index = (map.find(s[right])->second)+1;
                if(index>left)
                    left=index;
                //left = max((map.find(s[right])->second)+1, left);
            }
            map[s[right]] =  right;
            max_length = max(max_length, right-left+1);
        }
    // for(auto it=map.begin(); it!=map.end(); ++it)
    //     cout << it->first << " " << it->second;
    return max_length;
    }
};