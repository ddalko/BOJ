#include <cstdio>

int n;
int a[50][50];

int main()
{
    scanf("%d",&n);
    for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) scanf("%d", &a[i][j]);

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(a[i][j] != 1){
                bool flag = false;
                for(int row = 0; row < n; ++row){
                    if(row == i) continue;
                    int x = a[row][j];

                    for(int col = 0; col < n; ++col){
                        if(col == j) continue;
                        int y = a[i][col];
                        if(a[i][j] == x + y) {
                            flag = true;
                            break;
                        }
                    }
                    if(flag) break;
                }
                
                if(!flag){
                    puts("No");
                    return 0;
                }
            }
        }
    }
    puts("Yes");
    return 0;
}