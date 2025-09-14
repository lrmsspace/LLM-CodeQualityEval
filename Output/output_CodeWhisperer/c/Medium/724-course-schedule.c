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
bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    int* inDegree = (int*)malloc(sizeof(int) * numCourses);
    memset(inDegree, 0, sizeof(int) * numCourses);
    for (int i = 0; i < prerequisitesSize; i++) {
        inDegree[prerequisites[i][0]]++;
    }
    int* queue = (int*)malloc(sizeof(int) * numCourses);
    int front = 0, rear = 0;
    for (int i = 0; i < numCourses; i++) {
        if (inDegree[i] == 0) {
            queue[rear++] = i;
        }
    }
    int count = 0;
    while (front < rear) {
        int course = queue[front++];
        count++;
        for (int i = 0; i < prerequisitesSize; i++) {
            if (prerequisites[i][1] == course) {
                inDegree[prerequisites[i][0]]--;
                if (inDegree[prerequisites[i][0]] == 0) {
                    queue[rear++] = prerequisites[i][0];
                }
            }
        }
    }
    free(inDegree);
    free(queue);
    return count == numCourses;
}