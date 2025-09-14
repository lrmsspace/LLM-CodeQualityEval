/**https://leetcode.com/problems/count-anagrams/ */
//You are given a string s containing one or more words. Every consecutive pair of words is separated by a single space ' '.
//A string t is an anagram of string s if the ith word of t is a permutation of the ith word of s.
//	For example, "acb dfe" is an anagram of "abc def", but "def cab" and "adc bef" are not.
//Return the number of distinct anagrams of s. Since the answer may be very large, return it modulo 109 + 7.
// 
//Example 1:
//Input: s = "too hot"
//Output: 18
//Explanation: Some of the anagrams of the given string are "too hot", "oot hot", "oto toh", "too toh", and "too oht".
//Example 2:
//Input: s = "aa"
//Output: 1
//Explanation: There is only one anagram possible for the given string.
// 
//Constraints:
//	1 <= s.length <= 105
//	s consists of lowercase English letters and spaces ' '.
//	There is single space between consecutive words.
int countAnagrams(char* s) {
    int MOD = 1000000007;
    int n = strlen(s);
    int* dp = (int*)malloc(n * sizeof(int));
    dp[0] = 1;
    for (int i = 1; i < n; i++) {
        if (s[i - 1] == ' ') {
            dp[i] = dp[i - 1];
        } else {
            dp[i] = (dp[i - 1] * 2) % MOD;
        }
    }
    int result = 1;
    int start = 0;
    for (int i = 0; i <= n; i++) {
        if (i == n || s[i] == ' ') {
            int count[26] = { 0 };
            for (int j = start; j < i; j++) {
                count[s[j] - 'a']++;
            }
            int total = 1;
            for (int j = 0; j < 26; j++) {
                if (count[j] > 0) {
                    total = (total * dp[count[j]]) % MOD;
                }
            }
            result = (result * total) % MOD;
            start = i + 1;
        }
    }
    free(dp);
    return result;
}