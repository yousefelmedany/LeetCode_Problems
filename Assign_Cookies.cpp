#include <bits/stdc++.h>


using namespace std;


int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(),s.end());
        int count=0;
        for(auto e:g){
            auto it=lower_bound(s.begin(),s.end(),e);
            if(it!=s.end()){
                count++;
                s.erase(it);
            }
        }

return count;
}

int main(){

vector<int> g{4,2,3,1};
vector<int> s{1,2,3,4};

cout<< findContentChildren(g,s)<<endl;




}


