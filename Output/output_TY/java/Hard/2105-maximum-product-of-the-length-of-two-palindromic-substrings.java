/**https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-substrings/ */
//You are given a 0-indexed string s and are tasked with finding two non-intersecting palindromic substrings of odd length such that the product of their lengths is maximized.
//More formally, you want to choose four integers i, j, k, l such that 0 <= i <= j < k <= l < s.length and both the substrings s[i...j] and s[k...l] are palindromes and have odd lengths. s[i...j] denotes a substring from index i to index j inclusive.
//Return the maximum possible product of the lengths of the two non-intersecting palindromic substrings.
//A palindrome is a string that is the same forward and backward. A substring is a contiguous sequence of characters in a string.
// 
//Example 1:
//Input: s = "ababbb"
//Output: 9
//Explanation: Substrings "aba" and "bbb" are palindromes with odd length. product = 3 * 3 = 9.
//Example 2:
//Input: s = "zaaaxbbby"
//Output: 9
//Explanation: Substrings "aaa" and "bbb" are palindromes with odd length. product = 3 * 3 = 9.
// 
//Constraints:
//	2 <= s.length <= 105
//	s consists of lowercase English letters.
class Solution {
    public long maxProduct(String s) {
        int n=s.length(),max=0;
        for(int i=1;i<(1<<n);i++){
            StringBuilder sb=new StringBuilder();
            for(int j=0;j<n;j++){
                if((i&(1<<j))>0){
                    sb.append(s.charAt(j));
                }
            }
            StringBuilder sb2=new StringBuilder(sb);
            sb2.reverse();
            if(sb.toString().equals(sb2.toString())){
                max=Math.max(max,sb.length()*sb2.length());
            }
        }
        return max;
         
    }
}