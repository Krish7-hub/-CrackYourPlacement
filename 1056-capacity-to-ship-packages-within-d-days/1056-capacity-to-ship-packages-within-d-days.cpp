class Solution {
public:
    int findMinDay(vector<int>& weights, int mid){
        int days = 1, load = 0;
        for(int i = 0; i < weights.size(); i++){
            if(weights[i] + load > mid){
                days++;
                load = weights[i];
            }
            else{
                load += weights[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int sum = high;
        while(low <= high){
            int mid = low + (high-low)/2;
            int minDay = findMinDay(weights, mid);
            if(minDay <= days){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};