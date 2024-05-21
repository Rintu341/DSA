
#include <iostream>
#include <unordered_map>
using namespace std;
//Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map <char,int>m;
        int sSize = s.size();
        for(int i=0;i<sSize;i++){
            if(!m.empty())
            {
                auto it = m.find(s[i]); //this find() function  find the given element into an unordered_map ,return iterator of finding element either return ".end()" iterator.

                if(it!=m.end())
                    m[s[i]]++; // count occurence/frequency of each character into map
                else
                    m[s[i]] = 1;
                
            }else
               m.insert({s[i],1});
        }
        for(int i=0;i<sSize;i++){ // which character frequency exactly 1 and non-repeating character
            if(m[s[i]]==1)
                return i;  // return non-repeating character index.
        }
        return -1;// when non-repeating character do not present into an unordered_map.
    }

};
int main(){
    Solution Sol;
    cout<<Sol.firstUniqChar("aabb")<<endl;
    return 0;
}