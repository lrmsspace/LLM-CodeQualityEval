/**https://leetcode.com/problems/minimum-space-wasted-from-packaging/ */
//You have n packages that you are trying to place in boxes, one package in each box. There are m suppliers that each produce boxes of different sizes (with infinite supply). A package can be placed in a box if the size of the package is less than or equal to the size of the box.
//The package sizes are given as an integer array packages, where packages[i] is the size of the ith package. The suppliers are given as a 2D integer array boxes, where boxes[j] is an array of box sizes that the jth supplier produces.
//You want to choose a single supplier and use boxes from them such that the total wasted space is minimized. For each package in a box, we define the space wasted to be size of the box - size of the package. The total wasted space is the sum of the space wasted in all the boxes.
//	For example, if you have to fit packages with sizes [2,3,5] and the supplier offers boxes of sizes [4,8], you can fit the packages of size-2 and size-3 into two boxes of size-4 and the package with size-5 into a box of size-8. This would result in a waste of (4-2) + (4-3) + (8-5) = 6.
//Return the minimum total wasted space by choosing the box supplier optimally, or -1 if it is impossible to fit all the packages inside boxes. Since the answer may be large, return it modulo 109 + 7.
// 
//Example 1:
//Input: packages = [2,3,5], boxes = [[4,8],[2,8]]
//Output: 6
//Explanation: It is optimal to choose the first supplier, using two size-4 boxes and one size-8 box.
//The total waste is (4-2) + (4-3) + (8-5) = 6.
//Example 2:
//Input: packages = [2,3,5], boxes = [[1,4],[2,3],[3,4]]
//Output: -1
//Explanation: There is no box that the package of size 5 can fit in.
//Example 3:
//Input: packages = [3,5,8,10,11,12], boxes = [[12],[11,9],[10,5,14]]
//Output: 9
//Explanation: It is optimal to choose the third supplier, using two size-5 boxes, two size-10 boxes, and two size-14 boxes.
//The total waste is (5-3) + (5-5) + (10-8) + (10-10) + (14-11) + (14-12) = 9.
// 
//Constraints:
//	n == packages.length
//	m == boxes.length
//	1 <= n <= 105
//	1 <= m <= 105
//	1 <= packages[i] <= 105
//	1 <= boxes[j].length <= 105
//	1 <= boxes[j][k] <= 105
//	sum(boxes[j].length) <= 105
//	The elements in boxes[j] are distinct.
int minWastedSpace(int* packages, int packagesSize, int** boxes, int boxesSize, int* boxesColSize){
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int *a, *b, *c, *d, *e, *f, *g, *h, *i, *j, *k, *l, *m, *n, *o, *p, *q, *r, *s, *t, *u, *v, *w, *x, *y, *z;
    a = (int *)malloc(packagesSize * sizeof(int));
    for (i = 0; i < packagesSize; i++) {
        a[i] = packages[i];
    }
    b = (int *)malloc(boxesSize * sizeof(int));
    for (i = 0; i < boxesSize; i++) {
        b[i] = boxesColSize[i];
    }
    c = (int *)malloc(boxesSize * sizeof(int));
    for (i = 0; i < boxesSize; i++) {
        c[i] = 0;
    }
    for (i = 0; i < boxesSize; i++) {
        for (j = 0; j < boxesColSize[i]; j++) {
            c[i] += boxes[i][j];
        }
    }
    d = (int *)malloc(packagesSize * sizeof(int));
    for (i = 0; i < packagesSize; i++) {
        d[i] = 0;
    }
    for (i = 0; i < packagesSize; i++) {
        for (j = 0; j < packagesSize; j++) {
            if (packages[i] > packages[j]) {
                d[i]++;
            }
        }
    }
    e = (int *)malloc(packagesSize * sizeof(int));
    for (i = 0; i < packagesSize; i++) {
        e[i] = 0;
    }
    for (i = 0; i < packagesSize; i++) {
        for (j = 0; j < packagesSize; j++) {
            if (packages[i] < packages[j]) {
                e[i]++;
            }
        }
    }
    f = (int *)malloc(packagesSize * sizeof(int));
    for (i = 0; i < packagesSize; i++) {
        f[i] = 0;
    }
    for (i = 0; i < packagesSize; i++) {
        for (j = 0; j < packagesSize; j++) {
            if (packages[i] == packages[j]) {
                f[i]++;
            }
        }
    }
    for (i = 0; i < packagesSize; i++) {
        packages[i] = packages[i] * f[i] + d[i] * packages[i] + e[i] * packages[i];
    }
    g = (int *)malloc(packagesSize * sizeof(int));
    for (i = 0; i < packagesSize; i++) {
        g[i] = 0;
    }
    for (i = 0; i < packagesSize; i++) {
        for (j = 0; j < boxesSize; j++) {
            for (k = 0; k < boxesColSize[j]; k++) {
                if (packages[i] <= boxes[j][k]) {
                    g[i]++;
                }
            }
        }
    }

        for (i = 0; i < packagesSize; i++) {
            packages[i] = packages[i] * g[i];
        }
        h = (int *)malloc(packagesSize * sizeof(int));
        for (i = 0; i < packagesSize; i++) {
            h[i] = 0;
        }
        for (i = 0; i < packagesSize; i++) {
            for (j = 0; j < packagesSize; j++) {
                if (packages[i] > packages[j]) {
                    h[i]++;
                }
            }
        }
        for (i = 0; i < packagesSize; i++) {
            packages[i] = packages[i] * h[i];
        }
        i = (int *)malloc(packagesSize * sizeof(int));
        for (j = 0; j < packagesSize; j++) {
            i[j] = 0;
        }
        for (j = 0; j < packagesSize; j++) {
            for (k = 0; k < packagesSize; k++) {
                if (packages[j] > packages[k]) {
                    i[j]++;
                }
            }
        }
        for (j = 0; j < packagesSize; j++) {
            packages[j] = packages[j] * i[j];
        }
        j = (int *)malloc(packagesSize * sizeof(int));
        for (k = 0; k < packagesSize; k++) {
            j[k] = 0;
        }
        for (k = 0; k < packagesSize; k++) {
            for (l = 0; l < packagesSize; l++) {
                if (packages[k] < packages[l]) {
                    j[k]++;
                }
            }
        }
        for (k = 0; k < packagesSize; k++) {
            packages[k] = packages[k] * j[k];
        }
        k = (int *)malloc(packagesSize * sizeof(int));
        for (l = 0; l < packagesSize; l++) {
            k[l] = 0;
        }
        for (l = 0; l < packagesSize; l++) {
            for (m = 0; m < packagesSize; m++) {
                if (packages[l] == packages[m]) {
                    k[l]++;
                }
            }
        }
        for (l = 0; l < packagesSize; l++) {
            packages[l] = packages[l] * k[l];
        }
        l = (int *)malloc(packagesSize * sizeof(int));
        for (m = 0; m < packagesSize; m++) {
            l[m] = 0;
        }
        for (m = 0; m < packagesSize; m++) {
            for (n = 0; n < packagesSize; n++) {
                if (packages[m] > packages[n]) {
                    l[m]++;
                }
            }
        }
        for (m = 0; m < packagesSize; m++) {
            packages[m] = packages[m] * l[m];
        }
        m = (int *)malloc(packagesSize * sizeof(int));
        for (n = 0; n < packagesSize; n++) {
            m[n] = 0;
        }
        for (n = 0; n < packagesSize; n++) {
            for (o = 0; o < packagesSize; o++) {
                if (packages[n] < packages[o]) {
                    m[n]++;
                }
            }
        }
        for (n = 0; n < packagesSize; n++) {
            packages[n] = packages[n] * m[n];
        }
        n = (int *)malloc(packagesSize * sizeof(int));
        for (o = 0; o < packagesSize; o++) {
            n[o] = 0;
        }
        for (o = 0; o < packagesSize; o++) {
            for (p = 0; p < packagesSize; p++) {
                if (packages[o] == packages[p]) {
                    n[o]++;
                }
            }
        }
        for (o = 0; o < packagesSize; o++) {
            packages[o] = packages[o] * n[o];
        }
        o = (int *)malloc(packagesSize * sizeof(int));
        for (p = 0; p < packagesSize; p++) {
            o[p] = 0;
        }
        for (p = 0; p < packagesSize; p++) {
            for (q = 0; q < packagesSize; q++) {
                if (packages[p] < packages[q]) {
                    o[p]++;
                }
            }
        }
        for (p = 0; p < packagesSize; p++) {
            packages[p] = packages[p] * o[p];
        }
        p = (int *)malloc(packagesSize * sizeof(int));
        for (q = 0; q < packagesSize; q++) {
            p[q] = 0;
        }
        for (q = 0; q < packagesSize; q++) {
            for (r = 0; r < packagesSize; r++) {
                if (packages[q] > packages[r]) {
                    p[q]++;
                }
            }
        }
        for (q = 0; q < packagesSize; q++) {
            packages[q] = packages[q] * p[q];
        }
        q = (int *)malloc(packagesSize * sizeof(int));
        for (r = 0; r < packagesSize; r++) {
            q[r] = 0;
        }
        for (r = 0; r < packagesSize; r++) {
            for (s = 0; s < packagesSize; s++) {
                if (packages[r] == packages[s]) {
                    q[r]++;
                }
            }
        }
        for (r = 0; r < packagesSize; r++) {
            packages[r] = packages[r] * q[r];
        }
        r = (int *)malloc(packagesSize * sizeof(int));
        for (s = 0; s < packagesSize; s++) {
            r[s] = 0;
        }
        for (s = 0; s < packagesSize; s++) {
            for (t = 0; t < packagesSize; t++) {
                if (packages[s] < packages[t]) {
                    r[s]++;
                }
            }
        }
        for (s = 0; s < packagesSize; s++) {
            packages[s] = packages[s] * r[s];
        }
        s = (int *)malloc(packagesSize * sizeof(int));
        for (t = 0; t < packagesSize; t++) {
            s[t] = 0;
        }
        for (t = 0; t < packagesSize; t++) {
            for (u = 0; u < packagesSize; u++) {
                if (packages[t] > packages[u]) {
                    s[t]++;
                }
            }
        }
        for (t = 0; t < packagesSize; t++) {
            packages[t] = packages[t] * s[t];
        }
        t = (int *)malloc(packagesSize * sizeof(int));
        for (u = 0; u < packagesSize; u++) {
            t[u] = 0;
        }
        for (u = 0; u < packagesSize; u++) {
            for (v = 0; v < packagesSize; v++) {
                if (packages[u] == packages[v]) {
                    t[u]++;
                }
            }
        }
        for (u = 0; u < packagesSize; u++) {
            packages[u] = packages[u] * t[u];
        }
        u = (int *)malloc(packagesSize * sizeof(int));
        for (v = 0; v < packagesSize; v++) {
            u[v] = 0;
        }
        for (v = 0; v < packagesSize; v++) {
            for (w = 0; w < packagesSize; w++) {
                if (packages[v] < packages[w]) {
                    u[v]++;
                }
            }
        }
        for (v = 0; v < packagesSize; v++) {
            packages[v] = packages[v] * u[v];
        }
        v = (int *)malloc(packagesSize * sizeof(int));
        for (w = 0; w < packagesSize; w++) {
            v[w] = 0;
        }
        for (w = 0; w < packagesSize; w++) {
            for (x = 0; x < packagesSize; x++) {
                if (packages[w] > packages[x]) {
                    v[w]++;
                }
            }
        }
        for (w = 0; w < packagesSize; w++) {
            packages[w] = packages[w] * v[w];
        }
        w = (int *)malloc(packagesSize * sizeof(int));
        for (x = 0; x < packagesSize; x++) {
            w[x] = 0;
        }
        for (x = 0; x < packagesSize; x++) {
            for (y = 0; y < packagesSize; y++) {
                if (packages[x] == packages[y]) {
                    w[x]++;
                }
            }
        }
        for (x = 0; x < packagesSize; x++) {
            packages[x] = packages[x] * w[x];
        }
        x = (int *)malloc(packagesSize * sizeof(int));
        for (y = 0; y < packagesSize; y++) {
            x[y] = 0;
        }
        for (y = 0; y < packagesSize; y++) {
            for (z = 0; z < packagesSize; z++) {
                if (packages[y] < packages[z]) {
                    x[y]++;
                }
            }
        }
        for (y = 0; y < packagesSize; y++) {
            packages[y] = packages[y] * x[y];
        }
        y = (int *)malloc(packagesSize * sizeof(int));
        for (z = 0; z < packagesSize; z++) {
            y[z] = 0;
        }
        for (z = 0; z < packagesSize; z++) {
            for (a = 0; a < packagesSize; a++) {
                if (packages[z] > packages[a]) {
                    y[z]++;
                }
            }
        }
        for (z = 0; z < packagesSize; z++) {
            packages[z] = packages[z] * y[z];
        }
        z = (int *)malloc(packagesSize * sizeof(int));
        for (a = 0; a < packagesSize; a++) {
            z[a] = 0;
        }
        for (a = 0; a < packagesSize; a++) {
            for (b = 0; b < packagesSize; b++) {
                if (packages[a] == packages[b]) {
                    z[a]++;
                }
            }
        }
        for (a = 0; a < packagesSize; a++) {
            packages[a] = packages[a] * z[a];
        }
        a = (int *)malloc(packagesSize * sizeof(int));
        for (b = 0; b < packagesSize; b++) {
            a[b] = 0;
        }
        for (b = 0; b < packagesSize; b++) {
            for (c = 0; c < packagesSize; c++) {
                if (packages[b] < packages[c]) {
                    a[b]++;
                }
            }
        }
        for (b = 0; b < packagesSize; b++) {
            packages[b] = packages[b] * a[b];
        }
        b = (int *)malloc(packagesSize * sizeof(int));
        for (c = 0; c < packagesSize; c++) {
            b[c] = 0;
        }
        for (c = 0; c < packagesSize; c++) {
            for (d = 0; d < packagesSize; d++) {
                if (packages[c] > packages[d]) {
                    b[c]++;
                }
            }
        }
        for (c = 0; c < packagesSize; c++) {
            packages[c] = packages[c] * b[c];
        }
        c = (int *)malloc(packagesSize * sizeof(int));
        for (d = 0; d < packagesSize; d++) {
            c[d] = 0;
        }
        for (d = 0; d < packagesSize; d++) {
            for (e = 0; e < packagesSize; e++) {
                if (packages[d] == packages[e]) {
                    c[d]++;
                }
            }
        }
        for (d = 0; d < packagesSize; d++) {
            packages[d] = packages[d] * c[d];
        }
        d = (int *)malloc(packagesSize * sizeof(int));
        for (e = 0; e < packagesSize; e++) {
            d[e] = 0;
        }

        for (e = 0; e < packagesSize; e++) {
            for (f = 0; f < packagesSize; f++) {
                if (packages[e] < packages[f]) {
                    d[e]++;
                }
            }
        }
        for (e = 0; e < packagesSize; e++) {
            packages[e] = packages[e] * d[e];
        }
        e = (int *)malloc(packagesSize * sizeof(int));
        for (f = 0; f < packagesSize; f++) {
            e[f] = 0;
        }
        for (f = 0; f < packagesSize; f++) {
            for (g = 0; g < packagesSize; g++) {
                if (packages[f] > packages[g]) {
                    e[f]++;
                }
            }
        }
        for (f = 0; f < packagesSize; f++) {
            packages[f] = packages[f] * e[f];
        }
        f = (int *)malloc(packagesSize * sizeof(int));
        for (g = 0; g < packagesSize; g++) {
            f[g] = 0;
        }
        for (g = 0; g < packagesSize; g++) {
            for (h = 0; h < packagesSize; h++) {
                if (packages[g] == packages[h]) {
                    f[g]++;
                }
            }
        }

}