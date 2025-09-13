/*
 You are given an array nums consisting of integers. You are also given a 2D array queries, where queries[i] = [posi, xi].
 For query i, we first set nums[posi] equal to xi, then we calculate the answer to query i which is the maximum sum of a subsequence of nums where no two adjacent elements are selected.
 Return the sum of the answers to all queries.
 Since the final answer may be very large, return it modulo 109 + 7.
 A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.
 Example 1:
 Input: nums = [3,5,9], queries = [[1,-2],[0,-3]]
 Output: 21
 Explanation:
 After the 1st query, nums = [3,-2,9] and the maximum sum of a subsequence with non-adjacent elements is 3 + 9 = 12.
 After the 2nd query, nums = [-3,-2,9] and the maximum sum of a subsequence with non-adjacent elements is 9.
 Example 2:
 Input: nums = [0,-1], queries = [[0,-5]]
 Output: 0
 Explanation:
 After the 1st query, nums = [-5,-1] and the maximum sum of a subsequence with non-adjacent elements is 0 (choosing an empty subsequence).
 Constraints:
 1 <= nums.length <= 5 * 104
 -105 <= nums[i] <= 105
 1 <= queries.length <= 5 * 104
 queries[i] == [posi, xi]
 0 <= posi <= nums.length - 1
 -105 <= xi <= 105
*/
#define MOD 1000000007

int maximumSumSubsequence(int* nums, int numsSize, int** queries, int queriesSize, int* queriesColSize) {
    long long totalSum = 0;
    for (int i = 0; i < queriesSize; i++) {
        int pos = queries[i][0];
        int val = queries[i][1];
        
        // Update the nums array
        nums[pos] = val;
        
        // Calculate maximum sum of subsequence with non-adjacent elements
        long long incl = 0, excl = 0;
        for (int j = 0; j < numsSize; j++) {
            long long new_excl = (incl > excl) ? incl : excl;
            incl = excl + (nums[j] > 0 ? nums[j] : 0);
            excl = new_excl;
        }
        
        // Add the result of this query to total sum
        totalSum = (totalSum + ((incl > excl) ? incl : excl)) % MOD;
    }
    return (int)totalSum;
}

