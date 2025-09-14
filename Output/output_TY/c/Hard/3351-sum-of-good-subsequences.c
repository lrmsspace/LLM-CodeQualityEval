/*
 You are given an integer array nums. A good subsequence is defined as a subsequence of nums where the absolute difference between any two consecutive elements in the subsequence is exactly 1.
 Return the sum of all possible good subsequences of nums.
 Since the answer may be very large, return it modulo 109 + 7.
 Note that a subsequence of size 1 is considered good by definition.
 Example 1:
 Input: nums = [1,2,1]
 Output: 14
 Explanation:
 Good subsequences are: [1], [2], [1], [1,2], [2,1], [1,2,1].
 The sum of elements in these subsequences is 14.
 Example 2:
 Input: nums = [3,4,5]
 Output: 40
 Explanation:
 Good subsequences are: [3], [4], [5], [3,4], [4,5], [3,4,5].
 The sum of elements in these subsequences is 40.
 Constraints:
 1 <= nums.length <= 105
 0 <= nums[i] <= 105
*/

int sumOfGoodSubsequences(int* nums, int numsSize) {
        int i, j, k, n, m, sum = 0, cnt[100001] = {0};
        for (i = 0; i < numsSize; i++) {
                cnt[nums[i]]++;
        }
        for (i = 0; i < 100001; i++) {
                if (cnt[i] == 0) continue;
                n = cnt[i];
                sum += n * (n + 1) / 2 * i;
                for (j = 2; j <= n; j++) {
                        m = j * i;
                        sum -= cnt[m] * m;
                        cnt[m] = 0; 
                }
        } 
        return sum;
}