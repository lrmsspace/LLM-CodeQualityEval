/**https://leetcode.com/problems/smallest-string-with-swaps/ */
//You are given a string s, and an array of pairs of indices in the string pairs where pairs[i] = [a, b] indicates 2 indices(0-indexed) of the string.
//You can swap the characters at any pair of indices in the given pairs any number of times.
//Return the lexicographically smallest string that s can be changed to after using the swaps.
// 
//Example 1:
//Input: s = "dcab", pairs = [[0,3],[1,2]]
//Output: "bacd"
//Explaination: 
//Swap s[0] and s[3], s = "bcad"
//Swap s[1] and s[2], s = "bacd"
//Example 2:
//Input: s = "dcab", pairs = [[0,3],[1,2],[0,2]]
//Output: "abcd"
//Explaination: 
//Swap s[0] and s[3], s = "bcad"
//Swap s[0] and s[2], s = "acbd"
//Swap s[1] and s[2], s = "abcd"
//Example 3:
//Input: s = "cba", pairs = [[0,1],[1,2]]
//Output: "abc"
//Explaination: 
//Swap s[0] and s[1], s = "bca"
//Swap s[1] and s[2], s = "bac"
//Swap s[0] and s[1], s = "abc"
// 
//Constraints:
//	1 <= s.length <= 10^5
//	0 <= pairs.length <= 10^5
//	0 <= pairs[i][0], pairs[i][1] < s.length
//	s only contains lower case English letters.
/**
 * @param {string} s
 * @param {number[][]} pairs
 * @return {string}
 */
var smallestStringWithSwaps = function(s, pairs) {
    let n = s.length;
    let graph = Array.from({length: n}, () => new Set());
    for (let [a, b] of pairs) {
        graph[a].add(b);
        graph[b].add(a);
    }
    
    let visited = Array(n).fill(false);
    let order = Array(n).fill(0);
    let size = Array(n).fill(0);
    
    function dfs(node) {
        visited[node] = true;
        for (let neighbor of graph[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor);
            }
        }
        order[size[node]] = node;
        size[node]++;
    }
    
    for (let i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    
    let result = Array.from({length: n}, () => s[0]);
    let charMap = Array.from({length: 26}, () => []);
    for (let i = 0; i < n; i++) {
        charMap[s[order[i]].charCodeAt(0) - 'a'.charCodeAt(0)].push(order[i]);
    }
    
    for (let i = 0; i < n; i++) {
        let target = s[i];
        let targetIndex = charMap[target.charCodeAt(0) - 'a'.charCodeAt(0)].indexOf(i);
        let swapIndex = charMap[target.charCodeAt(0) - 'a'.charCodeAt(0)].pop();
        if (swapIndex!== targetIndex) {
            [result[i], result[swapIndex]] = [result[swapIndex], result[i]];
        }
    }
    
    return result.join('');
    
};