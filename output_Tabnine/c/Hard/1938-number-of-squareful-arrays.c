/**https://leetcode.com/problems/number-of-squareful-arrays/ */
//An array is squareful if the sum of every pair of adjacent elements is a perfect square.
//Given an integer array nums, return the number of permutations of nums that are squareful.
//Two permutations perm1 and perm2 are different if there is some index i such that perm1[i] != perm2[i].
// 
//Example 1:
//Input: nums = [1,17,8]
//Output: 2
//Explanation: [1,8,17] and [17,8,1] are the valid permutations.
//Example 2:
//Input: nums = [2,2,2]
//Output: 1
// 
//Constraints:
//	1 <= nums.length <= 12
//	0 <= nums[i] <= 109
int numSquarefulPerms(int* nums, int numsSize) {
    int n = numsSize;
    if (n < 4) return 0;
    
    // Sort the array in ascending order
    qsort(nums, n, sizeof(int), compare);
    
    // Create a 2D array to store the count of squareful permutations
    int dp[n][1 << n];
    memset(dp, 0, sizeof(dp));
    
    // Initialize the base case: there is only one way to arrange a single number
    for (int i = 0; i < n; i++)
        dp[i][1 << i] = 1;
    
    // Iterate through all possible subsets of numbers
    for (int mask = 1; mask < (1 << n); mask++) {
        int count = __builtin_popcount(mask); // Count the number of 1s in the current subset
        
        // Iterate through all possible pairs of adjacent numbers in the subset
        for (int i = 0; i < n - 1; i++) {
            // Check if the current pair of adjacent numbers form a squareful pair
            if (nums[i] + nums[i + 1] == (nums[mask >> i] & nums[mask >> (i + 1)])) {
                // Iterate through all possible permutations of the remaining numbers
                for (int j = i + 2; j < n; j++) {
                    // Check if the current number can be placed in the current subset
                    if ((mask & (1 << j)) == 0) {
                        // Update the count of squareful permutations
                        dp[i][mask] += dp[j][mask ^ (1 << j)];
                    }
                }
            }
        }
    }
    
    // Return the total number of squareful permutations
    int total = 0;
    for (int i = 0; i < n; i++)
        total += dp[i][(1 << n) - 1];
    return total;
    
}