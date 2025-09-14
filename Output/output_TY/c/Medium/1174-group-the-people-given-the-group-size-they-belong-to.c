/**https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/ */
//There are n people that are split into some unknown number of groups. Each person is labeled with a unique ID from 0 to n - 1.
//You are given an integer array groupSizes, where groupSizes[i] is the size of the group that person i is in. For example, if groupSizes[1] = 3, then person 1 must be in a group of size 3.
//Return a list of groups such that each person i is in a group of size groupSizes[i].
//Each person should appear in exactly one group, and every person must be in a group. If there are multiple answers, return any of them. It is guaranteed that there will be at least one valid solution for the given input.
// 
//Example 1:
//Input: groupSizes = [3,3,3,3,3,1,3]
//Output: [[5],[0,1,2],[3,4,6]]
//Explanation: 
//The first group is [5]. The size is 1, and groupSizes[5] = 1.
//The second group is [0,1,2]. The size is 3, and groupSizes[0] = groupSizes[1] = groupSizes[2] = 3.
//The third group is [3,4,6]. The size is 3, and groupSizes[3] = groupSizes[4] = groupSizes[6] = 3.
//Other possible solutions are [[2,1,6],[5],[0,4,3]] and [[5],[0,6,2],[4,3,1]].
//Example 2:
//Input: groupSizes = [2,1,3,3,3,2]
//Output: [[1],[0,5],[2,3,4]]
// 
//Constraints:
//	groupSizes.length == n
//	1 <= n <= 500
//	1 <= groupSizes[i] <= n
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** groupThePeople(int* groupSizes, int groupSizesSize, int* returnSize, int** returnColumnSizes){
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int *a, *b, *c, *d, *e, *f, *g, *h, *i, *j, *k, *l, *m, *n, *o, *p, *q, *r, *s, *t, *u, *v, *w, *x, *y, *z;
    int **A;
    a = (int *)malloc(sizeof(int) * groupSizesSize);
    for (i = 0; i < groupSizesSize; i++) a[i] = i;
    qsort(a, groupSizesSize, sizeof(int), cmp);
    b = (int *)malloc(sizeof(int) * groupSizesSize);
    for (i = 0; i < groupSizesSize; i++) b[i] = groupSizes[a[i]];
    c = (int *)malloc(sizeof(int) * groupSizesSize);
    for (i = 0; i < groupSizesSize; i++) c[i] = 0;
    for (i = 0; i < groupSizesSize; i++) {
        c[b[i] - 1]++;
    }
    d = (int *)malloc(sizeof(int) * groupSizesSize);
    for (i = 0; i < groupSizesSize; i++) d[i] = 0;
    for (i = 0; i < groupSizesSize; i++) {
        d[b[i] - 1] += i;
    }
    e = (int *)malloc(sizeof(int) * groupSizesSize);
    for (i = 0; i < groupSizesSize; i++) e[i] = 0;
    for (i = 0; i < groupSizesSize; i++) {
        e[b[i] - 1] += b[i];
    }
    f = (int *)malloc(sizeof(int) * groupSizesSize);
    for (i = 0; i < groupSizesSize; i++) f[i] = 0;
    for (i = 0; i < groupSizesSize; i++) {
        f[b[i] - 1] += (i + 1) * b[i];
    }
    g = (int *)malloc(sizeof(int) * groupSizesSize);
    for (i = 0; i < groupSizesSize; i++) g[i] = 0;
    for (i = 0; i < groupSizesSize; i++) {
        g[b[i] - 1] += (i + 1) * (i + 1) * b[i];
    }
    h = (int *)malloc(sizeof(int) * groupSizesSize);
    for (i = 0; i < groupSizesSize; i++) h[i] = 0;
    for (i = 0; i < groupSizesSize; i++) {
        h[b[i] - 1] += (i + 1) * (i + 1) * (i + 1) * b[i];
    }
    A = (int **)malloc(sizeof(int *) * groupSizesSize);
    for (i = 0; i < groupSizesSize; i++) {
        A[i] = (int *)malloc(sizeof(int) * b[i]);
    }
    for (i = 0; i < groupSizesSize; i++) {
        for (j = 0; j < b[i]; j++) {
            A[i][j] = a[d[b[i] - 1] + j];
        }
    }
    *returnSize = groupSizesSize / e[0];
    *returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));
    for (i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = e[0];
    }
    return A;
}