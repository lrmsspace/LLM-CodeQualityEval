/**https://leetcode.com/problems/number-of-good-paths/ */
//There is a tree (i.e. a connected, undirected graph with no cycles) consisting of n nodes numbered from 0 to n - 1 and exactly n - 1 edges.
//You are given a 0-indexed integer array vals of length n where vals[i] denotes the value of the ith node. You are also given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting nodes ai and bi.
//A good path is a simple path that satisfies the following conditions:
//	The starting node and the ending node have the same value.
//	All nodes between the starting node and the ending node have values less than or equal to the starting node (i.e. the starting node's value should be the maximum value along the path).
//Return the number of distinct good paths.
//Note that a path and its reverse are counted as the same path. For example, 0 -> 1 is considered to be the same as 1 -> 0. A single node is also considered as a valid path.
// 
//Example 1:
//Input: vals = [1,3,2,1,3], edges = [[0,1],[0,2],[2,3],[2,4]]
//Output: 6
//Explanation: There are 5 good paths consisting of a single node.
//There is 1 additional good path: 1 -> 0 -> 2 -> 4.
//(The reverse path 4 -> 2 -> 0 -> 1 is treated as the same as 1 -> 0 -> 2 -> 4.)
//Note that 0 -> 2 -> 3 is not a good path because vals[2] > vals[0].
//Example 2:
//Input: vals = [1,1,2,2,3], edges = [[0,1],[1,2],[2,3],[2,4]]
//Output: 7
//Explanation: There are 5 good paths consisting of a single node.
//There are 2 additional good paths: 0 -> 1 and 2 -> 3.
//Example 3:
//Input: vals = [1], edges = []
//Output: 1
//Explanation: The tree consists of only one node, so there is one good path.
// 
//Constraints:
//	n == vals.length
//	1 <= n <= 3 * 104
//	0 <= vals[i] <= 105
//	edges.length == n - 1
//	edges[i].length == 2
//	0 <= ai, bi < n
//	ai != bi
//	edges represents a valid tree.
/**
 * @param {number[]} vals
 * @param {number[][]} edges
 * @return {number}
 */
var numberOfGoodPaths = function(vals, edges) {
let parent = Array.from({length: vals.length}, (_, i) => i);
let rank = Array(vals.length).fill(0);

function find(x) {
    if (parent[x] !== x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

function union(x, y) {
    let rootX = find(x);
    let rootY = find(y);
    if (rootX !== rootY) {
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank[rootX] += 1;
        }
    }
}

let edgeList = edges.map(e => {
    return [vals[e[0]], vals[e[1]], e[0], e[1]];
});

edgeList.sort((a, b) => a[0] - b[0] || a[1] - b[1]);

let result = vals.length;

for (let i = 0; i < edgeList.length;) {
    let j = i;
    while (j < edgeList.length && edgeList[j][0] === edgeList[i][0] && edgeList[j][1] === edgeList[i][1]) {
        j++;
    }

    for (let k = i; k < j; k++) {
        union(edgeList[k][2], edgeList[k][3]);
    }

    let group = new Map();

    for (let k = i; k < j; k++) {
        let root = find(edgeList[k][2]);
        if (!group.has(root)) {
            group.set(root, 0);
        }
        group.set(root, group.get(root) + 1);
    }

    for (let count of group.values()) {
        result += (count * (count - 1)) / 2;
    }

    i = j;
}

return result;
};