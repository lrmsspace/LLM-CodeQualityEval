/**https://leetcode.com/problems/vowel-spellchecker/ */
//Given a wordlist, we want to implement a spellchecker that converts a query word into a correct word.
//For a given query word, the spell checker handles two categories of spelling mistakes:
//	Capitalization: If the query matches a word in the wordlist (case-insensitive), then the query word is returned with the same case as the case in the wordlist.
//	
//		Example: wordlist = ["yellow"], query = "YellOw": correct = "yellow"
//		Example: wordlist = ["Yellow"], query = "yellow": correct = "Yellow"
//		Example: wordlist = ["yellow"], query = "yellow": correct = "yellow"
//	
//	
//	Vowel Errors: If after replacing the vowels ('a', 'e', 'i', 'o', 'u') of the query word with any vowel individually, it matches a word in the wordlist (case-insensitive), then the query word is returned with the same case as the match in the wordlist.
//	
//		Example: wordlist = ["YellOw"], query = "yollow": correct = "YellOw"
//		Example: wordlist = ["YellOw"], query = "yeellow": correct = "" (no match)
//		Example: wordlist = ["YellOw"], query = "yllw": correct = "" (no match)
//	
//	
//In addition, the spell checker operates under the following precedence rules:
//	When the query exactly matches a word in the wordlist (case-sensitive), you should return the same word back.
//	When the query matches a word up to capitlization, you should return the first such match in the wordlist.
//	When the query matches a word up to vowel errors, you should return the first such match in the wordlist.
//	If the query has no matches in the wordlist, you should return the empty string.
//Given some queries, return a list of words answer, where answer[i] is the correct word for query = queries[i].
// 
//Example 1:
//Input: wordlist = ["KiTe","kite","hare","Hare"], queries = ["kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"]
//Output: ["kite","KiTe","KiTe","Hare","hare","","","KiTe","","KiTe"]
//Example 2:
//Input: wordlist = ["yellow"], queries = ["YellOw"]
//Output: ["yellow"]
// 
//Constraints:
//	1 <= wordlist.length, queries.length <= 5000
//	1 <= wordlist[i].length, queries[i].length <= 7
//	wordlist[i] and queries[i] consist only of only English letters.
class Solution {
    public String[] spellchecker(String[] wordlist, String[] queries) {
        Map<String, String> map1 = new HashMap<>();
        Map<String, String> map2 = new HashMap<>();
        Map<String, String> map3 = new HashMap<>();
        for (String word : wordlist) {
            String lower = word.toLowerCase();
            String cap = lower.substring(0, 1).toUpperCase() + lower.substring(1);
            String vows = lower.replaceAll("[aeiou]", "#");
            map1.putIfAbsent(lower, word);
            map2.putIfAbsent(cap, word);
            map3.putIfAbsent(vows, word);
        }
        String[] res = new String[queries.length];
        for (int i = 0; i < queries.length; i++) {
            String query = queries[i];
            String lower = query.toLowerCase();
            String cap = lower.substring(0, 1).toUpperCase() + lower.substring(1);
            String vows = lower.replaceAll("[aeiou]", "#");
            res[i] = map1.getOrDefault(query, map2.getOrDefault(cap, map3.get(vows)));
        }
        return res;
    }
}