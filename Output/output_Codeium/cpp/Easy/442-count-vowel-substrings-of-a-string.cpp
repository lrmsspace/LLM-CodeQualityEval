/**https://leetcode.com/problems/count-vowel-substrings-of-a-string/ */
//A substring is a contiguous (non-empty) sequence of characters within a string.
//A vowel substring is a substring that only consists of vowels ('a', 'e', 'i', 'o', and 'u') and has all five vowels present in it.
//Given a string word, return the number of vowel substrings in word.
// 
//Example 1:
//Input: word = "aeiouu"
//Output: 2
//Explanation: The vowel substrings of word are as follows (underlined):
//- "aeiouu"
//- "aeiouu"
//Example 2:
//Input: word = "unicornarihan"
//Output: 0
//Explanation: Not all 5 vowels are present, so there are no vowel substrings.
//Example 3:
//Input: word = "cuaieuouac"
//Output: 7
//Explanation: The vowel substrings of word are as follows (underlined):
//- "cuaieuouac"
//- "cuaieuouac"
//- "cuaieuouac"
//- "cuaieuouac"
//- "cuaieuouac"
//- "cuaieuouac"
//- "cuaieuouac"
// 
//Constraints:
//	1 <= word.length <= 100
//	word consists of lowercase English letters only.
class Solution {
public:
    int countVowelSubstrings(string word) {
        int count = 0;
        int vowelCount[5] = {0};
        unordered_map<char, int> vowelIndex = {{'a', 0}, {'e', 1}, {'i', 2}, {'o', 3}, {'u', 4}};
        for (int i = 0; i < word.length(); ++i) {
            if (vowelIndex.find(word[i]) != vowelIndex.end()) {
                int index = vowelIndex[word[i]];
                ++vowelCount[index];
                for (int j = 0; j < 5; ++j) {
                    if (vowelCount[j] > 0) {
                        ++count;
                    }
                }
            }
        }
        return count;
        
    }
};