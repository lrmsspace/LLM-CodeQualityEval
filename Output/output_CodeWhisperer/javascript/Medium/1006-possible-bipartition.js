/**https://leetcode.com/problems/possible-bipartition/ */
//We want to split a group of n people (labeled from 1 to n) into two groups of any size. Each person may dislike some other people, and they should not go into the same group.
//Given the integer n and the array dislikes where dislikes[i] = [ai, bi] indicates that the person labeled ai does not like the person labeled bi, return true if it is possible to split everyone into two groups in this way.
// 
//Example 1:
//Input: n = 4, dislikes = [[1,2],[1,3],[2,4]]
//Output: true
//Explanation: The first group has [1,4], and the second group has [2,3].
//Example 2:
//Input: n = 3, dislikes = [[1,2],[1,3],[2,3]]
//Output: false
//Explanation: We need at least 3 groups to divide them. We cannot put them in two groups.
// 
//Constraints:
//	1 <= n <= 2000
//	0 <= dislikes.length <= 104
//	dislikes[i].length == 2
//	1 <= ai < bi <= n
//	All the pairs of dislikes are unique.
/**
 * @param {number} n
 * @param {number[][]} dislikes
 * @return {boolean}
 */
var possibleBipartition = function(n, dislikes) {
    let graph = new Array(n + 1).fill(0).map(() => []);
    for (let [a, b] of dislikes) {
        graph[a].push(b);
        graph[b].push(a);
    }
    let colors = new Array(n + 1).fill(0);
    for (let i = 1; i <= n; i++) {
        if (colors[i] === 0) {
            colors[i] = 1;
            let queue = [i];
            while (queue.length > 0) {
                let node = queue.shift();
                for (let neighbor of graph[node]) {
                    if (colors[neighbor] === colors[node]) {
                        return false;
                    }
                    if (colors[neighbor] === 0) {
                        colors[neighbor] = -colors[node];
                        queue.push(neighbor);
                    }
                }
            }
        }
    }
    return true;
};