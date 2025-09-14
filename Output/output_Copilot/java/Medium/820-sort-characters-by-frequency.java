/**https://leetcode.com/problems/sort-characters-by-frequency/ */
//Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.
//Return the sorted string. If there are multiple answers, return any of them.
// 
//Example 1:
//Input: s = "tree"
//Output: "eert"
//Explanation: 'e' appears twice while 'r' and 't' both appear once.
//So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
//Example 2:
//Input: s = "cccaaa"
//Output: "aaaccc"
//Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
//Note that "cacaca" is incorrect, as the same characters must be together.
//Example 3:
//Input: s = "Aabb"
//Output: "bbAa"
//Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
//Note that 'A' and 'a' are treated as two different characters.
// 
//Constraints:
//	1 <= s.length <= 5 * 105
//	s consists of uppercase and lowercase English letters and digits.
class Solution {
    public String frequencySort(String s) {
        int[] freq = new int[128]; // ASCII size
        for (char c : s.toCharArray()) {
            freq[c]++;
        }
        
        StringBuilder[] buckets = new StringBuilder[s.length() + 1];
        for (int i = 0; i < buckets.length; i++) {
            buckets[i] = new StringBuilder();
        }
        
        for (char c = 0; c < freq.length; c++) {
            if (freq[c] > 0) {
                buckets[freq[c]].append(c);
            }
        }
        
        StringBuilder result = new StringBuilder();
        for (int i = buckets.length - 1; i >= 0; i--) {
            if (buckets[i].length() > 0) {
                for (int j = 0; j < buckets[i].length(); j++) {
                    result.append(buckets[i].charAt(j), 0, i);
                }
            }
        }
        
        return result.toString();        
    }
}