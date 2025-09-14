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
class Solution {
    public int longestCommonSubpath(int n, int[][] paths) {
        int left = 0;
        int right = Integer.MAX_VALUE;
        for (int i = 0; i < paths.length; i++) {
            right = Math.min(right, paths[i].length);
        }

        while (left < right) {
            int mid = (left + right + 1) / 2;
            if (hasCommonSubpath(mid, n, paths)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }

    private boolean hasCommonSubpath(int length, int n, int[][] paths) {
        long mod1 = 100000000019L;
        long mod2 = 100000000033L;
        long base1 = 100000007;
        long base2 = 100000009;
        Set<Long> common = null;

        for (int[] path : paths) {
            Set<Long> currentHashes = new HashSet<>();
            long hash1 = 0;
            long hash2 = 0;
            long base1L = 1;
            long base2L = 1;

            for (int i = 0; i < path.length; i++) {
                hash1 = (hash1 * base1 + path[i]) % mod1;
                hash2 = (hash2 * base2 + path[i]) % mod2;

                if (i >= length) {
                    hash1 = (hash1 - path[i - length] * base1L % mod1 + mod1) % mod1;
                    hash2 = (hash2 - path[i - length] * base2L % mod2 + mod2) % mod2;
                } else {
                    base1L = base1L * base1 % mod1;
                    base2L = base2L * base2 % mod2;
                }

                if (i >= length - 1) {
                    currentHashes.add(hash1 * mod2 + hash2);
                }
            }

            if (common == null) {
                common = currentHashes;
            } else {
                common.retainAll(currentHashes);
            }

            if (common.isEmpty()) {
                return false;
            }
        }
        return true;
    }   
}