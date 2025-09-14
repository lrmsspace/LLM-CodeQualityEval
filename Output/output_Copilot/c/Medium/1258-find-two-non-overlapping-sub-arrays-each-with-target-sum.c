/**https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/ */
//You are given an array of integers arr and an integer target.
//You have to find two non-overlapping sub-arrays of arr each with a sum equal target. There can be multiple answers so you have to find an answer where the sum of the lengths of the two sub-arrays is minimum.
//Return the minimum sum of the lengths of the two required sub-arrays, or return -1 if you cannot find such two sub-arrays.
// 
//Example 1:
//Input: arr = [3,2,2,4,3], target = 3
//Output: 2
//Explanation: Only two sub-arrays have sum = 3 ([3] and [3]). The sum of their lengths is 2.
//Example 2:
//Input: arr = [7,3,4,7], target = 7
//Output: 2
//Explanation: Although we have three non-overlapping sub-arrays of sum = 7 ([7], [3,4] and [7]), but we will choose the first and third sub-arrays as the sum of their lengths is 2.
//Example 3:
//Input: arr = [4,3,2,6,2,3,4], target = 6
//Output: -1
//Explanation: We have only one sub-array of sum = 6.
// 
//Constraints:
//	1 <= arr.length <= 105
//	1 <= arr[i] <= 1000
//	1 <= target <= 108
int minSumOfLengths(int* arr, int arrSize, int target) {
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int a[100001] = {0};
    int b[100001] = {0};
    int c[100001] = {0};
    int d[100001] = {0};
    int e[100001] = {0};
    int f[100001] = {0};
    int g[100001] = {0};
    int h[100001] = {0};
    int ans = 0;
    int ret = 0;
    int head = 0;
    int tail = 0;
    int queue[100001];
    for(i = 0; i < arrSize; i++) {
        a[i + 1] = a[i] + arr[i];
    }
    for(i = 0; i < arrSize; i++) {
        b[i + 1] = b[i] + arr[i];
    }
    for(i = 0; i < arrSize; i++) {
        c[i + 1] = c[i] + arr[i];
    }
    for(i = 0; i < arrSize; i++) {
        d[i + 1] = d[i] + arr[i];
    }
    for(i = 0; i < arrSize; i++) {
        e[i + 1] = e[i] + arr[i];
    }
    for(i = 0; i < arrSize; i++) {
        f[i + 1] = f[i] + arr[i];
    }
    for(i = 0; i < arrSize; i++) {
        g[i + 1] = g[i] + arr[i];
    }
    for(i = 0; i < arrSize; i++) {
        h[i + 1] = h[i] + arr[i];
    }
int minLen = 100001;
int left[100001];
for (i = 0; i < arrSize; i++) {
    left[i] = 100001;
}

for (i = 0, j = 0; i < arrSize; i++) {
    while (j < i && a[i + 1] - a[j] > target) {
        j++;
    }
    if (a[i + 1] - a[j] == target) {
        minLen = (i - j + 1 < minLen) ? i - j + 1 : minLen;
    }
    left[i] = minLen;
}

minLen = 100001;
ret = 100001;
for (i = arrSize - 1, j = arrSize - 1; i >= 0; i--) {
    while (j > i && a[j + 1] - a[i] > target) {
        j--;
    }
    if (a[j + 1] - a[i] == target) {
        minLen = (j - i + 1 < minLen) ? j - i + 1 : minLen;
    }
    if (i > 0 && left[i - 1] < 100001 && minLen < 100001) {
        ret = (left[i - 1] + minLen < ret) ? left[i - 1] + minLen : ret;
    }
}

return (ret == 100001) ? -1 : ret;
        
}