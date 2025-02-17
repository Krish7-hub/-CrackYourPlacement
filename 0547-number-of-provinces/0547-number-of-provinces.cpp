class Solution {
public:
    void dfs(vector<int>adj[], vector<int>&vis, int node){
        vis[node] = 1;
        for(auto it : adj[node]){
            if(vis[it] != 1){
                dfs(adj, vis, it);
            }
        }
    }

    int solve(vector<int>adj[], vector<int>&vis, int v){
        int cnt = 0;
        for(int i = 0; i < v; i++){
            if(vis[i] != 1){
                cnt++;
                dfs(adj, vis, i);
            }
        }
        return cnt;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        vector<int>adj[v];
        vector<int>vis(v, 0);

        for(int i = 0; i < v; i++){
            for(int j = 0; j < v; j++){
                if(isConnected[i][j] == 1 && i != j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        return solve(adj, vis, v);

    }
};