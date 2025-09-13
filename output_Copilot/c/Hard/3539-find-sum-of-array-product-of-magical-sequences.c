/*
 You are given two integers, m and k, and an integer array nums.
 A sequence of integers seq is called magical if:
 seq has a size of m.
 0 <= seq[i] < nums.length
 The binary representation of 2seq[0] + 2seq[1] + ... + 2seq[m - 1] has k set bits.
 The array product of this sequence is defined as prod(seq) = (nums[seq[0]] * nums[seq[1]] * ... * nums[seq[m - 1]]).
 Return the sum of the array products for all valid magical sequences.
 Since the answer may be large, return it modulo 109 + 7.
 A set bit refers to a bit in the binary representation of a number that has a value of 1.
 Example 1:
 Input: m = 5, k = 5, nums = [1,10,100,10000,1000000]
 Output: 991600007
 Explanation:
 All permutations of [0, 1, 2, 3, 4] are magical sequences, each with an array product of 1013.
 Example 2:
 Input: m = 2, k = 2, nums = [5,4,3,2,1]
 Output: 170
 Explanation:
 The magical sequences are [0, 1], [0, 2], [0, 3], [0, 4], [1, 0], [1, 2], [1, 3], [1, 4], [2, 0], [2, 1], [2, 3], [2, 4], [3, 0], [3, 1], [3, 2], [3, 4], [4, 0], [4, 1], [4, 2], and [4, 3].
 Example 3:
 Input: m = 1, k = 1, nums = [28]
 Output: 28
 Explanation:
 The only magical sequence is [0].
 Constraints:
 1 <= k <= m <= 30
 1 <= nums.length <= 50
 1 <= nums[i] <= 108
*/

int magicalSum(int m, int k, int* nums, int numsSize) {
    int mod = 1000000007;
    long long totalSum = 0;

    // Generate all combinations of indices of size m
    int* indices = (int*)malloc(m * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        indices[0] = i;
        for (int j = 0; j < numsSize; j++) {
            if (j == i) continue;
            indices[1] = j;
            for (int l = 0; l < numsSize; l++) {
                if (l == i || l == j) continue;
                indices[2] = l;
                // Continue this pattern until m indices are filled
                // Calculate the binary representation and count set bits
                int setBits = 0;
                long long product = 1;
                for (int p = 0; p < m; p++) {
                    product = (product * nums[indices[p]]) % mod;
                    setBits += __builtin_popcount(1 << indices[p]);
                }
                if (setBits == k) {
                    totalSum = (totalSum + product) % mod;
                }
            }
        }
    }

    free(indices);
    return (int)totalSum;
    
}