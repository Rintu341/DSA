#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> row;
        vector<int> column;

        int m = matrix.size(); // Row
        int n = matrix[0].size();// Column

        for(int i = 0; i <matrix.size() ; i++) // For column
        {
            for(int j = 0; j < matrix[i].size(); j++) // For Row
            {
                if(matrix[i][j] == 0)
                {
                    cout<<i<<" "<<j<<endl;
                    row.push_back(i);
                    column.push_back(j);
                }
            }
        }
        cout<<"--------------"<<endl;

        for(int k = 0; k<row.size(); k++)
        {
            for(int j = 0; j<matrix[0].size();j++)
            {   
                cout<<row[k]<<" "<<j<<endl;
                matrix[row[k]][j] = 0;           
            }
        cout<<"-----"<<endl;
        }
        cout<<"-----"<<endl;
        for(int k = 0; k<column.size(); k++)
        {
            for(int p = 0 ; p<matrix.size(); p++)
            {   
                cout<<p<<" "<<column[k]<<endl;
                matrix[p][column[k]] = 0;
            }
        cout<<"-----"<<endl;
        }
    }
};

void printMatrix(vector<vector<int>> & matrix)
{   
    int m = matrix.size();
    int n = matrix[0].size();
    for(int i = 0; i < matrix.size() ; i++)
        {
            for(int j = 0; j < matrix[i].size(); j++)
            {
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
}
int main() 
{
    // vector<vector<int>> matrix ={{1,1,1},{1,0,1},{1,1,1}}; 
    vector<vector<int>> matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    Solution s;
    s.setZeroes(matrix);
    printMatrix(matrix);
    return 0;
}