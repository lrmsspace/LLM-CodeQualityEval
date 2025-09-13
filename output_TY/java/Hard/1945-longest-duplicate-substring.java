/**https://leetcode.com/problems/longest-duplicate-substring/ */
//Given a string s, consider all duplicated substrings: (contiguous) substrings of s that occur 2 or more times. The occurrences may overlap.
//Return any duplicated substring that has the longest possible length. If s does not have a duplicated substring, the answer is "".
// 
//Example 1:
//Input: s = "banana"
//Output: "ana"
//Example 2:
//Input: s = "abcd"
//Output: ""
// 
//Constraints:
//	2 <= s.length <= 3 * 104
//	s consists of lowercase English letters.
class Solution {
    public String longestDupSubstring(String s) {
        int n = s.length();
        int[] p = new int[n];
        int[] pows = new int[n];
        pows[0] = 1;
        for(int i = 0; i < n; i++){
            p[i] = (s.charAt(i) - 'a' + 1);
            if(i > 0){
                p[i] += p[i-1] * 27;
            }
            pows[i] = pows[i-1] * 27;
        }
        int l = 0, r = n;
        while(l < r){
            int m = (l + r) / 2;
            if(check(p, pows, m)){
                l = m + 1;
            }else{
                r = m;
            }
        }   
        return l - 1;
        
    }
}