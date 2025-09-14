/**https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/ */
//You are given a positive integer n representing n cities numbered from 1 to n. You are also given a 2D array roads where roads[i] = [ai, bi, distancei] indicates that there is a bidirectional road between cities ai and bi with a distance equal to distancei. The cities graph is not necessarily connected.
//The score of a path between two cities is defined as the minimum distance of a road in this path.
//Return the minimum possible score of a path between cities 1 and n.
//Note:
//	A path is a sequence of roads between two cities.
//	It is allowed for a path to contain the same road multiple times, and you can visit cities 1 and n multiple times along the path.
//	The test cases are generated such that there is at least one path between 1 and n.
// 
//Example 1:
//Input: n = 4, roads = [[1,2,9],[2,3,6],[2,4,5],[1,4,7]]
//Output: 5
//Explanation: The path from city 1 to 4 with the minimum score is: 1 -> 2 -> 4. The score of this path is min(9,5) = 5.
//It can be shown that no other path has less score.
//Example 2:
//Input: n = 4, roads = [[1,2,2],[1,3,4],[3,4,7]]
//Output: 2
//Explanation: The path from city 1 to 4 with the minimum score is: 1 -> 2 -> 1 -> 3 -> 4. The score of this path is min(2,2,4,7) = 2.
// 
//Constraints:
//	2 <= n <= 105
//	1 <= roads.length <= 105
//	roads[i].length == 3
//	1 <= ai, bi <= n
//	ai != bi
//	1 <= distancei <= 104
//	There are no repeated edges.
//	There is at least one path between 1 and n.
int minScore(int n, int** roads, int roadsSize, int* roadsColSize){
    int i, j, k, l, m, n1, n2, d, min_d, min_s, *visited, *dist, *path, *path_d, *path_s;
    int *graph[n+1];
    for(i=0;i<=n;i++){
        graph[i] = (int*)malloc(sizeof(int)*n);
        for(j=0;j<n;j++){
            graph[i][j] = 0;
        }
    }
    for(i=0;i<roadsSize;i++){
        n1 = roads[i][0];
        n2 = roads[i][1];
        d = roads[i][2];
        graph[n1][n2-1] = d;
        graph[n2][n1-1] = d;
    }
    visited = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        visited[i] = 0;
    }
    path = (int*)malloc(sizeof(int)*n);
    path_d = (int*)malloc(sizeof(int)*n);
    path_s = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        path[i] = 0;
    }
    path_s[0] = 0;
    path[0] = 1;
    for(i=0;i<n;i++){
        if(path[i]==0){
            continue;
        }
        for(j=0;j<n;j++){
            if(graph[i][j]==0){
                continue;
            }
            if(path[j]==0){
                path[j] = 1;
                path_d[j] = graph[i][j];
                path_s[j] = path_s[i]+graph[i][j];
            }
            else{
                if(path_d[j]>graph[i][j]){
                    path_d[j] = graph[i][j];
                    path_s[j] = path_s[i]+graph[i][j];
                }
            }
        }
    }
    min_s = path_s[n-1];
    for(i=0;i<n;i++){
        if(path[i]==0){
            continue;
        }
        if(min_s>path_s[i]){
            min_s = path_s[i];
        }
    }
    return min_s;
}