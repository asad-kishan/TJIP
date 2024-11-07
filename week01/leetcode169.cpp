// 169. Majority Element >> https://leetcode.com/problems/majority-element/
// Time: O(N) where N is the size of the array
// Space: O(1)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj_ele;
        int count = 0;
        for(int num : nums) {
            if(!count) {
                maj_ele = num;
            }
            (num == maj_ele) ? count++ : count--;
        }
        return maj_ele;
    }
};
