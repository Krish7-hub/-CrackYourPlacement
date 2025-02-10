class Solution {
public:
    int romanToInt(string s) {

        // unordered_map<char, int>mpp;
        // mpp['I'] = 1;
        // mpp['V'] = 5;
        // mpp['X'] = 10;
        // mpp['L'] = 50;
        // mpp['C'] = 100;
        // mpp['D'] = 500;
        // mpp['M'] = 1000;

        // int ans = 0;
        // for(int i = 0; i < s.size(); i++){
        //     if(mpp[s[i]] < mpp[s[i+1]]){
        //         ans -= mpp[s[i]];
        //     }
        //     else{
        //         ans += mpp[s[i]];
        //     }
        // }
        // return ans;

        int result = 0;
        int preValue = 0;
        for(int i = s.size() - 1; i >= 0; i--){
            int value;
            switch(s[i]){
                case 'I':
                  value = 1;
                  break;
                case 'V':
                  value = 5;
                  break;
                case 'X':
                  value = 10;
                  break;
                case 'L':
                  value = 50;
                  break;
                case 'C':
                  value = 100;
                  break;
                case 'D':
                  value = 500;
                  break;
                case 'M':
                  value = 1000;
                  break;
                default:
                  continue;
            }
            if(value >= preValue){
                result += value;
            }
            else{
                result -= value;
            }
            preValue = value;
        }
        return result;

    }
};