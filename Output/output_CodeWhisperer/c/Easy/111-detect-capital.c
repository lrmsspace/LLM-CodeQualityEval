/**https://leetcode.com/problems/detect-capital/ */
//We define the usage of capitals in a word to be right when one of the following cases holds:
//	All letters in this word are capitals, like "USA".
//	All letters in this word are not capitals, like "leetcode".
//	Only the first letter in this word is capital, like "Google".
//Given a string word, return true if the usage of capitals in it is right.
// 
//Example 1:
//Input: word = "USA"
//Output: true
//Example 2:
//Input: word = "FlaG"
//Output: false
// 
//Constraints:
//	1 <= word.length <= 100
//	word consists of lowercase and uppercase English letters.
bool detectCapitalUse(char* word) {
    int len = strlen(word);
    if (len == 1) {
        return true;
    }
    if (word[0] >= 'a' && word[0] <= 'z') {
        for (int i = 1; i < len; i++) {
            if (word[i] >= 'A' && word[i] <= 'Z') {
                return false;
            }
        }
    } else if (word[0] >= 'A' && word[0] <= 'Z') {
        if (word[1] >= 'A' && word[1] <= 'Z') {
            for (int i = 2; i < len; i++) {
                if (word[i] >= 'a' && word[i] <= 'z') {
                    return false;
                }
            }
        } else {
            for (int i = 2; i < len; i++) {
                if (word[i] >= 'A' && word[i] <= 'Z') {
                    return false;
                }
            }
        }
    }
    return true;
    
}