#include <string>

using namespace std;

class ThePalindrome
{
    public:
    	int find(string s)
        {
            int ret = 0;
            int len = s.length();
            
            for(int i = 0; i < len; ++i){
                bool flag = true;
                for(int j = 0; j < (len+i) / 2; ++j){
                    if(j < i) continue;
                    
                    if(s[j] != s[len+i-1-j]){
                        flag = false;
                        break;
                    }
                }
                
                if(flag){
                    ret = len + i;
                    break;
                }         
            }
            return ret;
        }
};