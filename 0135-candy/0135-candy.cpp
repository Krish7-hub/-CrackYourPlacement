class Solution {
public:
    int candy(vector<int>& ratings) {

        int len = ratings.size();
        vector<int>left(len, 0);
        vector<int>right(len, 0);
        left[0] = 1, right[len-1] = 1;

        for(int i = 1; i < len; i++){
            if(ratings[i] > ratings[i-1]){
                left[i] = left[i-1] + 1;
            }
            else{
                left[i] = 1;
            }
        }

        for(int i = len - 2; i >= 0; i--){
            if(ratings[i] > ratings[i+1]){
                right[i] = right[i+1] + 1; 
            }
            else{
                right[i] = 1;
            }
        }

        int sum = 0;
        for(int i = 0; i < len; i++){
            sum += max(left[i], right[i]);
        }
        
        return sum;
    }
};