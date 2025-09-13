/**https://leetcode.com/problems/maximum-building-height/ */
//You want to build n new buildings in a city. The new buildings will be built in a line and are labeled from 1 to n.
//However, there are city restrictions on the heights of the new buildings:
//	The height of each building must be a non-negative integer.
//	The height of the first building must be 0.
//	The height difference between any two adjacent buildings cannot exceed 1.
//Additionally, there are city restrictions on the maximum height of specific buildings. These restrictions are given as a 2D integer array restrictions where restrictions[i] = [idi, maxHeighti] indicates that building idi must have a height less than or equal to maxHeighti.
//It is guaranteed that each building will appear at most once in restrictions, and building 1 will not be in restrictions.
//Return the maximum possible height of the tallest building.
// 
//Example 1:
//Input: n = 5, restrictions = [[2,1],[4,1]]
//Output: 2
//Explanation: The green area in the image indicates the maximum allowed height for each building.
//We can build the buildings with heights [0,1,2,1,2], and the tallest building has a height of 2.
//Example 2:
//Input: n = 6, restrictions = []
//Output: 5
//Explanation: The green area in the image indicates the maximum allowed height for each building.
//We can build the buildings with heights [0,1,2,3,4,5], and the tallest building has a height of 5.
//Example 3:
//Input: n = 10, restrictions = [[5,3],[2,5],[7,4],[10,3]]
//Output: 5
//Explanation: The green area in the image indicates the maximum allowed height for each building.
//We can build the buildings with heights [0,1,2,3,3,4,4,5,4,3], and the tallest building has a height of 5.
// 
//Constraints:
//	2 <= n <= 109
//	0 <= restrictions.length <= min(n - 1, 105)
//	2 <= idi <= n
//	idi is unique.
//	0 <= maxHeighti <= 109
int maxBuilding(int n, int** restrictions, int restrictionsSize, int* restrictionsColSize){
    int i, j, k, l, r, m, t, *a, *b, *c, *d, *e, *f, *g, *h, *p, *q, *r, *s, *t, *u, *v, *w, *x, *y, *z;
    a = malloc(sizeof(int) * n);
    for (i = 0; i < n; i++) a[i] = i;
    b = malloc(sizeof(int) * n);
    for (i = 0; i < n; i++) b[i] = 0;
    c = malloc(sizeof(int) * n);
    for (i = 0; i < n; i++) c[i] = 0;
    d = malloc(sizeof(int) * n);
    for (i = 0; i < n; i++) d[i] = 0;
    e = malloc(sizeof(int) * n);
    for (i = 0; i < n; i++) e[i] = 0;
    f = malloc(sizeof(int) * n);
    for (i = 0; i < n; i++) f[i] = 0;
    g = malloc(sizeof(int) * n);
    for (i = 0; i < n; i++) g[i] = 0;
    h = malloc(sizeof(int) * n);
    for (i = 0; i < n; i++) h[i] = 0;
    p = malloc(sizeof(int) * n);
    for (i = 0; i < n; i++) p[i] = 0;
    q = malloc(sizeof(int) * n);
    for (i = 0; i < n; i++) q[i] = 0;
    r = malloc(sizeof(int) * n);
    for (i = 0; i < n; i++) r[i] = 0;
    s = malloc(sizeof(int) * n);
    for (i = 0; i < n; i++) s[i] = 0;
    t = malloc(sizeof(int) * n);
    for (i = 0; i < n; i++) t[i] = 0;
    u = malloc(sizeof(int) * n);
    for (i = 0; i < n; i++) u[i] = 0;
    v = malloc(sizeof(int) * n);
    for (i = 0; i < n; i++) v[i] = 0;
    w = malloc(sizeof(int) * n);
    for (i = 0; i < n; i++) w[i] = 0;
    x = malloc(sizeof(int) * n);
    for (i = 0; i < n; i++) x[i] = 0;
    y = malloc(sizeof(int) * n);
    for (i = 0; i < n; i++) y[i] = 0;
    z = malloc(sizeof(int) * n);
    for (i = 0; i < n; i++) z[i] = 0;
    for (i = 0; i < restrictionsSize; i++) {
        j = restrictions[i][0] - 1;
        k = restrictions[i][1];
        l = restrictionsColSize[i];
        if (l == 2) {
            r[j] = k;
            s[j] = 1;
        }
        else {
            t[j] = k;
            u[j] = 1;
        }
    }
    for (i = 0; i < n; i++) {
        if (i > 0) {
            if (s[i - 1] == 0) {
                r[i] = r[i - 1];
            }
            else {
                r[i] = min(r[i], r[i - 1] + 1);
            }
        }
    }
    for (i = n - 1; i >= 0; i--) {
        if (i < n - 1) {
            if (u[i + 1] == 0) {
                t[i] = t[i + 1];
            }
            else {
                t[i] = min(t[i], t[i + 1] + 1);
            }
        }
    }
    for (i = 0; i < n; i++) {
        if (i > 0) {
            if (r[i - 1] == 0) {
                p[i] = p[i - 1];
            }
            else {
                p[i] = min(p[i], p[i - 1] + 1);
            }
        }
    }
    for (i = n - 1; i >= 0; i--) {
        if (i < n - 1) {
            if (t[i + 1] == 0) {
                q[i] = q[i + 1];
            }
            else {
                q[i] = min(q[i], q[i + 1] + 1);
            }
        }
    }
    for (i = 0; i < n; i++) {
        if (i > 0) {
            if (p[i - 1] == 0) {
                v[i] = v[i - 1];
            }
            else {
                v[i] = min(v[i], v[i - 1] + 1);
            }
        }
    }
    for (i = n - 1; i >= 0; i--) {
        if (i < n - 1) {
            if (q[i + 1] == 0) {
                w[i] = w[i + 1];
            }
            else {
                w[i] = min(w[i], w[i + 1] + 1);
            }
        }
    }
    for (i = 0; i < n; i++) {
        if (i > 0) {
            if (v[i - 1] == 0) {
                x[i] = x[i - 1];
            }
            else {
                x[i] = min(x[i], x[i - 1] + 1);
            }
        }
    }
}