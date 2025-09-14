/**https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/ */
//Given an undirected tree consisting of n vertices numbered from 0 to n-1, which has some apples in their vertices. You spend 1 second to walk over one edge of the tree. Return the minimum time in seconds you have to spend to collect all apples in the tree, starting at vertex 0 and coming back to this vertex.
//The edges of the undirected tree are given in the array edges, where edges[i] = [ai, bi] means that exists an edge connecting the vertices ai and bi. Additionally, there is a boolean array hasApple, where hasApple[i] = true means that vertex i has an apple; otherwise, it does not have any apple.
// 
//Example 1:
//Input: n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,true,false,true,true,false]
//Output: 8 
//Explanation: The figure above represents the given tree where red vertices have an apple. One optimal path to collect all apples is shown by the green arrows.  
//Example 2:
//Input: n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,true,false,false,true,false]
//Output: 6
//Explanation: The figure above represents the given tree where red vertices have an apple. One optimal path to collect all apples is shown by the green arrows.  
//Example 3:
//Input: n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,false,false,false,false,false]
//Output: 0
// 
//Constraints:
//	1 <= n <= 105
//	edges.length == n - 1
//	edges[i].length == 2
//	0 <= ai < bi <= n - 1
//	hasApple.length == n
int minTime(int n, int** edges, int edgesSize, int* edgesColSize, bool* hasApple, int hasAppleSize) {
    int* visited = (int*)malloc(sizeof(int) * n);
    memset(visited, 0, sizeof(int) * n);
    int** graph = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        graph[i] = (int*)malloc(sizeof(int) * n);
        memset(graph[i], 0, sizeof(int) * n);
    }
    for (int i = 0; i < edgesSize; i++) {
        graph[edges[i][0]][edges[i][1]] = 1;
        graph[edges[i][1]][edges[i][0]] = 1;
    }
    int* queue = (int*)malloc(sizeof(int) * n);
    int front = 0, rear = 0;
    queue[rear++] = 0;
    visited[0] = 1;
    int time = 0;
    while (front < rear) {
        int size = rear - front;
        for (int i = 0; i < size; i++) {
            int node = queue[front++];
            for (int j = 0; j < n; j++) {
                if (graph[node][j] && !visited[j]) {
                    queue[rear++] = j;
                    visited[j] = 1;
                    if (hasApple[j]) {
                        time += 2;
                    }
                }
            }
        }
    }
    return time > 0 ? time : 0;
}