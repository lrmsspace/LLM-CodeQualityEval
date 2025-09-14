/**https://leetcode.com/problems/minimum-possible-integer-after-at-most-k-adjacent-swaps-on-digits/ */
//You are given a string num representing the digits of a very large integer and an integer k. You are allowed to swap any two adjacent digits of the integer at most k times.
//Return the minimum integer you can obtain also as a string.
// 
//Example 1:
//Input: num = "4321", k = 4
//Output: "1342"
//Explanation: The steps to obtain the minimum integer from 4321 with 4 adjacent swaps are shown.
//Example 2:
//Input: num = "100", k = 1
//Output: "010"
//Explanation: It's ok for the output to have leading zeros, but the input is guaranteed not to have any leading zeros.
//Example 3:
//Input: num = "36789", k = 1000
//Output: "36789"
//Explanation: We can keep the number without any swaps.
// 
//Constraints:
//	1 <= num.length <= 3 * 104
//	num consists of only digits and does not contain leading zeros.
//	1 <= k <= 109
class Solution {
public:
    string minInteger(string num, int k) {
        int n = num.size();
        vector<queue<int>> pos(10);
        for (int i = 0; i < n; i++) {
            pos[num[i] - '0'].push(i);
        }
        string res;
        FenwickTree ft(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 10; j++) {
                if (!pos[j].empty()) {
                    int nextPos = pos[j].front();
                    int cost = ft.query(nextPos);
                    if (nextPos - cost <= k) {
                        k -= nextPos - cost;
                        res.push_back(j + '0');
                        ft.update(nextPos, 1);
                        pos[j].pop();
                        break;
                    }
                }
            }
        }
        return res;
    }
};