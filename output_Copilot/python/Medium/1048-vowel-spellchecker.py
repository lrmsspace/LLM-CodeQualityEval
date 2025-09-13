#https://leetcode.com/problems/vowel-spellchecker/
#Given a wordlist, we want to implement a spellchecker that converts a query word into a correct word.
#For a given query word, the spell checker handles two categories of spelling mistakes:
#	Capitalization: If the query matches a word in the wordlist (case-insensitive), then the query word is returned with the same case as the case in the wordlist.
#	
#		Example: wordlist = ["yellow"], query = "YellOw": correct = "yellow"
#		Example: wordlist = ["Yellow"], query = "yellow": correct = "Yellow"
#		Example: wordlist = ["yellow"], query = "yellow": correct = "yellow"
#	
#	
#	Vowel Errors: If after replacing the vowels ('a', 'e', 'i', 'o', 'u') of the query word with any vowel individually, it matches a word in the wordlist (case-insensitive), then the query word is returned with the same case as the match in the wordlist.
#	
#		Example: wordlist = ["YellOw"], query = "yollow": correct = "YellOw"
#		Example: wordlist = ["YellOw"], query = "yeellow": correct = "" (no match)
#		Example: wordlist = ["YellOw"], query = "yllw": correct = "" (no match)
#	
#	
#In addition, the spell checker operates under the following precedence rules:
#	When the query exactly matches a word in the wordlist (case-sensitive), you should return the same word back.
#	When the query matches a word up to capitlization, you should return the first such match in the wordlist.
#	When the query matches a word up to vowel errors, you should return the first such match in the wordlist.
#	If the query has no matches in the wordlist, you should return the empty string.
#Given some queries, return a list of words answer, where answer[i] is the correct word for query = queries[i].
# 
#Example 1:
#Input: wordlist = ["KiTe","kite","hare","Hare"], queries = ["kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"]
#Output: ["kite","KiTe","KiTe","Hare","hare","","","KiTe","","KiTe"]
#Example 2:
#Input: wordlist = ["yellow"], queries = ["YellOw"]
#Output: ["yellow"]
# 
#Constraints:
#	1 <= wordlist.length, queries.length <= 5000
#	1 <= wordlist[i].length, queries[i].length <= 7
#	wordlist[i] and queries[i] consist only of only English letters.
class Solution(object):
    def spellchecker(self, wordlist, queries):
        """
        :type wordlist: List[str]
        :type queries: List[str]
        :rtype: List[str]
        """
        # Create a set for the wordlist for O(1) lookups
        word_set = set(wordlist)
        
        # Create a dictionary to map lowercase words to their original form
        lower_map = {}
        for word in wordlist:
            lower_map[word.lower()] = word
        
        # Create a dictionary to map vowel-replaced words to their original form
        vowel_map = {}
        vowels = 'aeiou'
        
        for word in wordlist:
            # Replace vowels with a placeholder character (e.g., '*')
            vowel_replaced = ''.join('*' if c in vowels else c for c in word.lower())
            if vowel_replaced not in vowel_map:
                vowel_map[vowel_replaced] = word
        
        result = []
        
        for query in queries:
            if query in word_set:
                result.append(query)    
            elif query.lower() in lower_map:
                result.append(lower_map[query.lower()])
            else:
                # Replace vowels in the query
                vowel_query = ''.join('*' if c in vowels else c for c in query.lower())
                if vowel_query in vowel_map:
                    result.append(vowel_map[vowel_query])
                else:
                    result.append('')

                    return result   
                