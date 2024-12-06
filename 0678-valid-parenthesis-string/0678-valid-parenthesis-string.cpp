class Solution {
public:
    bool checkValidString(string s) {

        int minval = 0, maxval = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '('){
                minval += 1;
                maxval += 1;
            }
            else if(s[i] == ')'){
                minval -= 1;
                maxval -= 1;
            }
            else{
                minval -= 1;
                maxval += 1;
            }
            if(minval < 0) minval = 0;
            if(maxval < 0) return false;
        }
        return minval == 0;
    }
};