// 274. H-Index >> https://leetcode.com/problems/h-index/
// Time: O(NlogN) where N is the size of the array
// Space: O(1) 

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        int i;
        for(i = 0; i < citations.size(); i++) {
            if(citations[i] < i+1) break;;
        }      
        return i;
    }
};
