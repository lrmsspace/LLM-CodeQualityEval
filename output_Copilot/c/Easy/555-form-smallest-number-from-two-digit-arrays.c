/**https://leetcode.com/problems/form-smallest-number-from-two-digit-arrays/ */
//Given two arrays of unique digits nums1 and nums2, return the smallest number that contains at least one digit from each array.
// 
//Example 1:
//Input: nums1 = [4,1,3], nums2 = [5,7]
//Output: 15
//Explanation: The number 15 contains the digit 1 from nums1 and the digit 5 from nums2. It can be proven that 15 is the smallest number we can have.
//Example 2:
//Input: nums1 = [3,5,2,6], nums2 = [3,1,7]
//Output: 3
//Explanation: The number 3 contains the digit 3 which exists in both arrays.
// 
//Constraints:
//	1 <= nums1.length, nums2.length <= 9
//	1 <= nums1[i], nums2[i] <= 9
//	All digits in each array are unique.
int minNumber(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int a[10] = {0};
    int b[10] = {0};
    int c[10] = {0};
    int d[10] = {0};
    int e[10] = {0};
    int f[10] = {0};
    int g[10] = {0};
    int h[10] = {0};
    int ans = 0;
    for(i = 0; i < nums1Size; i++) {
        a[nums1[i]] = 1;
    }
    for(i = 0; i < nums2Size; i++) {
        b[nums2[i]] = 1;
    }
    for(i = 1; i < 10; i++) {
        if(a[i] == 1 && b[i] == 1) {
            c[i] = 1;
        }
    }
    for(i = 1; i < 10; i++) {
        if(a[i] == 1 && b[i] == 0) {
            d[i] = 1;
        }
    }
    for(i = 1; i < 10; i++) {
        if(a[i] == 0 && b[i] == 1) {
            e[i] = 1;
        }
    }
    for(i = 1; i < 10; i++) {
        if(a[i] == 0 && b[i] == 0) {
            f[i] = 1;
        }
    }
    for(i = 1; i < 10; i++) {
        if(c[i] == 1) {
            g[i] = 1;
        }
    }
    for(i = 1; i < 10; i++) {
        if(d[i] == 1) {
            for(j = 1; j < 10; j++) {
                if(c[j] == 1) {
                    if(i < j) {
                        g[i] = 1;
                    } else {
                        g[j] = 1;
                    }
                }
            }
        }
    }
    for(i = 1; i < 10; i++) {    
        if(e[i] == 1) {
            for(j = 1; j < 10; j++) {
                if(c[j] == 1) {
                    if(i < j) {
                        g[i] = 1;
                    } else {
                        g[j] = 1;
                    }
                }
            }
        }
    }
    for(i = 1; i < 10; i++) {
        if(f[i] == 1) {
            for(j = 1; j < 10; j++) {
                if(c[j] == 1) {
                    if(i < j) {
                        g[i] = 1;
                    } else {
                        g[j] = 1;
                    }
                }
            }
        }
    }
    for(i = 1; i < 10; i++) {
        if(g[i] == 1) {
            h[i] = 1;
        }
    }
    for(i = 1; i < 10; i++) {
        if(h[i] == 1) {
            ans = ans * 10 + i;
        }
    }
    return ans;
}