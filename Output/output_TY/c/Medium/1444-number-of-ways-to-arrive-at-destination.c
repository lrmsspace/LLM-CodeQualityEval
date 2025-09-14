/**https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/ */
//You are in a city that consists of n intersections numbered from 0 to n - 1 with bi-directional roads between some intersections. The inputs are generated such that you can reach any intersection from any other intersection and that there is at most one road between any two intersections.
//You are given an integer n and a 2D integer array roads where roads[i] = [ui, vi, timei] means that there is a road between intersections ui and vi that takes timei minutes to travel. You want to know in how many ways you can travel from intersection 0 to intersection n - 1 in the shortest amount of time.
//Return the number of ways you can arrive at your destination in the shortest amount of time. Since the answer may be large, return it modulo 109 + 7.
// 
//Example 1:
//Input: n = 7, roads = [[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]
//Output: 4
//Explanation: The shortest amount of time it takes to go from intersection 0 to intersection 6 is 7 minutes.
//The four ways to get there in 7 minutes are:
//- 0 ➝ 6
//- 0 ➝ 4 ➝ 6
//- 0 ➝ 1 ➝ 2 ➝ 5 ➝ 6
//- 0 ➝ 1 ➝ 3 ➝ 5 ➝ 6
//Example 2:
//Input: n = 2, roads = [[1,0,10]]
//Output: 1
//Explanation: There is only one way to go from intersection 0 to intersection 1, and it takes 10 minutes.
// 
//Constraints:
//	1 <= n <= 200
//	n - 1 <= roads.length <= n * (n - 1) / 2
//	roads[i].length == 3
//	0 <= ui, vi <= n - 1
//	1 <= timei <= 109
//	ui != vi
//	There is at most one road connecting any two intersections.
//	You can reach any intersection from any other intersection.
int countPaths(int n, int** roads, int roadsSize, int* roadsColSize){
    int *dis = (int *)malloc(sizeof(int) * n);
    int *cnt = (int *)malloc(sizeof(int) * n);
    memset(dis, 0x3f, sizeof(int) * n);
    memset(cnt, 0, sizeof(int) * n);
    dis[0] = 0;
    cnt[0] = 1;
    int *head = (int *)malloc(sizeof(int) * n);
    memset(head, -1, sizeof(int) * n);
    for (int i = 0; i < roadsSize; i++) {
        int u = roads[i][0];
        int v = roads[i][1];
        int t = roads[i][2];
        addEdge(head, u, v, t);
        addEdge(head, v, u, t);
    }
    int *q = (int *)malloc(sizeof(int) * n);
    int hh = 0, tt = -1;
    q[++tt] = 0;
    while (hh <= tt) {
        int cur = q[hh++];
        for (int i = head[cur]; i != -1; i = edges[i].next) {
            int next = edges[i].v;
            int t = edges[i].w;
            if (dis[next] > dis[cur] + t) {
                dis[next] = dis[cur] + t;
                cnt[next] = cnt[cur];
                q[++tt] = next;
            } else if (dis[next] == dis[cur] + t) {
                cnt[next] += cnt[cur];
            }
            }
        }
    return cnt[n - 1] % 1000000007;
}