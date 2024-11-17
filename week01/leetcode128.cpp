// 128. Longest Consecutive Sequence >> https://leetcode.com/problems/longest-consecutive-sequence/
// Time: O(N) where N is the size of the array
// Space: O(N) where N is the size of the array

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int res = 0;
        for(int num : nums) {
            if(numSet.count(num - 1) == 0) {
                int count = 1;
                int curr = num+1;
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
