/**https://leetcode.com/problems/minimum-cost-to-reach-destination-in-time/ */
//There is a country of n cities numbered from 0 to n - 1 where all the cities are connected by bi-directional roads. The roads are represented as a 2D integer array edges where edges[i] = [xi, yi, timei] denotes a road between cities xi and yi that takes timei minutes to travel. There may be multiple roads of differing travel times connecting the same two cities, but no road connects a city to itself.
//Each time you pass through a city, you must pay a passing fee. This is represented as a 0-indexed integer array passingFees of length n where passingFees[j] is the amount of dollars you must pay when you pass through city j.
//In the beginning, you are at city 0 and want to reach city n - 1 in maxTime minutes or less. The cost of your journey is the summation of passing fees for each city that you passed through at some moment of your journey (including the source and destination cities).
//Given maxTime, edges, and passingFees, return the minimum cost to complete your journey, or -1 if you cannot complete it within maxTime minutes.
// 
//Example 1:
//Input: maxTime = 30, edges = [[0,1,10],[1,2,10],[2,5,10],[0,3,1],[3,4,10],[4,5,15]], passingFees = [5,1,2,20,20,3]
//Output: 11
//Explanation: The path to take is 0 -> 1 -> 2 -> 5, which takes 30 minutes and has $11 worth of passing fees.
//Example 2:
//Input: maxTime = 29, edges = [[0,1,10],[1,2,10],[2,5,10],[0,3,1],[3,4,10],[4,5,15]], passingFees = [5,1,2,20,20,3]
//Output: 48
//Explanation: The path to take is 0 -> 3 -> 4 -> 5, which takes 26 minutes and has $48 worth of passing fees.
//You cannot take path 0 -> 1 -> 2 -> 5 since it would take too long.
//Example 3:
//Input: maxTime = 25, edges = [[0,1,10],[1,2,10],[2,5,10],[0,3,1],[3,4,10],[4,5,15]], passingFees = [5,1,2,20,20,3]
//Output: -1
//Explanation: There is no way to reach city 5 from city 0 within 25 minutes.
// 
//Constraints:
//	1 <= maxTime <= 1000
//	n == passingFees.length
//	2 <= n <= 1000
//	n - 1 <= edges.length <= 1000
//	0 <= xi, yi <= n - 1
//	1 <= timei <= 1000
//	1 <= passingFees[j] <= 1000 
//	The graph may contain multiple edges between two nodes.
//	The graph does not contain self loops.
int minCost(int maxTime, int** edges, int edgesSize, int* edgesColSize, int* passingFees, int passingFeesSize){
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int a[1000][1000], b[1000], c[1000], d[1000], e[1000], f[1000], g[1000], h[1000], i[1000], j[1000], k[1000], l[1000], m[1000], n[1000], o[1000], p[1000], q[1000], r[1000], s[1000], t[1000], u[1000], v[1000], w[1000], x[1000], y[1000], z[1000];
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
    memset(q, 0, sizeof(q));
    memset(r, 0, sizeof(r));
    memset(s, 0, sizeof(s));
    memset(t, 0, sizeof(t));
    memset(u, 0, sizeof(u));
    memset(v, 0, sizeof(v));
    memset(w, 0, sizeof(w));
    memset(x, 0, sizeof(x));
    memset(y, 0, sizeof(y));
    memset(z, 0, sizeof(z));
    for (i = 0; i < edgesSize; i++) {
        a[edges[i][0]][edges[i][1]] = edges[i][2];
    }
    for (i = 0; i < passingFeesSize; i++) {
        b[i] = passingFees[i];
    }
    for (i = 0; i < passingFeesSize; i++) {
        c[i] = b[i];
        d[i] = i;
        e[i] = i;
        f[i] = 0;
        g[i] = 0;
        h[i] = 0;
        i[i] = 0;
        j[i] = 0;
        k[i] = 0;
        l[i] = 0;
        m[i] = 0;
        n[i] = 0;
        o[i] = 0;
        p[i] = 0;
        q[i] = 0;
        r[i] = 0;
        s[i] = 0;
        t[i] = 0;
        u[i] = 0;
        v[i] = 0;
        w[i] = 0;
        x[i] = 0;
        y[i] = 0;
        z[i] = 0;
    }
    for (i = 0; i < passingFeesSize; i++) {
        for (j = 0; j < passingFeesSize; j++) {
            if (a[i][j] != 0) {
                if (c[i] + a[i][j] < c[j]) {
                    c[j] = c[i] + a[i][j];
                    d[j] = i;
                }
            }
        }
    }
    for (i = 0; i < passingFeesSize; i++) {
        for (j = 0; j < passingFeesSize; j++) {
            if (a[i][j] != 0) {
                if (c[i] + a[i][j] < c[j]) {
                    c[j] = c[i] + a[i][j];
                    d[j] = i;
               }
            }
        }
    }
}