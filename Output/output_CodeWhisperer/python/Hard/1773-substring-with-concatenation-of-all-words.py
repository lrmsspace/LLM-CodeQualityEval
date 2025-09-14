#https://leetcode.com/problems/substring-with-concatenation-of-all-words/
#You are given a string s and an array of strings words. All the strings of words are of the same length.
#A concatenated string is a string that exactly contains all the strings of any permutation of words concatenated.
#	For example, if words = ["ab","cd","ef"], then "abcdef", "abefcd", "cdabef", "cdefab", "efabcd", and "efcdab" are all concatenated strings. "acdbef" is not a concatenated string because it is not the concatenation of any permutation of words.
#Return an array of the starting indices of all the concatenated substrings in s. You can return the answer in any order.
# 
#Example 1:
#Input: s = "barfoothefoobarman", words = ["foo","bar"]
#Output: [0,9]
#Explanation:
#The substring starting at 0 is "barfoo". It is the concatenation of ["bar","foo"] which is a permutation of words.
#The substring starting at 9 is "foobar". It is the concatenation of ["foo","bar"] which is a permutation of words.
#Example 2:
#Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
#Output: []
#Explanation:
#There is no concatenated substring.
#Example 3:
#Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
#Output: [6,9,12]
#Explanation:
#The substring starting at 6 is "foobarthe". It is the concatenation of ["foo","bar","the"].
#The substring starting at 9 is "barthefoo". It is the concatenation of ["bar","the","foo"].
#The substring starting at 12 is "thefoobar". It is the concatenation of ["the","foo","bar"].
# 
#Constraints:
#	1 <= s.length <= 104
#	1 <= words.length <= 5000
#	1 <= words[i].length <= 30
#	s and words[i] consist of lowercase English letters.
class Solution(object):
    def findSubstring(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: List[int]
        """
        if not s or not words:
            return []
        word_len = len(words[0])
        word_count = len(words)
        word_dict = {}
        for word in words:
            word_dict[word] = word_dict.get(word, 0) + 1
        result = []
        for i in range(len(s) - word_len * word_count + 1):
            temp_dict = {}
            for j in range(word_count):
                start = i + j * word_len
                word = s[start:start + word_len]
                if word not in word_dict:
                    break
                temp_dict[word] = temp_dict.get(word, 0) + 1
                if temp_dict[word] > word_dict[word]:
                    break
            if temp_dict == word_dict:
                result.append(i)
        return result
        