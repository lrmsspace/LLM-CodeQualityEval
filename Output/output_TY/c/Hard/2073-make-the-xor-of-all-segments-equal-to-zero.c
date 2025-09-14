/**https://leetcode.com/problems/make-the-xor-of-all-segments-equal-to-zero/ */
//You are given an array nums​​​ and an integer k​​​​​. The XOR of a segment [left, right] where left <= right is the XOR of all the elements with indices between left and right, inclusive: nums[left] XOR nums[left+1] XOR ... XOR nums[right].
//Return the minimum number of elements to change in the array such that the XOR of all segments of size k​​​​​​ is equal to zero.
// 
//Example 1:
//Input: nums = [1,2,0,3,0], k = 1
//Output: 3
//Explanation: Modify the array from [1,2,0,3,0] to from [0,0,0,0,0].
//Example 2:
//Input: nums = [3,4,5,2,1,7,3,4,7], k = 3
//Output: 3
//Explanation: Modify the array from [3,4,5,2,1,7,3,4,7] to [3,4,7,3,4,7,3,4,7].
//Example 3:
//Input: nums = [1,2,4,1,2,5,1,2,6], k = 3
//Output: 3
//Explanation: Modify the array from [1,2,4,1,2,5,1,2,6] to [1,2,3,1,2,3,1,2,3].
// 
//Constraints:
//	1 <= k <= nums.length <= 2000
//	​​​​​​0 <= nums[i] < 210
int minChanges(int* nums, int numsSize, int k){
    int i, j, x, y, z, n, m, a[2000], b[2000], c[2000], d[2000], e[2000], f[2000], g[2000], h[2000], t[2000], u[2000], v[2000], w[2000], x[2000], y[2000], z[2000], p[2000], q[2000], r[2000], s[2000], o[2000], l[2000],   k1, k2, k3, k4, k5, k6, k7, k8, k9, k10;
    for (i = 0; i < numsSize; i += k) a[i / k] = nums[i];
    for (i = 0; i < numsSize; i += k) b[i / k] = nums[i] ^ a[i / k];
    for (i = 0; i < numsSize; i += k) c[i / k] = nums[i] ^ b[i / k];
    for (i = 0; i < numsSize; i += k) d[i / k] = nums[i] ^ c[i / k];
    for (i = 0; i < numsSize; i += k) e[i / k] = nums[i] ^ d[i / k];
    for (i = 0; i < numsSize; i += k) f[i / k] = nums[i] ^ e[i / k];
    for (i = 0; i < numsSize; i += k) g[i / k] = nums[i] ^ f[i / k];
    for (i = 0; i < numsSize; i += k) h[i / k] = nums[i] ^ g[i / k];
    for (i = 0; i < numsSize; i += k) t[i / k] = nums[i] ^ h[i / k];
    for (i = 0; i < numsSize; i += k) u[i / k] = nums[i] ^ t[i / k];
    for (i = 0; i < numsSize; i += k) v[i / k] = nums[i] ^ u[i / k];
    for (i = 0; i < numsSize; i += k) w[i / k] = nums[i] ^ v[i / k];
    for (i = 0; i < numsSize; i += k) x[i / k] = nums[i] ^ w[i / k];
    for (i = 0; i < numsSize; i += k) y[i / k] = nums[i] ^ x[i / k];
    for (i = 0; i < numsSize; i += k) z[i / k] = nums[i] ^ y[i / k];
    for (i = 0; i < numsSize; i += k) p[i / k] = nums[i] ^ z[i / k];
    for (i = 0; i < numsSize; i += k) q[i / k] = nums[i] ^ p[i / k];
    for (i = 0; i < numsSize; i += k) r[i / k] = nums[i] ^ q[i / k];
    for (i = 0; i < numsSize; i += k) s[i / k] = nums[i] ^ r[i / k];
    for (i = 0; i < numsSize; i += k) o[i / k] = nums[i] ^ s[i / k];
    for (i = 0; i < numsSize; i += k) l[i / k] = nums[i] ^ o[i / k];
    for (i = 0; i < numsSize; i += k) k1 = a[i / k], k2 = b[i / k], k3 = c[i / k], k4 = d[i / k], k5 = e[i / k], k6 = f[i / k], k7 = g[i / k], k8 = h[i / k], k9 = t[i / k], k10 = u[i/ k];
    for (i = 0; i < numsSize; i += k) {
        n = 0;
        for (j = 0; j < k; j++) {
            n += (nums[i + j] ^ k1) +   (nums[i + j] ^ k2) +   (nums[i + j] ^ k3) +   (nums[i + j] ^ k4) +   (nums[i + j] ^ k5) +   (nums[i + j] ^ k6) +   (nums[i + j] ^ k7) +   (nums[i + j] ^ k8) +   (nums[i +j] ^ k9) +   (nums[i + j]) +   (nums[i + j] ^ k10);
            if (n > k) break;
            m = 0;
            for (x = 0; x < k; x++) {
                m += (nums[i + x] ^ k1) +   (nums[i + x] ^ k2) +   (nums[i + x] ^ k3) +   (nums[i + x] ^ k4) +   (nums[i + x] ^ k5) +   (nums[i + x] ^ k6) +   (nums[i + x] ^ k7) +   (nums[i + x] ^ k8) +   (nums[i +x] ^ k9) +   (nums[i + x])    +   (nums[i + x] ^ k10);
                if (m > k) break;
                for (y = 0; y < k; y++) {
                    z = 0;
                    for (z = 0; z < k; z++) {
                        if ((nums[i + z] ^ k1) +   (nums[i + z] ^ k2) +   (nums[i + z] ^ k3) +   (nums[i + z] ^ k4) +   (nums[i+ z] ^ k5) +   (nums[i + z] ^ k6)) +   (nums[i + z] ^ k7) +   (nums[i + z] ^ k8) +   (nums[i +z] ^ k9) +   (nums[i + z])    +   (nums[i + z] ^ k10) > k) break;
                    }
                }
            }
        }
    } 
    return 0;     
}