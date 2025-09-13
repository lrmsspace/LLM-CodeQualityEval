/**https://leetcode.com/problems/sum-of-distances-in-tree/ */
//There is an undirected connected tree with n nodes labeled from 0 to n - 1 and n - 1 edges.
//You are given the integer n and the array edges where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.
//Return an array answer of length n where answer[i] is the sum of the distances between the ith node in the tree and all other nodes.
// 
//Example 1:
//Input: n = 6, edges = [[0,1],[0,2],[2,3],[2,4],[2,5]]
//Output: [8,12,6,10,10,10]
//Explanation: The tree is shown above.
//We can see that dist(0,1) + dist(0,2) + dist(0,3) + dist(0,4) + dist(0,5)
//equals 1 + 1 + 2 + 2 + 2 = 8.
//Hence, answer[0] = 8, and so on.
//Example 2:
//Input: n = 1, edges = []
//Output: [0]
//Example 3:
//Input: n = 2, edges = [[1,0]]
//Output: [1,1]
// 
//Constraints:
//	1 <= n <= 3 * 104
//	edges.length == n - 1
//	edges[i].length == 2
//	0 <= ai, bi < n
//	ai != bi
//	The given input represents a valid tree.
class Solution {
    public int[] sumOfDistancesInTree(int n, int[][] edges) {
        List<List<Integer>> adj = new ArrayList<>();
        for(int i=0;i<n;i++)
            adj.add(new ArrayList<>());
        for(int[] edge:edges){
            adj.get(edge[0]).add(edge[1]);
            adj.get(edge[1]).add(edge[0]);
        }
        int[] res = new int[n];
        int[] count = new int[n];
        dfs(adj,0,-1,res,count);
        dfs2(adj,0,-1,res,count,n);
        return res;
    }
    private void dfs(List<List<Integer>> adj,int node, int parent, int[] res, int[] count){
        for(int nextNode:adj.get(node)){
            if(nextNode!=parent){
                dfs(adj,nextNode,node,res,count);
                count[node]+=count[nextNode];
                res[node]+=res[nextNode]+count[nextNode];
            }
        }
        count[node]+=1;
        res[node]+=count[node];
        return;
    }
}