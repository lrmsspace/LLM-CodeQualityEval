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
    let graph = new Map();
    for(let i = 1; i <= n; i++){
        graph.set(i, []);
    }
    for(let [a, b] of dislikes){
        graph.get(a).push(b);
        graph.get(b).push(a);
    }
    let visited = new Set();
    let color = new Map();
    for(let i = 1; i <= n; i++){
        if(visited.has(i)) continue;
        let queue = [i];
        color.set(i, 0);
        while(queue.length){
            let node = queue.shift();
            visited.add(node);
        }
    }
    return true;
};