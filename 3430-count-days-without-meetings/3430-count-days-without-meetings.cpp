class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        if(meetings.size() == 0){
            return days;
        }
        sort(meetings.begin(), meetings.end());
        vector<vector<int>>newMeetings;
        int start = meetings[0][0];
        int end = meetings[0][1];
        for(int i = 1; i < meetings.size(); i++){
            if(meetings[i][0] <= end){
                end = max(end, meetings[i][1]);
            }
            else{
                newMeetings.push_back({start, end});
                start = meetings[i][0];
                end = meetings[i][1];
            }
        }
        newMeetings.push_back({start, end});
        int count = 0;
        if(!newMeetings.empty() && newMeetings[0][0] > 1){
            count += newMeetings[0][0] - 1;
        }
        for(int i = 1; i < newMeetings.size(); i++){
            count += newMeetings[i][0] - newMeetings[i-1][1] - 1;
        }
        if(!newMeetings.empty() && newMeetings.back()[1] < days){
            count += days - newMeetings.back()[1];
        }
        return count;
    }
};