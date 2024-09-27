class MyCalendarTwo {
    map<int, int>stops;
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        stops[start]++;
        stops[end]--;
        int booked = 0; // count of number of overlaps.
        for(auto &stop : stops){
            booked += stop.second;
            if(booked > 2){
                stops[start]--;
                stops[end]++;

                if(stops[start] == 0){
                    stops.erase(start);
                }
                if(stops[end] == 0){
                    stops.erase(end);
                }
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */