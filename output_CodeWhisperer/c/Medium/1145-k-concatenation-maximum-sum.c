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
    int sum = 0, max = 0, min = 0, total = 0;
    for (int i = 0; i < arrSize; i++) {
        sum += arr[i];
        if (sum > max) max = sum;
        if (sum < min) min = sum;
        total += arr[i];
    }
    if (k == 1) return max > 0 ? max : 0;
    if (sum <= 0) return max > 0 ? (k * max) % 1000000007 : 0;
    return (max + (k - 2) * sum + (total - min)) % 1000000007;
}