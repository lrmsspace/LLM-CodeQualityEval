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
    let n = strs.length;
    let parent = new Array(n).fill(0).map((_, i) => i);
    let rank = new Array(n).fill(0);
    let count = n;
    
    const find = (x) => {
        if(parent[x] === x) return x;
        return parent[x] = find(parent[x]);
    }
    
    const union = (x, y) => {
        let px = find(x);
        let py = find(y);
        
        if(px === py) return;
        
        if(rank[px] > rank[py]) {
            parent[py] = px;
        } else {
           parent[px] = py;
        }
    }
    
    for(let i = 0; i < n; i++) {
        for(let j = i+1; j < n; j++) {
            let s1 = strs[i];
            let s2 = strs[j];
            
            let diff = 0;
            for(let k = 0; k < s1.length; k++) {
                if(s1[k] !== s2[k]) diff++;
                if(diff > 2) break;
            }
            
            if(diff <= 2) union(i, j);
        }
    }
    
    return count;
};