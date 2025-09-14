/**https://leetcode.com/problems/longest-word-in-dictionary/ */
//Given an array of strings words representing an English Dictionary, return the longest word in words that can be built one character at a time by other words in words.
//If there is more than one possible answer, return the longest word with the smallest lexicographical order. If there is no answer, return the empty string.
//Note that the word should be built from left to right with each additional character being added to the end of a previous word. 
// 
//Example 1:
//Input: words = ["w","wo","wor","worl","world"]
//Output: "world"
//Explanation: The word "world" can be built one character at a time by "w", "wo", "wor", and "worl".
//Example 2:
//Input: words = ["a","banana","app","appl","ap","apply","apple"]
//Output: "apple"
//Explanation: Both "apply" and "apple" can be built from other words in the dictionary. However, "apple" is lexicographically smaller than "apply".
// 
//Constraints:
//	1 <= words.length <= 1000
//	1 <= words[i].length <= 30
//	words[i] consists of lowercase English letters. 
class Solution {
    public String longestWord(String[] words) {
        String result = "";
        HashSet<String> set = new HashSet<>();
        for (String word : words) set.add(word);
        for (String word : words) {
            if (word.length() > result.length() || 
                word.length() == result.length() && word.compareTo(result) < 0) {
                boolean valid = true;
                for (int i = 1; i < word.length(); i++) {
                    if (!set.contains(word.substring(0, i))) {
                        valid = false;
                        break;
                    }
                }
                if (valid) result = word;
            }
        }
        return result;      
    }
}