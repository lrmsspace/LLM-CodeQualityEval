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
    int mod = 1000000007;
    int *left = (int *)malloc(sizeof(int) * arrSize);
    int *right = (int *)malloc(sizeof(int) * arrSize);
    int *stack = (int *)malloc(sizeof(int) * arrSize);
    int top = -1;
    for (int i = 0; i < arrSize; i++) {
        while (top != -1 && arr[stack[top]] > arr[i]) {
            top--;
        }
        left[i] = top == -1 ? i + 1 : i - stack[top];
        stack[++top] = i;
    }
    top = -1;
    for (int i = arrSize - 1; i >= 0; i--) {
        while (top != -1 && arr[stack[top]] >= arr[i]) {
            top--;
        }
        right[i] = top == -1 ? arrSize - i : stack[top] - i;
        stack[++top] = i;
    }
    int sum = 0;
    for (int i = 0; i < arrSize; i++) {
        sum = (sum + arr[i] * left[i] * right[i]) % mod;
    }
    free(left);
    free(right);
    free(stack);
    return sum;    
}