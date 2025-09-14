/**https://leetcode.com/problems/adding-two-negabinary-numbers/ */
//Given two numbers arr1 and arr2 in base -2, return the result of adding them together.
//Each number is given in array format:  as an array of 0s and 1s, from most significant bit to least significant bit.  For example, arr = [1,1,0,1] represents the number (-2)^3 + (-2)^2 + (-2)^0 = -3.  A number arr in array, format is also guaranteed to have no leading zeros: either arr == [0] or arr[0] == 1.
//Return the result of adding arr1 and arr2 in the same format: as an array of 0s and 1s with no leading zeros.
// 
//Example 1:
//Input: arr1 = [1,1,1,1,1], arr2 = [1,0,1]
//Output: [1,0,0,0,0]
//Explanation: arr1 represents 11, arr2 represents 5, the output represents 16.
//Example 2:
//Input: arr1 = [0], arr2 = [0]
//Output: [0]
//Example 3:
//Input: arr1 = [0], arr2 = [1]
//Output: [1]
// 
//Constraints:
//	1 <= arr1.length, arr2.length <= 1000
//	arr1[i] and arr2[i] are 0 or 1
//	arr1 and arr2 have no leading zeros
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* addNegabinary(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize) {
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int a[1000] = {0};
    int b[1000] = {0};
    int c[1000] = {0};
    int d[1000] = {0};
    int e[1000] = {0};
    int f[1000] = {0};
    int g[1000] = {0};
    int h[1000] = {0};
    int ans = 0;
    int *ret = (int *)malloc(sizeof(int) * 1000);
    int head = 0;
    int tail = 0;
    int queue[1000];
    for(i = 0; i < 1000; i++) {
        queue[tail] = i;
        tail++;
    }
    for(i = 0; i < arr1Size; i++) {
        a[i] = arr1[i];
    }
    for(i = 0; i < arr2Size; i++) {
        b[i] = arr2[i];
    }
    i = arr1Size - 1;
    j = arr2Size - 1;
    k = 0;
    while(i >= 0 || j >= 0 || k) {
        k += i >= 0 ? a[i--] : 0;
        k += j >= 0 ? b[j--] : 0;
        ret[head] = k & 1;
        k = -(k >> 1);
        head++;
    }
    if(head == 1 && ret[0] == 0) {
        head = 0;
    }
    *returnSize = head;
    return ret;   
}