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
/**
 * @param {number} n
 * @param {number} m
 * @param {number[]} group
 * @param {number[][]} beforeItems
 * @return {number[]}
 */
var sortItems = function(n, m, group, beforeItems) {
    // Step 1: Create adjacency list for beforeItems
    const graph = Array(n).fill(null).map(() => []);
    for (let i = 0; i < n; i++) {
        for (let j of beforeItems[i]) {
            graph[j].push(i);
        }
    }
    
    // Step 2: Perform topological sort on the graph
    const visited = Array(n).fill(false);
    const order = [];
    function dfs(node) {
        visited[node] = true;
        for (let neighbor of graph[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor);
            }
        }
        order.unshift(node);
    }
    
    for (let i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    
    // Step 3: Assign groups to items in the order
    const itemGroup = Array(n).fill(0);
    let currentGroup = 0;
    for (let item of order) {
        itemGroup[item] = currentGroup;
        if (group[item] === -1) {
            currentGroup++;
        }
    }
    
    // Step 4: Sort items in each group
    const sortedItems = Array(currentGroup).fill(null).map(() => []);
    for (let i = 0; i < n; i++) {
        sortedItems[itemGroup[i]].push(i);
    }
    
    for (let group of sortedItems) {
        group.sort((a, b) => {
            for (let beforeItem of beforeItems[a]) {
                if (group.includes(beforeItem)) {
                    return beforeItems[a].indexOf(beforeItem) - group.indexOf(beforeItem);
                }
            }
            return 0;
        });
    }
    
    // Step 5: Combine sorted items into a single list
    return sortedItems.flat();
    
};