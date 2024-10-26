// 283. Move Zeroes
// https://leetcode.com/problems/move-zeroes/description/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l = 0;
        int r = 1;

        while(r < nums.size()) {
            if(nums[l]) l++; 
            else {
                if(nums[r]) {
                    swap(nums[l], nums[r]);
                    l++;
                }  
            }
            r++;
        }
    }
};
