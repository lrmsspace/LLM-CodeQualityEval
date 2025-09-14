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
        // Base case: If k is 0, return true since we can select no special substring
        if (k == 0) {
            return true;
        }
        
        // Base case: If k is greater than the number of unique characters in s, return false since we cannot select k disjoint special substrings
        if (k > new HashSet<>(s.chars()).size()) {
            return false;
        }
        
        // Initialize a boolean array dp of size n+1 to keep track of whether the substring ending at index i can be a special substring
        boolean[] dp = new boolean[s.length() + 1];
        
        // Initialize a variable maxLength to keep track of the maximum length of a special substring
        int maxLength = 0;  

        // Iterate through the string s from left to right
        for (int i = 1; i <= s.length(); i++) {
            // Iterate through the substring ending at index i-1
            for (int j = i - 1; j >= 0; j--) {
                // Check if the substring ending at index i-1 is a special substring
                if (dp[j] && s.charAt(j) == s.charAt(i - 1)) {
                    // Update the maxLength if necessary
                    maxLength = Math.max(maxLength, i - j);
                    // Mark the substring ending at index i as a special substring
                    dp[i] = true;
                    break;
                }
            }
        }
        
        // Return true if the maximum length of a special substring is greater than or equal to k
        return maxLength >= k;  
        
    }
}