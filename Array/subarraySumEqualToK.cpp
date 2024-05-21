#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int size = nums.size();
        int sum = 0;
        int maxi = 0;

        for(int i = 0; i<size;i++)
        {   
            sum = nums[i];
            if(sum == k)
                maxi = max(maxi,1);
            for(int j = i+1; j<size; j++)
            {
                sum += nums[j];
                if(sum == k )
                    maxi = max(maxi,j-i+1);
                else if(sum+1 >= k)
                    break;
            }
        }
        return maxi;
    }
};
int main() 
{
    vector <int> nums ={1,5,7,2,8,9,4,6,3};
    Solution s;
    int p = s.subarraySum(nums,12);
    cout<<p<<endl;
    return 0;
}