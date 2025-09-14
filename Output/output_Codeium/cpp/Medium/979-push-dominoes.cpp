/**https://leetcode.com/problems/push-dominoes/ */
//There are n dominoes in a line, and we place each domino vertically upright. In the beginning, we simultaneously push some of the dominoes either to the left or to the right.
//After each second, each domino that is falling to the left pushes the adjacent domino on the left. Similarly, the dominoes falling to the right push their adjacent dominoes standing on the right.
//When a vertical domino has dominoes falling on it from both sides, it stays still due to the balance of the forces.
//For the purposes of this question, we will consider that a falling domino expends no additional force to a falling or already fallen domino.
//You are given a string dominoes representing the initial state where:
//	dominoes[i] = 'L', if the ith domino has been pushed to the left,
//	dominoes[i] = 'R', if the ith domino has been pushed to the right, and
//	dominoes[i] = '.', if the ith domino has not been pushed.
//Return a string representing the final state.
// 
//Example 1:
//Input: dominoes = "RR.L"
//Output: "RR.L"
//Explanation: The first domino expends no additional force on the second domino.
//Example 2:
//Input: dominoes = ".L.R...LR..L.."
//Output: "LL.RR.LLRRLL.."
// 
//Constraints:
//	n == dominoes.length
//	1 <= n <= 105
//	dominoes[i] is either 'L', 'R', or '.'.
class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<int> l(n), r(n);
        l[0] = dominoes[0] == 'L' ? 0 : n;
        r[n-1] = dominoes[n-1] == 'R' ? 0 : n;
        for (int i = 1; i < n; i++) {
            if (dominoes[i] == 'L') l[i] = 0;
            else l[i] = l[i-1] + 1;
        }
        for (int i = n - 2; i >= 0; i--) {
            if (dominoes[i] == 'R') r[i] = 0;
            else r[i] = r[i+1] + 1;
        }
        string res(n, ' ');
        for (int i = 0; i < n; i++) {
            if (dominoes[i] == 'L' || dominoes[i] == 'R') res[i] = dominoes[i];
            else res[i] = l[i] < r[i] ? 'L' : 'R';
        }
        return res;
    }
};