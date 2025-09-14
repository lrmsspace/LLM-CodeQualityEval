/**https://leetcode.com/problems/redundant-connection-ii/ */
//In this problem, a rooted tree is a directed graph such that, there is exactly one node (the root) for which all other nodes are descendants of this node, plus every node has exactly one parent, except for the root node which has no parents.
//The given input is a directed graph that started as a rooted tree with n nodes (with distinct values from 1 to n), with one additional directed edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed.
//The resulting graph is given as a 2D-array of edges. Each element of edges is a pair [ui, vi] that represents a directed edge connecting nodes ui and vi, where ui is a parent of child vi.
//Return an edge that can be removed so that the resulting graph is a rooted tree of n nodes. If there are multiple answers, return the answer that occurs last in the given 2D-array.
// 
//Example 1:
//Input: edges = [[1,2],[1,3],[2,3]]
//Output: [2,3]
//Example 2:
//Input: edges = [[1,2],[2,3],[3,4],[4,1],[1,5]]
//Output: [4,1]
// 
//Constraints:
//	n == edges.length
//	3 <= n <= 1000
//	edges[i].length == 2
//	1 <= ui, vi <= n
//	ui != vi
class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1, 0), first, second;
        vector<int> root(n + 1);
        iota(root.begin(), root.end(), 0);
        for (auto &e : edges) {
            if (parent[e[1]] > 0) {
                first = {parent[e[1]], e[1]};
                second = e;
                e[1] = 0;
            } else {
                parent[e[1]] = e[0];
                int x = find(root, e[0]), y = find(root, e[1]);
                if (x == y) {
                    return e[1] ? e : second;
                }
                root[x] = y;
            }
        }
        return first;        
    }
};