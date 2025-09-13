/**https://leetcode.com/problems/longest-substring-of-all-vowels-in-order/ */
//A string is considered beautiful if it satisfies the following conditions:
//	Each of the 5 English vowels ('a', 'e', 'i', 'o', 'u') must appear at least once in it.
//	The letters must be sorted in alphabetical order (i.e. all 'a's before 'e's, all 'e's before 'i's, etc.).
//For example, strings "aeiou" and "aaaaaaeiiiioou" are considered beautiful, but "uaeio", "aeoiu", and "aaaeeeooo" are not beautiful.
//Given a string word consisting of English vowels, return the length of the longest beautiful substring of word. If no such substring exists, return 0.
//A substring is a contiguous sequence of characters in a string.
// 
//Example 1:
//Input: word = "aeiaaioaaaaeiiiiouuuooaauuaeiu"
//Output: 13
//Explanation: The longest beautiful substring in word is "aaaaeiiiiouuu" of length 13.
//Example 2:
//Input: word = "aeeeiiiioooauuuaeiou"
//Output: 5
//Explanation: The longest beautiful substring in word is "aeiou" of length 5.
//Example 3:
//Input: word = "a"
//Output: 0
//Explanation: There is no beautiful substring, so return 0.
// 
//Constraints:
//	1 <= word.length <= 5 * 105
//	word consists of characters 'a', 'e', 'i', 'o', and 'u'.
int longestBeautifulSubstring(char* word) {
    int vowels[5] = {0};
    int left = 0, right = 0, maxLen = 0;
    
    while (right < strlen(word)) {
        vowels[word[right] - 'a']++;
        
        while (vowels['a' - 'a'] > 0 && vowels['e' - 'a'] > 0 && vowels['i' - 'a'] > 0 && vowels['o' - 'a'] > 0 && vowels['u' - 'a'] > 0) {
            maxLen = max(maxLen, right - left + 1);
            vowels[word[left] - 'a']--;
            left++;
        }
        
        right++;
    }
    
    return maxLen;
    
}