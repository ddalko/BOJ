#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int ans;
int board[21][21];

void move(int d)
{
    for(int i = 0; i < n; ++i){
        vector<int> tmp;
        for(int j = 0; j < n; ++j){
            int val = (d < 2) ? board[i][j] : board[j][i];
            if(val) tmp.push_back(val);
        }

        if(d % 2) reverse(tmp.begin(), tmp.end());

        vector<int> perm;
        for(int j = 0; j < (int)tmp.size(); ++j){
            if(j+1 < (int)tmp.size() && tmp[j] == tmp[j+1]){
                perm.push_back(tmp[j]*2);
                j++;
            }else perm.push_back(tmp[j]);
        }
        for(int j = (int)perm.size(); j < n; ++j) perm.push_back(0);

        if(d % 2) reverse(perm.begin(), perm.end());

        for(int j = 0; j < (int)perm.size(); ++j){
            if(d < 2) board[i][j] = perm[j];
            else board[j][i] = perm[j];
        }
    }
}

void search(int step)
{
    if(step == 5){
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                ans = max(ans, board[i][j]);
            }
        }
        return ;
    }

    int ret = 0;
    int temp[20][20];
    for(int d = 0; d < 4; ++d){    
        for(int j = 0; j < n; ++j) for(int k = 0; k < n; ++k) temp[j][k] = board[j][k];
        move(d);
        search(step+1);
        for(int j = 0; j < n; ++j) for(int k = 0; k < n; ++k) board[j][k] = temp[j][k];
    }
}

int main()
{
    ans = -1e9;
    cin >> n;
    for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) cin >> board[i][j];

    search(0);
    printf("%d\n",ans);
}