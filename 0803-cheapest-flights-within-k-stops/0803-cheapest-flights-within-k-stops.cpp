class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<pair<int, int >>adj[n];
        for(auto it : flights){
            adj[it[0]].push_back({it[1], it[2]});
        }

        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});
        vector<int> dist(n , INT_MAX);
        dist[src] = 0;

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int stop = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            if(stop > k){
                continue;
            }

            for(auto itr : adj[node]){

                int newnode = itr.first;
                int newcost = itr.second + cost;

                if(dist[newnode] > newcost && stop <= k){
                    dist[newnode] = newcost;
                    q.push({stop + 1, {newnode, newcost}});
                }

            }

        }
        if(dist[dst] == INT_MAX){
            return -1;
        }
        return dist[dst];
    }
};