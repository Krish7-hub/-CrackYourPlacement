class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n = s.length();
        int res = 0;
        for(int i = 0; i < n; i++){
            vector<int>visited(256,0);
            for(int j = i; j < n; j++){
               if(visited[s[j]] == true){
                  break;
               }
               else{
                 res = max(res, j-i+1);
                 visited[s[j]] = true;
               }
            }
        }
        return res;
    }
};