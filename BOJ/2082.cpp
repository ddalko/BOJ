#include <bits/stdc++.h>

using namespace std;

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

string input[5];
char parse[4][5][3];

int main()
{
    for(int i = 0; i < 5; ++i) getline(cin, input[i]);
    
    for(int k = 0; k < 4; ++k){
        int c = 4 * k;
        for(int i = 0; i < 5; ++i){
            for(int j = 0; j < 3; ++j){
                parse[k][i][j] = input[i][c+j];
            }
        }
    }

    int M[4] = {2, 9, 5, 9};
    for(int k = 0; k < 4; ++k){
        for(int N = 0; N <= M[k]; ++N){

            bool flag = false;
            for(int i = 0; i < 5; ++i){
                for(int j = 0; j < 3; ++j){ 
                    if(parse[k][i][j] == '#' && number[N][i][j] == '.') flag = true;
                }
            }
            if(!flag){
                printf("%d",N);
                break;
            }
        }
        if(k == 1) printf(":");
    }
}