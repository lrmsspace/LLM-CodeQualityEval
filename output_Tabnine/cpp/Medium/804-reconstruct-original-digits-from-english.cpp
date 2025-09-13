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
        // Create a frequency map for each character
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        
        // Count the number of times each digit appears
        int count[10] = {0};
        count[0] = freq['z'];
        count[2] = freq['w'];
        count[4] = freq['u'];
        count[6] = freq['x'];
        count[8] = freq['g'];
        count[3] = freq['h'] - count[8];
        count[5] = freq['f'] - count[4] - count[3];
        count[7] = freq['s'] - count[6];
        count[9] = freq['o'] - count[0] - count[1] - count[2] - count[4] - count[5] - count[7];
        
        // Build the result string
        string result;
        for (int i = 9; i >= 0; i--) {
            for (int j = 0; j < count[i]; j++) {
                result += to_string(i);
            }
        }
        return result;
        
    }
};