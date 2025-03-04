class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        vector<vector<int>>cost(n, vector<int>(n, INT_MAX));
        for(auto it : edges){
            cost[it[0]][it[1]] = it[2];
            cost[it[1]][it[0]] = it[2];
        }

        for(int i = 0; i < n; i++){
            cost[i][i] = 0;
        }


        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){

                    if(cost[i][k] == INT_MAX || cost[k][j] == INT_MAX){
                        continue;
                    }
                    cost[i][j] = min(cost[i][j] , (cost[i][k] + cost[k][j]));
                }
            }
        }

        int maxcnt = n;
        int ans = -1;

        for(int i = 0; i < n; i++){
            int cnt = 0;
            for(int j = 0; j < n; j++){
                if(cost[i][j] <= distanceThreshold){
                    cnt++;
                }
            }
            if(cnt <= maxcnt){
                maxcnt = cnt;
                ans = i;
            }
        }

        return ans;

    }
};