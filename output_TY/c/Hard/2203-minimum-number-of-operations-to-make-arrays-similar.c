/**https://leetcode.com/problems/minimum-number-of-operations-to-make-arrays-similar/ */
//You are given two positive integer arrays nums and target, of the same length.
//In one operation, you can choose any two distinct indices i and j where 0 <= i, j < nums.length and:
//	set nums[i] = nums[i] + 2 and
//	set nums[j] = nums[j] - 2.
//Two arrays are considered to be similar if the frequency of each element is the same.
//Return the minimum number of operations required to make nums similar to target. The test cases are generated such that nums can always be similar to target.
// 
//Example 1:
//Input: nums = [8,12,6], target = [2,14,10]
//Output: 2
//Explanation: It is possible to make nums similar to target in two operations:
//- Choose i = 0 and j = 2, nums = [10,12,4].
//- Choose i = 1 and j = 2, nums = [10,14,2].
//It can be shown that 2 is the minimum number of operations needed.
//Example 2:
//Input: nums = [1,2,5], target = [4,1,3]
//Output: 1
//Explanation: We can make nums similar to target in one operation:
//- Choose i = 1 and j = 2, nums = [1,4,3].
//Example 3:
//Input: nums = [1,1,1,1,1], target = [1,1,1,1,1]
//Output: 0
//Explanation: The array nums is already similiar to target.
// 
//Constraints:
//	n == nums.length == target.length
//	1 <= n <= 105
//	1 <= nums[i], target[i] <= 106
//	It is possible to make nums similar to target.
long long makeSimilar(int* nums, int numsSize, int* target, int targetSize){
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int a[100000], b[100000], c[100000], d[100000], e[100000], f[100000], g[100000], h[100000], i[100000], j[100000], k[100000], l[100000], m[100000], n[100000], o[100000], p[100000], q[100000], r[100000], s[100000], t[100000], u[100000], v[100000], w[100000], x[100000], y[100000], z[100000];
    for (i = 0; i < numsSize; i++) {
        if (nums[i] % 2 == 0) {
            a[i] = nums[i];
        }
        else {
            b[i] = nums[i];
        }
    }
    for (i = 0; i < targetSize; i++) {
        if (target[i] % 2 == 0) {
            c[i] = target[i];
        }
        else {
            d[i] = target[i];
        }
    }
    for (i = 0; i < numsSize; i++) {
        if (nums[i] % 2 == 0) {
            e[i] = nums[i];
        }
        else {
            f[i] = nums[i];
        }
    }
    for (i = 0; i < targetSize; i++) {
        if (target[i] % 2 == 0) {
            g[i] = target[i];
        }
        else {
            h[i] = target[i];
        }
    }
    for (i = 0; i < numsSize; i++) {
        if (nums[i] % 2 == 0) {
            i[i] = nums[i];
        }
        else {
            j[i] = nums[i];
        }
    }
    for (i = 0; i < targetSize; i++) {
        if (target[i] % 2 == 0) {
            k[i] = target[i];
        }
        else {
            l[i] = target[i];
        }
    }
    for (i = 0; i < numsSize; i++) {
        if (nums[i] % 2 == 0) {
            m[i] = nums[i];
        }
        else {
            n[i] = nums[i];
        }
    }
    for (i = 0; i < targetSize; i++) {
        if (target[i] % 2 == 0) {
            o[i] = target[i];
        }
        else {
            p[i] = target[i];
        }
    }
    for (i = 0; i < numsSize; i++) {
        if (nums[i] % 2 == 0) {
            q[i] = nums[i];
        }
        else {
            r[i] = nums[i];
        }
    }
    for (i = 0; i < targetSize; i++) {
        if (target[i] % 2 == 0) {
            s[i] = target[i];
        }
        else {
            t[i] = target[i];
        }
    }
    for (i = 0; i < numsSize; i++) {
        if (nums[i] % 2 == 0) {
            u[i] = nums[i];
        }
        else {
            v[i] = nums[i];
        }
    }
    for (i = 0; i < targetSize; i++) {
        if (target[i] % 2 == 0) {
            w[i] = target[i];
        }
        else {
            x[i] = target[i];
        }
    }
    for (i = 0; i < numsSize; i++) {
        if (nums[i] % 2 == 0) {
            y[i] = nums[i];
        }
        else {
            z[i] = nums[i];
        }
    }
    return (long long)((abs(a - c) + abs(b - d)) + (abs(e - g) + abs(f - h)) + (abs(i - k) + abs(j - l)) + (abs(m - o) + abs(n - p)) + (abs(q - s) + abs(r - t)) + (abs(u - w) + abs(v - x)) + (abs(y - z) + abs(z - y)));
}