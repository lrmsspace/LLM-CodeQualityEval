/**https://leetcode.com/problems/longest-well-performing-interval/ */
//We are given hours, a list of the number of hours worked per day for a given employee.
//A day is considered to be a tiring day if and only if the number of hours worked is (strictly) greater than 8.
//A well-performing interval is an interval of days for which the number of tiring days is strictly larger than the number of non-tiring days.
//Return the length of the longest well-performing interval.
// 
//Example 1:
//Input: hours = [9,9,6,0,6,6,9]
//Output: 3
//Explanation: The longest well-performing interval is [9,9,6].
//Example 2:
//Input: hours = [6,6,6]
//Output: 0
// 
//Constraints:
//	1 <= hours.length <= 104
//	0 <= hours[i] <= 16
class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n = hours.size(), ans = 0;
        vector<int> st(n + 1);
        for (int i = 0; i < n; i++) {
            st[i + 1] = st[i] + (hours[i] > 8 ? 1 : -1);
        }
        stack<int> s;
        for (int i = 0; i <= n; i++) {
            if (s.empty() || st[s.top()] > st[i]) {
                s.push(i);
            }
        }
        for (int i = n; i >= 0; i--) {
            while (!s.empty() && st[s.top()] < st[i]) {
                ans = max(ans, i - s.top());
                s.pop();
            }
        }
        return ans;
    }
};