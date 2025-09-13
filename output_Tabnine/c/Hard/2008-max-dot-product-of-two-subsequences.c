/**https://leetcode.com/problems/max-dot-product-of-two-subsequences/ */
//Given two arrays nums1 and nums2.
//Return the maximum dot product between non-empty subsequences of nums1 and nums2 with the same length.
//A subsequence of a array is a new array which is formed from the original array by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, [2,3,5] is a subsequence of [1,2,3,4,5] while [1,5,3] is not).
// 
//Example 1:
//Input: nums1 = [2,1,-2,5], nums2 = [3,0,-6]
//Output: 18
//Explanation: Take subsequence [2,-2] from nums1 and subsequence [3,-6] from nums2.
//Their dot product is (2*3 + (-2)*(-6)) = 18.
//Example 2:
//Input: nums1 = [3,-2], nums2 = [2,-6,7]
//Output: 21
//Explanation: Take subsequence [3] from nums1 and subsequence [7] from nums2.
//Their dot product is (3*7) = 21.
//Example 3:
//Input: nums1 = [-1,-1], nums2 = [1,1]
//Output: -1
//Explanation: Take subsequence [-1] from nums1 and subsequence [1] from nums2.
//Their dot product is -1.
// 
//Constraints:
//	1 <= nums1.length, nums2.length <= 500
//	-1000 <= nums1[i], nums2[i] <= 1000
int maxDotProduct(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    // DP table to store the maximum dot product at each position
    int dp[nums1Size + 1][nums2Size + 1];
    
    // Initialize the DP table with a large negative number
    for (int i = 0; i <= nums1Size; i++) {
        for (int j = 0; j <= nums2Size; j++) {
            dp[i][j] = INT_MIN;
        }
    }
    
    // Start from the first element and calculate the maximum dot product
    for (int i = 1; i <= nums1Size; i++) {
        for (int j = 1; j <= nums2Size; j++) {
            // Calculate the maximum dot product by considering the current element and the maximum dot product ending at the previous position
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + nums1[i - 1] * nums2[j - 1];
        }
    }
    
    // Return the maximum dot product found in the DP table
    return dp[nums1Size][nums2Size];
    
}