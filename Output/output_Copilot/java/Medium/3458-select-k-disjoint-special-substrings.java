/*
 Given a string s of length n and an integer k, determine whether it is possible to select k disjoint special substrings.
 A special substring is a substring where:
 Any character present inside the substring should not appear outside it in the string.
 The substring is not the entire string s.
 Note that all k substrings must be disjoint, meaning they cannot overlap.
 Return true if it is possible to select k such disjoint special substrings; otherwise, return false.
 Example 1:
 Input: s = "abcdbaefab", k = 2
 Output: true
 Explanation:
 We can select two disjoint special substrings: "cd" and "ef".
 "cd" contains the characters 'c' and 'd', which do not appear elsewhere in s.
 "ef" contains the characters 'e' and 'f', which do not appear elsewhere in s.
 Example 2:
 Input: s = "cdefdc", k = 3
 Output: false
 Explanation:
 There can be at most 2 disjoint special substrings: "e" and "f". Since k = 3, the output is false.
 Example 3:
 Input: s = "abeabe", k = 0
 Output: true
 Constraints:
 2 <= n == s.length <= 5 * 104
 0 <= k <= 26
 s consists only of lowercase English letters.
*/

class Solution {
    public boolean maxSubstringLength(String s, int k) {
        int n = s.length();
        if (k == 0) return true; // If k is 0, we can always select 0 substrings.

        // Count the frequency of each character in the string.
        int[] freq = new int[26];
        for (char c : s.toCharArray()) {
            freq[c - 'a']++;
        }

        // Find special substrings
        int specialCount = 0;
        boolean[] visited = new boolean[26]; // To track characters already used in special substrings

        for (int i = 0; i < n; i++) {
            if (visited[s.charAt(i) - 'a']) continue; // Skip if character is already used

            // Start a new special substring
            int j = i;
            while (j < n && !visited[s.charAt(j) - 'a']) {
                visited[s.charAt(j) - 'a'] = true; // Mark character as used
                j++;
            }

            // We found a special substring from i to j-1
            specialCount++;
            if (specialCount >= k) return true; // If we found enough special substrings, return true

            i = j - 1; // Move to the end of the current special substring
        }

        return false; // Not enough special substrings found        
    }
}