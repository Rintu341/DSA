#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
// leet**cod*e
//"wdp**yy**gkp**n***d*k*nm*l**ze**sq*p"
class Solution {
public:
/*
    string removeStars(string s) {
        stack<char> sta;
        string ans;
        char temp;
        int count = 0;
        int i = 0;
        int size = s.size();

        for(int k = 0;s[k]; k++)
        {   
            // cout<<s[k]<<endl;
            sta.push(s[k]);
        }

        // cout<<sta.top()<<endl;
        while(i < size)
        {   
            
            temp = sta.top();

            
            if(temp == '*')
            {
                count++;
                sta.pop();
                i++;
            }else{
                if(count > 0)
                {
                    // for(int j = 0; j<count; j++,i++)
                    // {
                    //     sta.pop();
                    //     count--; 
                    // }
                    sta.pop();
                    count--;
                    i++;
                }
                else{
                        ans.push_back(temp);
                        sta.pop();
                        i++;
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
        }
        */
    
    string removeStars(string s) {
        string ans;
        char temp;
        int count = 0;
        int size = s.size();
        int i = size-1;

        while(i >= 0)
        {   
            temp = s[i];
            if(temp == '*')
            {
                count++;
                i--;
            }else{
                if(count > 0)
                {
                    count--;
                    i--;
                }
                else{
                        ans.push_back(temp);
                        i--;
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
int main() 
{
    Solution s;
    string str = s.removeStars("leet**cod*e");
    cout<<str<<endl;
    return 0;
}