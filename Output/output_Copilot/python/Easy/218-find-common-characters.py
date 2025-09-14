#https://leetcode.com/problems/find-common-characters/
#Given a string array words, return an array of all characters that show up in all strings within the words (including duplicates). You may return the answer in any order.
# 
#Example 1:
#Input: words = ["bella","label","roller"]
#Output: ["e","l","l"]
#Example 2:
#Input: words = ["cool","lock","cook"]
#Output: ["c","o"]
# 
#Constraints:
#	1 <= words.length <= 100
#	1 <= words[i].length <= 100
#	words[i] consists of lowercase English letters.
class Solution(object):
    def commonChars(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        # 1. 使用 Counter 统计第一个单词的字符出现次数
        count = Counter(words[0])

        # 2. 遍历其他单词，更新字符出现次数
        for word in words[1:]:
            count &= Counter(word)

        # 3. 返回所有字符
        return list(count.elements())
        