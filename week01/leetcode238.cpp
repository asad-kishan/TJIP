// 238. Product of Array Except Self >> https://leetcode.com/problems/product-of-array-except-self/
// Time: O(N) where N is the size of the array
// Space: O(N) where N is the size of the array

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n);
        
        arr[0] = 1;
        for(int i = 1; i < n; i++) {
            arr[i] = arr[i-1] * nums[i-1]; // Prefix product
        }

        int suffix = 1;
        for(int i = n-1; i >= 0; i--) {
            arr[i] = arr[i] * suffix; // Product of Array Except Self
            suffix *= nums[i];
        }
        return arr;
    } 
};
