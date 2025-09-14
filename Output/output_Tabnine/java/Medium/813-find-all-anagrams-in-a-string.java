/**https://leetcode.com/problems/find-all-anagrams-in-a-string/ */
//Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.
// 
//Example 1:
//Input: s = "cbaebabacd", p = "abc"
//Output: [0,6]
//Explanation:
//The substring with start index = 0 is "cba", which is an anagram of "abc".
//The substring with start index = 6 is "bac", which is an anagram of "abc".
//Example 2:
//Input: s = "abab", p = "ab"
//Output: [0,1,2]
//Explanation:
//The substring with start index = 0 is "ab", which is an anagram of "ab".
//The substring with start index = 1 is "ba", which is an anagram of "ab".
//The substring with start index = 2 is "ab", which is an anagram of "ab".
// 
//Constraints:
//	1 <= s.length, p.length <= 3 * 104
//	s and p consist of lowercase English letters.
class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        List<Integer> result = new ArrayList<>();
        if (s.length() < p.length()) return result;
        
        int[] charCount = new int[26];
        for (char c : p.toCharArray()) charCount[c - 'a']++;
        
        int left = 0, right = 0, matchCount = 0;
        while (right < s.length()) {
            char rightChar = s.charAt(right);
            charCount[rightChar - 'a']--;
            if (charCount[rightChar - 'a'] >= 0) matchCount++;
            
            if (right - left + 1 == p.length()) {
                if (matchCount == p.length()) result.add(left);
                charCount[s.charAt(left) - 'a']++;
                if (charCount[s.charAt(left) - 'a'] > 0) matchCount--;
                left++;
            }
            right++;
        }
        
        return result;
        
    }
}