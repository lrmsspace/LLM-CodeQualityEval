/*
 Given a string s, you need to partition it into one or more balanced substrings. For example, if s == "ababcc" then ("abab", "c", "c"), ("ab", "abc", "c"), and ("ababcc") are all valid partitions, but ("a", "bab", "cc"), ("aba", "bc", "c"), and ("ab", "abcc") are not. The unbalanced substrings are bolded.
 Return the minimum number of substrings that you can partition s into.
 Note: A balanced string is a string where each character in the string occurs the same number of times.
 Example 1:
 Input: s = "fabccddg"
 Output: 3
 Explanation:
 We can partition the string s into 3 substrings in one of the following ways: ("fab, "ccdd", "g"), or ("fabc", "cd", "dg").
 Example 2:
 Input: s = "abababaccddb"
 Output: 2
 Explanation:
 We can partition the string s into 2 substrings like so: ("abab", "abaccddb").
 Constraints:
 1 <= s.length <= 1000
 s consists only of English lowercase letters.
*/

class Solution {
    public int minimumSubstringsInPartition(String s) {
        int n = s.length();
        int[] count = new int[26];
        for (char c : s.toCharArray()) {
            count[c - 'a']++;
        }
        
        int minCount = Integer.MAX_VALUE;
        for (int i = 0; i < 26; i++) {
            if (count[i] % 2!= 0) {
                minCount = Math.min(minCount, count[i] / 2);
            }
        }
        
        if (minCount == Integer.MAX_VALUE) {
            return 0;
        }
        
        int left = 0;
        int right = 0;  
        int unbalancedCount = 0;
        while (right < n) {
            count[s.charAt(right) - 'a']--;
            if (count[s.charAt(right) - 'a'] % 2!= 0) {
                unbalancedCount++;
            }
            while (unbalancedCount > minCount) {
                count[s.charAt(left) - 'a']++;
                if (count[s.charAt(left) - 'a'] % 2 == 0) {
                    unbalancedCount--;
                }
                left++;
            }
            minCount = Math.min(minCount, right - left + 1);
            right++;
    
            // System.out.println("left: " + left + ", right: " + right + ", unbalancedCount: " + unbalancedCount + ", minCount: " + minCount);
        }
        return minCount;
        
    }
}