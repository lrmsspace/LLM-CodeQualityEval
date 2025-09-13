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
bool isSolvable(char** words, int wordsSize, char* result) {
    unordered_map<char, int> charMap;
    int sum = 0;
    
    // Count the occurrence of each character and calculate the sum of numbers
    for (int i = 0; i < wordsSize; ++i) {
        for (char c : words[i]) {
            if (charMap.find(c) == charMap.end()) {
                charMap[c] = 0;
            }
            charMap[c]++;
        }
        sum += stoi(words[i]);
    }
    
    // Calculate the target sum
    int targetSum = stoi(result);
    
    // Check if the sum of numbers on the left side equals to the number on the right side
    if (sum!= targetSum) {
        return false;
    }
    
    // Find a solution by iterating through all possible digits and mapping them
    vector<int> digits(10, 0);
    for (int i = 9; i >= 0; --i) {
        if (charMap[digits[i] + '0'] == 0) {
            continue;
        }
        charMap[digits[i] + '0']--;
        if (dfs(words, wordsSize, result, charMap, digits, i + 1, sum - digits[i])) {
            return true;
        }
        charMap[digits[i] + '0']++;
    }
    
    return false;
    
}