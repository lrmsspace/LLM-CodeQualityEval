/**https://leetcode.com/problems/longest-path-with-different-adjacent-characters/ */
//You are given a tree (i.e. a connected, undirected graph that has no cycles) rooted at node 0 consisting of n nodes numbered from 0 to n - 1. The tree is represented by a 0-indexed array parent of size n, where parent[i] is the parent of node i. Since node 0 is the root, parent[0] == -1.
//You are also given a string s of length n, where s[i] is the character assigned to node i.
//Return the length of the longest path in the tree such that no pair of adjacent nodes on the path have the same character assigned to them.
// 
//Example 1:
//Input: parent = [-1,0,0,1,1,2], s = "abacbe"
//Output: 3
//Explanation: The longest path where each two adjacent nodes have different characters in the tree is the path: 0 -> 1 -> 3. The length of this path is 3, so 3 is returned.
//It can be proven that there is no longer path that satisfies the conditions. 
//Example 2:
//Input: parent = [-1,0,0,0], s = "aabc"
//Output: 3
//Explanation: The longest path where each two adjacent nodes have different characters is the path: 2 -> 0 -> 3. The length of this path is 3, so 3 is returned.
// 
//Constraints:
//	n == parent.length == s.length
//	1 <= n <= 105
//	0 <= parent[i] <= n - 1 for all i >= 1
//	parent[0] == -1
//	parent represents a valid tree.
//	s consists of only lowercase English letters.
int longestPath(int* parent, int parentSize, char* s) {
    int i, j, k, n = parentSize;
    int *dp = (int *)malloc(sizeof(int) * n);
    int *dp2 = (int *)malloc(sizeof(int) * n);
    int *child = (int *)malloc(sizeof(int) * n);
    int *child2 = (int *)malloc(sizeof(int) * n);
    int *count = (int *)malloc(sizeof(int) * 26);
    int *count2 = (int *)malloc(sizeof(int) * 26);
    int ans = 0;
    for (i = 0; i < n; i++) {
        dp[i] = dp2[i] = 0;
        child[i] = child2[i] = 0;
    }
    for (i = n - 1; i > 0; i--) {
        child[parent[i]]++;
        if (child[i] > child[parent[i]]) {
            child[parent[i]] = child[i];
        }
    }
    for (i = 0; i < n; i++) {
        if (child[i] > 0) {
            child2[parent[i]] = child[i] - 1;
        }
    }
    for (i = 0; i < n; i++) {
        count[s[i] - 'a'] = count2[s[i] - 'a'] = -1;
    }
    for (i = 0; i < n; i++) {
        j = parent[i];
        if (count[s[i] - 'a'] == -1) {
            count[s[i] - 'a'] = i;
        } else {    
            dp[i] = i - count[s[i] - 'a'];
            count[s[i] - 'a'] = i;
        }
        if (count2[s[i] - 'a'] == -1) {
            count2[s[i] - 'a'] = i;
        } else {
            dp2[i] = i - count2[s[i] - 'a'];
            count2[s[i] - 'a'] = i;
        }
        if (j >= 0) {
            if (dp[j] > dp2[j]) {
                dp2[j] = dp[j];
            }
            if (dp2[i] > dp2[j]) {
                dp2[j] = dp2[i];
            if (s[i] != s[j]) {
                dp[j] = dp[j] > dp[i] + 1 ? dp[j] : dp[i] + 1;
                ans = ans > dp[j] ? ans : dp[j];
            }
        }
    }
    free(dp);
    free(dp2);
    free(child);
    free(child2);
    free(count);
    free(count2);
    return ans + 1;
}