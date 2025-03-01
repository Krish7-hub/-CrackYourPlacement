class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        if(grid[0][0] == 1){
            return -1;
        }

        int n = grid.size();
        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        q.push({1, {0, 0}});
        dist[0][0] = 1;

        int drow[] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int dcol[] = {0, 1, 1, 1, 0, -1, -1, -1};

        while(!q.empty()){
            auto it = q.front();
            int row = it.second.first;
            int col = it.second.second;
            int dis = it.first;
            q.pop();

            for(int i = 0; i < 8; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n &&
                    grid[nrow][ncol] == 0 && dist[nrow][ncol] > (dis + 1) ){

                    dist[nrow][ncol] = dis + 1;
                    q.push({dis + 1, {nrow, ncol}});
                }
            }
        }
        
        if(dist[n-1][n-1] != INT_MAX){
            return dist[n-1][n-1];
        }
        return -1;
    }
};