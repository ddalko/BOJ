#include <string>
#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    string buf;
    int word = 0;
    while(cin >> buf)
    {
        if(buf == "<br>") {
            printf("\n");
            word = 0;
        }
        else if(buf == "<hr>"){
            if(word != 0) printf("\n");
            puts("--------------------------------------------------------------------------------");
            word = 0;
        }else {
            if(word + (int)buf.size() + (word == 0) ? 0 : 1> 80) {
                cout << "\n" << buf << " ";
                word = (int)buf.size();
            }else{
                cout << buf << " "; 
                word += (int)buf.size();
            }
        }
    }
}