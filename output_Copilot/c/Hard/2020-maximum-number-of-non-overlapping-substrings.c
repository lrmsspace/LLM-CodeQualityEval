/**https://leetcode.com/problems/maximum-number-of-non-overlapping-substrings/ */
//Given a string s of lowercase letters, you need to find the maximum number of non-empty substrings of s that meet the following conditions:
//	The substrings do not overlap, that is for any two substrings s[i..j] and s[x..y], either j < x or i > y is true.
//	A substring that contains a certain character c must also contain all occurrences of c.
//Find the maximum number of substrings that meet the above conditions. If there are multiple solutions with the same number of substrings, return the one with minimum total length. It can be shown that there exists a unique solution of minimum total length.
//Notice that you can return the substrings in any order.
// 
//Example 1:
//Input: s = "adefaddaccc"
//Output: ["e","f","ccc"]
//Explanation: The following are all the possible substrings that meet the conditions:
//[
//  "adefaddaccc"
//  "adefadda",
//  "ef",
//  "e",
//  "f",
//  "ccc",
//]
//If we choose the first string, we cannot choose anything else and we'd get only 1. If we choose "adefadda", we are left with "ccc" which is the only one that doesn't overlap, thus obtaining 2 substrings. Notice also, that it's not optimal to choose "ef" since it can be split into two. Therefore, the optimal way is to choose ["e","f","ccc"] which gives us 3 substrings. No other solution of the same number of substrings exist.
//Example 2:
//Input: s = "abbaccd"
//Output: ["d","bb","cc"]
//Explanation: Notice that while the set of substrings ["d","abba","cc"] also has length 3, it's considered incorrect since it has larger total length.
// 
//Constraints:
//	1 <= s.length <= 105
//	s contains only lowercase English letters.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** maxNumOfSubstrings(char* s, int* returnSize) {
       int n = strlen(s);
        int first[26], last[26];
        for (int i = 0; i < 26; i++) {
            first[i] = n;
            last[i] = -1;
        }
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            first[c] = fmin(first[c], i);
            last[c] = fmax(last[c], i);
        }
        int* left = (int*)malloc(sizeof(int) * n);
        int* right = (int*)malloc(sizeof(int) * n);
        for (int i = 0; i < n; i++) {
            left[i] = i;
            right[i] = i;
        }
        for (int i = 0; i < 26; i++) {
            for (int j = first[i]; j <= last[i]; j++) {
                left[j] = fmin(left[j], first[i]);
                right[j] = fmax(right[j], last[i]);
            }
        }
        int* end = (int*)malloc(sizeof(int) * n);
        for (int i = 0; i < n; i++) {
            end[i] = right[i];
        }
        for (int i = n - 2; i >= 0; i--) {
            end[i] = fmin(end[i], end[i + 1]);
        }
        int* dp = (int*)malloc(sizeof(int) * n);
        for (int i = 0; i < n; i++) {
            dp[i] = -1;
        }
        for (int i = 0; i < n; i++) {
            if (i == right[i]) {
                dp[i] = 1;
            }
        }
        for (int i = 0; i < n; i++) {
            if (dp[i] == -1) {
                dp[i] = dp[i - 1];
            }
        }
        int* stack = (int*)malloc(sizeof(int) * n);
        int top = -1;
        for (int i = 0; i < n; i++) {
            if (i == left[i]) {
                stack[++top] = i;
            }
        }
        while (top >= 0) {
            int i = stack[top--];
            if (end[i] == i) {
                continue;
            }
            if (dp[end[i]] == -1 || dp[end[i]] > dp[i] + 1) {
                dp[end[i]] = dp[i] + 1;
                stack[++top] = end[i];
            }
                }

                char** result = (char**)malloc(sizeof(char*) * n);
                *returnSize = 0;
                int prevEnd = -1;
                for (int i = 0; i < n; i++) {
                    if (i == left[i] && end[i] > prevEnd) {
                    int len = end[i] - i + 1;
                    result[*returnSize] = (char*)malloc(sizeof(char) * (len + 1));
                    strncpy(result[*returnSize], s + i, len);
                    result[*returnSize][len] = '\0';
                    (*returnSize)++;
                    prevEnd = end[i];
                    }
                }

                free(left);
                free(right);
                free(end);
                free(dp);
                free(stack);
                
                return result;
}