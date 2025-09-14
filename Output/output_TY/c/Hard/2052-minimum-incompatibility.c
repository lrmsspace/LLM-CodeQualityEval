/**https://leetcode.com/problems/minimum-incompatibility/ */
//You are given an integer array nums​​​ and an integer k. You are asked to distribute this array into k subsets of equal size such that there are no two equal elements in the same subset.
//A subset's incompatibility is the difference between the maximum and minimum elements in that array.
//Return the minimum possible sum of incompatibilities of the k subsets after distributing the array optimally, or return -1 if it is not possible.
//A subset is a group integers that appear in the array with no particular order.
// 
//Example 1:
//Input: nums = [1,2,1,4], k = 2
//Output: 4
//Explanation: The optimal distribution of subsets is [1,2] and [1,4].
//The incompatibility is (2-1) + (4-1) = 4.
//Note that [1,1] and [2,4] would result in a smaller sum, but the first subset contains 2 equal elements.
//Example 2:
//Input: nums = [6,3,8,1,3,1,2,2], k = 4
//Output: 6
//Explanation: The optimal distribution of subsets is [1,2], [2,3], [6,8], and [1,3].
//The incompatibility is (2-1) + (3-2) + (8-6) + (3-1) = 6.
//Example 3:
//Input: nums = [5,3,3,6,3,3], k = 3
//Output: -1
//Explanation: It is impossible to distribute nums into 3 subsets where no two elements are equal in the same subset.
// 
//Constraints:
//	1 <= k <= nums.length <= 16
//	nums.length is divisible by k
//	1 <= nums[i] <= nums.length
int minimumIncompatibility(int* nums, int numsSize, int k){
    int i, j, kk, n, m, mask, mask2, mask3, mask4, mask5, mask6, mask7, mask8, mask9, mask10, mask11, mask12, mask13, mask14, mask15, mask16, mask17, mask18, mask19, mask20, mask21, mask22, mask23, mask24, mask25, mask26, mask27, mask28, mask29, mask30, mask31,mask32, mask33, mask34, mask35, mask36, mask37, mask38, mask39, mask40, mask41, mask42, mask43, mask44, mask45, mask46, mask47, mask48, mask49, mask50, mask51, mask52, mask53, mask54, mask55, mask56, mask57, mask58, mask59, mask60, mask61, mask62, mask63;
    int dp[64][64][64];
    memset(dp, -1, sizeof(dp));
    for (i = 0; i < numsSize; i++) {
        dp[1 << i][i][nums[i]] = 0;
    }
    for (kk = 2; kk <= k; kk++) {
        for (mask = 0; mask < (1 << numsSize); mask++) {
            if (__builtin_popcount(mask) != kk) {
                continue;
            }
            for (i = 0; i < numsSize; i++) {
                if ((mask & (1 << i)) == 0) {
                    continue;
               }
            }
        }
    }
    return -1;
}