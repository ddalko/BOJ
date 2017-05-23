#include <cstdio>

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};

int n;
int posx, posy;
pair<int,int> p[100005][5];
int dp[100005][5];

int main()
{
    scanf("%d",&n);
    scanf("%d %d",&posx,&posy);
    
    for(int i = 0; i < n; ++i){
        int a, b;
        scanf("%d %d",&a,&b);
        p[i][0].first = a;
        p[i][0].second = b;

        for(int i = 0; i < 4; ++i){
            int nx = a + dx[i];
            int ny = b + dy[i];
            p[i][i+1].first = nx;
            p[i][i+1].second = ny;
        }


    }
}