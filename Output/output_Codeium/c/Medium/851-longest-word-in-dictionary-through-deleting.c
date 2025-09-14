/**https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/ */
//Given a string s and a string array dictionary, return the longest string in the dictionary that can be formed by deleting some of the given string characters. If there is more than one possible result, return the longest word with the smallest lexicographical order. If there is no possible result, return the empty string.
// 
//Example 1:
//Input: s = "abpcplea", dictionary = ["ale","apple","monkey","plea"]
//Output: "apple"
//Example 2:
//Input: s = "abpcplea", dictionary = ["a","b","c"]
//Output: "a"
// 
//Constraints:
//	1 <= s.length <= 1000
//	1 <= dictionary.length <= 1000
//	1 <= dictionary[i].length <= 1000
//	s and dictionary[i] consist of lowercase English letters.
char* findLongestWord(char* s, char** dictionary, int dictionarySize) {
    
    int maxLen = 0;
    char *result = "";

    for (int i = 0; i < dictionarySize; i++) {
        char *word = dictionary[i];
        int wordLen = strlen(word);
        int sIndex = 0, wIndex = 0;

        while (s[sIndex] && wIndex < wordLen) {
            if (s[sIndex] == word[wIndex]) {
                wIndex++;
            }
            sIndex++;
        }

        if (wIndex == wordLen) {
            if (wordLen > maxLen || (wordLen == maxLen && strcmp(word, result) < 0)) {
                maxLen = wordLen;
                result = word;
            }
        }
    }

    return result;
}   