/**https://leetcode.com/problems/pancake-sorting/ */
//Given an array of integers arr, sort the array by performing a series of pancake flips.
//In one pancake flip we do the following steps:
//	Choose an integer k where 1 <= k <= arr.length.
//	Reverse the sub-array arr[0...k-1] (0-indexed).
//For example, if arr = [3,2,1,4] and we performed a pancake flip choosing k = 3, we reverse the sub-array [3,2,1], so arr = [1,2,3,4] after the pancake flip at k = 3.
//Return an array of the k-values corresponding to a sequence of pancake flips that sort arr. Any valid answer that sorts the array within 10 * arr.length flips will be judged as correct.
// 
//Example 1:
//Input: arr = [3,2,4,1]
//Output: [4,2,4,3]
//Explanation: 
//We perform 4 pancake flips, with k values 4, 2, 4, and 3.
//Starting state: arr = [3, 2, 4, 1]
//After 1st flip (k = 4): arr = [1, 4, 2, 3]
//After 2nd flip (k = 2): arr = [4, 1, 2, 3]
//After 3rd flip (k = 4): arr = [3, 2, 1, 4]
//After 4th flip (k = 3): arr = [1, 2, 3, 4], which is sorted.
//Example 2:
//Input: arr = [1,2,3]
//Output: []
//Explanation: The input is already sorted, so there is no need to flip anything.
//Note that other answers, such as [3, 3], would also be accepted.
// 
//Constraints:
//	1 <= arr.length <= 100
//	1 <= arr[i] <= arr.length
//	All integers in arr are unique (i.e. arr is a permutation of the integers from 1 to arr.length).
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* pancakeSort(int* arr, int arrSize, int* returnSize) {
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int a[100] = {0};
    int b[100] = {0};
    int c[100] = {0};
    int d[100] = {0};
    int e[100] = {0};
    int f[100] = {0};
    int g[100] = {0};
    int h[100] = {0};
    int ans = 0;
    int *ret = (int *)malloc(sizeof(int) * 100);
    int head = 0;
    int tail = 0;
    int queue[100];
    for(i = 0; i < arrSize; i++) {
        queue[tail] = i;
        tail++;
    }
    for(i = 0; i < arrSize; i++) {
        a[i] = arr[i];
    }
    for(i = arrSize; i > 0; i--) {
        for(j = 0; j < arrSize; j++) {
            if(a[j] == i) {
                break;
            }
        }
        if(j == i - 1) {
            continue;
        }
        if(j != 0) {
            ret[tail] = j + 1;
            tail++;
            for(k = 0; k < (j + 1) / 2; k++) {
                l = a[k];
                a[k] = a[j - k];
                a[j - k] = l;
            }
        }
        ret[tail] = i;
        tail++;
        for(k = 0; k < i / 2; k++) {
            l = a[k];
            a[k] = a[i - k - 1];
            a[i - k - 1] = l;
        }
    }
    *returnSize = tail;
    return ret;  
}