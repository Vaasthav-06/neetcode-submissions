class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int>vis(n);
        vector<vector<int>>adjList(n);
        for(auto it:edges){
            adjList[it[0]].push_back(it[1]);
            adjList[it[1]].push_back(it[0]);
        }
        int number_of_components = 0;
        for(int i = 0; i < n;i++){
            if(!vis[i]){
                number_of_components++;
                if(isCycle(i,-1,vis,adjList)){
                    return false;
                }
            }
        }

        if(number_of_components != 1){
            return false;
        }
        return true;
    }
private:
    bool isCycle(int node,int parent,vector<int>&vis,vector<vector<int>>&adjList){
        vis[node] = 1;
        for(auto it: adjList[node]){
            if(!vis[it]){
                if(isCycle(it,node,vis,adjList)) return true;
            }
            else if(vis[it] && it != parent){
                return true;
            }
        }

        return false;
    }
};
