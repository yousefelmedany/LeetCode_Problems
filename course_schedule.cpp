#include <bits/stdc++.h>

using namespace std;



class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        list<int> adj[numCourses];
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].emplace_back(prerequisites[i][0]);
        }
        bool* visited = new bool[numCourses];
        bool* Stack = new bool[numCourses];
        for (int i = 0; i < numCourses; i++) {
        visited[i] = false;
        Stack[i] = false;
            }
        for (int i = 0; i < numCourses; i++){
            if (!visited[i] && cyclecheck(i, visited, Stack, adj)){
                return false;}
            }
        return true;
    }

    bool cyclecheck(int i, bool visited[],bool* Stack,list<int>* adj){
     if (visited[i] == false) {
        visited[i] = true;
        Stack[i] = true;

        for (auto j = adj[i].begin(); j != adj[i].end(); ++j) {
            if (!visited[*j] && cyclecheck(*j, visited, Stack,adj))
                return true;
            else if (Stack[*j])
                return true;
        }
    }
 
        Stack[i] = false;
        return false;
    }

};

int main(){

Solution n;
vector<vector<int>> v{{1,0}};
int coursecount=2;


bool res=n.canFinish(coursecount,v);
cout<<res<<endl;

    return 0;
}