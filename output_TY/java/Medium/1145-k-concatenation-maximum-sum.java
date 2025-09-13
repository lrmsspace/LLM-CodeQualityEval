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
        int n = arr.length;
        int[] pre = new int[n];
        int[] suf = new int[n];
        int[] preSum = new int[n];
        int[] sufSum = new int[n];
        int sum = 0;
        int maxSum = 0;
        for(int i = 0; i < n; i++){
            sum += arr[i];
            pre[i] = sum;
            maxSum = Math.max(maxSum, sum);
        }
        sum = 0;
        for(int i = n - 1; i >= 0; i--){
            sum += arr[i];
            suf[i] = sum;
        }
        for(int i = 0; i < n; i++){
            preSum[i] = Math.max(pre[i], 0);
            sufSum[i] = Math.max(suf[i], 0);
        }
        if(sum < 0){
            return maxSum;
        }else{
            int ans = maxSum;
            for(int i = 0; i < n; i++){
                ans = Math.max(ans, preSum[i] + (k - 2) * sum + sufSum[i]);
            }
            return ans % 1000000007;
        }
        if(k == 1){
            return maxSum;
        }
        return ans % 1000000007;
    }
}