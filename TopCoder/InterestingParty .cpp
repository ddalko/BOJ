#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class InterestingParty
{
    public :
        int bestInvitation(vector <string> first, vector <string> second);
}

int InterestingParty::bestInvitation(vector <string> first, vector <string> second)
{
    map<string,int> m;
    int n = (int)first.size();

    for(int i = 0; i < n; ++i){
        m[first[i]] = 0;
        m[second[i]] = 0;
    }

    for(int i = 0; i < n; ++i){
        m[first[i]]++;
        m[second[i]]++;
    }

    int ans = 0;
    map<string,int>::iterator it;
    for(it = m.begin(); it != m.end(); ++it)
    {
        ans = max(ans, it->second);
    }

    return ans;
}

int main()
{

}