#include<bits/stdc++.h>
using namespace std;
    string common_prefix(string left, string right){
        string res;
        int i=0;
        int n1=left.size(); int n2 = right.size();
        while(i<n1 && i<n2 && left[i] == right[i]){
            res.push_back(left[i]);
            i++;
        }
        return res;
    }
    
    string lcpUtil(vector<string>& strs, int l, int r){
        if(l == r)
            return strs[l];
        int m=l+(r-l)/2;
        string left = lcpUtil(strs, l, m);
        string right = lcpUtil(strs, m+1, r);
        return common_prefix(left, right);
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        return lcpUtil(strs, 0, n-1);    
    }

int main(){
    vector<string> strs = {"geek", "gfg", "goat"};
    cout << longestCommonPrefix(strs);
}