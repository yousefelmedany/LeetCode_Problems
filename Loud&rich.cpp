#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        vector<int> answer;
        int number=quiet.size();
        list<int> adj[number];
        for(int x=0;x<richer.size();x++){
            adj[richer[x][1]].emplace_back(richer[x][0]);
        }
        for(int i=0;i<number;i++){
            int res=searchformin(i,quiet,adj);
            answer.emplace_back(res);
        }
        return answer;
    }
    int searchformin(int v,vector<int>& quiet,list<int>* adj){
        int leastquiet=v;
        int check;
        if(adj[v].size()==0){
            return leastquiet; 
        }
        for(auto i=adj[v].begin();i!=adj[v].end();++i){
            check=searchformin(*i,quiet,adj);
            if(quiet[check]<quiet[v]){
                leastquiet=check;
            }
        }
        return leastquiet;
    }


};

int main(){

Solution n;
vector<int> quiet{3,2,5,4,6,1,7,0};
vector<vector<int>> richer{{1,0},{2,1},{3,1},{3,7},{4,3},{5,3},{6,3}};
vector<int> res=n.loudAndRich(richer,quiet);



    return 0;
}