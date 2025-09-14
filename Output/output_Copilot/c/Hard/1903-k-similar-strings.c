/**https://leetcode.com/problems/k-similar-strings/ */
//Strings s1 and s2 are k-similar (for some non-negative integer k) if we can swap the positions of two letters in s1 exactly k times so that the resulting string equals s2.
//Given two anagrams s1 and s2, return the smallest k for which s1 and s2 are k-similar.
// 
//Example 1:
//Input: s1 = "ab", s2 = "ba"
//Output: 1
//Explanation: The two string are 1-similar because we can use one swap to change s1 to s2: "ab" --> "ba".
//Example 2:
//Input: s1 = "abc", s2 = "bca"
//Output: 2
//Explanation: The two strings are 2-similar because we can use two swaps to change s1 to s2: "abc" --> "bac" --> "bca".
// 
//Constraints:
//	1 <= s1.length <= 20
//	s2.length == s1.length
//	s1 and s2 contain only lowercase letters from the set {'a', 'b', 'c', 'd', 'e', 'f'}.
//	s2 is an anagram of s1.
int kSimilarity(char* s1, char* s2) {
    int n = strlen(s1);
    if (strcmp(s1, s2) == 0) return 0;
    char* s = (char*)malloc((n + 1) * sizeof(char));
    strcpy(s, s1);
    int result = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (s[i] != s2[i]) {
            for (int j = i + 1; j < n; j++) {
                if (s[j] == s2[i]) {
                    s[j] = s[i];
                    s[i] = s2[i];
                    result = fmin(result, 1 + kSimilarity(s, s2));
                    s[i] = s[j];
                    s[j] = s2[i];
                }
            }
            break;
        }
    }
    free(s);
    return result;   
}