/*
 You are given a binary string s of length n, where:
 '1' represents an active section.
 '0' represents an inactive section.
 You can perform at most one trade to maximize the number of active sections in s. In a trade, you:
 Convert a contiguous block of '1's that is surrounded by '0's to all '0's.
 Afterward, convert a contiguous block of '0's that is surrounded by '1's to all '1's.
 Return the maximum number of active sections in s after making the optimal trade.
 Note: Treat s as if it is augmented with a '1' at both ends, forming t = '1' + s + '1'. The augmented '1's do not contribute to the final count.
 Example 1:
 Input: s = "01"
 Output: 1
 Explanation:
 Because there is no block of '1's surrounded by '0's, no valid trade is possible. The maximum number of active sections is 1.
 Example 2:
 Input: s = "0100"
 Output: 4
 Explanation:
 String "0100" → Augmented to "101001".
 Choose "0100", convert "101001" → "100001" → "111111".
 The final string without augmentation is "1111". The maximum number of active sections is 4.
 Example 3:
 Input: s = "1000100"
 Output: 7
 Explanation:
 String "1000100" → Augmented to "110001001".
 Choose "000100", convert "110001001" → "110000001" → "111111111".
 The final string without augmentation is "1111111". The maximum number of active sections is 7.
 Example 4:
 Input: s = "01010"
 Output: 4
 Explanation:
 String "01010" → Augmented to "1010101".
 Choose "010", convert "1010101" → "1000101" → "1111101".
 The final string without augmentation is "11110". The maximum number of active sections is 4.
 Constraints:
 1 <= n == s.length <= 105
 s[i] is either '0' or '1'
*/

class Solution {
    public int maxActiveSectionsAfterTrade(String s) {
        int n = s.length();
        int maxActive = 0;
        int currentActive = 0;
        int leftZeros = 0;
        int rightZeros = 0;
        int totalActive = 0;

        // Count initial active sections and zero sections
        for (int i = 0; i < n; ++i) {
            if (s.charAt(i) == '1') {
                currentActive++;
            } else {
                if (currentActive > 0) {
                    maxActive = Math.max(maxActive, currentActive);
                    currentActive = 0;
                }
                if (i == 0 || s.charAt(i - 1) == '1') {
                    leftZeros = 1;
                } else {
                    leftZeros++;
                }
            }
            totalActive += (s.charAt(i) == '1') ? 1 : 0;
        }
        
        maxActive = Math.max(maxActive, currentActive);
        
        // Try to perform the trade operation
        for (int i = 1; i < n - 1; ++i) {
            if (s.charAt(i) == '0' && s.charAt(i - 1) == '1' && s.charAt(i + 1) == '1') {
                maxActive = Math.max(maxActive, totalActive + leftZeros + rightZeros);
            }
            if (s.charAt(i) == '0') {
                rightZeros = 1;
            } else {
                rightZeros++;
            }
        }

        return maxActive;

    }
}