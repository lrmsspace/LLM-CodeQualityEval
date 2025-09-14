#https://leetcode.com/problems/stickers-to-spell-word/
#We are given n different types of stickers. Each sticker has a lowercase English word on it.
#You would like to spell out the given string target by cutting individual letters from your collection of stickers and rearranging them. You can use each sticker more than once if you want, and you have infinite quantities of each sticker.
#Return the minimum number of stickers that you need to spell out target. If the task is impossible, return -1.
#Note: In all test cases, all words were chosen randomly from the 1000 most common US English words, and target was chosen as a concatenation of two random words.
# 
#Example 1:
#Input: stickers = ["with","example","science"], target = "thehat"
#Output: 3
#Explanation:
#We can use 2 "with" stickers, and 1 "example" sticker.
#After cutting and rearrange the letters of those stickers, we can form the target "thehat".
#Also, this is the minimum number of stickers necessary to form the target string.
#Example 2:
#Input: stickers = ["notice","possible"], target = "basicbasic"
#Output: -1
#Explanation:
#We cannot form the target "basicbasic" from cutting letters from the given stickers.
# 
#Constraints:
#	n == stickers.length
#	1 <= n <= 50
#	1 <= stickers[i].length <= 10
#	1 <= target.length <= 15
#	stickers[i] and target consist of lowercase English letters.
class Solution(object):
    def minStickers(self, stickers, target):
        """
        :type stickers: List[str]
        :type target: str
        :rtype: int
        """
        dp = [float('inf')] * (1 << len(target))
        dp[0] = 0
        for sticker in stickers:
            count = [0] * 26
            for ch in sticker:
                count[ord(ch) - ord('a')] += 1
            for i in range(1 << len(target)):
                if dp[i] == float('inf'):
                    continue
                j = i
                for k in range(len(target)):
                    if j & (1 << k) == 0 and count[ord(target[k]) - ord('a')] > 0:
                        j |= (1 << k)
                        count[ord(target[k]) - ord('a')] -= 1
                dp[j] = min(dp[j], dp[i] + 1)
        return dp[-1] if dp[-1] != float('inf') else -1        