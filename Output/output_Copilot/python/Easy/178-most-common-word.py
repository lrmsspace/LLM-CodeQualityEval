#https://leetcode.com/problems/most-common-word/
#Given a string paragraph and a string array of the banned words banned, return the most frequent word that is not banned. It is guaranteed there is at least one word that is not banned, and that the answer is unique.
#The words in paragraph are case-insensitive and the answer should be returned in lowercase.
# 
#Example 1:
#Input: paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.", banned = ["hit"]
#Output: "ball"
#Explanation: 
#"hit" occurs 3 times, but it is a banned word.
#"ball" occurs twice (and no other word does), so it is the most frequent non-banned word in the paragraph. 
#Note that words in the paragraph are not case sensitive,
#that punctuation is ignored (even if adjacent to words, such as "ball,"), 
#and that "hit" isn't the answer even though it occurs more because it is banned.
#Example 2:
#Input: paragraph = "a.", banned = []
#Output: "a"
# 
#Constraints:
#	1 <= paragraph.length <= 1000
#	paragraph consists of English letters, space ' ', or one of the symbols: "!?',;.".
#	0 <= banned.length <= 100
#	1 <= banned[i].length <= 10
#	banned[i] consists of only lowercase English letters.
class Solution(object):
    def mostCommonWord(self, paragraph, banned):
        """
        :type paragraph: str
        :type banned: List[str]
        :rtype: str
        """
        # 1. 预处理段落，去除标点符号并转换为小写
        for ch in "!?',;.":
            paragraph = paragraph.replace(ch, ' ')
        words = paragraph.lower().split()
        
        # 2. 统计单词频率
        word_count = {}
        for word in words:
            if word not in banned:
                word_count[word] = word_count.get(word, 0) + 1
        
        # 3. 找到出现频率最高的单词
        most_common_word = max(word_count, key=word_count.get)
        
        return most_common_word        