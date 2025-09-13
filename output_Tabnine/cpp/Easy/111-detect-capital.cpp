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
class Solution {
public:
    bool detectCapitalUse(string word) {
        //If the word has only one letter, it is always capitalized
        if (word.length() == 1) return true;
        
        //If the first letter is capitalized, then all other letters should also be capitalized
        if (isupper(word[0])) {
            for (int i = 1; i < word.length(); ++i) {
                if (!isupper(word[i])) return false;
            }
        }
        //If the first letter is not capitalized, then either all other letters should also be capitalized or the second letter should be capitalized
        else {
            int countUpper = 0;
            for (int i = 1; i < word.length(); ++i) {
                if (isupper(word[i])) ++countUpper;
            }
            return countUpper == word.length() - 1 || isupper(word[1]);
        }
        
        return true; //This line should never be reached, but added for completeness and readability. It will never return false in a valid input.
        
    }
};