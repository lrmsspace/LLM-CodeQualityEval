/**https://leetcode.com/problems/shifting-letters-ii/ */
//You are given a string s of lowercase English letters and a 2D integer array shifts where shifts[i] = [starti, endi, directioni]. For every i, shift the characters in s from the index starti to the index endi (inclusive) forward if directioni = 1, or shift the characters backward if directioni = 0.
//Shifting a character forward means replacing it with the next letter in the alphabet (wrapping around so that 'z' becomes 'a'). Similarly, shifting a character backward means replacing it with the previous letter in the alphabet (wrapping around so that 'a' becomes 'z').
//Return the final string after all such shifts to s are applied.
// 
//Example 1:
//Input: s = "abc", shifts = [[0,1,0],[1,2,1],[0,2,1]]
//Output: "ace"
//Explanation: Firstly, shift the characters from index 0 to index 1 backward. Now s = "zac".
//Secondly, shift the characters from index 1 to index 2 forward. Now s = "zbd".
//Finally, shift the characters from index 0 to index 2 forward. Now s = "ace".
//Example 2:
//Input: s = "dztz", shifts = [[0,0,0],[1,1,1]]
//Output: "catz"
//Explanation: Firstly, shift the characters from index 0 to index 0 backward. Now s = "cztz".
//Finally, shift the characters from index 1 to index 1 forward. Now s = "catz".
// 
//Constraints:
//	1 <= s.length, shifts.length <= 5 * 104
//	shifts[i].length == 3
//	0 <= starti <= endi < s.length
//	0 <= directioni <= 1
//	s consists of lowercase English letters.
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> diff(n+1, 0);
        for(auto& shift : shifts){
            int start = shift[0], end = shift[1], dir = shift[2];
            if(dir == 0) dir = -1;
            diff[start] += dir;
            diff[end+1] -= dir;
        }
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += diff[i];
            int val = (s[i] - 'a' + sum) % 26;
            if(val < 0) val += 26;
            s[i] = 'a' + val;
        }
        return s;
        
    }
};