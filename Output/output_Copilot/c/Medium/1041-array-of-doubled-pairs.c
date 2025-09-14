/**https://leetcode.com/problems/array-of-doubled-pairs/ */
//Given an integer array of even length arr, return true if it is possible to reorder arr such that arr[2 * i + 1] = 2 * arr[2 * i] for every 0 <= i < len(arr) / 2, or false otherwise.
// 
//Example 1:
//Input: arr = [3,1,3,6]
//Output: false
//Example 2:
//Input: arr = [2,1,2,6]
//Output: false
//Example 3:
//Input: arr = [4,-2,2,-4]
//Output: true
//Explanation: We can take two groups, [-2,-4] and [2,4] to form [-2,-4,2,4] or [2,4,-2,-4].
// 
//Constraints:
//	2 <= arr.length <= 3 * 104
//	arr.length is even.
//	-105 <= arr[i] <= 105
bool canReorderDoubled(int* arr, int arrSize) {
    int i, j, k, n = 0, m = 0;
    int *a = (int *)malloc(sizeof(int) * arrSize);
    int *b = (int *)malloc(sizeof(int) * arrSize);
    for (i = 0; i < arrSize; i++) {
        if (arr[i] < 0) {
            a[n++] = arr[i];
        } else {
            b[m++] = arr[i];
        }
    }
    if (n % 2 != 0 || m % 2 != 0) {
        return false;
    }
    qsort(a, n, sizeof(int), cmp);
    qsort(b, m, sizeof(int), cmp);
    for (i = 0; i < n; i++) {
        if (a[i] == 0) {
            continue;
        }
        for (j = 0; j < n; j++) {
            if (a[j] == 0) {
                continue;
            }
            if (a[i] == 2 * a[j]) {
                a[i] = 0;
                a[j] = 0;
                break;
            }
        }
        if (j == n) {
            return false;
        }
    }
    for (i = 0; i < m; i++) {
        if (b[i] == 0) {
            continue;
        }
        for (j = 0; j < m; j++) {
            if (b[j] == 0) {
                continue;
            }
            if (b[i] == 2 * b[j]) {
                b[i] = 0;
                b[j] = 0;
                break;
            }
        }
        if (j == m) {
            return false;
        }
    }
    return true;    
}