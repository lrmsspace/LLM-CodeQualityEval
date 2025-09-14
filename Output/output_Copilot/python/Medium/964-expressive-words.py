#https://leetcode.com/problems/expressive-words/
#Sometimes people repeat letters to represent extra feeling. For example:
#	"hello" -> "heeellooo"
#	"hi" -> "hiiii"
#In these strings like "heeellooo", we have groups of adjacent letters that are all the same: "h", "eee", "ll", "ooo".
#You are given a string s and an array of query strings words. A query word is stretchy if it can be made to be equal to s by any number of applications of the following extension operation: choose a group consisting of characters c, and add some number of characters c to the group so that the size of the group is three or more.
#	For example, starting with "hello", we could do an extension on the group "o" to get "hellooo", but we cannot get "helloo" since the group "oo" has a size less than three. Also, we could do another extension like "ll" -> "lllll" to get "helllllooo". If s = "helllllooo", then the query word "hello" would be stretchy because of these two extension operations: query = "hello" -> "hellooo" -> "helllllooo" = s.
#Return the number of query strings that are stretchy.
# 
#Example 1:
#Input: s = "heeellooo", words = ["hello", "hi", "helo"]
#Output: 1
#Explanation: 
#We can extend "e" and "o" in the word "hello" to get "heeellooo".
#We can't extend "helo" to get "heeellooo" because the group "ll" is not size 3 or more.
#Example 2:
#Input: s = "zzzzzyyyyy", words = ["zzyy","zy","zyy"]
#Output: 3
# 
#Constraints:
#	1 <= s.length, words.length <= 100
#	1 <= words[i].length <= 100
#	s and words[i] consist of lowercase letters.
class Solution(object):
    def expressiveWords(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: int
        """
        def count(s):
            count = []
            prev = s[0]
            cnt = 1
            for i in range(1, len(s)):
                if s[i] == prev:
                    cnt += 1
                else:
                    count.append((prev, cnt))
                    prev = s[i]
                    cnt = 1
            count.append((prev, cnt))
            return count
        
        def check(s_count, w_count):
            if len(s_count) != len(w_count):
                return False
            for (s_char, s_cnt), (w_char, w_cnt) in zip(s_count, w_count):
                if s_char != w_char or (s_cnt < w_cnt or (s_cnt > w_cnt and s_cnt < 3)):
                    return False
            return True
        
        s_count = count(s)
        ans = 0
        for word in words:
            if check(s_count, count(word)):
                ans += 1
        return ans        