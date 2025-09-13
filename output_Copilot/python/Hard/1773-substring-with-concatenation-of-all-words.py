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

        word_length = len(words[0])
        word_count = len(words)
        total_length = word_length * word_count
        result = []

        # Create a frequency map of the words
        word_map = {}
        for word in words:
            if word in word_map:
                word_map[word] += 1
            else:
                word_map[word] = 1

        # Iterate through the string s
        for i in range(len(s) - total_length + 1):
            seen_words = {}
            for j in range(word_count):
                start_index = i + j * word_length
                end_index = start_index + word_length
                current_word = s[start_index:end_index]

                if current_word in word_map:
                    if current_word in seen_words:
                        seen_words[current_word] += 1
                    else:
                        seen_words[current_word] = 1

                    # If the count exceeds, break out of the loop
                    if seen_words[current_word] > word_map[current_word]:
                        break
                else:
                    break

            # If all words are found, add the starting index to the result
            if seen_words == word_map:
                result.append(i)

        return result        