// 128. Longest Consecutive Sequence
// https://leetcode.com/problems/longest-consecutive-sequence/description/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;

        unordered_set<int> numSet(nums.begin(), nums.end());
        int res = 0;
        for(int num : nums) {
            if(numSet.count(num - 1)) {
                continue;
            } else {
                int count = 0;
                int curr = num;
                while(numSet.count(curr)) {
                    numSet.erase(curr);
                    curr++;
                    count++;
                }
                res = max(res, count);
            }
        }
        return res;
    }
};
