// 253. Meeting Rooms II >> https://neetcode.io/problems/meeting-schedule-ii/
// Time: O(NlogN) where N is the size of the array
// Space: O(N) where N is the size of the array

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.empty()) return 0;

        sort(intervals.begin(), intervals.end(), [](const Interval &a, const Interval &b){
            return a.start < b.start;
        });
        priority_queue<int, vector<int>, greater<int>> endTimes;
        endTimes.push(intervals[0].end);
        
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i].start >= endTimes.top()) {
                endTimes.pop();
            }
            endTimes.push(intervals[i].end);
        }
        return endTimes.size();
    }
};
