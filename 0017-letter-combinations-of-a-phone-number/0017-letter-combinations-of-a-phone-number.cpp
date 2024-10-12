class Solution {
public:
    
    void solve(string& digits, vector<string>&ans, string output, int index, vector<string>&mapping){

        //base case
        if(index >= digits.size()){
            ans.push_back(output);
            return;
        }
        int digit = digits[index] - '0';
        string value = mapping[digit];
        for(int i = 0; i < value.size(); i++){
            output.push_back(value[i]);
            solve(digits, ans, output, index+1, mapping);
            output.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {

        if(digits.length() == 0) return {};

        vector<string>ans;
        string output = "";
        int index = 0;

        vector<string>mapping(10);
        mapping[2] = "abc";
        mapping[3] = "def";
        mapping[4] = "ghi";
        mapping[5] = "jkl";
        mapping[6] = "mno";
        mapping[7] = "pqrs";
        mapping[8] = "tuv";
        mapping[9] = "wxyz";
        solve(digits, ans, output, index, mapping);
        return ans;

    }
};