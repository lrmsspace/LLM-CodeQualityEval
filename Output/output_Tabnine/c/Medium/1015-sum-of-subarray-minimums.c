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
int sumSubarrayMins(int* arr, int arrSize) {
    int MOD = 1000000007;
    int n = arrSize;
    int* left = (int*)malloc(sizeof(int) * n);
    int* right = (int*)malloc(sizeof(int) * n);
    int* stack = (int*)malloc(sizeof(int) * n);
    int top = -1;
    
    left[0] = -1;
    for (int i = 1; i < n; i++) {
        while (top >= 0 && arr[stack[top]] > arr[i]) {
            top--;
        }
        left[i] = stack[top] + 1;
        stack[++top] = i;
    }
    
    top = -1;
    right[n - 1] = n;
    for (int i = n - 2; i >= 0; i--) {
        while (top >= 0 && arr[stack[top]] >= arr[i]) {
            top--;
        }
        right[i] = stack[top] - 1;
        stack[++top] = i;
    }
    
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum = (sum + (left[i] * right[i] * arr[i]) % MOD) % MOD;
    }
    
    free(left);
    free(right);    
    free(stack);
    
    return sum;
    
}