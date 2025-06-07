class Solution {
public:
    bool isMatch(char c1, char c2){
        if(c1 == '(' && c2 == ')') return true;
        if(c1 == '{' && c2 == '}') return true;
        if(c1 == '[' && c2 == ']') return true;
        return false;
    }
    bool isValid(string s) {

        int n = s.size();
        int top = -1;
        for(int i = 0; i < n; i++){
            if(top < 0 || !isMatch(s[top], s[i])){
                top++;
                s[top] = s[i];
            }
            else{
                top--;
            }
        }
        return top == -1;
    }
};