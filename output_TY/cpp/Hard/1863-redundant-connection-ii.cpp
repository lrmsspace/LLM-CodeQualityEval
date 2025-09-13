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
        vector<int> indegree(n+1,0);
        for(auto edge:edges){
            indegree[edge[1]]++;
        }
        int node1 = -1,node2 = -1;
        for(int i=n;i>=1;i--){
            if(indegree[i]>1){
                node1 = i;
                break;
            }
        }
        for(auto edge:edges){
            if(edge[1]==node1){
                node2 = edge[0];
                break;
            }
        }
        unordered_map<int,vector<int>> graph;
        for(auto edge:edges){
            graph[edge[0]].push_back(edge[1]);
        }
        vector<int> ans;
        bool found = false;
        for(auto edge:edges){
            if(edge[0]==node2){
                continue;
            }
            vector<int> visited(n+1,0);
            queue<int> q;
            q.push(edge[0]);
            visited[edge[0]] = 1;
            while(!q.empty()){
                int node = q.front();
                q.pop();
                for(auto it:graph[node]){
                    if(it==node1){
                        ans = edge;
                        found = true;
                        break;
                    }
                    if(!visited[it]){
                        q.push(it);
                    }
                }
            }
        }
        if(!found){
            ans = {node2,node1};
        }
        return ans;
    }
};