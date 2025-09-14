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
int minNumberOfSemesters(int n, int** relations, int relationsSize, int* relationsColSize, int k) {
        int prerequisites[1 << n];
        memset(prerequisites, 0, sizeof(prerequisites));
    
        for (int i = 0; i < relationsSize; i++) {
            int prev = relations[i][0] - 1;
            int next = relations[i][1] - 1;
            prerequisites[1 << next] |= (1 << prev);
        }

        int dp[1 << n];
        memset(dp, 0x3f, sizeof(dp));
        dp[0] = 0;

        for (int mask = 0; mask < (1 << n); mask++) {
            int available = 0;
            for (int i = 0; i < n; i++) {
                if ((mask & (1 << i)) == 0 && (mask & prerequisites[1 << i]) == prerequisites[1 << i]) {
                    available |= (1 << i);
                }
            }

            for (int subset = available; subset > 0; subset = (subset - 1) & available) {
                if (__builtin_popcount(subset) <= k) {
                    dp[mask | subset] = fmin(dp[mask | subset], dp[mask] + 1);
                }
            }
        }

        return dp[(1 << n) - 1];
}