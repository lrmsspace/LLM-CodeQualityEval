/**https://leetcode.com/problems/verbal-arithmetic-puzzle/ */
//Given an equation, represented by words on the left side and the result on the right side.
//You need to check if the equation is solvable under the following rules:
//	Each character is decoded as one digit (0 - 9).
//	No two characters can map to the same digit.
//	Each words[i] and result are decoded as one number without leading zeros.
//	Sum of numbers on the left side (words) will equal to the number on the right side (result).
//Return true if the equation is solvable, otherwise return false.
// 
//Example 1:
//Input: words = ["SEND","MORE"], result = "MONEY"
//Output: true
//Explanation: Map 'S'-> 9, 'E'->5, 'N'->6, 'D'->7, 'M'->1, 'O'->0, 'R'->8, 'Y'->'2'
//Such that: "SEND" + "MORE" = "MONEY" ,  9567 + 1085 = 10652
//Example 2:
//Input: words = ["SIX","SEVEN","SEVEN"], result = "TWENTY"
//Output: true
//Explanation: Map 'S'-> 6, 'I'->5, 'X'->0, 'E'->8, 'V'->7, 'N'->2, 'T'->1, 'W'->'3', 'Y'->4
//Such that: "SIX" + "SEVEN" + "SEVEN" = "TWENTY" ,  650 + 68782 + 68782 = 138214
//Example 3:
//Input: words = ["LEET","CODE"], result = "POINT"
//Output: false
//Explanation: There is no possible mapping to satisfy the equation, so we return false.
//Note that two different characters cannot map to the same digit.
// 
//Constraints:
//	2 <= words.length <= 5
//	1 <= words[i].length, result.length <= 7
//	words[i], result contain only uppercase English letters.
//	The number of different characters used in the expression is at most 10.    
class Solution {
public:
    bool isSolvable(vector<string>& words, string result) {
        // Initialize character to digit mapping and digit usage
        unordered_map<char, int> charToDigit;
        vector<bool> usedDigits(10, false);
        
        // Track leading characters (can't be zero)
        unordered_set<char> leadingChars;
        
        // Add leading characters
        for (const string& word : words) {
            if (word.length() > 1) {
                leadingChars.insert(word[0]);
            }
        }
        if (result.length() > 1) {
            leadingChars.insert(result[0]);
        }
        
        // Collect all unique characters
        unordered_set<char> allChars;
        for (const string& word : words) {
            for (char c : word) {
                allChars.insert(c);
            }
        }
        for (char c : result) {
            allChars.insert(c);
        }
        
        // Convert to vector for backtracking
        vector<char> chars(allChars.begin(), allChars.end());
        
        return backtrack(words, result, chars, 0, charToDigit, usedDigits, leadingChars);
    }
    
private:
    bool backtrack(const vector<string>& words, const string& result, 
                  const vector<char>& chars, int index,
                  unordered_map<char, int>& charToDigit, 
                  vector<bool>& usedDigits,
                  const unordered_set<char>& leadingChars) {
        
        // Base case: all characters have been assigned
        if (index == chars.size()) {
            return checkEquation(words, result, charToDigit);
        }
        
        char currentChar = chars[index];
        
        // Try each possible digit for the current character
        for (int digit = 0; digit <= 9; digit++) {
            // Skip if digit is already used
            if (usedDigits[digit]) continue;
            
            // Skip if this is a leading character and digit is 0
            if (digit == 0 && leadingChars.count(currentChar) > 0) continue;
            
            // Assign the digit to the character
            charToDigit[currentChar] = digit;
            usedDigits[digit] = true;
            
            // Recursively try to assign the next character
            if (backtrack(words, result, chars, index + 1, charToDigit, usedDigits, leadingChars)) {
                return true;
            }
            
            // Backtrack
            usedDigits[digit] = false;
            charToDigit.erase(currentChar);
        }
        
        return false;
    }
    
    bool checkEquation(const vector<string>& words, const string& result, 
                      const unordered_map<char, int>& charToDigit) {
        long long sum = 0;
        
        // Calculate the sum of words
        for (const string& word : words) {
            long long num = 0;
            for (char c : word) {
                num = num * 10 + charToDigit.at(c);
            }
            sum += num;
        }
        
        // Calculate the value of result
        long long resultNum = 0;
        for (char c : result) {
            resultNum = resultNum * 10 + charToDigit.at(c);
        }
        
        return sum == resultNum;
    }
};
