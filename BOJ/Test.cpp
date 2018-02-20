<<<<<<< HEAD
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string data = "BNeweYork";
	
	transform(data.begin(), data.end(), data.begin(), ::tolower);

	cout << data << endl;
}
=======
#include <cstdio>

const char *number[10][5] = {
    {"###", "#.#", "#.#", "#.#", "###"},
    {"..#", "..#", "..#", "..#", "..#"},
    {"###", "..#", "###", "#..", "###"},
    {"###", "..#", "###", "..#", "###"},
    {"#.#", "#.#", "###", "..#", "..#"},
    {"###", "#..", "###", "..#", "###"},
    {"###", "#..", "###", "#.#", "###"},
    {"###", "..#", "..#", "..#", "..#"},
    {"###", "#.#", "###", "#.#", "###"},
    {"###", "#.#", "###", "..#", "###"}
};

int n;
char input[5][36];
char parse[10][5][3];

int main()
{
    scanf("%d",&n);
    for(int i = 0; i < 5; ++i) scanf("%s",input[i]);

    for(int k = 0; k < n; ++k){
        int c = 4 * k;
        for(int i = 0; i < 5; ++i){
            for(int j = 0; j < 3; ++j){
                parse[k][i][j] = input[i][c+j];
            }
        }
    }

    for(int n = 0; n < 10; ++n){
        bool flag = false;
        
        for(int i = 0; i < 5; ++i){
            for(int j = 0; j < 3; ++j){
                if(parse[0][i][j] == '#' && number[n][i][j] == '.') flag = true;
            }
        }
        
        if(flag) printf("%d Un Matched!\n", n);
        else printf("%d Matched!\n", n);
    }
}
>>>>>>> 411b3482630c7ac6490c4f4cb353062fa94a3432
