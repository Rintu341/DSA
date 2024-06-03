#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        stack<int> asteroidsStack;
        stack<int> negativeAsteroidsStack;

        vector<int> temp;
        for(int i = 0; i<asteroids.size(); i++)
        {
            asteroidsStack.push(asteroids[i]);
        }

        while(!asteroidsStack.empty())
        {

            if(asteroidsStack.top() < 0 )
            {
                negativeAsteroidsStack.push(-(asteroidsStack.top()));
                asteroidsStack.pop();
            }else if(asteroidsStack.top() > 0 && negativeAsteroidsStack.empty())
            {
                ans.push_back(asteroidsStack.top());
                asteroidsStack.pop();
            }else{
                if(asteroidsStack.top() > negativeAsteroidsStack.top())
                {
                    negativeAsteroidsStack.pop();
                }else if(asteroidsStack.top() < negativeAsteroidsStack.top()){
                        asteroidsStack.pop();
                }else{
                    asteroidsStack.pop();
                    negativeAsteroidsStack.pop();
                }
            }
        }

            while (!negativeAsteroidsStack.empty())
            {   

                temp.push_back(-(negativeAsteroidsStack.top()));
                negativeAsteroidsStack.pop();
            }
            
    
        reverse(ans.begin(),ans.end());
        for(int i = 0; i< ans.size();i++)
        {
            temp.push_back(ans[i]);
        }
        return temp;
    }
};
int main() 
{
    Solution s;

    vector<int> asteroids = {-2,-1,1,2}; 

    vector<int> ans = s.asteroidCollision(asteroids);

    for(int i = 0; i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
