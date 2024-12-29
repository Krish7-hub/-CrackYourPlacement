class Solution {
public:
    static bool comparator(vector<int>&a, vector<int>&b){
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), comparator);
        int count = 1;
        int lastEndTime = intervals[0][1];
        for(int i = 1; i < n; i++){
            if(intervals[i][0] >= lastEndTime){
                count++;
                lastEndTime = intervals[i][1];
            }
        }

        return n - count;

        
    }
};