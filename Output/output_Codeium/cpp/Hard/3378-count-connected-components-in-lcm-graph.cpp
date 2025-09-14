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
public:
    int countComponents(vector<int>& nums, int threshold) {
        int n = nums.size();
        vector<int> parent(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (lcm(nums[i], nums[j]) <= threshold) {
                    int root1 = find(parent, i);
                    int root2 = find(parent, j);
                    if (root1 != root2) {
                        parent[root1] = root2;
                    }
                }
            }
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (parent[i] == i) {
                count++;
            }
        }
        return count;
    }
    
    int find(vector<int>& parent, int x) {
        if (parent[x] != x) {
            parent[x] = find(parent, parent[x]);
        }
        return parent[x];
    }
    
    int lcm(int a, int b) {
        int gcd = __gcd(a, b);
        return a * b / gcd;
    }
};