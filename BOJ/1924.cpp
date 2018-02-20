#include <cstdio>

const char D[7][4] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

int main()
{
	int x, y;
	int i, j;
	scanf("%d %d",&x,&y);

	int k = 1;
	for(i = 1; i <= 12; ++i){		
		if(i==1||i==3||i==5||i==7||i==8||i==10||i==12){
			for(j = 1; j <= 31; ++j){
				if(i==x && j==y) {
					printf("%s\n",D[k%7]);
					return 0;
				}
				k++;
			}
		}else if(i==4||i==6||i==9||i==11){
			for(j = 1; j <= 30; ++j){
				if(i==x && j==y) {
					printf("%s\n",D[k%7]);
					return 0;
				}
				k++;
			}
		}else{
			for(j = 1; j <= 28; ++j){
				if(i==x && j==y) {
					printf("%s\n",D[k%7]);
					return 0;
				}
				k++;
			}
		}
	}
}