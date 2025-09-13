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
        int n = s.length();
        int idx1 = -1, idx2 = -1;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (s[j] > s[i]) {
                    if (idx1 == -1 || s[j] > s[idx1]) {
                        idx2 = i;
                        idx1 = j;
                    }
                }
            }
        }
        if (idx1 != -1) {
            swap(s[idx1], s[idx2]);
        }
        return stoi(s);
    }
};