/**https://leetcode.com/problems/word-subsets/ */
//You are given two string arrays words1 and words2.
//A string b is a subset of string a if every letter in b occurs in a including multiplicity.
//	For example, "wrr" is a subset of "warrior" but is not a subset of "world".
//A string a from words1 is universal if for every string b in words2, b is a subset of a.
//Return an array of all the universal strings in words1. You may return the answer in any order.
// 
//Example 1:
//Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["e","o"]
//Output: ["facebook","google","leetcode"]
//Example 2:
//Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["l","e"]
//Output: ["apple","google","leetcode"]
// 
//Constraints:
//	1 <= words1.length, words2.length <= 104
//	1 <= words1[i].length, words2[i].length <= 10
//	words1[i] and words2[i] consist only of lowercase English letters.
//	All the strings of words1 are unique.
class Solution {
    public List<String> wordSubsets(String[] words1, String[] words2) {
        Map<Character, Integer> wordCount = new HashMap<>();
        for (String word : words2) {
            Map<Character, Integer> count = new HashMap<>();
            for (char c : word.toCharArray()) {
                count.put(c, count.getOrDefault(c, 0) + 1);
            }
            for (Map.Entry<Character, Integer> entry : count.entrySet()) {
                char c = entry.getKey();
                int value = entry.getValue();
                if (!wordCount.containsKey(c) || wordCount.get(c) < value) {
                    wordCount.put(c, value);
                }
            }
        }
        
        List<String> result = new ArrayList<>();
        for (String word : words1) {
            boolean isUniversal = true;
            for (Map.Entry<Character, Integer> entry : wordCount.entrySet()) {
                char c = entry.getKey();
                int value = entry.getValue();
                if (word.indexOf(c) == -1 || word.substring(word.indexOf(c)).length() < value) {
                    isUniversal = false;
                    break;
                }
            }
            if (isUniversal) {
                result.add(word);
            }
        }
        return result;
        
    }
}