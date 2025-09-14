/**https://leetcode.com/problems/reconstruct-original-digits-from-english/ */
//Given a string s containing an out-of-order English representation of digits 0-9, return the digits in ascending order.
// 
//Example 1:
//Input: s = "owoztneoer"
//Output: "012"
//Example 2:
//Input: s = "fviefuro"
//Output: "45"
// 
//Constraints:
//	1 <= s.length <= 105
//	s[i] is one of the characters ["e","g","f","i","h","o","n","s","r","u","t","w","v","x","z"].
//	s is guaranteed to be valid.
class Solution {
public: 
    string originalDigits(string s) {
        // Count the frequency of each character
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }
        
        // Count the frequency of each digit
        vector<int> digits(10, 0);
        
        // Unique character identifiers
        digits[0] = count['z' - 'a'];  // 'z' only appears in "zero"
        digits[2] = count['w' - 'a'];  // 'w' only appears in "two"
        digits[4] = count['u' - 'a'];  // 'u' only appears in "four"
        digits[6] = count['x' - 'a'];  // 'x' only appears in "six"
        digits[8] = count['g' - 'a'];  // 'g' only appears in "eight"
        
        // Characters that become unique after removing other digits
        digits[1] = count['o' - 'a'] - digits[0] - digits[2] - digits[4];  // 'o' in "one", "zero", "two", "four"
        digits[3] = count['r' - 'a'] - digits[0] - digits[4];  // 'r' in "three", "zero", "four"
        digits[5] = count['f' - 'a'] - digits[4];  // 'f' in "five", "four"
        digits[7] = count['s' - 'a'] - digits[6];  // 's' in "seven", "six"
        digits[9] = count['i' - 'a'] - digits[5] - digits[6] - digits[8];  // 'i' in "nine", "five", "six", "eight"
        
        // Build the result string
        string result = "";
        for (int i = 0; i < 10; i++) {
            result += string(digits[i], '0' + i);
        }
        
        return result;
    }
    
};
