/**https://leetcode.com/problems/sum-of-distances/ */
//You are given a 0-indexed integer array nums. There exists an array arr of length nums.length, where arr[i] is the sum of |i - j| over all j such that nums[j] == nums[i] and j != i. If there is no such j, set arr[i] to be 0.
//Return the array arr.
// 
//Example 1:
//Input: nums = [1,3,1,1,2]
//Output: [5,0,3,4,0]
//Explanation: 
//When i = 0, nums[0] == nums[2] and nums[0] == nums[3]. Therefore, arr[0] = |0 - 2| + |0 - 3| = 5. 
//When i = 1, arr[1] = 0 because there is no other index with value 3.
//When i = 2, nums[2] == nums[0] and nums[2] == nums[3]. Therefore, arr[2] = |2 - 0| + |2 - 3| = 3. 
//When i = 3, nums[3] == nums[0] and nums[3] == nums[2]. Therefore, arr[3] = |3 - 0| + |3 - 2| = 4. 
//When i = 4, arr[4] = 0 because there is no other index with value 2. 
//Example 2:
//Input: nums = [0,5,3]
//Output: [0,0,0]
//Explanation: Since each element in nums is distinct, arr[i] = 0 for all i.
// 
//Constraints:
//	1 <= nums.length <= 105
//	0 <= nums[i] <= 109
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
long long* distance(int* nums, int numsSize, int* returnSize){
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int a[100000], b[100000], c[100000], d[100000], e[100000], f[100000], g[100000], h[100000], i[100000], j[100000], k[100000], l[100000], m[100000], n[100000], o[100000], p[100000],
    q[100000], r[100000], s[100000], t[100000], u[100000], v[100000], w[100000], x[100000], y[100000], z[100000];
    for (i = 0; i < numsSize; i++) {
        a[i] = 0;
        b[i] = 0;
        c[i] = 0;
        d[i] = 0;
        e[i] = 0;
        f[i] = 0;
        g[i] = 0;
        h[i] = 0;
        i[i] = 0;
    }
    for (i = 0; i < numsSize; i++) {
        for (j = 0; j < numsSize; j++) {
            if (nums[i] == nums[j]) {
                a[i] += j;
                b[i]++;
            }
        }
    }
    for (i = 0; i < numsSize; i++) {
        c[i] = a[i] - (b[i] * i);
    }
    for (i = 0; i < numsSize; i++) {
        for (j = 0; j < numsSize; j++) {
            if (nums[i] == nums[j]) {
                d[i] += j * j;
                e[i]++;
            }
        }
    }
    for (i = 0; i < numsSize; i++) {
        f[i] = d[i] - (e[i] * i * i);
    }
    for (i = 0; i < numsSize; i++) {
        g[i] = f[i] - (c[i] * c[i]);
    }
    for (i = 0; i < numsSize; i++) {
        h[i] = g[i] - (b[i] * c[i]);
    }
    for (i = 0; i < numsSize; i++) {
        i[i] = h[i] - (a[i] * c[i]);
    }
    for (i = 0; i < numsSize; i++) {
        j[i] = i[i] - (b[i] * c[i]);
    }
    for (i = 0; i < numsSize; i++) {
        k[i] = j[i] - (a[i] * c[i]);
    }
    for (i = 0; i < numsSize; i++) {
        l[i] = k[i] - (b[i] * c[i]);
    }
    for (i = 0; i < numsSize; i++) {
        m[i] = l[i] - (a[i] * c[i]);
    }
    for (i = 0; i < numsSize; i++) {
        n[i] = m[i] - (b[i] * c[i]);
    }
    for (i = 0; i < numsSize; i++) {
        o[i] = n[i] - (a[i] * c[i]);
    }
    for (i = 0; i < numsSize; i++) {
        p[i] = o[i] - (b[i] * c[i]);
}
for (i = 0; i < numsSize; i++) {
    q[i] = p[i] - (a[i] * c[i]);
}
for (i = 0; i < numsSize; i++) {
    r[i] = q[i] - (b[i] * c[i]);
}
for (i = 0; i < numsSize; i++) {
    s[i] = r[i] - (a[i] * c[i]);
}
for (i = 0; i < numsSize; i++) {
    t[i] = s[i] - (b[i] * c[i]);
}
for (i = 0; i < numsSize; i++) {
    u[i] = t[i] - (a[i] * c[i]);
}
for (i = 0; i < numsSize; i++) {
    v[i] = u[i] - (b[i] * c[i]);
}
for (i = 0; i < numsSize; i++) {
    w[i] = v[i] - (a[i] * c[i]);
}
for (i = 0; i < numsSize; i++) {
    x[i] = w[i] - (b[i] * c[i]);
}
for (i = 0; i < numsSize; i++) {
    y[i] = x[i] - (a[i] * c[i]);
}
for (i = 0; i < numsSize; i++) {
    z[i] = y[i] - (b[i] * c[i]);
}
*returnSize = numsSize;
return z;
}