// 136. Single Number >> https://leetcode.com/problems/single-number/
// Time: O(N) where N is the size of the array
// Space: O(1)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int num : nums) {
            res ^= num;
        }
        return res;
    }
};
