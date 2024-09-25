class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        if(p.length() > s.length()) return {};
        vector<int>ans;
        vector<int>storestr(26,0);
        vector<int>storepat(26,0);
        for(int i = 0; i < p.length(); i++){
            storestr[s[i] - 'a']++;
            storepat[p[i] - 'a']++;
        }
        if(storestr == storepat) ans.push_back(0);
        int left = p.length(), right = s.length();
        while(left < right){
            storestr[s[left] - 'a']++;
            storestr[s[left-p.length()] - 'a']--;
            if(storestr == storepat) ans.push_back(left - p.length() + 1);
            left++;
        }
        return ans;
    }
};