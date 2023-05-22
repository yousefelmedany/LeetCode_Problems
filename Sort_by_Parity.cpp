#include <bits/stdc++.h>

using namespace std;


vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int> res(nums.size());
        int e=0,o=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2){
                res[o]=nums[i];
                o+=2;
            }else{
                res[e]=nums[i];
                e+=2;
            }
        }
    return res;    
}



int main(){
vector<int> r{4,2,5,7};
vector<int> c=sortArrayByParityII(r);

for(auto e:c){
    cout<<e<<", ";
}
cout<<endl;

}