class DisjointSet{
    public:
    vector<int>size, parent;
    DisjointSet(int n){
        size.resize(n+1);
        parent.resize(n+1);
        for(int i = 0; i < n; i++){
            size[i] = 1;
            parent[i] = i;
        }
    }

    int findUPar(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } 
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
private:
    bool isValid(int row, int col, int n){
        return (row >= 0 && row < n && col >= 0 && col < n);
    }
public:
    int largestIsland(vector<vector<int>>& grid) {

        int n = grid.size();
        DisjointSet ds(n*n);

        // it will make connected components.
        for(int row = 0; row < n; row++){
            for(int col = 0; col < n; col++){
                if(grid[row][col] == 0) continue;
                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, 1, 0, -1};
                for(int ind = 0; ind < 4; ind++){
                    int nr = row + dr[ind];
                    int nc = col + dc[ind];
                    if(isValid(nr, nc, n) && grid[nr][nc] == 1){
                        int nodeNo = row * n + col;
                        int adjNode = nr * n + nc;
                        ds.unionBySize(nodeNo, adjNode);
                    }
                }
            }
        }

        int mx = 0;

        for(int row = 0; row < n; row++){
            for(int col = 0; col < n; col++){
                if(grid[row][col] == 1) continue;
                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, 1, 0, -1};
                set<int>uniqueNode;
                for(int ind = 0; ind < 4; ind++){
                    int nr = row + dr[ind];
                    int nc = col + dc[ind];
                    if(isValid(nr, nc, n)){
                        if(grid[nr][nc] != 0){
                            uniqueNode.insert(ds.findUPar(nr * n + nc));
                        }
                    }
                }
                int temp = 0;
                for(auto it : uniqueNode){
                    temp += ds.size[ds.findUPar(it)];
                }
                mx = max(temp + 1 , mx);
            }
        }

        for(int ind = 0; ind < n*n; ind++){
            mx = max(mx, ds.size[ind]);
        }
        return mx;

    }
};