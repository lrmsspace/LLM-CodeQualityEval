/**https://leetcode.com/problems/course-schedule/ */
//There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
//	For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
//Return true if you can finish all courses. Otherwise, return false.
// 
//Example 1:
//Input: numCourses = 2, prerequisites = [[1,0]]
//Output: true
//Explanation: There are a total of 2 courses to take. 
//To take course 1 you should have finished course 0. So it is possible.
//Example 2:
//Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
//Output: false
//Explanation: There are a total of 2 courses to take. 
//To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
// 
//Constraints:
//	1 <= numCourses <= 2000
//	0 <= prerequisites.length <= 5000
//	prerequisites[i].length == 2
//	0 <= ai, bi < numCourses
//	All the pairs prerequisites[i] are unique.
bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize){
    int* indegree = (int*)malloc(sizeof(int) * numCourses);
    memset(indegree, 0, sizeof(int) * numCourses);
    for (int i = 0; i < prerequisitesSize; i++) {
        indegree[prerequisites[i][0]]++;
    }
    int* queue = (int*)malloc(sizeof(int) * numCourses);
    int head = 0, tail = 0;
    for (int i = 0; i < numCourses; i++) {
        if (indegree[i] == 0) {
            queue[tail++] = i;
        }
    }
    while (head < tail) {
        int cur = queue[head++];
        for (int i = 0; i < prerequisitesSize; i++) {
            if (prerequisites[i][1] == cur) {
                indegree[prerequisites[i][0]]--;
                if (indegree[prerequisites[i][0]] == 0) {
                    queue[tail++]= prerequisites[i][0];
                }
            }
        }
    }
    return head == numCourses;
}