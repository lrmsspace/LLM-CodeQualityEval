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
        int mod = 1e9 + 7;
        int n = arr.size();
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
        }
        long long maxSum = 0;
        long long curSum = 0;
        for (int i = 0; i < 2 * n; i++) {
            curSum = max((long long)0, curSum + arr[i % n]);
            maxSum = max(maxSum, curSum);
        }
        if (k == 1) {
            return maxSum % mod;
        }
        long long leftSum = 0;
        long long rightSum = 0;
        long long curLeftSum = 0;
        long long curRightSum = 0;
        for (int i = 0; i < n; i++) {
            curLeftSum = max((long long)0, curLeftSum + arr[i]);
            leftSum = max(leftSum, curLeftSum);
        }
        for (int i = n - 1; i >= 0; i--) {
            curRightSum = max((long long)0, curRightSum + arr[i]);
            rightSum = max(rightSum, curRightSum);
        }
        long long ans = max(maxSum, leftSum + rightSum + max((long long)0, sum) * (k - 2));
        return ans % mod;        
    }
};