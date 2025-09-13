/*
 You are given an array of positive integers nums.
 An array arr is called product equivalent if prod(arr) == lcm(arr) * gcd(arr), where:
 prod(arr) is the product of all elements of arr.
 gcd(arr) is the GCD of all elements of arr.
 lcm(arr) is the LCM of all elements of arr.
 Return the length of the longest product equivalent subarray of nums.
 Example 1:
 Input: nums = [1,2,1,2,1,1,1]
 Output: 5
 Explanation: 
 The longest product equivalent subarray is [1, 2, 1, 1, 1], where prod([1, 2, 1, 1, 1]) = 2, gcd([1, 2, 1, 1, 1]) = 1, and lcm([1, 2, 1, 1, 1]) = 2.
 Example 2:
 Input: nums = [2,3,4,5,6]
 Output: 3
 Explanation: 
 The longest product equivalent subarray is [3, 4, 5].
 Example 3:
 Input: nums = [1,2,3,1,4,5,1]
 Output: 5
 Constraints:
 2 <= nums.length <= 100
 1 <= nums[i] <= 10
*/

int maxLength(int* nums, int numsSize) {
    int i, j, maxLen = 0, n = numsSize;
    int* dp = (int*)malloc(n * sizeof(int));
    int* prefix = (int*)malloc(n * sizeof(int));
    int* suffix = (int*)malloc(n * sizeof(int));
    
    prefix[0] = nums[0];
    for (i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] * nums[i];
    }
    
    suffix[n - 1] = nums[n - 1];
    for (i = n - 2; i >= 0; i--) {
        suffix[i] = suffix[i + 1] * nums[i];

        for (j = i; j < n; j++) {
            dp[j] = (prefix[j] * suffix[i]) / gcd(prefix[j], suffix[i]);
            maxLen = fmax(maxLen, j - i + 1);
        }
    }
    free(dp);
    free(prefix);
    free(suffix);
    return maxLen;
    
}