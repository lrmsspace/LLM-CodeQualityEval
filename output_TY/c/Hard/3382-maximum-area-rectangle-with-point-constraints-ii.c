/*
 There are n points on an infinite plane. You are given two integer arrays xCoord and yCoord where (xCoord[i], yCoord[i]) represents the coordinates of the ith point.
 Your task is to find the maximum area of a rectangle that:
 Can be formed using four of these points as its corners.
 Does not contain any other point inside or on its border.
 Has its edges parallel to the axes.
 Return the maximum area that you can obtain or -1 if no such rectangle is possible.
 Example 1:
 Input: xCoord = [1,1,3,3], yCoord = [1,3,1,3]
 Output: 4
 Explanation:
 We can make a rectangle with these 4 points as corners and there is no other point that lies inside or on the border. Hence, the maximum possible area would be 4.
 Example 2:
 Input: xCoord = [1,1,3,3,2], yCoord = [1,3,1,3,2]
 Output: -1
 Explanation:
 There is only one rectangle possible is with points [1,1], [1,3], [3,1] and [3,3] but [2,2] will always lie inside it. Hence, returning -1.
 Example 3:
 Input: xCoord = [1,1,3,3,1,3], yCoord = [1,3,1,3,2,2]
 Output: 2
 Explanation:
 The maximum area rectangle is formed by the points [1,3], [1,2], [3,2], [3,3], which has an area of 2. Additionally, the points [1,1], [1,2], [3,1], [3,2] also form a valid rectangle with the same area.
 Constraints:
 1 <= xCoord.length == yCoord.length <= 2 * 105
 0 <= xCoord[i], yCoord[i] <= 8 * 107
 All the given points are unique.
*/

long long maxRectangleArea(int* xCoord, int xCoordSize, int* yCoord, int yCoordSize) {
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int a[xCoordSize], b[yCoordSize], c[xCoordSize], d[yCoordSize];
    for (i = 0; i < xCoordSize; i++) {
        a[i] = xCoord[i];
        c[i] = xCoord[i];
    }
    for (i = 0; i < yCoordSize; i++) {
        b[i] = yCoord[i];
        d[i] = yCoord[i];
    }
    qsort(a, xCoordSize, sizeof(int), compare);
    qsort(b, yCoordSize, sizeof(int), compare);
    qsort(c, xCoordSize, sizeof(int), compare);
    qsort(d, yCoordSize, sizeof(int), compare);
    long long ans = 0;
    for (i = 0; i < xCoordSize; i++) {
        int x1 = a[i];
        int x2 = c[i];
        int y1 = b[0];
        int y2 = d[0];
        int j = 1;
        while (j < yCoordSize && b[j] == b[j - 1])
            j++;
        y1 = b[j - 1];
        y2 = d[j - 1];
        ans = max(ans, (long long)(x2 - x1) * (y2 - y1));
        j = 1;
        while (j < xCoordSize && a[j] == a[j - 1])
            j++;
    }
    return ans;
}