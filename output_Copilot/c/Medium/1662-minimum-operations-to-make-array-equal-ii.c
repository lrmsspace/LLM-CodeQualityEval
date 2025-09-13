/**https://leetcode.com/problems/minimum-operations-to-make-array-equal-ii/ */
//You are given two integer arrays nums1 and nums2 of equal length n and an integer k. You can perform the following operation on nums1:
//	Choose two indexes i and j and increment nums1[i] by k and decrement nums1[j] by k. In other words, nums1[i] = nums1[i] + k and nums1[j] = nums1[j] - k.
//nums1 is said to be equal to nums2 if for all indices i such that 0 <= i < n, nums1[i] == nums2[i].
//Return the minimum number of operations required to make nums1 equal to nums2. If it is impossible to make them equal, return -1.
// 
//Example 1:
//Input: nums1 = [4,3,1,4], nums2 = [1,3,7,1], k = 3
//Output: 2
//Explanation: In 2 operations, we can transform nums1 to nums2.
//1st operation: i = 2, j = 0. After applying the operation, nums1 = [1,3,4,4].
//2nd operation: i = 2, j = 3. After applying the operation, nums1 = [1,3,7,1].
//One can prove that it is impossible to make arrays equal in fewer operations.
//Example 2:
//Input: nums1 = [3,8,5,2], nums2 = [2,4,1,6], k = 1
//Output: -1
//Explanation: It can be proved that it is impossible to make the two arrays equal.
// 
//Constraints:
//	n == nums1.length == nums2.length
//	2 <= n <= 105
//	0 <= nums1[i], nums2[j] <= 109
//	0 <= k <= 105
long long minOperations(int* nums1, int nums1Size, int* nums2, int nums2Size, int k) {
    int i, j, n = nums1Size, m = nums2Size;
    int sum1 = 0, sum2 = 0;
    for (i = 0; i < n; i++) {
        sum1 += nums1[i];
    }
    for (i = 0; i < m; i++) {
        sum2 += nums2[i];
    }
    if (n > m) {
        int *tmp = nums1;
        nums1 = nums2;
        nums2 = tmp;
        int t = n;
        n = m;
        m = t;
        t = sum1;
        sum1 = sum2;
        sum2 = t;
    }
    int *diff = (int *)malloc(sizeof(int) * m);
    for (i = 0; i < m; i++) {
        diff[i] = nums2[i] - nums1[i];
    }
    qsort(diff, m, sizeof(int), cmp);
    int median = diff[m / 2];
    long long ans = 0;
    for (i = 0; i < m; i++) {
        if (diff[i] < median) {
            ans += median - diff[i];
        } else {
            ans += diff[i] - median;
        }
    }
    long long res = ans;
    for (i = 0; i < m; i++) {
        int x = nums2[i] - median;
        int y = nums1[i] + k - median;
        if (x > 0 && y > 0) {
            res = fmin(res, ans - fmax(x, y));
        }
        x = nums1[i] + median;
        y = nums2[i] - k + median;
        if (x > 0 && y > 0) {
            res = fmin(res, ans - fmax(x, y));
        }
    }
    return res;    
}