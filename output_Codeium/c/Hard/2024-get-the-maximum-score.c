/**https://leetcode.com/problems/get-the-maximum-score/ */
//You are given two sorted arrays of distinct integers nums1 and nums2.
//A valid path is defined as follows:
//	Choose array nums1 or nums2 to traverse (from index-0).
//	Traverse the current array from left to right.
//	If you are reading any value that is present in nums1 and nums2 you are allowed to change your path to the other array. (Only one repeated value is considered in the valid path).
//The score is defined as the sum of unique values in a valid path.
//Return the maximum score you can obtain of all possible valid paths. Since the answer may be too large, return it modulo 109 + 7.
// 
//Example 1:
//Input: nums1 = [2,4,5,8,10], nums2 = [4,6,8,9]
//Output: 30
//Explanation: Valid paths:
//[2,4,5,8,10], [2,4,5,8,9], [2,4,6,8,9], [2,4,6,8,10],  (starting from nums1)
//[4,6,8,9], [4,5,8,10], [4,5,8,9], [4,6,8,10]    (starting from nums2)
//The maximum is obtained with the path in green [2,4,6,8,10].
//Example 2:
//Input: nums1 = [1,3,5,7,9], nums2 = [3,5,100]
//Output: 109
//Explanation: Maximum sum is obtained with the path [1,3,5,100].
//Example 3:    
//Input: nums1 = [1,2,3,4,5], nums2 = [6,7,8,9,10]
//Output: 40
//Explanation: There are no common elements between nums1 and nums2.
//Maximum sum is obtained with the path [6,7,8,9,10].
// 
//Constraints:
//	1 <= nums1.length, nums2.length <= 105
//	1 <= nums1[i], nums2[i] <= 107
//	nums1 and nums2 are strictly increasing.
int maxSum(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int dp1[nums1Size + 1], dp2[nums2Size + 1];
    dp1[0] = dp2[0] = 0;
    for (int i = 0; i < nums1Size; i++) {
        dp1[i + 1] = max(dp1[i] + nums1[i], dp2[i] + nums1[i]);
    }
    for (int i = 0; i < nums2Size; i++) {
        dp2[i + 1] = max(dp2[i] + nums2[i], dp1[i] + nums2[i]);
    }
    return max(dp1[nums1Size], dp2[nums2Size]) % 1000000007;
}