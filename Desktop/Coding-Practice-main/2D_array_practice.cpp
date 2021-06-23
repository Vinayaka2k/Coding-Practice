#include<bits/stdc++.h>
using namespace std;

int main(){
    int m = 3; int n = 4;
    int** arr = (int**)malloc(sizeof(int*) * m);
    for(int i=0; i<m; ++i)
        arr[i] = (int*)malloc(sizeof(int)* n);

    for(int i=0; i<m; ++i)
        for(int j=0; j<n; ++i)
            arr[i][j] = j;
    
    for(int i=0; i<m; ++i)
    {
        for(int j=0; j<n; ++i)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    
    
}