class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>>dist(n, vector<int>(m, INT_MAX));
        priority_queue<pair< int, pair<int, int>>, vector<pair<int , pair<int, int>>>, greater< pair<int, pair< int, int>>>>pq;
        pq.push({0 ,{0,0}});
        dist[0][0] = 0;

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        while(!pq.empty()){

            auto it = pq.top();
            pq.pop();

            int dis = it.first;
            int row = it.second.first;
            int col = it.second.second;

            if(n - 1 == row && m - 1 == col ){
                return dis;
            }

            for(int i = 0; i < 4; i++){

                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m ){
                    int newEffort = max(abs(heights[nrow][ncol] - heights[row][col]), dis);
                    if(newEffort < dist[nrow][ncol]){
                        dist[nrow][ncol] = newEffort;
                        pq.push({newEffort, {nrow, ncol}});
                    }
                }
            }
        }
        return 0;
    }
};