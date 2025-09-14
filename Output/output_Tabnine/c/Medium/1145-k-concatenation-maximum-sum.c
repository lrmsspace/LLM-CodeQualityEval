/**https://leetcode.com/problems/k-concatenation-maximum-sum/ */
//Given an integer array arr and an integer k, modify the array by repeating it k times.
//For example, if arr = [1, 2] and k = 3 then the modified array will be [1, 2, 1, 2, 1, 2].
//Return the maximum sub-array sum in the modified array. Note that the length of the sub-array can be 0 and its sum in that case is 0.
//As the answer can be very large, return the answer modulo 109 + 7.
// 
//Example 1:
//Input: arr = [1,2], k = 3
//Output: 9
//Example 2:
//Input: arr = [1,-2,1], k = 5
//Output: 2
//Example 3:
//Input: arr = [-1,-2], k = 7
//Output: 0
// 
//Constraints:
//	1 <= arr.length <= 105
//	1 <= k <= 105
//	-104 <= arr[i] <= 104
int kConcatenationMaxSum(int* arr, int arrSize, int k) {
    long long MOD = 1000000007;
    long long maxSum = 0;
    int n = arrSize;
    
    if (k == 1) {
        for (int i = 0; i < n; i++) {
            maxSum = (maxSum + arr[i]) % MOD;
        }
        return (int)maxSum;
    }
    
    long long prefixSum = 0;
    long long suffixSum = 0;
    long long maxPrefixSum = 0;
    long long maxSuffixSum = 0;
    
    for (int i = 0; i < n; i++) {
        prefixSum = (prefixSum + arr[i]) % MOD;
        maxPrefixSum = max(maxPrefixSum, prefixSum);
    }
    
    for (int i = n - 1; i >= 0; i--) {
        suffixSum = (suffixSum + arr[i]) % MOD;
        maxSuffixSum = max(maxSuffixSum, suffixSum);
    }
    
    long long totalSum = (k * (prefixSum + suffixSum) - maxPrefixSum - maxSuffixSum) % MOD;
    return (int)totalSum;
    
}