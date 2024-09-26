class MyCalendar {
    map<int,int>intervals; // key -> end & value-> start 
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto it = intervals.upper_bound(start);
        if(it == intervals.end() || it->second >= end){
            intervals[end] = start;
            return true;
        }
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */