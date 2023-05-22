#include <bits/stdc++.h>

using namespace std;
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> a(n,vector<int>(n,1e7));
        vector<int> res(n,0);

        for(int i=0;i<edges.size();i++){
            a[edges[i][0]][edges[i][1]]=edges[i][2];
            a[edges[i][1]][edges[i][0]]=edges[i][2];


        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(i==k||j==k||i==j){
                        continue;
                    }
                    a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
                }
            }
        }
        int mini=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(a[i][j]<=distanceThreshold){
                        res[i]++;
                }
            }
            if(res[i]<res[mini] || (res[i]==res[mini] && i>mini)){
                mini=i;
            }
        }

        return mini;
    }

int main(){

int n=4,distancethreshold=4;
vector<vector<int>> edges{{0,1,3},{1,2,1},{2,3,1},{1,3,4}};


int res=findTheCity(n,edges,distancethreshold);
cout<<res<<endl;




    return 0;
}