/**https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-subsequences/ */
//Given a string s, find two disjoint palindromic subsequences of s such that the product of their lengths is maximized. The two subsequences are disjoint if they do not both pick a character at the same index.
//Return the maximum possible product of the lengths of the two palindromic subsequences.
//A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters. A string is palindromic if it reads the same forward and backward.
// 
//Example 1:
//Input: s = "leetcodecom"
//Output: 9
//Explanation: An optimal solution is to choose "ete" for the 1st subsequence and "cdc" for the 2nd subsequence.
//The product of their lengths is: 3 * 3 = 9.
//Example 2:
//Input: s = "bb"
//Output: 1
//Explanation: An optimal solution is to choose "b" (the first character) for the 1st subsequence and "b" (the second character) for the 2nd subsequence.
//The product of their lengths is: 1 * 1 = 1.
//Example 3:
//Input: s = "accbcaxxcxx"
//Output: 25
//Explanation: An optimal solution is to choose "accca" for the 1st subsequence and "xxcxx" for the 2nd subsequence.
//The product of their lengths is: 5 * 5 = 25.
// 
//Constraints:
//	2 <= s.length <= 12
//	s consists of lowercase English letters only.
class Solution {
    public int maxProduct(String s) {
        int n = s.length();
        int maxProduct = 0;

        for (int mask1 = 0; mask1 < (1 << n); mask1++) {
            StringBuilder sb1 = new StringBuilder();
            for (int i = 0; i < n; i++) {
                if ((mask1 & (1 << i)) != 0) {
                    sb1.append(s.charAt(i));
                }
            }
            if (!isPalindrome(sb1.toString())) continue;

            for (int mask2 = 0; mask2 < (1 << n); mask2++) {
                if ((mask1 & mask2) != 0) continue;

                StringBuilder sb2 = new StringBuilder();
                for (int i = 0; i < n; i++) {
                    if ((mask2 & (1 << i)) != 0) {
                        sb2.append(s.charAt(i));
                    }
                }
                
                if (isPalindrome(sb2.toString())) {
                    int product = sb1.length() * sb2.length();
                    maxProduct = Math.max(maxProduct, product);
                }
            }
        }

        return maxProduct;
    }

    private boolean isPalindrome(String s) {
        int l = 0, r = s.length() - 1;
        while (l < r) {
            if (s.charAt(l++) != s.charAt(r--)) {
                return false;
            }
        }
        return true;
    }
    
}