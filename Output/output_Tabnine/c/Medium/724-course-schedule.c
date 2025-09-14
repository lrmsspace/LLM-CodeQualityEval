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
    int* indegree = new int[numCourses];
    memset(indegree, 0, sizeof(int) * numCourses);
    
    for (int i = 0; i < prerequisitesSize; ++i) {
        ++indegree[prerequisites[i][1]];
    }
    
    queue<int> q;
    for (int i = 0; i < numCourses; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    
    int count = 0;
    while (!q.empty()) {
        int course = q.front();
        q.pop();
        ++count;
        
        for (int i = 0; i < prerequisitesSize; ++i) {
            if (prerequisites[i][0] == course) {
                --indegree[prerequisites[i][1]];
                if (indegree[prerequisites[i][1]] == 0) {
                    q.push(prerequisites[i][1]);
                }
            }
        }
    }
    
    delete[] indegree;
    return count == numCourses;
    
}