/**https://leetcode.com/problems/minimum-degree-of-a-connected-trio-in-a-graph/ */
//You are given an undirected graph. You are given an integer n which is the number of nodes in the graph and an array edges, where each edges[i] = [ui, vi] indicates that there is an undirected edge between ui and vi.
//A connected trio is a set of three nodes where there is an edge between every pair of them.
//The degree of a connected trio is the number of edges where one endpoint is in the trio, and the other is not.
//Return the minimum degree of a connected trio in the graph, or -1 if the graph has no connected trios.
// 
//Example 1:
//Input: n = 6, edges = [[1,2],[1,3],[3,2],[4,1],[5,2],[3,6]]
//Output: 3
//Explanation: There is exactly one trio, which is [1,2,3]. The edges that form its degree are bolded in the figure above.
//Example 2:
//Input: n = 7, edges = [[1,3],[4,1],[4,3],[2,5],[5,6],[6,7],[7,5],[2,6]]
//Output: 0
//Explanation: There are exactly three trios:
//1) [1,4,3] with degree 0.
//2) [2,5,6] with degree 2.
//3) [5,6,7] with degree 2.
// 
//Constraints:
//	2 <= n <= 400
//	edges[i].length == 2
//	1 <= edges.length <= n * (n-1) / 2
//	1 <= ui, vi <= n
//	ui != vi
//	There are no repeated edges.
class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for(auto edge : edges){
            graph[edge[0]-1].push_back(edge[1]-1);
            graph[edge[1]-1].push_back(edge[0]-1);
        }
        int ans = INT_MAX;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                for(int k = j+1; k < n; k++){
                    int degree = 0;
                    if(find(graph[i].begin(), graph[i].end(), j) != graph[i].end()){
                        degree++;
                    }
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};