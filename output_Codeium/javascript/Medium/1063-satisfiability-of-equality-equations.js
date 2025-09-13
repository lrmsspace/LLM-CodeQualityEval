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
    const uf = new UnionFind(26);
    for (const equation of equations) {
        const [a, operator, b] = equation.split('');
        if (operator === '=') uf.union(a.charCodeAt(0) - 97, b.charCodeAt(0) - 97);
    }
    for (const equation of equations) {
        const [a, operator, b] = equation.split('');
        if (operator === '!' && uf.find(a.charCodeAt(0) - 97) === uf.find(b.charCodeAt(0) - 97)) return false;
    }
    return true;

class UnionFind {
    constructor(n) {
        this.parent = Array.from({ length: n }, (_, i) => i);
        this.rank = Array(n).fill(0);
    }

    find(x) {
        if (this.parent[x] !== x) this.parent[x] = this.find(this.parent[x]);
        return this.parent[x];
    }

    union(x, y) {
        const rootX = this.find(x);
        const rootY = this.find(y);
        if (rootX !== rootY) {
            if (this.rank[rootX] > this.rank[rootY]) {
                this.parent[rootY] = rootX;
            } else if (this.rank[rootX] < this.rank[rootY]) {
                this.parent[rootX] = rootY;
            } else {
                this.parent[rootY] = rootX;
                this.rank[rootX]++;
            }
        }
    }
}
};