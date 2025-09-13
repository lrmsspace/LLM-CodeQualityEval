/*
 You are given a string s and a pattern string p, where p contains exactly two '*' characters.
 The '*' in p matches any sequence of zero or more characters.
 Return the length of the shortest substring in s that matches p. If there is no such substring, return -1.
 Note: The empty substring is considered valid.
 Example 1:
 Input: s = "abaacbaecebce", p = "ba*c*ce"
 Output: 8
 Explanation:
 The shortest matching substring of p in s is "baecebce".
 Example 2:
 Input: s = "baccbaadbc", p = "cc*baa*adb"
 Output: -1
 Explanation:
 There is no matching substring in s.
 Example 3:
 Input: s = "a", p = "**"
 Output: 0
 Explanation:
 The empty substring is the shortest matching substring.
 Example 4:
 Input: s = "madlogic", p = "*adlogi*"
 Output: 6
 Explanation:
 The shortest matching substring of p in s is "adlogi".
 Constraints:
 1 <= s.length <= 105
 2 <= p.length <= 105
 s contains only lowercase English letters.
 p contains only lowercase English letters and exactly two '*'.
*/
int shortestMatchingSubstring(char* s, char* p) {
    int n = strlen(s);
    int m = strlen(p);
    int firstStarIndex = -1;
    int secondStarIndex = -1;

    // Find the positions of the two '*' in the pattern
    for (int i = 0; i < m; i++) {
        if (p[i] == '*') {
            if (firstStarIndex == -1) {
                firstStarIndex = i;
            } else {
                secondStarIndex = i;
            }
        }
    }

    // If '*' locations are invalid, return -1
    if (firstStarIndex == -1 || secondStarIndex == -1 || firstStarIndex >= secondStarIndex) {
        return -1;
    }

    int minLength = INT_MAX;

    // Iterate over all possible starting points in s
    for (int start = 0; start < n; start++) {
        int i = start, j = 0;
        while (i < n && j < firstStarIndex && s[i] == p[j]) {
            i++;
            j++;
        }

        // If we matched up to the first '*', continue to match after the second '*'
        if (j == firstStarIndex) {
            int k = secondStarIndex + 1;
            while (i < n && k < m && s[i] == p[k]) {
                i++;
                k++;
            }

            // If we matched till the end of the pattern, calculate the length
            if (k == m) {
                minLength = (i - start < minLength) ? i - start : minLength;
            }
        }
    }

    return (minLength == INT_MAX) ? -1 : minLength;
}