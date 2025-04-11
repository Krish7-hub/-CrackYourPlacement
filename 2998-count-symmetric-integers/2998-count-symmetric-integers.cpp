class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for(int i = low; i <= high; i++){
           int digit = floor(log10(i) + 1);
           if(!(digit & 1)){
              int sum1 = 0; 
              int sum2 = 0;
              string str = to_string(i);
              int len = str.size();
              for(int j = 0; j < len/2; j++){
                  sum1 += str[j];
                  sum2 += str[len - j - 1];
              }
              if(sum1 == sum2){
                count++;
              }
           }
        }
        return count;
    }
};