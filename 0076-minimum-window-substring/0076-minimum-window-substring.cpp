class Solution {
public:
    string minWindow(string s, string t) {

        int n = s.size(), m = t.size();
        int hash[256];
        fill(hash, hash+256, 0);
        int left = 0, right = 0, sindex = -1, cnt = 0;
        double minlen = 10e9;
        for(int i = 0; i < m; i++){
            hash[t[i]]++;
        }
        while(right < n){
            if(hash[s[right]] > 0) cnt =  cnt + 1;
            hash[s[right]]--;
            while(cnt == m){
                if(right - left + 1 < minlen){
                    minlen = right - left + 1;
                    sindex = left;
                }
                hash[s[left]]++;
                if(hash[s[left]] > 0) cnt = cnt - 1;
                left = left + 1;
            }
            right = right + 1;
        }
        return sindex == -1 ? "" : s.substr(sindex, minlen);
    }
};