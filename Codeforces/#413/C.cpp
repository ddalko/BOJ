#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int n;
int money, dia;
pii D[100005];
pii C[100005];

int main()
{
    cin >> n >> money >> dia;
    int cIdx = 0; int dIdx = 0;

    for(int i = 0; i < n; ++i){
        int a, b; char c;
        cin >> a >> b >> c;

        if(c == 'C'){
            C[cIdx].first = a;
            C[cIdx].second = b;
            cIdx++;
        }
        else if(c == 'D'){
            D[dIdx]
        }
    }
    sort(f, f+n);

    int ans = 0; int cnt = 0;
    for(int i = 0; i < n; ++i){
        if(cnt == 2) break;

        if(f[i].type == 'C'){
            if(money >= f[i].c){
                ans += f[i].beauty;
                money -= f[i].c;
                cnt++;
            }
        }else if(f[i].type == 'D'){
            if(dia >= f[i].c){
                ans += f[i].beauty;
                dia -= f[i].c;
                cnt++;
            }
        }
    }
    if(cnt == 2) printf("%d\n",ans);
    else puts("0");
}