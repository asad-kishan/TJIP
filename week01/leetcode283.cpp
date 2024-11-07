// 283. Move Zeroes >> https://leetcode.com/problems/move-zeroes/
// Time: O(N) where N is the size of the array
// Space: O(1) 

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l = 0, r = 1;
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
