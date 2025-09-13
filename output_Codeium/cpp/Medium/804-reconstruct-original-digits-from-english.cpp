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
        vector<int> count(10, 0);
        for (char c : s) {
            switch (c) {
                case 'z': count[0]++; break;
                case 'w': count[2]++; break;
                case 'u': count[4]++; break;
                case 'x': count[6]++; break;
                case 'g': count[8]++; break;
                case 'o': count[1] += count[0] ? 0 : 1; break;
                case 'h': count[3] += count[8] ? 0 : 1; break;
                case 'f': count[5] += count[4] ? 0 : 1; break;
                case 's': count[7] += count[6] ? 0 : 1; break;
                case 'i': count[9] += count[5] + count[8] + count[6] ? 0 : 1; break;
            }
        }
        string res;
        for (int i = 0; i < 10; ++i) {
            if (count[i])
                res += string(count[i], '0' + i);
        }
        return res;
    }
};