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
int findLength(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int** dp = (int**)malloc(sizeof(int*) * (nums1Size + 1));
    for (int i = 0; i <= nums1Size; i++) {
        dp[i] = (int*)malloc(sizeof(int) * (nums2Size + 1));
        for (int j = 0; j <= nums2Size; j++) {
            dp[i][j] = 0;
        }
    }
    int max = 0;
    for (int i = 1; i <= nums1Size; i++) {
        for (int j = 1; j <= nums2Size; j++) {
            if (nums1[i - 1] == nums2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > max) {
                    max = dp[i][j];
                }
            }
        }
    }
    for (int i = 0; i <= nums1Size; i++) {
        free(dp[i]);
    }
    free(dp);
    return max;
}