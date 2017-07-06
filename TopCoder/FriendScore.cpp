#include <vector>
#include <algorithm>
using namespace std;

class FriendScore
{
    public:
        int highestScore(vector<string> friends)
        {
            int n = (int)friends.size();
            int ret = 0;

            for(int i = 0; i < n; ++i){
                int f = 0;
                for(int j = 0; j < n; ++j){
                    if(i == j) continue;
                    if(friends[i][j] == 'Y') f++;
                    else{
                        for(int k = 0; k < n; ++k){
                            if(friends[j][k] == 'Y' && friends[k][i] == 'Y'){
                                f++;
                                break;
                            }
                        }
                    }
                }
                ret = max(ret, f);                
            }

            return ret;
        }
};