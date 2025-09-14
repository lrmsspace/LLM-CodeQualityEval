/**https://leetcode.com/problems/longest-common-subpath/ */
//There is a country of n cities numbered from 0 to n - 1. In this country, there is a road connecting every pair of cities.
//There are m friends numbered from 0 to m - 1 who are traveling through the country. Each one of them will take a path consisting of some cities. Each path is represented by an integer array that contains the visited cities in order. The path may contain a city more than once, but the same city will not be listed consecutively.
//Given an integer n and a 2D integer array paths where paths[i] is an integer array representing the path of the ith friend, return the length of the longest common subpath that is shared by every friend's path, or 0 if there is no common subpath at all.
//A subpath of a path is a contiguous sequence of cities within that path.
// 
//Example 1:
//Input: n = 5, paths = [[0,1,2,3,4],
//                       [2,3,4],
//                       [4,0,1,2,3]]
//Output: 2
//Explanation: The longest common subpath is [2,3].
//Example 2:
//Input: n = 3, paths = [[0],[1],[2]]
//Output: 0
//Explanation: There is no common subpath shared by the three paths.
//Example 3:
//Input: n = 5, paths = [[0,1,2,3,4],
//                       [4,3,2,1,0]]
//Output: 1
//Explanation: The possible longest common subpaths are [0], [1], [2], [3], and [4]. All have a length of 1.
// 
//Constraints:
//	1 <= n <= 105
//	m == paths.length
//	2 <= m <= 105
//	sum(paths[i].length) <= 105
//	0 <= paths[i][j] < n
//	The same city is not listed multiple times consecutively in paths[i].
/**
 * @param {number} n
 * @param {number[][]} paths
 * @return {number}
 */
var longestCommonSubpath = function(n, paths) {
    const mod = 1e9 + 7;
    const base = 1e4 + 3;
    let maxLen = 0;
    const hashes = new Set();

    const getHash = (path, len) => {
        let hash = 0;
        for (let i = 0; i < len; i++) {
            hash = (hash * base + path[i]) % mod;
        }
        return hash;
    };

    const rabinKarp = (path, len) => {
        let hash = getHash(path, len);
        hashes.add(hash);
        let basePow = Math.pow(base, len - 1) % mod;

        for (let i = len; i < path.length; i++) {
            hash = (hash * base - path[i - len] * basePow + path[i]) % mod;
            if (hash < 0) hash += mod;
            hashes.add(hash);
        }
    };

    const checkCommonSubpath = (len) => {
        hashes.clear();
        rabinKarp(paths[0], len);
        for (let i = 1; i < paths.length; i++) {
            let currentHashSet = new Set();
            rabinKarp(paths[i], len);
            if ([...hashes].some(hash => currentHashSet.has(hash))) {
                return true;
            }
            hashes.clear();
        }
        return false;
    };

    let left = 1, right = Math.min(...paths.map(path => path.length));
    while (left <= right) {
        const mid = Math.floor((left + right) / 2);
        if (checkCommonSubpath(mid)) {
            maxLen = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return maxLen;    
};