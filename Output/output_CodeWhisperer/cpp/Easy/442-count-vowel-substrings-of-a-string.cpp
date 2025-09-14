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
        int n = word.length();
        int res = 0;
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        for (int i = 0; i < n; i++) {
            unordered_set<char> seen;
            for (int j = i; j < n; j++) {
                if (!vowels.count(word[j])) {
                    break;
                }
                seen.insert(word[j]);
                if (seen.size() == 5) {
                    res++;
                }
            }
        }
        return res;       
    }
};