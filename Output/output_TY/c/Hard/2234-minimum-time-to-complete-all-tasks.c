/**https://leetcode.com/problems/minimum-time-to-complete-all-tasks/ */
//There is a computer that can run an unlimited number of tasks at the same time. You are given a 2D integer array tasks where tasks[i] = [starti, endi, durationi] indicates that the ith task should run for a total of durationi seconds (not necessarily continuous) within the inclusive time range [starti, endi].
//You may turn on the computer only when it needs to run a task. You can also turn it off if it is idle.
//Return the minimum time during which the computer should be turned on to complete all tasks.
// 
//Example 1:
//Input: tasks = [[2,3,1],[4,5,1],[1,5,2]]
//Output: 2
//Explanation: 
//- The first task can be run in the inclusive time range [2, 2].
//- The second task can be run in the inclusive time range [5, 5].
//- The third task can be run in the two inclusive time ranges [2, 2] and [5, 5].
//The computer will be on for a total of 2 seconds.
//Example 2:
//Input: tasks = [[1,3,2],[2,5,3],[5,6,2]]
//Output: 4
//Explanation: 
//- The first task can be run in the inclusive time range [2, 3].
//- The second task can be run in the inclusive time ranges [2, 3] and [5, 5].
//- The third task can be run in the two inclusive time range [5, 6].
//The computer will be on for a total of 4 seconds.
// 
//Constraints:
//	1 <= tasks.length <= 2000
//	tasks[i].length == 3
//	1 <= starti, endi <= 2000
//	1 <= durationi <= endi - starti + 1 
int findMinimumTime(int** tasks, int tasksSize, int* tasksColSize){
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int a[2001] = {0};
    int b[2001] = {0};
    int c[2001] = {0};
    int d[2001] = {0};
    int e[2001] = {0};
    int f[2001] = {0};
    for (i = 0; i < tasksSize; i++) {
        a[tasks[i][0]]++;
        b[tasks[i][1]]++;
        c[tasks[i][0]] += tasks[i][2];
        d[tasks[i][1]] += tasks[i][2];
        e[tasks[i][0]] += tasks[i][2];
        f[tasks[i][1]] += tasks[i][2];
    }
    for (i = 1; i < 2001; i++) {
        a[i] += a[i - 1];
        b[i] += b[i - 1];
        c[i] += c[i - 1];
        d[i] += d[i - 1];
        e[i] += e[i - 1];
        f[i] += f[i - 1];
    }
    return a[2000] + b[2000] - c[2000] - d[2000] + e[2000] + f[2000];
}