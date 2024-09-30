class Solution {
public:
    int myAtoi(string s) {
           int startIdx = 0, len = s.size(), sign = 1, ans = 0;
           //Handle WhiteSpace
           while(startIdx < len && s[startIdx] == ' '){
                startIdx++; 
           }
           // Handle the sign part
           if(s[startIdx] == '-'){
              sign = -1, startIdx++;
           }
           else if(s[startIdx] == '+'){
               startIdx++;
           }
           //Finding the Interger Value.
           while(s[startIdx] >= '0' && s[startIdx] <='9'){
                int digit = s[startIdx++] - '0';
                if(ans > INT_MAX/10 || ans == INT_MAX/10 && digit > 7){
                    return sign == 1 ? INT_MAX : INT_MIN;
                }
                ans = ans*10 + digit;
           }
           return sign*ans;
    }
};