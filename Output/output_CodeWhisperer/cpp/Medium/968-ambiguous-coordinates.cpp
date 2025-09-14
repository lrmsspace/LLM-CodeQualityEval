/**https://leetcode.com/problems/ambiguous-coordinates/ */
//We had some 2-dimensional coordinates, like "(1, 3)" or "(2, 0.5)". Then, we removed all commas, decimal points, and spaces and ended up with the string s.
//	For example, "(1, 3)" becomes s = "(13)" and "(2, 0.5)" becomes s = "(205)".
//Return a list of strings representing all possibilities for what our original coordinates could have been.
//Our original representation never had extraneous zeroes, so we never started with numbers like "00", "0.0", "0.00", "1.0", "001", "00.01", or any other number that can be represented with fewer digits. Also, a decimal point within a number never occurs without at least one digit occurring before it, so we never started with numbers like ".1".
//The final answer list can be returned in any order. All coordinates in the final answer have exactly one space between them (occurring after the comma.)
// 
//Example 1:
//Input: s = "(123)"
//Output: ["(1, 2.3)","(1, 23)","(1.2, 3)","(12, 3)"]
//Example 2:
//Input: s = "(0123)"
//Output: ["(0, 1.23)","(0, 12.3)","(0, 123)","(0.1, 2.3)","(0.1, 23)","(0.12, 3)"]
//Explanation: 0.0, 00, 0001 or 00.01 are not allowed.
//Example 3:
//Input: s = "(00011)"
//Output: ["(0, 0.011)","(0.001, 1)"]
// 
//Constraints:
//	4 <= s.length <= 12
//	s[0] == '(' and s[s.length - 1] == ')'.
//	The rest of s are digits.   
class Solution {
    public:
        vector<string> ambiguousCoordinates(string s) {
            vector<string> result;
            // Remove the surrounding parentheses
            string digits = s.substr(1, s.length() - 2);
            int n = digits.length();
            
            // Try all possible positions to split the digits into x and y coordinates
            for (int i = 1; i < n; i++) {
                string left = digits.substr(0, i);
                string right = digits.substr(i);
                
                // Get all valid number formats for the left part
                vector<string> leftNums = getValidNumbers(left);
                // Get all valid number formats for the right part
                vector<string> rightNums = getValidNumbers(right);
                
                // Combine all valid left and right numbers to form coordinates
                for (const string& x : leftNums) {
                    for (const string& y : rightNums) {
                        result.push_back("(" + x + ", " + y + ")");
                    }
                }
            }
            
            return result;
        }
        
    private:
        // Generate all valid number formats for a given string of digits
        vector<string> getValidNumbers(const string& s) {
            vector<string> validNums;
            int n = s.length();
            
            // Case 1: No decimal point
            if (isValidInteger(s)) {
                validNums.push_back(s);
            }
            
            // Case 2: With decimal point at different positions
            for (int i = 1; i < n; i++) {
                string intPart = s.substr(0, i);
                string decimalPart = s.substr(i);
                
                if (isValidInteger(intPart) && isValidDecimal(decimalPart)) {
                    validNums.push_back(intPart + "." + decimalPart);
                }
            }
            
            return validNums;
        }
        
        // Check if a string is a valid integer (no leading zeros unless it's just "0")
        bool isValidInteger(const string& s) {
            if (s.length() > 1 && s[0] == '0') {
                return false; // Leading zeros are not allowed
            }
            return true;
        }
        
        // Check if a string is a valid decimal part (no trailing zeros)
        bool isValidDecimal(const string& s) {
            if (s.empty() || s.back() == '0') {
                return false; // Empty or trailing zeros are not allowed
            }
            return true;
        }
    };
    