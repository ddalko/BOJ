#include <iostream>

using namespace std;

struct student{
    int y;
    int m;
    int d;
    string name;

    bool operator < (const student rhs) const
    {
        if (y != rhs.y) return y > rhs.y;
        if (m != rhs.m) return m > rhs.m;
        return d > rhs.d;
    }
};

int n;

int main()
{
    student Max; student Min;
    Min.y = 0; Min.m = 0; Min.d = 0;
    Max.y = 9999; Max.m = 12; Max.d = 31;
    
    cin >> n;
    while(n--){
        student tmp;
        cin >> tmp.name >> tmp.d >> tmp.m >> tmp.y;

        if(Max < tmp){
            Max.name = tmp.name;
            Max.y = tmp.y;
            Max.m = tmp.m;
            Max.d = tmp.d;
        }

        if(tmp < Min){
            Min.name = tmp.name;
            Min.y = tmp.y;
            Min.m = tmp.m;
            Min.d = tmp.d;
        }
    }
    cout << Min.name << '\n' << Max.name;
}