/**https://leetcode.com/problems/minimum-number-of-work-sessions-to-finish-the-tasks/ */
//There are n tasks assigned to you. The task times are represented as an integer array tasks of length n, where the ith task takes tasks[i] hours to finish. A work session is when you work for at most sessionTime consecutive hours and then take a break.
//You should finish the given tasks in a way that satisfies the following conditions:
//	If you start a task in a work session, you must complete it in the same work session.
//	You can start a new task immediately after finishing the previous one.
//	You may complete the tasks in any order.
//Given tasks and sessionTime, return the minimum number of work sessions needed to finish all the tasks following the conditions above.
//The tests are generated such that sessionTime is greater than or equal to the maximum element in tasks[i].
// 
//Example 1:
//Input: tasks = [1,2,3], sessionTime = 3
//Output: 2
//Explanation: You can finish the tasks in two work sessions.
//- First work session: finish the first and the second tasks in 1 + 2 = 3 hours.
//- Second work session: finish the third task in 3 hours.
//Example 2:
//Input: tasks = [3,1,3,1,1], sessionTime = 8
//Output: 2
//Explanation: You can finish the tasks in two work sessions.
//- First work session: finish all the tasks except the last one in 3 + 1 + 3 + 1 = 8 hours.
//- Second work session: finish the last task in 1 hour.
//Example 3:
//Input: tasks = [1,2,3,4,5], sessionTime = 15
//Output: 1
//Explanation: You can finish all the tasks in one work session.
// 
//Constraints:
//	n == tasks.length
//	1 <= n <= 14
//	1 <= tasks[i] <= 10
//	max(tasks[i]) <= sessionTime <= 15
int minSessions(int* tasks, int tasksSize, int sessionTime){
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int *a, *b, *c, *d, *e, *f, *g, *h, *i, *j, *k, *l, *m, *n, *o, *p, *q, *r, *s, *t, *u, *v, *w, *x, *y, *z;
    a = tasks;
    b = (int*)malloc(sizeof(int)*tasksSize);
    c = (int*)malloc(sizeof(int)*tasksSize);
    d = (int*)malloc(sizeof(int)*tasksSize);
    e = (int*)malloc(sizeof(int)*tasksSize);
    f = (int*)malloc(sizeof(int)*tasksSize);
    g = (int*)malloc(sizeof(int)*tasksSize);
    h =(int*)malloc(sizeof(int)*tasksSize);
    i = (int*)malloc(sizeof(int)*tasksSize);
    j = (int*)malloc(sizeof(int)*tasksSize);
    k = (int*)malloc(sizeof(int)*tasksSize);
    l = (int*)malloc(sizeof(int)*tasksSize);
    m = (int*)malloc(sizeof(int)*tasksSize);
    n = (int*)malloc(sizeof(int)*tasksSize);
    o = (int*)malloc(sizeof(int)*tasksSize);
    p = (int*)malloc(sizeof(int)*tasksSize);
    q = (int*)malloc(sizeof(int)*tasksSize);
    r = (int*)malloc(sizeof(int)*tasksSize);
    s = (int*)malloc(sizeof(int)*tasksSize);
    t = (int*)malloc(sizeof(int)*tasksSize);
    u = (int*)malloc(sizeof(int)*tasksSize);
    v = (int*)malloc(sizeof(int)*tasksSize);
    w = (int*)malloc(sizeof(int)*tasksSize);
    x = (int*)malloc(sizeof(int)*tasksSize);
    y = (int*)malloc(sizeof(int)*tasksSize);
    z = (int*)malloc(sizeof(int)*tasksSize);
    for(i=0;i<tasksSize;i++){
        b[i] = a[i];
    }
    for(i=0;i<tasksSize;i++){
        c[i] = 0;
    }
    for(i=0;i<tasksSize;i++){   
        for(j=0;j<tasksSize;j++){
            if(b[j]>sessionTime){
                c[j]++;
                b[j] -= sessionTime;
            }
            else{
                break;
            }
        }
    }
    for(i=0;i<tasksSize;i++){
        d[i] = 0;
    }
    for(i=0;i<tasksSize;i++){
        d[i] = b[i]/sessionTime;
    }
    for(i=0;i<tasksSize;i++){
        e[i] = 0;
    }
    for(i=0;i<tasksSize;i++){
        e[i] = b[i]%sessionTime;
    }
    for(i=0;i<tasksSize;i++){
        f[i] = 0;
    }

        for(i=0;i<tasksSize;i++){
            f[i] = d[i]+c[i];
        }
        for(i=0;i<tasksSize;i++){
            g[i] = 0;
        }
        for(i=0;i<tasksSize;i++){
            g[i] = f[i]+e[i];
        }
    return g[0];
}