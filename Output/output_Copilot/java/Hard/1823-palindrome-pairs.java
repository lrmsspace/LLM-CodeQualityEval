/**https://leetcode.com/problems/palindrome-pairs/ */
//You are given a 0-indexed array of unique strings words.
//A palindrome pair is a pair of integers (i, j) such that:
//	0 <= i, j < words.length,
//	i != j, and
//	words[i] + words[j] (the concatenation of the two strings) is a palindrome.
//Return an array of all the palindrome pairs of words.
//You must write an algorithm with O(sum of words[i].length) runtime complexity.
// 
//Example 1:
//Input: words = ["abcd","dcba","lls","s","sssll"]
//Output: [[0,1],[1,0],[3,2],[2,4]]
//Explanation: The palindromes are ["abcddcba","dcbaabcd","slls","llssssll"]
//Example 2:
//Input: words = ["bat","tab","cat"]
//Output: [[0,1],[1,0]]
//Explanation: The palindromes are ["battab","tabbat"]
//Example 3:
//Input: words = ["a",""]
//Output: [[0,1],[1,0]]
//Explanation: The palindromes are ["a","a"]
// 
//Constraints:
//	1 <= words.length <= 5000
//	0 <= words[i].length <= 300
//	words[i] consists of lowercase English letters.
class Solution {
    public List<List<Integer>> palindromePairs(String[] words) {
           List<List<Integer>> result = new ArrayList<>();
            Map<String, Integer> wordMap = new HashMap<>();
    
            for (int i = 0; i < words.length; i++) {
                wordMap.put(words[i], i);
            }
    
            for (int i = 0; i < words.length; i++) {
                String word = words[i];
                int wordLen = word.length();
    
                for (int j = 0; j <= wordLen; j++) {
                    String prefix = word.substring(0, j);
                    String suffix = word.substring(j);
    
                    if (isPalindrome(prefix)) {
                        String reversedSuffix = new StringBuilder(suffix).reverse().toString();
                        if (wordMap.containsKey(reversedSuffix) && wordMap.get(reversedSuffix) != i) {
                            result.add(Arrays.asList(wordMap.get(reversedSuffix), i));
                        }
                    }
    
                    if (j < wordLen && isPalindrome(suffix)) {
                        String reversedPrefix = new StringBuilder(prefix).reverse().toString();
                        if (wordMap.containsKey(reversedPrefix) && wordMap.get(reversedPrefix) != i) {
                            result.add(Arrays.asList(i, wordMap.get(reversedPrefix)));
                        }
                    }
                }
            }
    
            return result;     
    }
}