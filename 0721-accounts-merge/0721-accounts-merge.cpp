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
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string, int>mppMail;

        for(int i = 0; i < n; i++){
            for(int j = 1; j < accounts[i].size(); j++){
                string mail = accounts[i][j];
                if(mppMail.find(mail) == mppMail.end()){
                    mppMail[mail] = i;
                }
                else{
                    ds.unionBySize(i, mppMail[mail]);
                }
            }
        }

        vector<string>storeMail[n];
        for(auto it : mppMail){
            string mail = it.first;
            int par = ds.findUPar(it.second);
            storeMail[par].push_back(mail);
        }

        vector<vector<string>>ans;

        for(int i = 0; i < n; i++){

            if(storeMail[i].size() == 0)continue;
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            sort(storeMail[i].begin(), storeMail[i].end());
            for(auto it : storeMail[i]){
                temp.push_back(it);
            } 
            ans.push_back(temp);
        }
        return ans;
    }
};