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
int longestCommonSubpath(int n, int** paths, int pathsSize, int* pathsColSize) {
    int m = pathsSize;
    int len[m];
    for (int i = 0; i < m; i++) {
        len[i] = pathsColSize[i];
    }
    int mod = 1000000007;
    int base = 10007;
    int l = 0, r = 100000;
    int ans = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        int flag = 0;
        long long basePow = 1;
        for (int i = 0; i < mid - 1; i++) {
            basePow = basePow * base % mod;
        }
        unordered_map<int, int> hash;
        for (int i = 0; i < m; i++) {
            int h = 0;
            for (int j = 0; j < len[i]; j++) {
                h = (h * base + paths[i][j]) % mod;
                if (j >= mid - 1) {
                    if (j >= mid) {
                        h = (h - paths[i][j - mid] * basePow % mod + mod) % mod;
                    }
                    if (hash.count(h)) {
                        int k = hash[h];
                        int u = i, v = k;
                        int len = mid;
                        int flag = 1;
                        while (len--) {
                            if (paths[u][j - len] != paths[v][j - len]) {
                                flag = 0;
                                break;
                            }
                        }
                        if (flag) {
                            break;
                        }
                    }
                    hash[h] = i;
                }
            }
            if (flag) {
                break;
            }
        }
        if (flag) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return ans;  
}