/*
 You are given an integer array nums of length n, and a positive integer k.
 The power of a subsequence is defined as the minimum absolute difference between any two elements in the subsequence.
 Return the sum of powers of all subsequences of nums which have length equal to k.
 Since the answer may be large, return it modulo 109 + 7.
 Example 1:
 Input: nums = [1,2,3,4], k = 3
 Output: 4
 Explanation:
 There are 4 subsequences in nums which have length 3: [1,2,3], [1,3,4], [1,2,4], and [2,3,4]. The sum of powers is |2 - 3| + |3 - 4| + |2 - 1| + |3 - 4| = 4.
 Example 2:
 Input: nums = [2,2], k = 2
 Output: 0
 Explanation:
 The only subsequence in nums which has length 2 is [2,2]. The sum of powers is |2 - 2| = 0.
 Example 3:
 Input: nums = [4,3,-1], k = 2
 Output: 10
 Explanation:
 There are 3 subsequences in nums which have length 2: [4,3], [4,-1], and [3,-1]. The sum of powers is |4 - 3| + |4 - (-1)| + |3 - (-1)| = 10.
 Constraints:
 2 <= n == nums.length <= 50
 -108 <= nums[i] <= 108 
 2 <= k <= n
*/

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int minAbsDiff(int* arr, int size) {
    int minDiff = abs(arr[1] - arr[0]);
    for (int i = 2; i < size; ++i) {
        int diff = abs(arr[i] - arr[i - 1]);
        if (diff < minDiff) {
            minDiff = diff;
        }
    }
    return minDiff;
}

int sumOfPowers(int* nums, int numsSize, int k) {
    int mod = 1000000007;
    int sum = 0;
    qsort(nums, numsSize, sizeof(int), compare);

    // Generate all combinations of size k
    int *comb = (int *)malloc(k * sizeof(int));
    for (int i = 0; i < (1 << numsSize); ++i) {
        if (__builtin_popcount(i) == k) {
            int index = 0;
            for (int j = 0; j < numsSize; ++j) {
                if (i & (1 << j)) {
                    comb[index++] = nums[j];
                }
            }
            sum = (sum + minAbsDiff(comb, k)) % mod;
        }
    }
    free(comb);
    return sum;
}
