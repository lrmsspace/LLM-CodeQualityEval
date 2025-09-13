/**https://leetcode.com/problems/find-the-closest-palindrome/ */
//Given a string n representing an integer, return the closest integer (not including itself), which is a palindrome. If there is a tie, return the smaller one.
//The closest is defined as the absolute difference minimized between two integers.
// 
//Example 1:
//Input: n = "123"
//Output: "121"
//Example 2:
//Input: n = "1"
//Output: "0"
//Explanation: 0 and 2 are the closest palindromes but we return the smallest which is 0.
// 
//Constraints:
//	1 <= n.length <= 18
//	n consists of only digits.
//	n does not have leading zeros.
//	n is representing an integer in the range [1, 1018 - 1].
class Solution {
    public String nearestPalindromic(String n) {
        // 1. Generate all possible candidates
        Set<String> candidates = new HashSet<>();
        int len = n.length();
        long num = Long.parseLong(n);
        // 2. Add the edge cases: 10^len and 10^(len-1) - 1
        candidates.add(String.valueOf((long) Math.pow(10, len) + 1)); // 1000...001
        candidates.add(String.valueOf((long) Math.pow(10, len - 1) - 1)); // 999...999

        // 3. Generate the prefix and its mirror
        String prefix = n.substring(0, (len + 1) / 2);
        for (int i = -1; i <= 1; i++) {
            String newPrefix = String.valueOf(Long.parseLong(prefix) + i);
            StringBuilder sb = new StringBuilder(newPrefix);
            if (len % 2 == 0) {
                candidates.add(newPrefix + sb.reverse().toString());
            } else {
                candidates.add(newPrefix + sb.reverse().substring(1).toString());
            }
        }

        // 4. Find the closest palindrome
        String closestPalindrome = null;
        long minDiff = Long.MAX_VALUE;
        for (String candidate : candidates) {
            if (candidate.equals(n)) continue; // Skip the original number
            long candidateNum = Long.parseLong(candidate);
            long diff = Math.abs(candidateNum - num);
            if (diff < minDiff || (diff == minDiff && candidateNum < Long.parseLong(closestPalindrome))) {
                closestPalindrome = candidate;
                minDiff = diff;
            }
        }
        return closestPalindrome;        
    }
}