/**https://leetcode.com/problems/satisfiability-of-equality-equations/ */
//You are given an array of strings equations that represent relationships between variables where each string equations[i] is of length 4 and takes one of two different forms: "xi==yi" or "xi!=yi".Here, xi and yi are lowercase letters (not necessarily different) that represent one-letter variable names.
//Return true if it is possible to assign integers to variable names so as to satisfy all the given equations, or false otherwise.
// 
//Example 1:
//Input: equations = ["a==b","b!=a"]
//Output: false
//Explanation: If we assign say, a = 1 and b = 1, then the first equation is satisfied, but not the second.
//There is no way to assign the variables to satisfy both equations.
//Example 2:
//Input: equations = ["b==a","a==b"]
//Output: true
//Explanation: We could assign a = 1 and b = 1 to satisfy both equations.
// 
//Constraints:
//	1 <= equations.length <= 500
//	equations[i].length == 4
//	equations[i][0] is a lowercase letter.
//	equations[i][1] is either '=' or '!'.
//	equations[i][2] is '='.
//	equations[i][3] is a lowercase letter.
/**
 * @param {string[]} equations
 * @return {boolean}
 */
var equationsPossible = function(equations) {
    const graph = Array.from({length: 26}, () => new Set());
    const visited = Array.from({length: 26}, () => false);
    const stack = [];
    
    for (const equation of equations) {
        const [x, op, y] = equation;
        const [a, b] = [x.charCodeAt(0) - 'a'.charCodeAt(0), y.charCodeAt(0) - 'a'.charCodeAt(0)];
        
        if (op === '=') {
            graph[a].add(b);
            graph[b].add(a);
        }
    }
    
    function dfs(node) {
        if (visited[node]) return false;
        visited[node] = true;
        stack.push(node);
        
        for (const neighbor of graph[node]) {
            if (!dfs(neighbor)) return false;
        }
        
        return true;
    }
    
    for (let i = 0; i < 26; i++) {
        if (!visited[i] &&!dfs(i)) return false;
    }
    
    return true;
    
};