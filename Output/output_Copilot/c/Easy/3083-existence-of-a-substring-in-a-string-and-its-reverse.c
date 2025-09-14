/*
 Given a string s, find any substring of length 2 which is also present in the reverse of s.
 Return true if such a substring exists, and false otherwise.
 Example 1:
 Input: s = "leetcode"
 Output: true
 Explanation: Substring "ee" is of length 2 which is also present in reverse(s) == "edocteel".
 Example 2:
 Input: s = "abcba"
 Output: true
 Explanation: All of the substrings of length 2 "ab", "bc", "cb", "ba" are also present in reverse(s) == "abcba".
 Example 3:
 Input: s = "abcd"
 Output: false
 Explanation: There is no substring of length 2 in s, which is also present in the reverse of s.
 Constraints:
 1 <= s.length <= 100
 s consists only of lowercase English letters.
*/

bool isSubstringPresent(char* s) {
    int length = strlen(s);
    for (int i = 0; i < length - 1; i++) {
        // Check the substring s[i:i+2]
        char substring[3] = {s[i], s[i + 1], '\0'};
        
        // Check if the substring is present in the reverse of s
        for (int j = length - 2; j >= 0; j--) {
            if (s[j] == substring[0] && s[j + 1] == substring[1]) {
                return true; // Found a matching substring
            }
        }
    }
    return false; // No matching substring found
}