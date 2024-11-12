class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int hasharr[256];
        fill(hasharr, hasharr + 256, -1);
        int len = s.size();
        int l = 0, r = 0, maxlen = 0;
        while(r < len){
            if(hasharr[s[r]] != -1){
                if(hasharr[s[r]] >= l){
                    l = hasharr[s[r]] + 1;
                }
            }
            maxlen = max(maxlen, r - l + 1);
            hasharr[s[r]] = r;
            r++;
        }
        return maxlen;
    }
};