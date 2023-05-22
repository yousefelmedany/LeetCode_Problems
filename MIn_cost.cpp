#include <bits/stdc++.h>

using namespace std;

int minCostConnectPoints(vector<vector<int>>& points) {
    int cost=0;
    vector<int> x;
    bool arr[points.size()];
    fill(arr,arr+points.size(),false);

    for(int i=0;i<points.size();i++){
        for(int j=0;j<points.size();j++){
            if(i==j){
                x.push_back(100000);
            }else{
            x.push_back(abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]));
            }
        }
        if(arr[i]==false){
            auto mini=min_element(x.begin(),x.end());
            int ind=mini-x.begin();
            cost+= *mini;
            arr[i]=true;
            arr[ind]=true;
        }
        x.clear();
    }

    return cost;
}





int main(){

vector<vector<int>> x{{0,0},{2,2},{3,10},{5,2},{7,0}};

cout<<"cost is "<<minCostConnectPoints(x)<<endl;

}

