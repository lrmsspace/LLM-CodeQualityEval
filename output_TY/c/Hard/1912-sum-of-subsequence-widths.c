/**https://leetcode.com/problems/sum-of-subsequence-widths/ */
//The width of a sequence is the difference between the maximum and minimum elements in the sequence.
//Given an array of integers nums, return the sum of the widths of all the non-empty subsequences of nums. Since the answer may be very large, return it modulo 109 + 7.
//A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].
// 
//Example 1:
//Input: nums = [2,1,3]
//Output: 6
//Explanation: The subsequences are [1], [2], [3], [2,1], [2,3], [1,3], [2,1,3].
//The corresponding widths are 0, 0, 0, 1, 1, 2, 2.
//The sum of these widths is 6.
//Example 2:
//Input: nums = [2]
//Output: 0
// 
//Constraints:
//	1 <= nums.length <= 105
//	1 <= nums[i] <= 105
int sumSubseqWidths(int* nums, int numsSize){
    int i, j, k, n, m, a, b, c, d, e, f, g, h, l, r, s, t, u, v, w, x, y, z;
    int sum = 0;
    int mod = 1000000007;
    int p[100001];
    int q[100001];
    for (i = 0; i < numsSize; i++) {
        p[i] = nums[i];
    }
    for (i = 0; i < numsSize; i++) {
        q[i] = nums[i];
    }
    for (i = 0; i < numsSize; i++) {
        for (j = 0; j < numsSize; j++) {
            if (p[i] > p[j]) {
                a = p[i];
                b = p[j];
                p[i] = b;
                p[j] = a;
            }
        }
    }
    for (i = 0; i < numsSize; i++) {
        for (j = 0; j < numsSize; j++) {
            if (q[i] < q[j]) {
                a = q[i];
                b = q[j];
                q[i] = b;
                q[j] = a;
            }
        }
    }
    for (i = 0; i < numsSize; i++) {
        for (j = 0; j < numsSize; j++) {
            if (p[i] - q[j] > 0) {
                sum += (p[i] - q[j]);
            }
        }
    }
    return sum % mod;
}