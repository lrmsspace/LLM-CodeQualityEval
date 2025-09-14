/**https://leetcode.com/problems/create-maximum-number/ */
//You are given two integer arrays nums1 and nums2 of lengths m and n respectively. nums1 and nums2 represent the digits of two numbers. You are also given an integer k.
//Create the maximum number of length k <= m + n from digits of the two numbers. The relative order of the digits from the same array must be preserved.
//Return an array of the k digits representing the answer.
// 
//Example 1:
//Input: nums1 = [3,4,6,5], nums2 = [9,1,2,5,8,3], k = 5
//Output: [9,8,6,5,3]
//Example 2:
//Input: nums1 = [6,7], nums2 = [6,0,4], k = 5
//Output: [6,7,6,0,4]
//Example 3:
//Input: nums1 = [3,9], nums2 = [8,9], k = 3
//Output: [9,8,9]
// 
//Constraints:
//	m == nums1.length
//	n == nums2.length
//	1 <= m, n <= 500
//	0 <= nums1[i], nums2[i] <= 9
//	1 <= k <= m + n
class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        vector<int> ans(k);
        
        for (int i = 0; i <= k; i++) {
            int j = k - i;
            int left = max(0, i - n);
            int right = min(m, k - i);
            
            vector<int> candidate1 = pickMax(nums1, left, right);
            vector<int> candidate2 = pickMax(nums2, 0, j);
            
            if (compare(candidate1, candidate2) >= 0) {
                copy(candidate1.begin(), candidate1.begin() + i, ans.begin());
            } else {
                copy(candidate2.begin(), candidate2.begin() + j, ans.begin());
            }
        }
        
        return ans;
        
    }
};