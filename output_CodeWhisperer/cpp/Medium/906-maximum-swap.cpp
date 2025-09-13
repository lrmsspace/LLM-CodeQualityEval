/**https://leetcode.com/problems/maximum-swap/ */
//You are given an integer num. You can swap two digits at most once to get the maximum valued number.
//Return the maximum valued number you can get.
// 
//Example 1:
//Input: num = 2736
//Output: 7236
//Explanation: Swap the number 2 and the number 7.
//Example 2:
//Input: num = 9973
//Output: 9973
//Explanation: No swap.
// 
//Constraints:
//	0 <= num <= 108
class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.size();
        vector<int> last(10, -1);
        for (int i = 0; i < n; i++) {
            last[s[i] - '0'] = i;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 9; j > s[i] - '0'; j--) {
                if (last[j] > i) {
                    swap(s[i], s[last[j]]);
                    return stoi(s);
                }
            }
        }
        return num;       
    }
};