class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        vector<vector<int>>result;
        int i = 0;
        int n = intervals.size();
        //Left sorted part
        while(i < n && intervals[i][1] < newInterval[0]){
            result.push_back(intervals[i]);
            i += 1;
        }
        
        while(i < n && intervals[i][0] <= newInterval[1]){
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]);
            i += 1;
        }

        result.push_back(newInterval);

        while(i < n){
            result.push_back(intervals[i]);
            i += 1;
        }

        return result;
        
    }
};