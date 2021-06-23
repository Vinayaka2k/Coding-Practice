#include <bits/stdc++.h>

using namespace std;

long power(int x, int n){
    if(n == 1)
        return x;
    long half = n/2;
    return power(x,half) * power(x,n-half);
}

int main()
{
    cout<<power(2,9);

    return 0;
}