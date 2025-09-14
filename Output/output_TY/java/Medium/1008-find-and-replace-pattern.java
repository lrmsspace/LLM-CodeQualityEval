/**https://leetcode.com/problems/find-and-replace-pattern/ */
//Given a list of strings words and a string pattern, return a list of words[i] that match pattern. You may return the answer in any order.
//A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.
//Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.
// 
//Example 1:
//Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
//Output: ["mee","aqq"]
//Explanation: "mee" matches the pattern because there is a permutation {a -> m, b -> e, ...}. 
//"ccc" does not match the pattern because {a -> c, b -> c, ...} is not a permutation, since a and b map to the same letter.
//Example 2:
//Input: words = ["a","b","c"], pattern = "a"
//Output: ["a","b","c"]
// 
//Constraints:
//	1 <= pattern.length <= 20
//	1 <= words.length <= 50
//	words[i].length == pattern.length
//	pattern and words[i] are lowercase English letters.
class Solution {
    public List<String> findAndReplacePattern(String[] words, String pattern) {
        List<String> result = new ArrayList<>();
        for (String word : words) {
            if (isMatch(word, pattern)) {
                result.add(word);
            }
        }
        return result;
    }

    private boolean isMatch(String word, String pattern) {
        Map<Character, Character> map = new HashMap<>();
        for (int i = 0; i < word.length(); i++) {
            char c1 = word.charAt(i);
            char c2 = pattern.charAt(i);
            if (map.containsKey(c1)) {
                if (map.get(c1) != c2) {
                   return false;
                }
            }
            else {
                if (map.containsValue(c2)) {
                    return false;
                }
                map.put(c1, c2);
            }
    }
    return true;
    }
}