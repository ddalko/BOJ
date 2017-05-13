#include <cstdio>

int r, c, zr, zc;
char o[55][55];
char scan[255][255];

int main()
{
    scanf("%d %d %d %d",&r,&c,&zr,&zc);

    for(int i = 0; i < r; ++i){
        scanf("%s",o[i]);
        for(int j = 0; j < c; ++j){
            for(int k = i*zr; k < i*zr + zr; ++k){
                for(int l = j*zc; l < j*zc + zc; ++l){
                    scan[k][l] = o[i][j];
                }
            }
        }
    }

    for(int i = 0; i < r * zr; ++i) printf("%s\n",scan[i]);
}