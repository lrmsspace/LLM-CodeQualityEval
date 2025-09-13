/*
 You are given a positive integer n.
 A binary string x is valid if all substrings of x of length 2 contain at least one "1".
 Return all valid strings with length n, in any order.
 Example 1:
 Input: n = 3
 Output: ["010","011","101","110","111"]
 Explanation:
 The valid strings of length 3 are: "010", "011", "101", "110", and "111".
 Example 2:
 Input: n = 1
 Output: ["0","1"]
 Explanation:
 The valid strings of length 1 are: "0" and "1".
 Constraints:
 1 <= n <= 18
*/

class Solution {
public:
    vector<string> validStrings(int n) {
        vector<string> result;
        generateStrings(n, "", result);
        return result;
    }

private:
    void generateStrings(int n, string current, vector<string>& result) {
        if (current.length() == n) {
            result.push_back(current);
            return;
        }

        // Add '0' if the last character is not '0'
        if (current.empty() || current.back() != '0') {
            generateStrings(n, current + '0', result);
        }

        // Add '1' if the last character is not '1'
        if (current.empty() || current.back() != '1') {
            generateStrings(n, current + '1', result);
        }
        
    }
};