/*
 You are given a string s and a character c. Return the total number of substrings of s that start and end with c.
 Example 1:
 Input: s = "abada", c = "a"
 Output: 6
 Explanation: Substrings starting and ending with "a" are: "abada", "abada", "abada", "abada", "abada", "abada".
 Example 2:
 Input: s = "zzz", c = "z"
 Output: 6
 Explanation: There are a total of 6 substrings in s and all start and end with "z".
 Constraints:
 1 <= s.length <= 105
 s and c consist only of lowercase English letters.
*/

class Solution {
    public long countSubstrings(String s, char c) {
        long count = 0;
        int i = 0;
        while(i < s.length()){
            int j = i;
            while(j < s.length() && s.charAt(j) != c){
                j++;
            }
            int k = j;
            while(k < s.length() && s.charAt(k) == c){
                k++;
            }
            count += (j - i) * (k - j);
            i = j;
        }
        return count;       
    }
}