class Solution {
private:
    int bfs(vector<vector<int>>&grid, vector<vector<int>>&vis, int& m, int& n){
        queue<pair< pair<int, int>, int>>q;
        int countFresh = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    q.push({{i, j}, 0});
                }
                else if(grid[i][j] == 1){
                    countFresh++;
                }
            }
        }
        int tm = 0;
        int foundfresh = 0;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        while(!q.empty()){
            int len = q.size();
            for(int i = 0; i < len; i++){
                int row = q.front().first.first;
                int col = q.front().first.second;
                int t = q.front().second;
                tm = max(tm, t);
                q.pop();
                vis[row][col] = 1;
                for(int j = 0; j < 4; j++){
                    int rw = row + drow[j];
                    int cl = col + dcol[j];
                    if(rw >= 0 && rw < m && cl >= 0 && cl < n && grid[rw][cl] == 1 && vis[rw][cl] != 1){
                        vis[rw][cl] = 1;
                        q.push({{rw, cl}, t+1});
                        foundfresh++;
                    }
                }
            }
        }
        if(countFresh != foundfresh){
            return -1;
        }
        return tm;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>vis(m, vector<int>(n, 0));
        return bfs(grid, vis, m, n);
    }
};