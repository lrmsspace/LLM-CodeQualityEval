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
int minimumIncompatibility(int* nums, int numsSize, int k) {
    int n = numsSize / k;
    int dp[1 << n];
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for (int mask = 1; mask < (1 << n); mask++) {
        int cnt[16];
        memset(cnt, 0, sizeof(cnt));
        int maxNum = 0, minNum = 15;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                cnt[nums[i]]++;
                maxNum = fmax(maxNum, nums[i]);
                minNum = fmin(minNum, nums[i]);
            }
        }
        if (maxNum == minNum) {
            dp[mask] = 0;
            continue;
        }
        int sum = 0;
        for (int i = 0; i < 16; i++) {
            if (cnt[i] > 1) {
                dp[mask] = -1;
                break;
            }
            if (cnt[i] == 1) {
                sum++;
            }
        }
        if (dp[mask] == -1) {
            continue;
        }
        for (int subset = mask; subset > 0; subset = (subset - 1) & mask) {
            if (__builtin_popcount(subset) == n) {
                dp[mask] = fmin(dp[mask], dp[mask ^ subset] + maxNum - minNum);
            }
        }
    }
    int ans = dp[(1 << n) - 1];
    return ans == 0x3f3f3f3f ? -1 : ans;    
}