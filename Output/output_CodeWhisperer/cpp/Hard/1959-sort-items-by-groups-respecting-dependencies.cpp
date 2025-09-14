/**https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies/ */
//There are n items each belonging to zero or one of m groups where group[i] is the group that the i-th item belongs to and it's equal to -1 if the i-th item belongs to no group. The items and the groups are zero indexed. A group can have no item belonging to it.
//Return a sorted list of the items such that:
//	The items that belong to the same group are next to each other in the sorted list.
//	There are some relations between these items where beforeItems[i] is a list containing all the items that should come before the i-th item in the sorted array (to the left of the i-th item).
//Return any solution if there is more than one solution and return an empty list if there is no solution.
// 
//Example 1:
//Input: n = 8, m = 2, group = [-1,-1,1,0,0,1,0,-1], beforeItems = [[],[6],[5],[6],[3,6],[],[],[]]
//Output: [6,3,4,1,5,2,0,7]
//Example 2:
//Input: n = 8, m = 2, group = [-1,-1,1,0,0,1,0,-1], beforeItems = [[],[6],[5],[6],[3],[],[4],[]]
//Output: []
//Explanation: This is the same as example 1 except that 4 needs to be before 6 in the sorted list.
// 
//Constraints:
//	1 <= m <= n <= 3 * 104
//	group.length == beforeItems.length == n
//	-1 <= group[i] <= m - 1
//	0 <= beforeItems[i].length <= n - 1
//	0 <= beforeItems[i][j] <= n - 1
//	i != beforeItems[i][j]
//	beforeItems[i] does not contain duplicates elements.    
class Solution {
    public:
        vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
            // Assign unique group IDs to items with no group (-1)
            int groupId = m;
            for (int i = 0; i < n; i++) {
                if (group[i] == -1) {
                    group[i] = groupId++;
                }
            }
            
            // Build group graph and item graph
            vector<vector<int>> groupGraph(groupId);
            vector<vector<int>> itemGraph(n);
            vector<int> groupIndegree(groupId, 0);
            vector<int> itemIndegree(n, 0);
            
            // Build the dependency graphs
            for (int i = 0; i < n; i++) {
                for (int prev : beforeItems[i]) {
                    itemGraph[prev].push_back(i);
                    itemIndegree[i]++;
                    
                    // If they belong to different groups, add an edge between groups
                    if (group[prev] != group[i]) {
                        groupGraph[group[prev]].push_back(group[i]);
                        groupIndegree[group[i]]++;
                    }
                }
            }
            
            // Topological sort for groups
            vector<int> groupOrder = topologicalSort(groupGraph, groupIndegree, groupId);
            if (groupOrder.empty()) return {};
            
            // Topological sort for items within each group
            vector<int> result;
            unordered_map<int, vector<int>> groupToItems;
            
            // Group items by their group ID
            for (int i = 0; i < n; i++) {
                groupToItems[group[i]].push_back(i);
            }
            
            // Process each group in the sorted group order
            for (int gid : groupOrder) {
                vector<int> items = groupToItems[gid];
                if (items.empty()) continue;
                
                // Get the topological ordering of items within this group
                vector<int> itemOrder = topologicalSortWithinGroup(itemGraph, itemIndegree, items);
                if (itemOrder.empty()) return {};
                
                // Add the sorted items to the result
                for (int item : itemOrder) {
                    result.push_back(item);
                }
            }
            
            return result;
        }
        
    private:
        // Topological sort function
        vector<int> topologicalSort(vector<vector<int>>& graph, vector<int>& indegree, int count) {
            vector<int> result;
            queue<int> q;
            
            // Add all nodes with 0 indegree to the queue
            for (int i = 0; i < count; i++) {
                if (indegree[i] == 0) {
                    q.push(i);
                }
            }
            
            while (!q.empty()) {
                int curr = q.front();
                q.pop();
                result.push_back(curr);
                
                for (int next : graph[curr]) {
                    if (--indegree[next] == 0) {
                        q.push(next);
                    }
                }
            }
            
            // If we couldn't include all nodes, there's a cycle
            return result.size() == count ? result : vector<int>();
        }
        
        // Topological sort for items within a group
        vector<int> topologicalSortWithinGroup(vector<vector<int>>& graph, vector<int>& indegree, 
                                              vector<int>& items) {
            vector<int> result;
            queue<int> q;
            
            // Add all items in this group with 0 indegree to the queue
            for (int item : items) {
                if (indegree[item] == 0) {
                    q.push(item);
                }
            }
            
            while (!q.empty()) {
                int curr = q.front();
                q.pop();
                result.push_back(curr);
                
                for (int next : graph[curr]) {
                    if (--indegree[next] == 0) {
                        q.push(next);
                    }
                }
            }
            
            // If we couldn't include all items in this group, there's a cycle
            return result.size() == items.size() ? result : vector<int>();
        }
    };
    