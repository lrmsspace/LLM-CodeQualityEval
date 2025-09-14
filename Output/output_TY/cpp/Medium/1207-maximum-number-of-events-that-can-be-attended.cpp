/**https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/ */
//You are given an array of events where events[i] = [startDayi, endDayi]. Every event i starts at startDayi and ends at endDayi.
//You can attend an event i at any day d where startTimei <= d <= endTimei. You can only attend one event at any time d.
//Return the maximum number of events you can attend.
// 
//Example 1:
//Input: events = [[1,2],[2,3],[3,4]]
//Output: 3
//Explanation: You can attend all the three events.
//One way to attend them all is as shown.
//Attend the first event on day 1.
//Attend the second event on day 2.
//Attend the third event on day 3.
//Example 2:
//Input: events= [[1,2],[2,3],[3,4],[1,2]]
//Output: 4
// 
//Constraints:
//	1 <= events.length <= 105
//	events[i].length == 2
//	1 <= startDayi <= endDayi <= 105
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size(), ans = 0;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = n - 1; i >= 0; i--){
            for (int j = i; j >= 0; j--){
                dp[i][j] = max(events[i][1] - events[j][0] + 1, 0) + dp[i + 1][j + 1];
                for (int k = j + 1; k < n; k++){
                    if (events[k][0] > events[i][1]) break;
                    dp[i][j] = max(dp[i][j], dp[i + 1][k]);
                }
            }
        }
        return dp[0][0];
    }
};