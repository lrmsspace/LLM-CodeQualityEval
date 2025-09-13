/**https://leetcode.com/problems/make-the-xor-of-all-segments-equal-to-zero/ */
//You are given an array nums​​​ and an integer k​​​​​. The XOR of a segment [left, right] where left <= right is the XOR of all the elements with indices between left and right, inclusive: nums[left] XOR nums[left+1] XOR ... XOR nums[right].
//Return the minimum number of elements to change in the array such that the XOR of all segments of size k​​​​​​ is equal to zero.
// 
//Example 1:
//Input: nums = [1,2,0,3,0], k = 1
//Output: 3
//Explanation: Modify the array from [1,2,0,3,0] to from [0,0,0,0,0].
//Example 2:
//Input: nums = [3,4,5,2,1,7,3,4,7], k = 3
//Output: 3
//Explanation: Modify the array from [3,4,5,2,1,7,3,4,7] to [3,4,7,3,4,7,3,4,7].
//Example 3:
//Input: nums = [1,2,4,1,2,5,1,2,6], k = 3
//Output: 3
//Explanation: Modify the array from [1,2,4,1,2,5,1,2,6] to [1,2,3,1,2,3,1,2,3].
// 
//Constraints:
//	1 <= k <= nums.length <= 2000
//	​​​​​​0 <= nums[i] < 210
int minChanges(int* nums, int numsSize, int k) {
    int dp[2048] = {0};
    int cnt[2048][2048] = {0};
    int i, j, l, m, n, sum, ans = 0x3f3f3f3f;
    for (i = 0; i < k; i++) {
        for (j = 0; i + j < numsSize; j += k) {
            cnt[i][nums[i + j]]++;
        }
    }
    for (i = 0; i < 2048; i++) {
        dp[i] = 0x3f3f3f3f;
    }
    dp[0] = 0;
    for (i = 0; i < k; i++) {
        sum = 0;
        for (j = 0; j < 2048; j++) {
            sum += cnt[i][j];
        }
        for (j = 0; j < 2048; j++) {
            for (l = 0; i + l < numsSize; l += k) {
                dp[j ^ nums[i + l]] = fmin(dp[j ^ nums[i + l]], dp[j] + sum - cnt[i][nums[i + l]]);
            }
        }
    }
    for (i = 0; i < 2048; i++) {
        ans = fmin(ans, dp[i]);
    }
    return ans;    
}