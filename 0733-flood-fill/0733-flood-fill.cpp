class Solution {
public:
    void bfs(vector<vector<int>>& image, vector<vector<int>>& vis, int sr,
             int sc, int& color, int& startcolor) {

        int m = image.size();
        int n = image[0].size();
        queue<pair<int, int>> q;
        q.push({sr, sc});

        while (!q.empty()) {

            int row = q.front().first;
            int col = q.front().second;
            vis[row][col] = color;
            q.pop();
            int top = row - 1;
            int right = col + 1;
            int bottom = row + 1;
            int left = col - 1;
            if(top >=0 && top < m && image[top][col] == startcolor && vis[top][col] != color){
                q.push({top, col});
                vis[top][col] = color;
            }
            if(right >=0 && right < n && image[row][right] == startcolor && vis[row][right] != color){
                q.push({row, right});
                vis[row][right] = color;
            }
            if(bottom >=0 && bottom < m && image[bottom][col] == startcolor && vis[bottom][col] != color){
                q.push({bottom, col});
                vis[bottom][col] = color;
            }
            if(left >=0 && left < n && image[row][left] == startcolor && vis[row][left] != color){
                q.push({row, left});
                vis[row][left] = color;
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        int startcolor = image[sr][sc];
        vector<vector<int>> vis = image;
        bfs(image, vis, sr, sc, color, startcolor);
        return vis;
        
    }
};