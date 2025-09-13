/**https://leetcode.com/problems/find-a-value-of-a-mysterious-function-closest-to-target/ */
//Winston was given the above mysterious function func. He has an integer array arr and an integer target and he wants to find the values l and r that make the value |func(arr, l, r) - target| minimum possible.
//Return the minimum possible value of |func(arr, l, r) - target|.
//Notice that func should be called with the values l and r where 0 <= l, r < arr.length.
// 
//Example 1:
//Input: arr = [9,12,3,7,15], target = 5
//Output: 2
//Explanation: Calling func with all the pairs of [l,r] = [[0,0],[1,1],[2,2],[3,3],[4,4],[0,1],[1,2],[2,3],[3,4],[0,2],[1,3],[2,4],[0,3],[1,4],[0,4]], Winston got the following results [9,12,3,7,15,8,0,3,7,0,0,3,0,0,0]. The value closest to 5 is 7 and 3, thus the minimum difference is 2.
//Example 2:
//Input: arr = [1000000,1000000,1000000], target = 1
//Output: 999999
//Explanation: Winston called the func with all possible values of [l,r] and he always got 1000000, thus the min difference is 999999.
//Example 3:
//Input: arr = [1,2,4,8,16], target = 0
//Output: 0
// 
//Constraints:
//	1 <= arr.length <= 105
//	1 <= arr[i] <= 106
//	0 <= target <= 107
int closestToTarget(int* arr, int arrSize, int target){
    int i, j, k, l, r, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int a[100000], b[100000], c[100000], d[100000], e[100000], f[100000], g[100000], h[100000], i[100000], j[100000], k[100000], l[100000], m[100000], n[100000], o[100000], p[100000]  ;
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(c, 0, sizeof(c));
    memset(d, 0, sizeof(d));
    memset(e, 0, sizeof(e));
    memset(f, 0, sizeof(f));
    memset(g, 0, sizeof(g));
    memset(h, 0, sizeof(h));
    memset(i, 0, sizeof(i));
    memset(j, 0, sizeof(j));
    memset(k, 0, sizeof(k));
    memset(l, 0, sizeof(l));
    memset(m, 0, sizeof(m));
    memset(n, 0, sizeof(n));
    memset(o, 0, sizeof(o));
    memset(p, 0, sizeof(p));
    for (i = 0; i < arrSize; i++) {
        for (j = 0; j < 32; j++) {
            if (arr[i] & (1 << j)) {
                a[j]++;
            }
        }
    }
    for (i = 0; i < arrSize; i++) {
        for (j = 0; j < 32; j++) {
            if (arr[i] & (1 << j)) {
                b[j]++;
            }
        }
    }
    for (i = 0; i < arrSize; i++) {
        for (j = 0; j < 32; j++) {
            if (arr[i] & (1 << j)) {
                c[j]++;
            }
        }
    }
    for (i = 0; i < arrSize; i++) {
        for (j = 0; j < 32; j++) {
            if (arr[i] & (1 << j)) {
                d[j]++;
            }
        }
    }
    for (i = 0; i < arrSize; i++) {
        for (j = 0; j < 32; j++) {
            if (arr[i] & (1 << j)) {
                e[j]++;
            }
        }
    }
    for (i = 0; i < arrSize; i++) {
        for (j = 0; j < 32; j++) {
            if (arr[i] & (1 << j)) {
                f[j]++;
            }
        }
    }
    for (i = 0; i < arrSize; i++) {
        for (j = 0; j < 32; j++) {
            if (arr[i] & (1 << j)) {
                g[j]++;
            }
        }
    }
    for (i = 0; i < arrSize; i++) {
        for (j = 0; j < 32; j++) {
            if (arr[i] & (1 << j)) {
                h[j]++;
            }
        }
    }
    for (i = 0; i < arrSize; i++) {
        for (j = 0; j < 32; j++) {
            if (arr[i] & (1 << j)) {
                i[j]++;
            }
        }
    }
    for (i = 0; i < arrSize; i++) {
        for (j = 0; j < 32; j++) {
            if (arr[i] & (1 << j)) {
                j[j]++;
                k[j]++;
                l[j]++;
                m[j]++;
                n[j]++;
                o[j]++;
                p[j]++;
                q[j]++;
                r[j]++;
                s[j]++;
                t[j]++;
                u[j]++;
                v[j]++;
                w[j]++;
                x[j]++;
                y[j]++;
                z[j]++;
            }
        }
    }
    return 0;
}