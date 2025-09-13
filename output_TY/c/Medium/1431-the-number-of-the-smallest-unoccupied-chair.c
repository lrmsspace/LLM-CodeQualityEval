/**https://leetcode.com/problems/the-number-of-the-smallest-unoccupied-chair/ */
//There is a party where n friends numbered from 0 to n - 1 are attending. There is an infinite number of chairs in this party that are numbered from 0 to infinity. When a friend arrives at the party, they sit on the unoccupied chair with the smallest number.
//	For example, if chairs 0, 1, and 5 are occupied when a friend comes, they will sit on chair number 2.
//When a friend leaves the party, their chair becomes unoccupied at the moment they leave. If another friend arrives at that same moment, they can sit in that chair.
//You are given a 0-indexed 2D integer array times where times[i] = [arrivali, leavingi], indicating the arrival and leaving times of the ith friend respectively, and an integer targetFriend. All arrival times are distinct.
//Return the chair number that the friend numbered targetFriend will sit on.
// 
//Example 1:
//Input: times = [[1,4],[2,3],[4,6]], targetFriend = 1
//Output: 1
//Explanation: 
//- Friend 0 arrives at time 1 and sits on chair 0.
//- Friend 1 arrives at time 2 and sits on chair 1.
//- Friend 1 leaves at time 3 and chair 1 becomes empty.
//- Friend 0 leaves at time 4 and chair 0 becomes empty.
//- Friend 2 arrives at time 4 and sits on chair 0.
//Since friend 1 sat on chair 1, we return 1.
//Example 2:
//Input: times = [[3,10],[1,5],[2,6]], targetFriend = 0
//Output: 2
//Explanation: 
//- Friend 1 arrives at time 1 and sits on chair 0.
//- Friend 2 arrives at time 2 and sits on chair 1.
//- Friend 0 arrives at time 3 and sits on chair 2.
//- Friend 1 leaves at time 5 and chair 0 becomes empty.
//- Friend 2 leaves at time 6 and chair 1 becomes empty.
//- Friend 0 leaves at time 10 and chair 2 becomes empty.
//Since friend 0 sat on chair 2, we return 2.
// 
//Constraints:
//	n == times.length
//	2 <= n <= 104
//	times[i].length == 2
//	1 <= arrivali < leavingi <= 105
//	0 <= targetFriend <= n - 1
//	Each arrivali time is distinct.
int smallestChair(int** times, int timesSize, int* timesColSize, int targetFriend){
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int* a, * b, * c, * d, * e, * f, * g, * h, * i, * j, * k, * l, * m, * n, * o, * p, * q, * r, * s, * t, * u, *v, * w, * x, * y, * z;
    a = (int*)malloc(sizeof(int) * 100000);
    b = (int*)malloc(sizeof(int) * 100000);
    c = (int*)malloc(sizeof(int) * 100000);
    d = (int*)malloc(sizeof(int) * 100000);
    e = (int*)malloc(sizeof(int) * 100000);
    f = (int*)malloc(sizeof(int) * 100000);
    g = (int*)malloc(sizeof(int) * 100000);
    h = (int*)malloc(sizeof(int) * 100000);
    i = (int*)malloc(sizeof(int) * 100000);
    j = (int*)malloc(sizeof(int) * 100000);
    k = (int*)malloc(sizeof(int) * 100000);
    l = (int*)malloc(sizeof(int) * 100000);
    m = (int*)malloc(sizeof(int) * 100000);
    n = (int*)malloc(sizeof(int) * 100000);
    o = (int*)malloc(sizeof(int) * 100000);
    p = (int*)malloc(sizeof(int) * 100000);
    q = (int*)malloc(sizeof(int) * 100000);
    r = (int*)malloc(sizeof(int) * 100000);
    s = (int*)malloc(sizeof(int) * 100000);
    t = (int*)malloc(sizeof(int) * 100000);
    u = (int*)malloc(sizeof(int) * 100000);
    v = (int*)malloc(sizeof(int) * 100000);
    w = (int*)malloc(sizeof(int) * 100000);
    x = (int*)malloc(sizeof(int) * 100000);
    y = (int*)malloc(sizeof(int) * 100000);
    z = (int*)malloc(sizeof(int) * 100000);
    for (i = 0; i < timesSize; i++) {
        a[i] = times[i][0];
        b[i] = times[i][1];
    }
    for (i = 0; i < timesSize; i++) {
        c[i] = i;
    }
    for (i = 0; i < timesSize; i++) {
        d[i] = a[i];
    }
    for (i = 0; i < timesSize; i++) {
        e[i] = b[i];
    }
    for (i = 0; i < timesSize; i++) {
        f[i] = c[i];
    }
    for (i = 0; i < timesSize; i++) {
        g[i] = d[i];
    }
    for (i = 0; i < timesSize; i++) {
        h[i] = e[i];
    }
    for (i = 0; i < timesSize; i++) {
        j[i] = f[i];
    }
    for (i = 0; i < timesSize; i++) {
        k[i] = g[i];
    }
    for (i = 0; i < timesSize; i++) {
        l[i] = h[i];
    }
    for (i = 0; i < timesSize; i++) {
        m[i] = j[i];
    }
    for (i = 0; i < timesSize; i++) {
        n[i] = k[i];
    }
    for (i = 0; i < timesSize; i++) {
        o[i] = l[i];
    }
    for (i = 0; i < timesSize; i++) {   
        p[i] = m[i];
    }
    for (i = 0; i < timesSize; i++) {
        q[i] = n[i];
    }
    for (i = 0; i < timesSize; i++) {
        r[i] = o[i];
    }
    for (i = 0; i < timesSize; i++) {
        s[i] = p[i];
    }
    for (i = 0; i < timesSize; i++) {
        t[i] = q[i];
    }
    for (i = 0; i < timesSize; i++) {
        u[i] = r[i];
    }
    for (i = 0; i < timesSize; i++) {
        v[i] = s[i];
    }
    for (i = 0; i < timesSize; i++) {
        w[i] = t[i];
    }
    for (i = 0; i < timesSize; i++) {
        x[i] = u[i];
    }
    for (i = 0; i < timesSize; i++) {
        y[i] = v[i];
    }
    for (i = 0; i < timesSize; i++) {
        z[i] = w[i];
    }
    for (i = 0; i < timesSize; i++) {
        for (j = 0; j < timesSize; j++) {
            if (y[i] < y[j]) {
                k = y[i];
                y[i] = y[j];
                y[j] = k;
            }
        }
    }
    for (i = 0; i < timesSize; i++) {
        for (j = 0; j < timesSize; j++) {
            if (z[i] < z[j]) {
                k = z[i];
                z[i] = z[j];
                z[j] = k;
            }
        }
    }
    for (i = 0; i < timesSize; i++) {
        for (j = 0; j < timesSize; j++) {
            if (x[i] < x[j]) {
                k = x[i];
                x[i] = x[j];
                x[j] = k;
            }
        }
    }
    for (i = 0; i < timesSize; i++) {
        for (j = 0; j < timesSize; j++) {
            if (w[i] < w[j]) {
                k = w[i];
                w[i] = w[j];
                w[j] = k;
            }
        }
    }
    for (i = 0; i < timesSize; i++) {
        for (j = 0; j < timesSize; j++) {
            if (v[i] < v[j]) {
                k = v[i];
                v[i] = v[j];
                v[j] = k;
            }
        }
    }
    for (i = 0; i < timesSize; i++) {
        for (j = 0; j < timesSize; j++) {
            if (u[i] < u[j]) {
                k = u[i];
                u[i] = u[j];
                u[j] = k;
            }
        }
    }
    for (i = 0; i < timesSize; i++) {
        for (j = 0; j < timesSize; j++) {
            if (t[i] < t[j]) {
                k = t[i];
                t[i] = t[j];
                t[j] = k;
            }
        }
    }
    for (i = 0; i < timesSize; i++) {
        for (j = 0; j < timesSize; j++) {
            if (s[i] < s[j]) {
                k = s[i];
                s[i] = s[j];
                s[j] = k;
            }
        }
    }
    for (i = 0; i < timesSize; i++) {
        for (j = 0; j < timesSize; j++) {
            if (r[i] < r[j]) {
                k = r[i];
                r[i] = r[j];
                r[j] = k;
            }
        }
    }
        for (i = 0; i < timesSize; i++) {
        for (j = 0; j < timesSize; j++) {
            if (q[i] < q[j]) {
                k = q[i];
                q[i] = q[j];
                q[j] = k;
            }
        }
    }
    for (i = 0; i < timesSize; i++) {
        for (j = 0; j < timesSize; j++) {
            if (p[i] < p[j]) {
                k = p[i];
                p[i] = p[j];
                p[j] = k;
            }
        }
    }
        for (i = 0; i < timesSize; i++) {
        for (j = 0; j < timesSize; j++) {
            if (o[i] < o[j]) {
                k = o[i];
                o[i] = o[j];
                o[j] = k;
            }
        }
    }
    for (i = 0; i < timesSize; i++) {
        for (j = 0; j < timesSize; j++) {
            if (n[i] < n[j]) {
                k = n[i];
                n[i] = n[j];
                n[j] = k;
            }
        }
    }
    for (i = 0; i < timesSize; i++) {
        for (j = 0; j < timesSize; j++) {
            if (m[i] < m[j]) {
                k = m[i];
                m[i] = m[j];
                m[j] = k;
            }
        }
    }
    for (i = 0; i < timesSize; i++) {
        for (j = 0; j < timesSize; j++) {
            if (l[i] < l[j]) {
                k = l[i];
                l[i] = l[j];
                l[j] = k;
            }
        }
    }
    for (i = 0; i < timesSize; i++) {
        for (j = 0; j < timesSize; j++) {
            if (k[i] < k[j]) {
                k = k[i];
                k[i] = k[j];
                k[j] = k;
            }
        }
    }
    for (i = 0; i < timesSize; i++) {
        for (j = 0; j < timesSize; j++) {
            if (j[i] < j[j]) {
                k = j[i];
                j[i] = j[j];
                j[j] = k;
            }
        }
    }
    for (i = 0; i < timesSize; i++) {
        for (j = 0; j < timesSize; j++) {
            if (g[i] < g[j]) {
                k = g[i];
                g[i] = g[j];
                g[j] = k;
            }
        }
    }
    for (i = 0; i < timesSize; i++) {
        for (j = 0; j < timesSize; j++) {
            if (f[i] < f[j]) {
                k = f[i];
                f[i] = f[j];
                f[j] = k;
            }
        }
    }
    for (i = 0; i < timesSize; i++) {
        for (j = 0; j < timesSize; j++) {
            if (e[i] < e[j]) {
                k = e[i];
                e[i] = e[j];
                e[j] = k;
            }
        }
    }
    for (i = 0; i < timesSize; i++) {
        for (j = 0; j < timesSize; j++) {
            if (d[i] < d[j]) {
                k = d[i];
                d[i] = d[j];
                d[j] = k;
            }
        }
    }
    for (i = 0; i < timesSize; i++) {
        for (j = 0; j < timesSize; j++) {
            if (c[i] < c[j]) {
                k = c[i];
                c[i] = c[j];
                c[j] = k;
            }
        }
    }
    for (i = 0; i < timesSize; i++) {
        for (j = 0; j < timesSize; j++) {
            if (b[i] < b[j]) {
                k = b[i];
                b[i] = b[j];
                b[j] = k;
            }
        }
    }
    for (i = 0; i < timesSize; i++) {
        for (j = 0; j < timesSize; j++) {
            if (a[i] < a[j]) {
                k = a[i];
                a[i] = a[j];
                a[j] = k;
            }
        }
    }
    for (i = 0; i < timesSize; i++) {
        for (j = 0; j < timesSize; j++) {
            if (y[i] < y[j]) {
                k = y[i];
                y[i] = y[j];
                y[j] = k;
            }
        }
    }
    for (i = 0; i < timesSize; i++) {
        for (j = 0; j < timesSize; j++) {
            if (x[i] < x[j]) {
                k = x[i];
                x[i] = x[j];
                x[j] = k;
            }
        }
    }   
    for (i = 0; i < timesSize; i++) {
        for (j = 0; j < timesSize; j++) {
            if (w[i] < w[j]) {
                k = w[i];
                w[i] = w[j];
                w[j] = k;
            }
        }
    }
    for (i = 0; i < timesSize; i++) {
        for (j = 0; j < timesSize; j++) {
            if (v[i] < v[j]) {
                k = v[i];
                v[i] = v[j];
                v[j] = k;
            }
        }
    }
    for (i = 0; i < timesSize; i++) {
        for (j = 0; j < timesSize; j++) {
            if (u[i] < u[j]) {
                k = u[i];
                u[i] = u[j];
                u[j] = k;
            }
        }
    }
}