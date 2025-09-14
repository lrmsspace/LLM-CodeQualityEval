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
    let ans = [];
    let group_id = m;
    for (let i = 0; i < n; i++) {
        if (group[i] === -1) {
            group[i] = group_id++;
        }
    }
    let group_graph = Array.from({ length: group_id }, () => []);
    let group_in = Array(group_id).fill(0);
    let item_graph = Array.from({ length: n }, () => []);
    let item_in = Array(n).fill(0);
    for (let i = 0; i < n; i++) {
        for (let j of beforeItems[i]) {
            if (group[i] !== group[j]) {
                if (group_graph[group[j]].indexOf(group[i]) === -1) {
                    group_graph[group[j]].push(group[i]);
                    group_in[group[i]]++;
                }
            } else {
                if (item_graph[j].indexOf(i) === -1) {
                    item_graph[j].push(i);
                    item_in[i]++;
                }
            }
        }
    }
    let queue = [];
    for (let i = 0; i < item_in.length; i++) {
        if (item_in[i] === 0) {
            queue.push(i);
        }
    }
    while (queue.length !== 0) {
        let cur = queue.shift();
        result.push(cur);
        for (let i = 0; i < item_graph[cur].length; i++) {
            item_in[item_graph[cur][i]]--;
            if (item_in[item_graph[cur][i]] === 0) {
                queue.push(item_graph[cur][i]);
            }
        }
    }
    return result.length === item_graph.length ? result.join("") : "";
};