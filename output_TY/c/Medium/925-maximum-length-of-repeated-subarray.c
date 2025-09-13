/**https://leetcode.com/problems/maximum-length-of-repeated-subarray/ */
//Given two integer arrays nums1 and nums2, return the maximum length of a subarray that appears in both arrays.
// 
//Example 1:
//Input: nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
//Output: 3
//Explanation: The repeated subarray with maximum length is [3,2,1].
//Example 2:
//Input: nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
//Output: 5
//Explanation: The repeated subarray with maximum length is [0,0,0,0,0].
// 
//Constraints:
//	1 <= nums1.length, nums2.length <= 1000
//	0 <= nums1[i], nums2[i] <= 100
int findLength(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int dp[nums1Size+1][nums2Size+1];
    int max_len = 0;
    for (int i = 1; i <= nums1Size; i++) {
        for (int j = 1; j <= nums2Size; j++) {
            dp[i][j] = nums1[i-1] == nums2[j-1] ? dp[i-1][j-1] + 1 : 0;
        }
    }
    for (int i = 1; i <= nums1Size; i++) {
        for (int j = 1; j <= nums2Size; j++) {
            max_len = max(max_len, dp[i][j]);
        }
    }
    return max_len;
}