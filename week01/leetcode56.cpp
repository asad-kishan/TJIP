// 56. Merge Intervals
// https://leetcode.com/problems/merge-intervals/description/

class Solution {
public:
    static bool customComparator(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), customComparator);

        vector<vector<int>> result;
        result.push_back(intervals[0]);

        for(int i = 1; i < intervals.size(); i++) {
            int top = result.size() - 1;
            if(intervals[i][0] <= result[top][1]) {
                result[top][1] = max(result[top][1], intervals[i][1]);
            } else {
                result.push_back(intervals[i]);
            }
        }

        return result;
    }
};
