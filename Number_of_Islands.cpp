#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        for(int i=0;i<grid.size();i++){
            for (int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    count++;
                    checkisland(grid,i,j);
                }
            }
        }
        return count;
    }

    void checkisland(vector<vector<char>>& grid,int i,int j){
            if(i<0||j<0||i>=grid.size()||j>=grid[0].size()||grid[i][j]=='0'){
                return;
            }
            grid[i][j]='0';
            checkisland(grid,i-1,j);
            checkisland(grid,i+1,j);
            checkisland(grid,i,j-1);
            checkisland(grid,i,j+1);
            return;
        }

};

int main(){

Solution n;
vector<vector<char>> grid= {{'1','1','0','0','0'},{'1','1','0','0','0'},{'0','0','1','0','0'},{'0','0','0','1','1'}};

int res=n.numIslands(grid);

cout<<res<<endl;

    
    return 0;
}


