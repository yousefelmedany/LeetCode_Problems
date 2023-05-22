#include <bits/stdc++.h>

using namespace std;



class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> p(stones.begin(),stones.end());
        int max1,max2;
        while(!p.empty()&&(p.size()>1)){
            max1=p.top();
            p.pop();
            max2=p.top();
            p.pop();
            if(max1==max2){
                continue;
            }
            else{
                max1-=max2;
                p.emplace(max1);
            }

        }
        return p.top();
    }
};

int main(){

Solution n;
vector<int> v{1};

int res=n.lastStoneWeight(v);
cout<<res<<endl;

    return 0;
}