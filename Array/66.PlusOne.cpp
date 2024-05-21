#include <iostream>
#include <vector>
#include <list>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int k = 0;
        for(int i=0;i<digits.size();i++){
            k =(k*10)+digits[i];
        }
        cout<<k<<endl;
        return {-1};
    }
};
int main(){
    Solution s;
    vector <int> m;
    m.push_back(1);
    m.push_back(2);
    m.push_back(3);
    s.plusOne(m);
    return 0;
}