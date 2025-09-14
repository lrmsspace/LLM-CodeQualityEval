/**https://leetcode.com/problems/prison-cells-after-n-days/ */
//There are 8 prison cells in a row and each cell is either occupied or vacant.
//Each day, whether the cell is occupied or vacant changes according to the following rules:
//	If a cell has two adjacent neighbors that are both occupied or both vacant, then the cell becomes occupied.
//	Otherwise, it becomes vacant.
//Note that because the prison is a row, the first and the last cells in the row can't have two adjacent neighbors.
//You are given an integer array cells where cells[i] == 1 if the ith cell is occupied and cells[i] == 0 if the ith cell is vacant, and you are given an integer n.
//Return the state of the prison after n days (i.e., n such changes described above).
// 
//Example 1:
//Input: cells = [0,1,0,1,1,0,0,1], n = 7
//Output: [0,0,1,1,0,0,0,0]
//Explanation: The following table summarizes the state of the prison on each day:
//Day 0: [0, 1, 0, 1, 1, 0, 0, 1]
//Day 1: [0, 1, 1, 0, 0, 0, 0, 0]
//Day 2: [0, 0, 0, 0, 1, 1, 1, 0]
//Day 3: [0, 1, 1, 0, 0, 1, 0, 0]
//Day 4: [0, 0, 0, 0, 0, 1, 0, 0]
//Day 5: [0, 1, 1, 1, 0, 1, 0, 0]
//Day 6: [0, 0, 1, 0, 1, 1, 0, 0]
//Day 7: [0, 0, 1, 1, 0, 0, 0, 0]
//Example 2:
//Input: cells = [1,0,0,1,0,0,1,0], n = 1000000000
//Output: [0,0,1,1,1,1,1,0]
// 
//Constraints:
//	cells.length == 8
//	cells[i] is either 0 or 1.
//	1 <= n <= 109
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* prisonAfterNDays(int* cells, int cellsSize, int n, int* returnSize) {
    int i, j, k, l, m, o, p, q, r, s, t, u, v, w, x, y, z;
    int a[8] = {0};
    int b[8] = {0};
    int c[8] = {0};
    int d[8] = {0};
    int e[8] = {0};
    int f[8] = {0};
    int g[8] = {0};
    int h[8] = {0};
    int ans = 0;
    int *ret = (int *)malloc(sizeof(int) * 8);
    int head = 0;
    int tail = 0;
    int queue[256];
    for(i = 0; i < 8; i++) {
        queue[tail] = i;
        tail++;
    }
    for(i = 0; i < 8; i++) {
        a[i] = cells[i];
    }
    for(i = 0; i < n; i++) {
        for(j = 0; j < 8; j++) {
            if(j == 0 || j == 7) {
                b[j] = 0;
            } else {
                b[j] = a[j - 1] == a[j + 1];
            }
        }
        for(j = 0; j < 8; j++) {
            a[j] = b[j];
        }
        for(j = 0; j < 8; j++) {
            if(i == n - 1) {
                ret[j] = a[j];
            }
        }
    }
    *returnSize = 8;
    return ret;
}