#https://leetcode.com/problems/extra-characters-in-a-string/
#You are given a 0-indexed string s and a dictionary of words dictionary. You have to break s into one or more non-overlapping substrings such that each substring is present in dictionary. There may be some extra characters in s which are not present in any of the substrings.
#Return the minimum number of extra characters left over if you break up s optimally.
# 
#Example 1:
#Input: s = "leetscode", dictionary = ["leet","code","leetcode"]
#Output: 1
#Explanation: We can break s in two substrings: "leet" from index 0 to 3 and "code" from index 5 to 8. There is only 1 unused character (at index 4), so we return 1.
#Example 2:
#Input: s = "sayhelloworld", dictionary = ["hello","world"]
#Output: 3
#Explanation: We can break s in two substrings: "hello" from index 3 to 7 and "world" from index 8 to 12. The characters at indices 0, 1, 2 are not used in any substring and thus are considered as extra characters. Hence, we return 3.
# 
#Constraints:
#	1 <= s.length <= 50
#	1 <= dictionary.length <= 50
#	1 <= dictionary[i].length <= 50
#	dictionary[i] and s consists of only lowercase English letters
#	dictionary contains distinct words
class Solution(object):
    def minExtraChar(self, s, dictionary):
        """
        :type s: str
        :type dictionary: List[str]
        :rtype: int
        """
        # Step 1: Count the frequency of each word in dictionary
        word_freq = {}
        for word in dictionary:
            if word in word_freq:
                word_freq[word] += 1
            else:
                word_freq[word] = 1
        
        # Step 2: Count the frequency of each character in s
        char_freq = {}
        for char in s:
            if char in char_freq:
                char_freq[char] += 1
            else:
                char_freq[char] = 1
        
        # Step 3: Find the maximum frequency of any word in dictionary
        max_freq = 0
        for word in word_freq.values():
            max_freq = max(max_freq, word)
        
        # Step 4: Calculate the number of extra characters
        extra_char = 0
        for char, freq in char_freq.items():
            extra_char += max_freq - freq
        
        return extra_char
        