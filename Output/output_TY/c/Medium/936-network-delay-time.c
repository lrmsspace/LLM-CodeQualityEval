/**https://leetcode.com/problems/network-delay-time/ */
//You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.
//We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.
// 
//Example 1:
//Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
//Output: 2
//Example 2:
//Input: times = [[1,2,1]], n = 2, k = 1
//Output: 1
//Example 3:
//Input: times = [[1,2,1]], n = 2, k = 2
//Output: -1
// 
//Constraints:
//	1 <= k <= n <= 100
//	1 <= times.length <= 6000
//	times[i].length == 3
//	1 <= ui, vi <= n
//	ui != vi
//	0 <= wi <= 100
//	All the pairs (ui, vi) are unique. (i.e., no multiple edges.)
int networkDelayTime(int** times, int timesSize, int* timesColSize, int n, int k){
    int i, j, min, min_i, min_j, min_t, t, *dist, *visited;
    int *queue, *queue_i, *queue_j, *queue_t;
    int queue_size, queue_i_size, queue_j_size, queue_t_size;
    int ans;
    
    dist = (int*)malloc(n * sizeof(int));
    visited = (int*)malloc(n * sizeof(int));
    queue = (int*)malloc(n * sizeof(int));
    queue_i = (int*)malloc(n * sizeof(int));
    queue_j = (int*)malloc(n * sizeof(int));
    queue_t = (int*)malloc(n * sizeof(int));
    queue_size = queue_i_size = queue_j_size = queue_t_size = 0;
    for (i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    dist[k] = 0;
    queue[queue_size++] = k;
    while (queue_size > 0) {
        i = queue[0];
        queue_i[queue_i_size++] = i;
    }
    return dist[end] == INT_MAX ? -1 : dist[end];
}