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
    int mod = 1000000007;
    int maxSum = 0;
    int sum = 0;
    int maxSumLeft = 0;
    int maxSumRight = 0;
    int sumLeft = 0;
    int sumRight = 0;
    for (int i = 0; i < arrSize; i++) {
        sum += arr[i];
        sumLeft += arr[i];
        sumRight += arr[arrSize - i - 1];
        if (sum < 0) {
            sum = 0;
        }
        if (sumLeft > maxSumLeft) {
            maxSumLeft = sumLeft;
        }
        if (sumRight > maxSumRight) {
            maxSumRight = sumRight;
        }
        if (sum > maxSum) {
            maxSum = sum;
        }
    }
    if (k == 1) {
        return maxSum;
    }
    int maxSum2 = maxSumLeft + maxSumRight;
    if (maxSum2 > maxSum) {
        maxSum = maxSum2;
    }
    if (sumLeft + sumRight > maxSum) {
        maxSum = sumLeft + sumRight;
    }
    if (sumLeft + sumRight + sum * (k - 2) > maxSum) {
        maxSum = sumLeft + sumRight + sum * (k - 2);
    }
    return maxSum % mod;    
}