class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(), s.end());
        sort(g.begin(), g.end());
        int str1 = 0, str2 = 0;
        int len1 = g.size(), len2 = s.size();
        int cnt = 0;
        while(str1 < len2 && str2 < len1){
            if(s[str1] >= g[str2]){
                cnt++;
                str1++, str2++;
            }
            else if(g[str2] > s[str1]){
                str1++;
            }
        }
        return cnt;
    }
};