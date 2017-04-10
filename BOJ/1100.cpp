#include <cstdio>

char board[8][9];

int main()
{
	for(int i = 0; i < 8; ++i) scanf("%s",board[i]);

	int ans = 0;
	for(int i = 0; i < 8; ++i){
		if(i%2){
			for(int j = 1; j < 8; j+=2) if(board[i][j] == 'F') ans++;
		}else{
			for(int j = 0; j < 8; j+=2) if(board[i][j] == 'F') ans++;
		}
	}
	printf("%d\n",ans);
}