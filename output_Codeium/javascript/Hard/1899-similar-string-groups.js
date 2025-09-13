/**https://leetcode.com/problems/similar-string-groups/ */
//Two strings, X and Y, are considered similar if either they are identical or we can make them equivalent by swapping at most two letters (in distinct positions) within the string X.
//For example, "tars" and "rats" are similar (swapping at positions 0 and 2), and "rats" and "arts" are similar, but "star" is not similar to "tars", "rats", or "arts".
//Together, these form two connected groups by similarity: {"tars", "rats", "arts"} and {"star"}.  Notice that "tars" and "arts" are in the same group even though they are not similar.  Formally, each group is such that a word is in the group if and only if it is similar to at least one other word in the group.
//We are given a list strs of strings where every string in strs is an anagram of every other string in strs. How many groups are there?
// 
//Example 1:
//Input: strs = ["tars","rats","arts","star"]
//Output: 2
//Example 2:
//Input: strs = ["omv","ovm"]
//Output: 1
// 
//Constraints:
//	1 <= strs.length <= 300
//	1 <= strs[i].length <= 300
//	strs[i] consists of lowercase letters only.
//	All words in strs have the same length and are anagrams of each other.
/**
 * @param {string[]} strs
 * @return {number}
 */
var numSimilarGroups = function(strs) {
    const n = strs[0].length;
    const parent = new Array(strs.length).fill(0).map((_, i) => i);
    const rank = new Array(strs.length).fill(0);

    function find(x) {
        return parent[x] === x ? x : parent[x] = find(parent[x]);
    }

    function union(x, y) {
        const rootX = find(x);
        const rootY = find(y);
        if (rootX !== rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }

    for (let i = 0; i < strs.length; i++) {
        for (let j = i + 1; j < strs.length; j++) {
            let diff = 0;
            let x = -1, y = -1;
            for (let k = 0; k < n; k++) {
                if (strs[i][k] !== strs[j][k]) {
                    if (x === -1) {
                        x = k;
                    } else if (y === -1) {
                        y = k;
                    } else {
                        diff++;
                    }
                }
            }
            if (diff <= 2) {
                union(i, j);
            }
        }
    }

    let groups = 0;
    for (let i = 0; i < strs.length; i++) {
        if (find(i) === i) {
            groups++;
        }
    }

    return groups;
};