#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i<n;i++)
        {
            for(int j = i+1; j < n; j++)
            {   
                    swap(matrix[i][j],matrix[j][i]);
            }
        }
        display(matrix);
        for(int i = 0; i<n;i++)
        {
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }

    void display(vector<vector<int>> matrix)
    {
      int n = matrix.size();
        for(int i = 0; i<n;i++)
        {
            for(int j = 0; j < n; j++)
            {
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }  
    }
  
};
int main() 
{
    vector<vector<int>> matrix ={{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};

    Solution obj;
    obj.display(matrix);
    cout<<endl;
    obj.rotate(matrix);
    obj.display(matrix);
    return 0;
}