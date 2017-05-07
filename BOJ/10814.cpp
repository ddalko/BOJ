#include <bits/stdc++.h>

using namespace std;

struct M{
    int idx;
    int age;
    char name[105];

    bool operator < (const M rhs) const
    {
        if(age == rhs.age) return idx < rhs.idx;
        return age < rhs.age;
    }
};

int n;
M member[100005];

int main()
{
    scanf("%d",&n);
    for(int i = 0; i < n; ++i){
        member[i].idx = i;
        scanf("%d %s", &member[i].age, &member[i].name);
    }
    sort(member, member+n);
    for(int i = 0; i < n; ++i){
        printf("%d %s\n",member[i].age,member[i].name);
    }
}