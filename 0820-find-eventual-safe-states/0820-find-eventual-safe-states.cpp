class Solution {
public:
   bool dfs(int node, vector<int>&vis, vector<int>&path, vector<int>&check, vector<vector<int>>&graph){
      vis[node] = 1;
      path[node] = 1;
      for(auto it : graph[node]){
        if(!vis[it]){
            if(dfs(it, vis, path, check, graph)){
                check[it] = 0;
                return true;
            }
        }
        if(path[it] == 1){
            check[it] = 0;
            return true;
        }
      }
      path[node] = 0;
      check[node] = 1;
      return false;
   }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>vis(n, 0);
        vector<int>path(n, 0);
        vector<int>check(n, 0);
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(i, vis, path, check, graph);
            }
        }
        vector<int>ans;
        for(int i = 0; i < n; i++){
            if(check[i] == 1){
                ans.push_back(i);
            }
        }
        return ans;
    }
};