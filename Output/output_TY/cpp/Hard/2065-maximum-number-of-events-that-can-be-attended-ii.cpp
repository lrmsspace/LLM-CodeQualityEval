/**https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/ */
//You are given an array of events where events[i] = [startDayi, endDayi, valuei]. The ith event starts at startDayi and ends at endDayi, and if you attend this event, you will receive a value of valuei. You are also given an integer k which represents the maximum number of events you can attend.
//You can only attend one event at a time. If you choose to attend an event, you must attend the entire event. Note that the end day is inclusive: that is, you cannot attend two events where one of them starts and the other ends on the same day.
//Return the maximum sum of values that you can receive by attending events.
// 
//Example 1:
//Input: events = [[1,2,4],[3,4,3],[2,3,1]], k = 2
//Output: 7
//Explanation: Choose the green events, 0 and 1 (0-indexed) for a total value of 4 + 3 = 7.
//Example 2:
//Input: events = [[1,2,4],[3,4,3],[2,3,10]], k = 2
//Output: 10
//Explanation: Choose event 2 for a total value of 10.
//Notice that you cannot attend any other event as they overlap, and that you do not have to attend k events.
//Example 3:
//Input: events = [[1,1,1],[2,2,2],[3,3,3],[4,4,4]], k = 3
//Output: 9
//Explanation: Although the events do not overlap, you can only attend 3 events. Pick the highest valued three.
// 
//Constraints:
//	1 <= k <= events.length
//	1 <= k * events.length <= 106
//	1 <= startDayi <= endDayi <= 109
//	1 <= valuei <= 106
class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        vector<vector<int>> dp(n, vector<int>(k + 1, 0));
        vector<pair<int, int>> start(n);
        for (int i = 0; i < n; i++) {
            start[i] = {events[i][0], i};
        }
        sort(start.begin(), start.end());
        for (int i = 0; i < n; i++) {
            dp[i][1] = events[start[i].second][2];
        }
        for (int i = 1; i < k; i++) {
            for (int j = 0; j < n;j++) {
                dp[j][i + 1] = dp[j][i];
                for (int k = j + 1; k < n; k++) {
                    if (events[start[k].second][0] > events[start[j].second][1]) {
                        dp[j][i + 1] = max(dp[j][i + 1], events[start[k].second][2] + dp[k][i]);
                    }
                }
            }
        }
        return dp[0][k];
    }
};