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

class Solution {
    public int shortestMatchingSubstring(String s, String p) {
        int n = s.length();
        int m = p.length();
        int firstStarIndex = -1;
        int secondStarIndex = -1;

        // Find the positions of the two '*' in the pattern
        for (int i = 0; i < m; i++) {
            if (p.charAt(i) == '*') {
                if (firstStarIndex == -1) {
                    firstStarIndex = i;
                } else {
                    secondStarIndex = i;
                    break;
                }
            }
        }

        // If '*' locations are invalid, return -1
        if (firstStarIndex == -1 || secondStarIndex == -1 || firstStarIndex >= secondStarIndex) {
            return -1;
        }

        // Iterate over each possible starting point in s
        int minLength = Integer.MAX_VALUE;
        for (int start = 0; start < n; start++) {
            int sIndex = start;
            int pIndex = 0;
            boolean isMatching = true;

            // Match the pattern before the first '*'
            while (pIndex < firstStarIndex && sIndex < n) {
                if (s.charAt(sIndex) != p.charAt(pIndex)) {
                    isMatching = false;
                    break;
                }
                sIndex++;
                pIndex++;
            }

            if (!isMatching || pIndex != firstStarIndex) {
                continue;
            }

            // Skip matching for the first '*'
            sIndex++;

            // Match the pattern between the two '*'
            pIndex = firstStarIndex + 1;
            while (pIndex < secondStarIndex && sIndex < n) {
                if (s.charAt(sIndex) != p.charAt(pIndex)) {
                    isMatching = false;
                    break;
                }
                sIndex++;
                pIndex++;
            }

            if (!isMatching || pIndex != secondStarIndex) {
                continue;
            }

            // Skip matching for the second '*'
            sIndex++;

            // Match the pattern after the second '*'
            pIndex = secondStarIndex + 1;
            while (pIndex < m && sIndex < n) {
                if (s.charAt(sIndex) != p.charAt(pIndex)) {
                    isMatching = false;
                    break;
                }
                sIndex++;
                pIndex++;
            }

            if (isMatching && pIndex == m) {
                minLength = Math.min(minLength, sIndex - start);
            }
        }

        return minLength == Integer.MAX_VALUE ? -1 : minLength;

    }
}