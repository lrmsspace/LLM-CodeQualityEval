/*
 You are given an array of integers nums of size n and a positive integer threshold.
 There is a graph consisting of n nodes with the ith node having a value of nums[i]. Two nodes i and j in the graph are connected via an undirected edge if lcm(nums[i], nums[j]) <= threshold.
 Return the number of connected components in this graph.
 A connected component is a subgraph of a graph in which there exists a path between any two vertices, and no vertex of the subgraph shares an edge with a vertex outside of the subgraph.
 The term lcm(a, b) denotes the least common multiple of a and b.
 Example 1:
 Input: nums = [2,4,8,3,9], threshold = 5
 Output: 4
 Explanation: 
 The four connected components are (2, 4), (3), (8), (9).
 Example 2:
 Input: nums = [2,4,8,3,9,12], threshold = 10
 Output: 2
 Explanation: 
 The two connected components are (2, 3, 4, 8, 9), and (12).
 Constraints:
 1 <= nums.length <= 105
 1 <= nums[i] <= 109
 All elements of nums are unique.
 1 <= threshold <= 2 * 105
*/

class Solution {
    public int countComponents(int[] nums, int threshold) {
        int n = nums.length;
        int[] parent = new int[n];
        int[] rank = new int[n];
        
        // Initialize parent and rank arrays
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
        
        // Helper function to find the root of a node
        int find = (node) -> {
            while (parent[node] != node) {
                parent[node] = parent[parent[node]]; // Path compression
                node = parent[node];
            }
            return node;
        };
        
        // Helper function to union two nodes
        int union = (node1, node2) -> {
            int root1 = find.apply(node1);
            int root2 = find.apply(node2);
            
            if (root1 != root2) {
                if (rank[root1] > rank[root2]) {
                    parent[root2] = root1;
                    rank[root1] += rank[root2];
                } else {
                    parent[root1] = root2;
                    rank[root2] += rank[root1];
                }
            }
        };
        
        // Union nodes based on the given condition
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] % nums[j] == 0 || nums[j] % nums[i] == 0) {
                    union.apply(i, j);
                }
                if (nums[i] * nums[j] <= threshold) {
                    union.apply(i, j);
                }
            }
        }
        
        // Count the number of connected components
        int components = 0;
        for (int i = 0; i < n; i++) {
            if (parent[i] == i) {
                components++;
            }
        }
        
        return components;
                
    }
}