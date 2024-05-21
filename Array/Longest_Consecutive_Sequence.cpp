#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        int size = nums.size();
        int longest = 0;
        int maxi = 0;
        int prev;
        if(size > 0)
        {
            prev = nums[0];
            longest++;
            maxi = 1;
        }else
        {
            return 0;
        }
        cout<<"hello"<<endl;
        for(int i = 1; i < size; i++)
        {   

            if(nums[i] == prev+1)
            {
                longest++;
                prev = nums[i];
            }else if( nums[i] > prev + 1)
            {
                prev = nums[i];
                longest = 1; 
            }
            maxi = max(maxi,longest);
            cout<<" i "<<i<<" maxi "<<maxi<<" "<<"longest"<<longest<<endl;
        }

        return maxi;
    }
};
int main() 
{
    Solution s;
    // vector<int> nums ={0,3,7,2,5,8,4,6,0,1};
    vector<int> nums ={5,4,7,3,1,2,3};

    int ans = s.longestConsecutive(nums);
    cout<<ans<<endl;
    return 0;
}