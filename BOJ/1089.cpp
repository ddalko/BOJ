#include <cstdio>
#include <vector>

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
const int DEC[11] = {1, 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};

int n;
char input[5][41];
char parse[10][5][3];

int main()
{
    scanf("%d",&n);
    for(int i = 0; i < 5; ++i) scanf("%s",input[i]);
    
    //pre-processing
    for(int k = 0; k < n; ++k){
        int c = 4 * k;
        for(int i = 0; i < 5; ++i){
            for(int j = 0; j < 3; ++j){
                parse[k][i][j] = input[i][c+j];
            }
        }
    }

    vector<int> cand[10];
    for(int k = 0; k < n; ++k){
        for(int N = 0; N < 10; ++N){
            bool flag = false;
            for(int i = 0; i < 5; ++i){
                for(int j = 0; j < 3; ++j){ 
                    if(parse[k][i][j] == '#' && number[N][i][j] == '.') flag = true;
                }
            }
            if(!flag) {
                cand[k].push_back(N);   
            }
        }
    }

    //Cal
    vector<int> sum(n, 0);
    for(int i=n-1; i>=0; --i){
        int size = cand[i].size();
        if(size < 1) return puts("-1"), 0;
        for(int j=0; j<size; ++j) sum[i] += cand[i][j];
    }
    
    double ret = 0;
    for(int i=0; i<n; ++i){
        ret += (DEC[n-i]*sum[i]+1e-15)/cand[i].size();
    }
    printf("%.10lf", ret);
}