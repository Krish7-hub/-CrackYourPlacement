class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {

        if(s1 == s2){
            return true;
        }

        int left = 0, right = s1.size()-1;
        bool flag = true;
        while(left <= right){
            if(s1[left] != s2[left] && s1[right] != s2[right]){
                swap(s1[left], s1[right]);
                if(s1 == s2){
                    return true;
                }
                else{
                    return false;
                }
                break;
            }
            else if(s1[left] == s2[left]){
                flag = false;
                left++;
            }
            else if(s2[right] == s2[right]){
                flag = false;
                right--;
            }
        }
        return flag;
    }
};