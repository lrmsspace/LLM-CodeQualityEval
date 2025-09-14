/**https://leetcode.com/problems/sum-of-floored-pairs/ */
//Given an integer array nums, return the sum of floor(nums[i] / nums[j]) for all pairs of indices 0 <= i, j < nums.length in the array. Since the answer may be too large, return it modulo 109 + 7.
//The floor() function returns the integer part of the division.
// 
//Example 1:
//Input: nums = [2,5,9]
//Output: 10
//Explanation:
//floor(2 / 5) = floor(2 / 9) = floor(5 / 9) = 0
//floor(2 / 2) = floor(5 / 5) = floor(9 / 9) = 1
//floor(5 / 2) = 2
//floor(9 / 2) = 4
//floor(9 / 5) = 1
//We calculate the floor of the division for every pair of indices in the array then sum them up.
//Example 2:
//Input: nums = [7,7,7,7,7,7,7]
//Output: 49
// 
//Constraints:
//	1 <= nums.length <= 105
//	1 <= nums[i] <= 105
int sumOfFlooredPairs(int* nums, int numsSize) {
    int MOD = 1000000007;
    int n = numsSize;
    long res = 0;
    
    // Count the frequency of each number
    int* freq = (int*)calloc(n + 1, sizeof(int));
    for (int i = 0; i < n; i++) {
        freq[nums[i]]++;
    }
    
    // Calculate the prefix sum of frequency
    int* prefixSum = (int*)calloc(n + 1, sizeof(int));
    prefixSum[0] = 0;
    for (int i = 1; i <= n; i++) {
        prefixSum[i] = prefixSum[i - 1] + freq[i];
    }
    
    // Calculate the result
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j *= 2) {
            res += (long)prefixSum[j] - prefixSum[i - 1];
            if (res >= MOD) {
                res -= MOD;
            }
        }
    }
    
    free(freq);
    free(prefixSum);
    
    return (int)res;
    
}