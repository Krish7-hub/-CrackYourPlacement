class Solution {
public:
    bool isPalindrome(string s) {
        string check = "";
        for(int i = 0; i < s.size(); i++){
            if(s[i]>='A' && s[i] <= 'Z'){
                check += s[i] - 'A' + 'a' ;
            }
            else if((s[i] >= 'a' && s[i] <= 'z')){
                check += s[i];
            }
            else if(s[i] >= '0' && s[i] <= '9'){
                check += s[i];
            }
        }
        int low = 0;
        int high = check.size() - 1;
        while(low <= high){
            if(check[low] != check[high]){
                return false;
            }
            else{
                low++;
                high--;
            }
        }
        return true;
    }
};