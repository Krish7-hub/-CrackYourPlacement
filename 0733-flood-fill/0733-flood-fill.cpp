class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int& color, int& startcolor){

        if(sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size()){
            return;
        }

        if(image[sr][sc] != startcolor || image[sr][sc] == color){
            return;
        }

        if(image[sr][sc] != color && image[sr][sc] == startcolor){
            image[sr][sc] = color;
            dfs(image, sr - 1, sc, color, startcolor);
            dfs(image, sr, sc - 1, color, startcolor);
            dfs(image, sr, sc + 1, color, startcolor);
            dfs(image, sr + 1, sc, color, startcolor);
        }
        else {
            return;
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int startcolor = image[sr][sc];
        dfs(image, sr, sc, color, startcolor);
        return image;
    }
};