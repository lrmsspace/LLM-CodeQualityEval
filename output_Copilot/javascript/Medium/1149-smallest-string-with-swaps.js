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
    const parent = Array.from({ length: s.length }, (_, i) => i); // Union-Find parent array

    const find = (x) => {
        if (parent[x] !== x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    };

    const union = (x, y) => {
        const rootX = find(x);
        const rootY = find(y);
        if (rootX !== rootY) {
            parent[rootY] = rootX; // Union the two sets
        }
    };

    // Union the indices based on the pairs
    for (const [a, b] of pairs) {
        union(a, b);
    }

    // Create a map to group characters by their root index
    const groups = new Map();
    for (let i = 0; i < s.length; i++) {
        const root = find(i);
        if (!groups.has(root)) {
            groups.set(root, []);
        }
        groups.get(root).push(s[i]);
    }

    // Sort each group and create the result string
    let result = Array.from(s);
    for (const group of groups.values()) {
        group.sort(); // Sort characters in the group
        for (let i = 0; i < group.length; i++) {
            const index = find(i); // Find the original index for each character in the sorted group
            result[index] = group[i]; // Place sorted character back into the result string
        }
    }

    return result.join(''); // Convert array back to string and return it   
};