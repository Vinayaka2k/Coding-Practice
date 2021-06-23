
#include <bits/stdc++.h>

using namespace std;

void printArray(vector<int>& res){
    int n = res.size();
    for(int i=0; i<n; ++i)
        cout << res[i] << " ";
    cout << endl;
}

int main()
{
   string res;
   string a = "abcdefg";
   string b = "zxy";
   int k=0;
   int m = a.length(); int n = b.length();
   int i=0; int j=0;
   
   while(i<m && j<n){
       res.push_back(a[i]);
       res.push_back(b[j]);
       ++i; ++j;
   }
   while(i<m){
       res.push_back(a[i]);
       ++i;
   }
   while(j<n){
       res.push_back(b[j]);
       ++j;
   }
   cout << res << endl;
}
