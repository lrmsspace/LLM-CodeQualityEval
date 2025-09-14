/**https://leetcode.com/problems/sum-of-subarray-minimums/ */
//Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.
// 
//Example 1:
//Input: arr = [3,1,2,4]
//Output: 17
//Explanation: 
//Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
//Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
//Sum is 17.
//Example 2:
//Input: arr = [11,81,94,43,3]
//Output: 444
// 
//Constraints:
//	1 <= arr.length <= 3 * 104
//	1 <= arr[i] <= 3 * 104
int sumSubarrayMins(int* arr, int arrSize){
    int sum = 0;
    int mod = 1e9 + 7;
    for (int i = 0; i < arrSize; i++) {
        int left = i, right = i;
        while (left > 0 && arr[left - 1] > arr[i]) {
            left--;
        }
        while (right < arrSize - 1 && arr[right + 1] >= arr[i]) {
           right++;
        }
    }
    return sum % mod;
}