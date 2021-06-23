// Permutation in String
// https://leetcode.com/problems/permutation-in-string/

class Solution {
public:
    bool checkMatch(int* arr, int* freq){
        for(int i=0; i<26; ++i){
            if(arr[i] != freq[i])
                return false;
        }
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        int n1=s1.length(); int n2=s2.length();
        int* arr = new int[26];
        int* freq = new int[26];
        
        if(n1>n2)
            return false;
        
        for(int i=0; i<n1; ++i){
            freq[s1[i]-'a']++;
        }
        for(int i=0; i<n1; ++i){
            arr[s2[i]-'a']++;
        }
        if(checkMatch(arr, freq))   return true;
        for(int i=n1; i<n2; ++i){
            arr[s2[i]-'a']++;
            arr[s2[i-n1]-'a']--;
            if(checkMatch(arr, freq))   return true;
        }
    return false;
    }
};