#include <bits/stdc++.h>

using namespace std;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adjacency(n);
        vector<int> minprice(n,1000000);
        queue<pair<int,int>> q;
        q.push({src,0});
        int stop=0;
        
        for(auto flight: flights){
            adjacency[flight[0]].push_back({flight[1],flight[2]});
        }        
        while(!q.empty() &&stop<=k){
            int i=q.size();
            while(i--){
                pair<int,int> curr=q.front();q.pop();
                for(auto neighbour: adjacency[curr.first]){
                    if(curr.second+neighbour.second<minprice[neighbour.first]){
                        minprice[neighbour.first]=curr.second+neighbour.second;
                        q.push({neighbour.first,minprice[neighbour.first]});
                    }
                }
            }
            stop++;
        }
        if(minprice[dst]==1000000){
            return -1;
        }
        return minprice[dst];

    }

int main(){

int n=4,src=0, dst=3,k=1;
vector<vector<int>> flights{{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};

int res=findCheapestPrice(n,flights,src,dst,k);
cout<<"result is "<<res<<endl;


    return 0;
}