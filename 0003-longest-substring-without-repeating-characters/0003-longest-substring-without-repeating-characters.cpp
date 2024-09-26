class Solution {
public:
    int lengthOfLongestSubstring(string S) {

      if(S.length() == 0) return 0;
    if(S.length() == 1) return 1;
    
    int left = 0, right = 0;
    int maxstrlen = 0;
    vector<int>visited(256,false);
    
    while(right < S.length()){
        while(visited[S[right]] == true){
            visited[S[left]] = false;
            left++;
        }
        visited[S[right]] = true;
        maxstrlen = max(maxstrlen, right-left+1);
        right++;
    }
    return maxstrlen;
    }
};