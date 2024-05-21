#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix[0].size();//Row
        int n = matrix.size();
        int left = 0,right = m-1, top = 0,bottom = n-1;

        while(left<=right && top <=bottom)
        {   
            // left -> right
            for(int i = left; i<=right; i++)
            {
                ans.push_back(matrix[top][i]);
            }
            top++;
            // cout<<top<<endl;
            //top ->bottom
            for(int i = top; i<=bottom; i++)
            {
                ans.push_back(matrix[i][right]);
            }
            right--;
            // cout<<right<<endl;
            //right->left
            if(top <= bottom)
            {
                for(int i = right; i>=left; i--)
                {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            // cout<<bottom<<endl;
            //bottom -> top
            if(left <= right){
                for(int i = bottom; i>=top; i--)
                {
                    ans.push_back(matrix[i][left]);
                }
                left++; 
            }  
            // cout<<left<<endl;
        }
         return ans;
    }
};
void printMatrix(vector<int> matrix)
{   
    int m = matrix.size();
    for(int i = 0; i < m; i++)
        {
           
                cout<<matrix[i]<<" ";
            
        }
}
int main() 
{
    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    vector<int> ans;
    Solution s;
    ans = s.spiralOrder(matrix);
    printMatrix(s.spiralOrder(matrix));
    return 0;
}