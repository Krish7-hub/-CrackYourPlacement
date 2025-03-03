class Solution {
public:
    int strStr(string haystack, string needle) {

        int res = haystack.find(needle);
        if(res != string::npos){
            return res;
        }
        else{
            return -1;
        }

    }
};