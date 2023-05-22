#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    auto it1=intervals[0];
    auto it2=intervals[1];
    int maxi= it1[1];
    vector<vector<int>> res;
    for(int i=1;i<intervals.size();i++){
     if(it1[1] >= it2[0]){
            maxi=max(maxi,it2[1]);
            if(i!=intervals.size()-1)
            it2=intervals[i+1];
     }else{
        res.push_back({it1[0],maxi});
        it1=it2;
        if(i!=intervals.size()-1)
        it2=intervals[i+1];
        maxi=it1[1];
     }
    }
    res.push_back({it1[0],maxi});
    return res;
}



int main(){

vector<vector<int>> x{{1,4},{4,5}};

vector<vector<int>> r=merge(x);

for(auto e1: r){
    cout<<"[ ";
    for(auto e2: e1){
        cout<<e2<<", ";
    }
    cout<<" ]";
}



}
