/**https://leetcode.com/problems/create-components-with-same-value/ */
//There is an undirected tree with n nodes labeled from 0 to n - 1.
//You are given a 0-indexed integer array nums of length n where nums[i] represents the value of the ith node. You are also given a 2D integer array edges of length n - 1 where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.
//You are allowed to delete some edges, splitting the tree into multiple connected components. Let the value of a component be the sum of all nums[i] for which node i is in the component.
//Return the maximum number of edges you can delete, such that every connected component in the tree has the same value.
// 
//Example 1:
//Input: nums = [6,2,2,2,6], edges = [[0,1],[1,2],[1,3],[3,4]] 
//Output: 2 
//Explanation: The above figure shows how we can delete the edges [0,1] and [3,4]. The created components are nodes [0], [1,2,3] and [4]. The sum of the values in each component equals 6. It can be proven that no better deletion exists, so the answer is 2.
//Example 2:
//Input: nums = [2], edges = []
//Output: 0
//Explanation: There are no edges to be deleted.
// 
//Constraints:
//	1 <= n <= 2 * 104
//	nums.length == n
//	1 <= nums[i] <= 50
//	edges.length == n - 1
//	edges[i].length == 2
//	0 <= edges[i][0], edges[i][1] <= n - 1
//	edges represents a valid tree.  
class Solution {
    public:
        int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
            int n = nums.size();
            
            // If there's only one node, we can't delete any edges
            if (n == 1) return 0;
            
            // Build the adjacency list representation of the tree
            vector<vector<int>> graph(n);
            for (const auto& edge : edges) {
                graph[edge[0]].push_back(edge[1]);
                graph[edge[1]].push_back(edge[0]);
            }
            
            // Calculate the total sum and find the maximum value
            int totalSum = 0;
            int maxVal = 0;
            for (int val : nums) {
                totalSum += val;
                maxVal = max(maxVal, val);
            }
            
            // Find the maximum possible number of components
            // We'll try from the maximum possible number of components down to 1
            for (int components = n; components >= 1; components--) {
                // If totalSum is not divisible by components, we can't have equal components
                if (totalSum % components != 0) {
                    continue;
                }
                
                int targetSum = totalSum / components;
                
                // If any single node exceeds the target sum, it's not possible
                if (maxVal > targetSum) {
                    continue;
                }
                
                // Try to split the tree into 'components' equal parts
                vector<bool> visited(n, false);
                if (dfs(graph, nums, 0, -1, targetSum, visited) == 0) {
                    // If successful, we can delete (components - 1) edges
                    return components - 1;
                }
            }
            
            return 0; // Default: can't delete any edges
        }
        
    private:
        // DFS function returns:
        // - The sum of the current subtree if it's < targetSum
        // - 0 if the current subtree forms a valid component with sum = targetSum
        // - -1 if it's not possible to form valid components
        int dfs(const vector<vector<int>>& graph, const vector<int>& nums, int node, int parent, int targetSum, vector<bool>& visited) {
            visited[node] = true;
            
            int currentSum = nums[node];
            
            for (int neighbor : graph[node]) {
                if (neighbor != parent && !visited[neighbor]) {
                    int subtreeSum = dfs(graph, nums, neighbor, node, targetSum, visited);
                    
                    // If any subtree is invalid, the whole solution is invalid
                    if (subtreeSum == -1) {
                        return -1;
                    }
                    
                    // Add the subtree sum to the current sum
                    currentSum += subtreeSum;
                }
            }
            
            // If the current sum equals the target, we can cut this subtree
            if (currentSum == targetSum) {
                return 0;
            }
            
            // If the current sum exceeds the target, it's not possible
            if (currentSum > targetSum) {
                return -1;
            }
            
            // Otherwise, return the current sum to be added to the parent
            return currentSum;
        }
    };
    