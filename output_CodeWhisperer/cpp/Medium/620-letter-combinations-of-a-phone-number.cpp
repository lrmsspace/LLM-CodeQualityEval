/**https://leetcode.com/problems/letter-combinations-of-a-phone-number/ */
//Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
//A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
// 
//Example 1:
//Input: digits = "23"
//Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
//Example 2:
//Input: digits = ""
//Output: []
//Example 3:
//Input: digits = "2"
//Output: ["a","b","c"]
// 
//Constraints:
//	0 <= digits.length <= 4
//	digits[i] is a digit in the range ['2', '9'].
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits.empty()) return result;
        string mapping[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        result.push_back("");
        for(int i = 0; i < digits.size(); i++){
            vector<string> temp;
            string chars = mapping[digits[i] - '0'];
            for(int j = 0; j < chars.size(); j++){
                for(int k = 0; k < result.size(); k++){
                    temp.push_back(result[k] + chars[j]);
                }
            }
            result = temp;
        }
        return result;      
    }
};