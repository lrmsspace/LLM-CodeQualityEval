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
        int n = hours.size(), res = 0, score = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; ++i) {
            score += hours[i] > 8 ? 1 : -1;
            if (score > 0) res = max(res, i + 1);
            else mp[score] = i;
            if (mp.count(score - 1)) res = max(res, i - mp[score - 1]);
        }
        return res;
    }
};