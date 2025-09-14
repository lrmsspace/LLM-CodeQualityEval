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
/**
 * @param {number} numCourses
 * @param {number[][]} prerequisites
 * @return {boolean}
 */
var canFinish = function(numCourses, prerequisites) {
    const graph = new Array(numCourses).fill(0).map(() => []);
    const indegree = new Array(numCourses).fill(0);
    
    for (const [a, b] of prerequisites) {
        graph[b].push(a);
        indegree[a]++;
    }
    
    const queue = [];
    for (let i = 0; i < numCourses; i++) {
        if (indegree[i] === 0) {
            queue.push(i);
        }
    }
    
    let count = 0;
    
    while (queue.length > 0) {
        const course = queue.shift();
        count++;
        
        for (const nextCourse of graph[course]) {
            indegree[nextCourse]--;
            if (indegree[nextCourse] === 0) {
                queue.push(nextCourse);
            }
        }
    }
    
    return count === numCourses;    
};