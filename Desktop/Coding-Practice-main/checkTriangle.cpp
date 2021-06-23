
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
    int a,b,c;
    vector<int> res;
    vector<int> arr = {1,2,2,5,5,4};
    for(int i=0; i<arr.size()-2; ++i){
        a=arr[i]; b=arr[i+1]; c=arr[i+2];
        if(a+b>c && b+c>a && a+c>b)
            res.push_back(1);
        else
            res.push_back(0);
    }
    printArray(res);
}
