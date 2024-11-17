// 1. Two Sum >> https://leetcode.com/problems/two-sum/
// Time: O(N) where N is the size of the array
// Space: O(N) where N is the size of the array

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>  hashTable;
        for(int i = 0; i < nums.size(); i++) {
            int expected_val = target - nums[i];
            if(hashTable.find(expected_val) == hashTable.end()) {
                hashTable[nums[i]] = i;
            } else {
                return {hashTable[expected_val], i};
            }
        }
        return {};
    }
};
