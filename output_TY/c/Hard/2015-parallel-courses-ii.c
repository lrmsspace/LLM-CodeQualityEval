/**https://leetcode.com/problems/parallel-courses-ii/ */
//You are given an integer n, which indicates that there are n courses labeled from 1 to n. You are also given an array relations where relations[i] = [prevCoursei, nextCoursei], representing a prerequisite relationship between course prevCoursei and course nextCoursei: course prevCoursei has to be taken before course nextCoursei. Also, you are given the integer k.
//In one semester, you can take at most k courses as long as you have taken all the prerequisites in the previous semesters for the courses you are taking.
//Return the minimum number of semesters needed to take all courses. The testcases will be generated such that it is possible to take every course.
// 
//Example 1:
//Input: n = 4, relations = [[2,1],[3,1],[1,4]], k = 2
//Output: 3
//Explanation: The figure above represents the given graph.
//In the first semester, you can take courses 2 and 3.
//In the second semester, you can take course 1.
//In the third semester, you can take course 4.
//Example 2:
//Input: n = 5, relations = [[2,1],[3,1],[4,1],[1,5]], k = 2
//Output: 4
//Explanation: The figure above represents the given graph.
//In the first semester, you can only take courses 2 and 3 since you cannot take more than two per semester.
//In the second semester, you can take course 4.
//In the third semester, you can take course 1.
//In the fourth semester, you can take course 5.
// 
//Constraints:
//	1 <= n <= 15
//	1 <= k <= n
//	0 <= relations.length <= n * (n-1) / 2
//	relations[i].length == 2
//	1 <= prevCoursei, nextCoursei <= n
//	prevCoursei != nextCoursei
//	All the pairs [prevCoursei, nextCoursei] are unique.
//	The given graph is a directed acyclic graph.
int minNumberOfSemesters(int n, int** relations, int relationsSize, int* relationsColSize, int k){
    int* inDegree = (int*)malloc(sizeof(int) * n);
    int* course = (int*)malloc(sizeof(int) * n);
    int* next = (int*)malloc(sizeof(int) * n);
    int* pre = (int*)malloc(sizeof(int) * n);
    int* preNum = (int*)malloc(sizeof(int) * n);
    int* preCourse= (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        inDegree[i] = 0;
        course[i] = 0;
        next[i] = 0;
        pre[i] = 0;
        preNum[i] = 0;
        preCourse[i] = 0;
    }
    for (int i = 0; i < relationsSize; i++) {
        inDegree[relations[i][1] - 1]++;
        next[relations[i][0] - 1] |= 1 << (relations[i][1] - 1);
    }
    int* q = (int*)malloc(sizeof(int) * n);
    int qHead = 0, qTail = 0;
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            q[qTail++] = i;
        }
    }
    while (qHead < qTail) {
        int cur = q[qHead++];
        for (int i = 0; i < n; i++) {
            if (next[cur] & (1 << i)) {
                inDegree[i]--;
                if (inDegree[i] == 0) {
                    q[qTail++] = i;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (inDegree[i] > 0) {
            int j = i;
            int num = 0;
            while (j != 0) {
                int t = j & -j;
                j -= t;
                num++;
            }
            preNum[i] = num;
            preCourse[i] = j;
        }
    }
    int ans = 0;
    while (course[0] != (1 << n) - 1) {
        int cur = 0;
        int curNum = 0;
        for (int i = 0; i < n; i++) {
            if (course[i] == 0 && preNum[i] <= k && (pre[i] & course[0]) == preCourse[i]) {
                cur |= 1 << i;
                curNum++;
            }
        }
    }
    if (curNum <= k) {
        ans++;
    }
    return ans;
}