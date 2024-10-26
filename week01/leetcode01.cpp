// 1. Two Sum
// https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashTable;
        vector<int> result;

        for(int i = 0; i < nums.size(); i++) {
            int expected_val = target - nums[i];
            
            if(hashTable.find(expected_val) == hashTable.end()) {
                hashTable[nums[i]] = i;
            } else {
                result.push_back(hashTable[expected_val]);
                result.push_back(i);
                break;
            }
        }

        return result;
    }
};
