/**https://leetcode.com/problems/maximum-number-of-visible-points/ */
//You are given an array points, an integer angle, and your location, where location = [posx, posy] and points[i] = [xi, yi] both denote integral coordinates on the X-Y plane.
//Initially, you are facing directly east from your position. You cannot move from your position, but you can rotate. In other words, posx and posy cannot be changed. Your field of view in degrees is represented by angle, determining how wide you can see from any given view direction. Let d be the amount in degrees that you rotate counterclockwise. Then, your field of view is the inclusive range of angles [d - angle/2, d + angle/2].
//Your browser does not support the video tag or this video format.
//You can see some set of points if, for each point, the angle formed by the point, your position, and the immediate east direction from your position is in your field of view.
//There can be multiple points at one coordinate. There may be points at your location, and you can always see these points regardless of your rotation. Points do not obstruct your vision to other points.
//Return the maximum number of points you can see.
// 
//Example 1:
//Input: points = [[2,1],[2,2],[3,3]], angle = 90, location = [1,1]
//Output: 3
//Explanation: The shaded region represents your field of view. All points can be made visible in your field of view, including [3,3] even though [2,2] is in front and in the same line of sight.
//Example 2:
//Input: points = [[2,1],[2,2],[3,4],[1,1]], angle = 90, location = [1,1]
//Output: 4
//Explanation: All points can be made visible in your field of view, including the one at your location.
//Example 3:
//Input: points = [[1,0],[2,1]], angle = 13, location = [1,1]
//Output: 1
//Explanation: You can only see one of the two points, as shown above.
// 
//Constraints:
//	1 <= points.length <= 105
//	points[i].length == 2
//	location.length == 2
//	0 <= angle < 360
//	0 <= posx, posy, xi, yi <= 100
int visiblePoints(int** points, int pointsSize, int* pointsColSize, int angle, int* location, int locationSize){
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int *a, *b, *c, *d, *e, *f, *g, *h, *i, *j, *k, *l, *m, *n, *o, *p, *q, *r, *s, *t, *u, *v, *w, *x, *y, *z;
    a = malloc(sizeof(int) * pointsSize);
    b = malloc(sizeof(int) * pointsSize);
    c = malloc(sizeof(int) * pointsSize);
    d = malloc(sizeof(int) * pointsSize);
    e = malloc(sizeof(int) * pointsSize);
    f = malloc(sizeof(int) * pointsSize);
    g = malloc(sizeof(int) * pointsSize);
    h = malloc(sizeof(int) * pointsSize);
    i = malloc(sizeof(int) * pointsSize);
    j = malloc(sizeof(int) * pointsSize);
    k = malloc(sizeof(int) * pointsSize);
    l = malloc(sizeof(int) * pointsSize);
    m = malloc(sizeof(int) * pointsSize);
    n = malloc(sizeof(int) * pointsSize);
    o = malloc(sizeof(int) * pointsSize);
    p = malloc(sizeof(int) * pointsSize);
    q = malloc(sizeof(int) * pointsSize);
    r = malloc(sizeof(int) * pointsSize);
    s = malloc(sizeof(int) * pointsSize);
    t = malloc(sizeof(int) * pointsSize);
    u = malloc(sizeof(int) * pointsSize);
    v = malloc(sizeof(int) * pointsSize);
    w = malloc(sizeof(int) * pointsSize);
    x = malloc(sizeof(int) * pointsSize);
    y = malloc(sizeof(int) * pointsSize);
    z = malloc(sizeof(int) * pointsSize);
    for (i = 0; i < pointsSize; i++) {
        a[i] = points[i][0] - location[0];
        b[i] = points[i][1] - location[1];
        c[i] = a[i] * a[i] + b[i] * b[i];
        d[i] = atan2(b[i], a[i]);
        e[i] =d[i] * 180 / 3.14159265358979323846;
    }
    qsort(d, pointsSize, sizeof(double), cmp);
    for (i = 0; i < pointsSize; i++) {
        f[i] = d[i] * 180 / 3.14159265358979323846;
    }
    for (i = 0; i < pointsSize; i++) {
        g[i] = c[i];
    }
    for (i = 0; i < pointsSize; i++) {
        h[i] = c[i];
    }
    for (i = 0; i < pointsSize; i++) {
        j[i] = c[i];
    }
    for (i = 0; i < pointsSize; i++) {
        k[i] = c[i];
    }
    for (i = 0; i < pointsSize; i++) {
        l[i] = c[i];
    }
    for (i = 0; i < pointsSize; i++) {
        m[i] = c[i];
    }
    for (i = 0; i < pointsSize; i++) {
        n[i] = c[i];
    }
    for (i = 0; i < pointsSize; i++) {
        o[i] = c[i];
    }
    for (i = 0; i < pointsSize; i++) {
        p[i] = c[i];
    }
    for (i = 0; i < pointsSize; i++) {
        q[i] = c[i];
    }
    for (i = 0; i < pointsSize; i++) {
        r[i] = c[i];
    }
    for (i = 0; i < pointsSize; i++) {
        s[i] = c[i];
    }
    for (i = 0; i < pointsSize; i++) {
        t[i] = c[i];
    }
    for (i = 0; i < pointsSize; i++) {
        u[i] = c[i];
    }
    for (i = 0; i < pointsSize; i++) {
        v[i] = c[i];
    }
    for (i = 0; i < pointsSize; i++) {
        w[i] = c[i];
    }
    for (i = 0; i < pointsSize; i++) {
        x[i] = c[i];
    }
    for (i = 0; i < pointsSize; i++) {
        y[i] = c[i];
    }
    for (i = 0; i < pointsSize; i++) {
        z[i] = c[i];
    }
    for (i = 0; i < pointsSize; i++) {
        for (j = 0; j < pointsSize; j++) {
            if (i != j) {
                if (a[i] == a[j] && b[i] == b[j]) {
                    g[i] = 0;
                    h[j] = 0;
                }
            }
        }
    }
    for (i = 0; i < pointsSize; i++) {
        for (j = 0; j < pointsSize; j++) {
            if (i != j) {
                if (a[i] == a[j] && b[i] == b[j]) {
                    j[i] = 0;
                    k[j] = 0;
                }
            }
        }
    }
    for (i = 0; i < pointsSize; i++) {
        for (j = 0; j < pointsSize; j++) {
            if (i != j) {
                if (a[i] == a[j] && b[i] == b[j]) {
                    l[i] = 0;
                    m[j] = 0;
                }
            }
        }
    }   
    for (i = 0; i < pointsSize; i++) {
        for (j = 0; j < pointsSize; j++) {
            if (i != j) {
                if (a[i] == a[j] && b[i] == b[j]) {
                    n[i] = 0;
                    o[j] = 0;
                }
            }
        }
    }
    for (i = 0; i < pointsSize; i++) {
        for (j = 0; j < pointsSize; j++) {
            if (i != j) {
                if (a[i] == a[j] && b[i] == b[j]) {
                    p[i] = 0;
                    q[j] = 0;
                }
            }
        }
    }
    for (i = 0; i < pointsSize; i++) {
        for (j = 0; j < pointsSize; j++) {
            if (i != j) {
                if (a[i] == a[j] && b[i] == b[j]) {
                    r[i] = 0;
                    s[j] = 0;
                }
            }
        }
    }
    for (i = 0; i < pointsSize; i++) {
        for (j = 0; j < pointsSize; j++) {
            if (i != j) {
                if (a[i] == a[j] && b[i] == b[j]) {
                    t[i] = 0;
                    u[j] = 0;
                }
            }
        }
    }   
    for (i = 0; i < pointsSize; i++) {
        for (j = 0; j < pointsSize; j++) {
            if (i != j) {
                if (a[i] == a[j] && b[i] == b[j]) {
                    v[i] = 0;
                    w[j] = 0;
                }
            }
        }
    }
    for (i = 0; i < pointsSize; i++) {
        for (j = 0; j < pointsSize; j++) {
            if (i != j) {
                if (a[i] == a[j] && b[i] == b[j]) {
                    x[i] = 0;
                    y[j] = 0;
                }
            }
        }
    }
    for (i = 0; i < pointsSize; i++) {
        for (j = 0; j < pointsSize; j++) {
            if (i != j) {
                if (a[i] == a[j] && b[i] == b[j]) {
                    z[i] = 0;
                    a[j] = 0;
                }
            }
        }
    }
    for (i = 0; i < pointsSize; i++) {
        if (g[i] != 0) {
            count++;
        }
    }
    for (i = 0; i < pointsSize; i++) {
        if (h[i] != 0) {
            count++;
        }
    }
    for (i = 0; i < pointsSize; i++) {
        if (j[i] != 0) {
            count++;
        }
    }
    for (i = 0; i < pointsSize; i++) {
        if (k[i] != 0) {
            count++;
        }
    }
    for (i = 0; i < pointsSize; i++) {
        if (l[i] != 0) {
            count++;
        }
    }
    for (i = 0; i < pointsSize; i++) {
        if (m[i] != 0) {
            count++;
        }
    }
    for (i = 0; i < pointsSize; i++) {
        if (n[i] != 0) {
            count++;
        }
    }
    for (i = 0; i < pointsSize; i++) {
        if (o[i] != 0) {
            count++;
        }
    }
    for (i = 0; i < pointsSize; i++) {
        if (p[i] != 0) {
            count++;
        }
    }
    for (i = 0; i < pointsSize; i++) {
        if (q[i] != 0) {
            count++;
        }
    }
    for (i = 0; i < pointsSize; i++) {
        if (r[i] != 0) {
            count++;
        }
    }
    for (i = 0; i < pointsSize; i++) {
        if (s[i] != 0) {
            count++;
        }
    }
    for (i = 0; i < pointsSize; i++) {
        if (t[i] != 0) {
            count++;
        }
    }
    for (i = 0; i < pointsSize; i++) {
        if (u[i] != 0) {
            count++;
        }
    }
    for (i = 0; i < pointsSize; i++) {
        if (v[i] != 0) {
            count++;
        }
    }
    for (i = 0; i < pointsSize; i++) {
        if (w[i] != 0) {
            count++;
        }
    }
    for (i = 0; i < pointsSize; i++) {
        if (x[i] != 0) {
            count++;
        }
    }
    for (i = 0; i < pointsSize; i++) {
        if (y[i] != 0) {
            count++;
        }
    }
    for (i = 0; i < pointsSize; i++) {
        if (z[i] != 0) {
            count++;
        }
    }
    return count;
}