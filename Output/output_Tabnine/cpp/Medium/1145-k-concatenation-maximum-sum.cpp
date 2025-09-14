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
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {

        int n = arr.size();
        long long prefixSum = 0, suffixSum = 0, maxSum = 0, sum = 0;
        
        for (int i = 0; i < n; ++i) {
            sum += arr[i];
            prefixSum = max(prefixSum + arr[i], arr[i]);
            suffixSum = max(suffixSum + arr[n - 1 - i], arr[n - 1 - i]);
            maxSum = max(maxSum, prefixSum);
            maxSum = max(maxSum, suffixSum);
        }
        
        if (k == 1) return maxSum % 1000000007;
        
        long long totalSum = (k - 2) * sum % 1000000007 + prefixSum + suffixSum;
        
        return max(maxSum, totalSum) % 1000000007;  // return the maximum sub-array sum modulo 109 + 7.
        
    }
};