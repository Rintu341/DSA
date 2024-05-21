#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<vector<int>> ans;
    int nodes =3;
    for(int i=0;i<nodes;++i){
        ans.push_back(vector <int> ());
        for(int j=0;j<=i;++j){
            if(j==0 || i==j)
                ans[i].push_back(1);
            else
                ans[i].push_back(ans[i-1][j-1] + ans[i-1][j]);
        }
    }
   for(int i=0;i<nodes;++i){
        for(int j=0;j<=i;++j){
        cout<<ans[i][j]<<" ";
        }
        cout<<endl;
   }
    return 0;
}