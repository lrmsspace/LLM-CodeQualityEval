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
class Solution {
    public int kConcatenationMaxSum(int[] arr, int k) {
        int mod = 1000000007;
        int n = arr.length;
        long sum = 0;
        long maxSum = 0;
        long maxPrefixSum = 0;
        long maxSuffixSum = 0;
        long prefixSum = 0;
        long suffixSum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            prefixSum += arr[i];
            suffixSum += arr[n - i - 1];
            maxPrefixSum = Math.max(maxPrefixSum, prefixSum);
            maxSuffixSum = Math.max(maxSuffixSum, suffixSum);
            maxSum = Math.max(maxSum, sum);
            if (prefixSum < 0) {
                prefixSum = 0;
            }
            if (suffixSum < 0) {
                suffixSum = 0;
            }
        }
        long ans = 0;
        if (k == 1) {
            ans = maxSum;
        } else {
            ans = Math.max(maxSum, maxSuffixSum + maxPrefixSum + Math.max(0, k - 2) * sum);
        }
        return (int) (ans % mod);        
    }
}