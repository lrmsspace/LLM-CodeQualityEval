/**https://leetcode.com/problems/find-the-shortest-superstring/ */
//Given an array of strings words, return the smallest string that contains each string in words as a substring. If there are multiple valid strings of the smallest length, return any of them.
//You may assume that no string in words is a substring of another string in words.
// 
//Example 1:
//Input: words = ["alex","loves","leetcode"]
//Output: "alexlovesleetcode"
//Explanation: All permutations of "alex","loves","leetcode" would also be accepted.
//Example 2:
//Input: words = ["catg","ctaagt","gcta","ttca","atgcatc"]
//Output: "gctaagttcatgcatc"
// 
//Constraints:
//	1 <= words.length <= 12
//	1 <= words[i].length <= 20
//	words[i] consists of lowercase English letters.
//	All the strings of words are unique.
char* shortestSuperstring(char** words, int wordsSize) {
    int n = wordsSize;
    int* dp = malloc(n * sizeof(int));
    int* parent = malloc(n * sizeof(int));
    memset(dp, 0x3f, n * sizeof(int));
    memset(parent, -1, n * sizeof(int));
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            int len = strlen(words[i]) + strlen(words[j]) - lcs(words[i], words[j]);
            if (len < dp[j] && check(words[i], words[j])) {
                dp[j] = len;
                parent[j] = i;
            }
        }
    }
    int min_index = 0;
    for (int i = 1; i < n; i++) {
        if (dp[i] < dp[min_index]) {
            min_index = i;
        }
    }
    char* ans = malloc((dp[min_index] + 1) * sizeof(char));
    ans[dp[min_index]] = '\0';
    int index = min_index;
    for (int i = dp[min_index] - 1; i >= 0; i--) {
        strcat(ans, words[index]);
        index = parent[index];
    }
    return ans;
}