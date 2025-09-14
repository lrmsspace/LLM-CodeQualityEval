/*
 You are given three strings: s1, s2, and s3. In one operation you can choose one of these strings and delete its rightmost character. Note that you cannot completely empty a string.
 Return the minimum number of operations required to make the strings equal. If it is impossible to make them equal, return -1.
 Example 1:
 Input: s1 = "abc", s2 = "abb", s3 = "ab"
 Output: 2
 Explanation: Deleting the rightmost character from both s1 and s2 will result in three equal strings.
 Example 2:
 Input: s1 = "dac", s2 = "bac", s3 = "cac"
 Output: -1
 Explanation: Since the first letters of s1 and s2 differ, they cannot be made equal.
 Constraints:
 1 <= s1.length, s2.length, s3.length <= 100
 s1, s2 and s3 consist only of lowercase English letters.
*/

class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
        int minLength = min({n1, n2, n3});

        for (int i = 0; i < minLength; ++i) {
            if (s1[n1 - 1 - i] != s2[n2 - 1 - i] || s1[n1 - 1 - i] != s3[n3 - 1 - i]) {
                return -1; // If any character doesn't match, return -1
            }
        }

        // The number of operations is the sum of the remaining characters in each string
        return (n1 - minLength) + (n2 - minLength) + (n3 - minLength);        
    }
};