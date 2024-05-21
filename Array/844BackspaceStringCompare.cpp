#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
    public:
        bool backspaceCompare(string s, string t) {
            return compare(s)==compare(t);
        }
    private:
        stack <char> compare(string str){
            stack<char> mystack;
            for (int i=0;i<str.length();i++)
            {
                if (str[i]!='#')
                {
                    mystack.push(str[i]);
                }else{
                    if(!mystack.empty())
                        mystack.pop();
                }
            }
                return mystack;
        }
    /*
public:
    stack <char> s_stack;
    stack <char> t_stack;
    
    bool backspaceCompare(string s, string t) {
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i]!='#')
            {
                s_stack.push(s[i]);
            }else{
                if(!s_stack.empty()){
                    s_stack.pop();
                }
            }
        }
        for (int i = 0; i < t.length(); i++)
        {
            if (t[i]!='#')
            {
                t_stack.push(t[i]);
            }else{
                if(!t_stack.empty()){
                    t_stack.pop();
                }
            }
        }
    while(!s_stack.empty() && !t_stack.empty()){
        if(s_stack.top()==t_stack.top()){
            s_stack.pop();
            t_stack.pop();
        }else
            return false;
    }
        if(t_stack.empty())
            if(s_stack.empty())
                return true;

        return false;
    }
    */
};
int main(){
    Solution sol;
    if(sol.backspaceCompare("bxj##tw","bxj###tw"))
        cout<<"accepted"<<endl;
    else   
        cout<<"not accepted"<<endl;
    return 0;
}