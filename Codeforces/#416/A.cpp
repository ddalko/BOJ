#include <cstdio>
#include <iostream>

using namespace std;

long long a[2];

int main()
{
    cin >> a[0] >> a[1];

    int idx = 0;
    int c = 1;

    while(1)
    {   
        if(a[idx%2] < c) break;
        a[idx%2] -= c;
        idx++; c++;
    }
    
    if(idx%2) puts("Valera");
    else puts("Vladik");
    
    return 0;
}