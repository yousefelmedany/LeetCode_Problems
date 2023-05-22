#include<bits/stdc++.h>


using namespace std;


int subarraySum(vector<int>& nums, int k) {
unordered_map<int,int> m;
m[0]=1;
int sum=0,count=0;
for(auto x:nums){
    sum+=x;
    if(m.find(sum-k)!=m.end()){
        count+=m[sum-k];
    }
    m[sum]++;
}

return count;

} 





int main(){

vector<int> num{1,1,1};
int k=2;
subarraySum(num,k);
cout<<subarraySum(num,k)<<endl;



}





