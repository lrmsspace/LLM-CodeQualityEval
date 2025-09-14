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
        int[] pCount = new int[26];
        int[] sCount = new int[26];
        int pLength = p.length();
        int sLength = s.length();
        for (int i = 0; i < pLength; i++) {
            pCount[p.charAt(i) - 'a']++;
        }
        int start = 0;
        int end = 0;
        while (end < sLength) {
            sCount[s.charAt(end) - 'a']++;
            if (end - start + 1 == pLength) {
                if (Arrays.equals(pCount,sCount)) {
                    result.add(start);
                }
            }
        }
        return result;
    }
}