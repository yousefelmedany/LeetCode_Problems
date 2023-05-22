#include <bits/stdc++.h>

using namespace std;

#define MAX 1000000000
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size(),m=heights[0].size();
        vector<vector<int>> efforts(n,vector<int>(m,1e7));
        efforts[0][0]=0;
        priority_queue <pair<int, pair<int, int>>, vector<pair<int, 
        pair<int, int>>>, greater<pair<int, pair<int, int>>>> p;
        p.push({0,{0,0}});
        vector<int> cx,cy;
        cx={-1,0,1,0}; cy={0,1,0,-1};

        while(!p.empty()){
        int eff=p.top().first,row=p.top().second.first,col=p.top().second.second;
        p.pop();
        if(row==n-1&&col==m-1){
            return eff;
        }
        for(int i=0;i<4;i++){
            int r=row+cx[i],c=col+cy[i];
            if(r>=0 && r<n && c>=0 && c<m){
                int neweff=max(eff,abs(heights[r][c]-heights[row][col]));
                if(neweff<efforts[r][c]){
                    efforts[r][c]=neweff;
                    p.push({neweff,{r,c}});
                }
            }
        }
        }
        return -1;
    }


int main(){

vector<vector<int>> heights{{1,2,2},{3,8,2},{5,3,5}};



    return 0;
}
