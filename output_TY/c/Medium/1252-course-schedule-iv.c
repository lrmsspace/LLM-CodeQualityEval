/**https://leetcode.com/problems/course-schedule-iv/ */
//There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course ai first if you want to take course bi.
//	For example, the pair [0, 1] indicates that you have to take course 0 before you can take course 1.
//Prerequisites can also be indirect. If course a is a prerequisite of course b, and course b is a prerequisite of course c, then course a is a prerequisite of course c.
//You are also given an array queries where queries[j] = [uj, vj]. For the jth query, you should answer whether course uj is a prerequisite of course vj or not.
//Return a boolean array answer, where answer[j] is the answer to the jth query.
// 
//Example 1:
//Input: numCourses = 2, prerequisites = [[1,0]], queries = [[0,1],[1,0]]
//Output: [false,true]
//Explanation: The pair [1, 0] indicates that you have to take course 1 before you can take course 0.
//Course 0 is not a prerequisite of course 1, but the opposite is true.
//Example 2:
//Input: numCourses = 2, prerequisites = [], queries = [[1,0],[0,1]]
//Output: [false,false]
//Explanation: There are no prerequisites, and each course is independent.
//Example 3:
//Input: numCourses = 3, prerequisites = [[1,2],[1,0],[2,0]], queries = [[1,0],[1,2]]
//Output: [true,true]
// 
//Constraints:
//	2 <= numCourses <= 100
//	0 <= prerequisites.length <= (numCourses * (numCourses - 1) / 2)
//	prerequisites[i].length == 2
//	0 <= ai, bi <= n - 1
//	ai != bi
//	All the pairs [ai, bi] are unique.
//	The prerequisites graph has no cycles.
//	1 <= queries.length <= 104
//	0 <= ui, vi <= n - 1
//	ui != vi
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* checkIfPrerequisite(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize){
    int i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z;
    int* a=(int*)malloc(sizeof(int)*numCourses*numCourses);
    bool* b=(bool*)malloc(sizeof(bool)*queriesSize);
    for(i=0;i<numCourses*numCourses;i++)a[i]=0;
    for(i=0;i<prerequisitesSize;i++){
        a[prerequisites[i][0]*numCourses+prerequisites[i][1]]=1;
    }
    for(i=0;i<numCourses;i++){
        for(j=0;j<numCourses;j++){
            for(k=0;k<numCourses;k++){
                a[j*numCourses+k]=a[j*numCourses+k]||(a[j*numCourses+i]&&a[i*numCourses+k]);
            }
        }
    }
    for(i=0;i<queriesSize;i++){
        b[i]=a[queries[i][0]*numCourses+queries[i][1]];
    }
    *returnSize=queriesSize;
    return b;
}