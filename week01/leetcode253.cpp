// 253. Meeting Rooms II
// https://neetcode.io/problems/meeting-schedule-ii

/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> start;
        vector<int> end;

        for(auto interval : intervals) {
            start.push_back(interval.start);
            end.push_back(interval.end);
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int count = 0, res = 0, i = 0, j = 0;
        int n = start.size();
        while(i < n) {
            if(start[i] < end[j]) {
                count++;
                res = max(count, res);
                i++;
            } else {
                count--;
                j++;
            }
        }

        return res;
    }
};

// minHip based solution

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
