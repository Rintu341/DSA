#include <iostream>
#include <stack>
#include <unordered_map>
#include <string>
using namespace std;
class solution{
    unordered_map<char,char>mymap={{'(',')'},{'{','}'},{'[',']'}};
    unordered_map<char,char>mymap1={{')','('},{'}','{'},{']','['}};
    stack  <char> mystack;
    public:
        
        bool isvalid(string s){
                int i=0;
                for(auto it =s.begin();it!=s.end();++it,i++){
                    // this find() function search the element in map and return position iterator if don not find the element  then return .end(){iterator} 
                    unordered_map<char,char>::const_iterator get = mymap.find(s[i]);
                        if(get==mymap.end()){
                            //this block of code excecute when find() functio do not find the element in 'mymap'
                            get = mymap1.find(s[i]);//then find element in 'mymap1'
                            if(get->first==s[i]){
                                if(mystack.empty())
                                    return false;
                                else{
                                    if(get->second==mystack.top()){
                                            mystack.pop();
                                    }else   return false;
                                }
                            }
                        }else{

                            if(get->second==s[i]){
                                if(mystack.empty())// underflow condition chack
                                    return false;
                                else{
                                    if(get->first==mystack.top()){
                                            mystack.pop();
                                    }else   return false;
                                }
                            }else{

                                mystack.push(s[i]);//push only open Parentheses in stack
                            }
                }
                }
                if(mystack.empty()) // when stack is empty and string become end that means string is accpted
                    return true;
                
            return false;//when all the condition execute and do not determine the answer
                /*
            while(!mystack.empty()){
                cout<<mystack.top();
                mystack.pop();
            }
            */
        }
};
int main(){
    string s= "]()";
    solution sol;
    bool flag =sol.isvalid(s);
    if(flag)
        cout<<"accepted"<<endl;
    else    
        cout<<"not accepted"<<endl;
    return 0;
}