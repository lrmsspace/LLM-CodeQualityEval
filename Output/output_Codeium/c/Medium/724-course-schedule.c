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
bool dfs(int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* visited, int course, int pre) {
    if (visited[pre] == 1) {
        return true;
    }
    
    if (visited[pre] == 2) {
        return false;
    }
    
    visited[pre] = 1;
    
    for (int i = 0; i < prerequisitesSize; i++) {
        if (prerequisites[i][0] == pre) {
            if (dfs(prerequisites, prerequisitesSize, prerequisitesColSize, visited, course, prerequisites[i][1])) {
                return true;
            }
        }
    }
    
    visited[pre] = 2;
    
    return false;
}
bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    int visited[numCourses];
    for (int i = 0; i < numCourses; i++) {
        visited[i] = 0;
    }
    
    for (int i = 0; i < prerequisitesSize; i++) {
        int course = prerequisites[i][0];
        int pre = prerequisites[i][1];
        
        if (visited[course] == 0) {
            if (dfs(prerequisites, prerequisitesSize, prerequisitesColSize, visited, course, pre)) {
                return false;
            }
        }
    }
    
    return true;
}   