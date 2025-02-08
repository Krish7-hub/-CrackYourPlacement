class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        sort(strs.begin(), strs.end());
        int len = strs.size();
        string str1 = strs[0];
        int lenstr1 = str1.size();
        string str2 = strs[len-1];
        int lenstr2 = str2.size();
        string ans = "";
        int minlen = min(lenstr1, lenstr2);
        for(int i = 0; i < minlen; i++){
            if(str1[i] == str2[i]){
                ans += str1[i];
            }
            else{
                break;
            }
        }
        return ans;
    }
};