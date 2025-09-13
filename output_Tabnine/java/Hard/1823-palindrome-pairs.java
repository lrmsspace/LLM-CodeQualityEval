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
        Map<String, Integer> map = new HashMap<>();
        for (int i = 0; i < words.length; i++) {
            map.put(words[i], i);
        }
        
        List<List<Integer>> result = new ArrayList<>();
        
        for (int i = 0; i < words.length; i++) {
            String word = words[i];
            int length = word.length();
            
            // Check for palindromes of length 1
            for (int j = 0; j < length; j++) {
                String prefix = word.substring(0, j);
                String suffix = word.substring(j);
                
                if (map.containsKey(suffix) && map.get(suffix)!= i) {
                    result.add(Arrays.asList(i, map.get(suffix)));
                }
                
                if (map.containsKey(prefix) && map.get(prefix)!= i && prefix.equals(new StringBuilder(prefix).reverse().toString())) {
                    result.add(Arrays.asList(map.get(prefix), i));
                }
            }
            
            // Check for palindromes of length greater than 1
            for (int j = 1; j < length; j++) {
                String substring = word.substring(j);
                String reversedSubstring = new StringBuilder(substring).reverse().toString();
                
                if (map.containsKey(reversedSubstring) && map.get(reversedSubstring)!= i) {
                    result.add(Arrays.asList(map.get(reversedSubstring), i));
                }
                
                String concat = substring + word.substring(0, j);
                if (map.containsKey(concat) && map.get(concat)!= i) {
                    result.add(Arrays.asList(i, map.get(concat)));
                }
                
                concat = word.substring(0, j) + substring;
                if (map.containsKey(concat) && map.get(concat)!= i) {
                    result.add(Arrays.asList(map.get(concat), i));
                }
            }
        }
        
        return result;
        
    }
}