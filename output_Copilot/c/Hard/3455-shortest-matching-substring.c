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
    int firstStar = -1, secondStar = -1;

    // Find the positions of the two '*' characters in p
    for (int i = 0; i < m; i++) {
        if (p[i] == '*') {
            if (firstStar == -1) {
                firstStar = i;
            } else {
                secondStar = i;
                break;
            }
        }
    }

    // If we don't find two stars, return -1
    if (secondStar == -1) {
        return -1;
    }

    // Check all possible starting points for the first star
    int minLength = n + 1; // Initialize to a value larger than any possible substring length
    for (int start = 0; start <= n; start++) {
        int endFirstStar = start + firstStar;
        if (endFirstStar > n) break; // If the first star goes out of bounds

        // Check the substring from start to endFirstStar
        int matchLength = endFirstStar - start;

        // Now check for the second star
        for (int endSecondStar = endFirstStar + secondStar + 1; endSecondStar <= n; endSecondStar++) {
            if (s[endFirstStar] == p[firstStar + 1] && s[endSecondStar - 1] == p[secondStar - 1]) {
                matchLength += endSecondStar - endFirstStar - 1;
                minLength = matchLength < minLength ? matchLength : minLength;
            }
        }
    }

    return minLength == n + 1 ? -1 : minLength;
    
}