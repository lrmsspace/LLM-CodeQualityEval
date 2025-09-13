#https://leetcode.com/problems/length-of-the-longest-valid-substring/
#You are given a string word and an array of strings forbidden.
#A string is called valid if none of its substrings are present in forbidden.
#Return the length of the longest valid substring of the string word.
#A substring is a contiguous sequence of characters in a string, possibly empty.
# 
#Example 1:
#Input: word = "cbaaaabc", forbidden = ["aaa","cb"]
#Output: 4
#Explanation: There are 11 valid substrings in word: "c", "b", "a", "ba", "aa", "bc", "baa", "aab", "ab", "abc" and "aabc". The length of the longest valid substring is 4. 
#It can be shown that all other substrings contain either "aaa" or "cb" as a substring. 
#Example 2:
#Input: word = "leetcode", forbidden = ["de","le","e"]
#Output: 4
#Explanation: There are 11 valid substrings in word: "l", "t", "c", "o", "d", "tc", "co", "od", "tco", "cod", and "tcod". The length of the longest valid substring is 4.
#It can be shown that all other substrings contain either "de", "le", or "e" as a substring. 
# 
#Constraints:
#	1 <= word.length <= 105
#	word consists only of lowercase English letters.
#	1 <= forbidden.length <= 105
#	1 <= forbidden[i].length <= 10
#	forbidden[i] consists only of lowercase English letters.
class Solution(object):
    def longestValidSubstring(self, word, forbidden):
        """
        :type word: str
        :type forbidden: List[str]
        :rtype: int
        """
        # 1. 使用集合存储 forbidden 字符串
        # 2. 使用双指针法，左指针指向当前 valid substring 的起始位置，右指针指向当前 valid substring 的结束位置
        # 3. 当右指针移动到 forbidden 字符串的起始位置时，更新左指针的位置
        # 4. 返回 valid substring 的长度
        forbidden_set = set(forbidden)
        n = len(word)
        left = 0
        max_length = 0
        
        for right in range(n):
            for length in range(1, 11):
                if right - length + 1 >= 0 and word[right - length + 1:right + 1] in forbidden_set:
                    left = right - length + 2
                    break
            max_length = max(max_length, right - left + 1)
        return max_length