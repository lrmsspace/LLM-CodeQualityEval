/*
 You are given an undirected tree rooted at node 0, with n nodes numbered from 0 to n - 1. This is represented by a 2D array edges of length n - 1, where edges[i] = [ui, vi, lengthi] indicates an edge between nodes ui and vi with length lengthi. You are also given an integer array nums, where nums[i] represents the value at node i.
 A special path is defined as a downward path from an ancestor node to a descendant node in which all node values are distinct, except for at most one value that may appear twice.
 Return an array result of size 2, where result[0] is the length of the longest special path, and result[1] is the minimum number of nodes in all possible longest special paths.
 Example 1:
 Input: edges = [[0,1,1],[1,2,3],[1,3,1],[2,4,6],[4,7,2],[3,5,2],[3,6,5],[6,8,3]], nums = [1,1,0,3,1,2,1,1,0]
 Output: [9,3]
 Explanation:
 In the image below, nodes are colored by their corresponding values in nums.
 The longest special paths are 1 -> 2 -> 4 and 1 -> 3 -> 6 -> 8, both having a length of 9. The minimum number of nodes across all longest special paths is 3.
 Example 2:
 Input: edges = [[1,0,3],[0,2,4],[0,3,5]], nums = [1,1,0,2]
 Output: [5,2]
 Explanation:
 The longest path is 0 -> 3 consisting of 2 nodes with a length of 5.
 Constraints:
 2 <= n <= 5 * 104
 edges.length == n - 1
 edges[i].length == 3
 0 <= ui, vi < n
 1 <= lengthi <= 103
 nums.length == n
 0 <= nums[i] <= 5 * 104
 The input is generated such that edges represents a valid tree.
*/
class Solution {
public:
    vector<vector<pair<int,int>>> adj;
    vector<int> result;
    int maxLen = 0;
    int minNodes = INT_MAX;
    
    void dfs(int node, int parent, int len, int nodes, vector<int>& nums, unordered_map<int,int>& freq) {
        // Track frequency of current node value
        freq[nums[node]]++;
        
        // Check if path is valid (at most one value appears twice)
        int duplicates = 0;
        for(auto& f : freq) {
            if(f.second > 1) duplicates++;
        }
        
        // Update result if valid path
        if(duplicates <= 1) {
            if(len > maxLen) {
                maxLen = len;
                minNodes = nodes;
            }
            else if(len == maxLen) {
                minNodes = min(minNodes, nodes);
            }
        }
        
        // Explore children
        for(auto& [next, weight] : adj[node]) {
            if(next != parent) {
                dfs(next, node, len + weight, nodes + 1, nums, freq);
            }
        }
        
        // Backtrack
        freq[nums[node]]--;
    }
    
    vector<int> longestSpecialPath(vector<vector<int>>& edges, vector<int>& nums) {
        int n = nums.size();
        adj.resize(n);
        
        // Build adjacency list
        for(auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        
        // Try each node as root
        for(int i = 0; i < n; i++) {
            unordered_map<int,int> freq;
            dfs(i, -1, 0, 1, nums, freq);
        }
        
        return {maxLen, minNodes};
    }
};          