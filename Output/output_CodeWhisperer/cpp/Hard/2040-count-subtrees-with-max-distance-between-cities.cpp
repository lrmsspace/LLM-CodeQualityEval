/**https://leetcode.com/problems/count-subtrees-with-max-distance-between-cities/ */
//There are n cities numbered from 1 to n. You are given an array edges of size n-1, where edges[i] = [ui, vi] represents a bidirectional edge between cities ui and vi. There exists a unique path between each pair of cities. In other words, the cities form a tree.
//A subtree is a subset of cities where every city is reachable from every other city in the subset, where the path between each pair passes through only the cities from the subset. Two subtrees are different if there is a city in one subtree that is not present in the other.
//For each d from 1 to n-1, find the number of subtrees in which the maximum distance between any two cities in the subtree is equal to d.
//Return an array of size n-1 where the dth element (1-indexed) is the number of subtrees in which the maximum distance between any two cities is equal to d.
//Notice that the distance between the two cities is the number of edges in the path between them.
// 
//Example 1:
//Input: n = 4, edges = [[1,2],[2,3],[2,4]]
//Output: [3,4,0]
//Explanation:
//The subtrees with subsets {1,2}, {2,3} and {2,4} have a max distance of 1.
//The subtrees with subsets {1,2,3}, {1,2,4}, {2,3,4} and {1,2,3,4} have a max distance of 2.
//No subtree has two nodes where the max distance between them is 3.
//Example 2:
//Input: n = 2, edges = [[1,2]]
//Output: [1]
//Example 3:
//Input: n = 3, edges = [[1,2],[2,3]]
//Output: [2,1]
// 
//Constraints:
//	2 <= n <= 15
//	edges.length == n-1
//	edges[i].length == 2
//	1 <= ui, vi <= n
//	All pairs (ui, vi) are distinct.
class Solution {
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<int> res(n - 1, 0);
        vector<vector<int>> graph(n, vector<int>(n, 0));
        for (auto edge : edges) {
            graph[edge[0] - 1][edge[1] - 1] = 1;
            graph[edge[1] - 1][edge[0] - 1] = 1;
        }
        for (int i = 0; i < (1 << n); i++) {
            vector<int> cities;
            for (int j = 0; j < n; j++) {
                if ((i & (1 << j)) != 0) {
                    cities.push_back(j);
                }
            }
            if (cities.size() <= 1) continue;
            vector<vector<int>> dist(cities.size(), vector<int>(cities.size(), INT_MAX));
            for (int j = 0; j < cities.size(); j++) {
                for (int k = 0; k < cities.size(); k++) {
                    if (j == k) dist[j][k] = 0;
                    else if (graph[cities[j]][cities[k]] == 1) dist[j][k] = 1;
                }
            }
            for (int j = 0; j < cities.size(); j++) {
                for (int k = 0; k < cities.size(); k++) {
                    for (int l = 0; l < cities.size(); l++) {
                        if (dist[k][j] != INT_MAX && dist[j][l] != INT_MAX) {
                            dist[k][l] = min(dist[k][l], dist[k][j] + dist[j][l]);
                        }
                    }
                }
            }
            int maxDist = 0;
            for (int j = 0; j < cities.size(); j++) {
                for (int k = 0; k < cities.size(); k++) {
                    if (dist[j][k] != INT_MAX) {
                        maxDist = max(maxDist, dist[j][k]);
                    }
                }
            }
            res[maxDist - 1]++;
        }
        return res;       
    }
};