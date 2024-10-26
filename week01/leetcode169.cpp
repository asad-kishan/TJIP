// 169. Majority Element
// https://leetcode.com/problems/majority-element/description/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj_ele = 0;
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
