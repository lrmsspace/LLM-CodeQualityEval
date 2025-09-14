/**https://leetcode.com/problems/advantage-shuffle/ */
//You are given two integer arrays nums1 and nums2 both of the same length. The advantage of nums1 with respect to nums2 is the number of indices i for which nums1[i] > nums2[i].
//Return any permutation of nums1 that maximizes its advantage with respect to nums2.
// 
//Example 1:
//Input: nums1 = [2,7,11,15], nums2 = [1,10,4,11]
//Output: [2,11,7,15]
//Example 2:
//Input: nums1 = [12,24,8,32], nums2 = [13,25,32,11]
//Output: [24,32,8,12]
// 
//Constraints:
//	1 <= nums1.length <= 105
//	nums2.length == nums1.length
//	0 <= nums1[i], nums2[i] <= 109
class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<pair<int, int>> nums(n);
        for (int i = 0; i < n; ++i) {
            nums[i] = {nums1[i], i};
        }
        sort(nums.begin(), nums.end(), greater<pair<int, int>>());
        
        vector<int> ans(n);
        int left = 0, right = n - 1;
        for (int i = 0; i < n; ++i) {
            if (nums[i].first > nums2[right]) {
                ans[nums[i].second] = nums2[right];
                --right;
            } else {
                ans[nums[i].second] = nums2[left];
                ++left;
            }
        }
        
        return ans;
        
    }
};