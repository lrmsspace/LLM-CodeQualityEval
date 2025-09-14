/**https://leetcode.com/problems/number-of-valid-words-in-a-sentence/ */
//A sentence consists of lowercase letters ('a' to 'z'), digits ('0' to '9'), hyphens ('-'), punctuation marks ('!', '.', and ','), and spaces (' ') only. Each sentence can be broken down into one or more tokens separated by one or more spaces ' '.
//A token is a valid word if all three of the following are true:
//	It only contains lowercase letters, hyphens, and/or punctuation (no digits).
//	There is at most one hyphen '-'. If present, it must be surrounded by lowercase characters ("a-b" is valid, but "-ab" and "ab-" are not valid).
//	There is at most one punctuation mark. If present, it must be at the end of the token ("ab,", "cd!", and "." are valid, but "a!b" and "c.," are not valid).
//Examples of valid words include "a-b.", "afad", "ba-c", "a!", and "!".
//Given a string sentence, return the number of valid words in sentence.
// 
//Example 1:
//Input: sentence = "cat and  dog"
//Output: 3
//Explanation: The valid words in the sentence are "cat", "and", and "dog".
//Example 2:
//Input: sentence = "!this  1-s b8d!"
//Output: 0
//Explanation: There are no valid words in the sentence.
//"!this" is invalid because it starts with a punctuation mark.
//"1-s" and "b8d" are invalid because they contain digits.
//Example 3:
//Input: sentence = "alice and  bob are playing stone-game10"
//Output: 5
//Explanation: The valid words in the sentence are "alice", "and", "bob", "are", and "playing".
//"stone-game10" is invalid because it contains digits.
// 
//Constraints:
//	1 <= sentence.length <= 1000
//	sentence only contains lowercase English letters, digits, ' ', '-', '!', '.', and ','.
//	There will be at least 1 token.
int countValidWords(char* sentence) {
    int count = 0;
    int start = 0;
    int len = strlen(sentence);
    while (start < len) {
        // Skip spaces
        while (start < len && sentence[start] =='') {
            start++;
        }
        
        // Find the end of the current word
        int end = start;
        while (end < len && sentence[end]!='' && sentence[end]!= '-' && sentence[end]!= '!' && sentence[end]!= '.') {
            end++;
        }
        
        // Check if the word is valid
        int hyphenCount = 0;
        int punctuationCount = 0;
        for (int i = start; i < end; i++) {
            if (sentence[i] == '-') {
                hyphenCount++;
                if (i + 1 < end && sentence[i + 1]!='') {
                    return count; // Invalid hyphen
                }
            } else if (sentence[i] == '!' || sentence[i] == '.' || sentence[i] == ',') {
                punctuationCount++;
                if (i + 1 < end && sentence[i + 1]!='') {
                    return count; // Invalid punctuation
                }
            } else if (sentence[i] < 'a' || sentence[i] > 'z') {
                return count; // Invalid character
            }
        }
        
        if (hyphenCount > 1 || punctuationCount > 1) {
            return count; // Invalid word format
        }
        
        count++;
        start = end + 1;
    }
    return count;
}