// 136. Single Number
// https://leetcode.com/problems/single-number/description/

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
