#include <bits/stdc++.h>

using namespace std;

int n, m;
int board[100][100];

int chkr()
{
    for(int i = 0; i < n; ++i){
        int rc = 0;
        for(int j = 0; j < m; ++j){
            if(board[i][j]) rc++;
        }
        if(rc == m) return i;
    }
    return -1;
}

int chkc()
{
    for(int i = 0; i < m; ++i){
        int rc = 0;
        for(int j = 0; j < n; ++j){
            if(board[j][i]) rc++;
        }
        if(rc == n) return i;
    }
    return -1;
}

int main()
{
    scanf("%d %d",&n,&m);
    for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) scanf("%d",&board[i][j]);

    vector<pair<char, int> > ans;

    while(1)
    {
        int r = chkr();

        if(r == -1) {
            break;
        }else {
            for(int i = 0; i < m; ++i) board[r][i]--;
            ans.push_back(make_pair('r', r+1));
        }
        
    }   

    while(1)
    {
        int c = chkc();
        
        if(c == -1){
            break;
        }else {
            for(int i = 0; i < n; ++i) board[i][c]--;
            ans.push_back(make_pair('c', c+1));
        }
    }

    if(ans.size()){
        printf("%d\n", (int)ans.size());
        for(int i = 0; i < (int)ans.size(); ++i){
            if(ans[i].first == 'r') printf("row %d\n",ans[i].second);
            else if(ans[i].first == 'c') printf("col %d\n",ans[i].second);
        }
    }else{
        puts("-1");
    }
    
    return 0;
}