// 238. Product of Array Except Self
// https://leetcode.com/problems/product-of-array-except-self/description/

// Optimal solution
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n);
        arr[0] = nums[0];

        arr[0] = 1;
        for(int i = 1; i < n; i++) arr[i] = arr[i-1] * nums[i-1];

        int suffix = 1;
        for(int i = n-1; i >= 0; i--) {
            arr[i] = arr[i] * suffix;
            suffix *= nums[i];
        }

        return arr;
    } 
};

// Sub optimal solution
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr1(n), arr2(n);
        arr1[0] = nums[0];
        arr2[n-1] = nums[n-1];

        arr1[0] = 1;
        for(int i = 1; i < n; i++) arr1[i] = arr1[i-1] * nums[i-1];
        arr2[n-1] = 1;
        for(int i = n-2; i >= 0; i--) arr2[i] = arr2[i+1] * nums[i+1];

        for(int i = 0; i < n; i++) {
            nums[i] = arr1[i] * arr2[i];
        }

        return nums;
    } 
};
