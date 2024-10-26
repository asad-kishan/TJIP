// 88. Merge Sorted Array
// https://leetcode.com/problems/merge-sorted-array/description/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int last_idx = n+m;

        while(m > 0 && n > 0) {
            if(nums2[n-1] > nums1[m-1]) {
                nums1[--last_idx] = nums2[--n];
            } else {
                nums1[--last_idx] = nums1[--m];
            }
        }

        while(n > 0) {
            nums1[--last_idx] = nums2[--n];
        }
    }
};
