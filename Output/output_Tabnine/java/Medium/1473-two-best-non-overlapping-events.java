/**https://leetcode.com/problems/two-best-non-overlapping-events/ */
//You are given a 0-indexed 2D integer array of events where events[i] = [startTimei, endTimei, valuei]. The ith event starts at startTimei and ends at endTimei, and if you attend this event, you will receive a value of valuei. You can choose at most two non-overlapping events to attend such that the sum of their values is maximized.
//Return this maximum sum.
//Note that the start time and end time is inclusive: that is, you cannot attend two events where one of them starts and the other ends at the same time. More specifically, if you attend an event with end time t, the next event must start at or after t + 1.
// 
//Example 1:
//Input: events = [[1,3,2],[4,5,2],[2,4,3]]
//Output: 4
//Explanation: Choose the green events, 0 and 1 for a sum of 2 + 2 = 4.
//Example 2:
//Input: events = [[1,3,2],[4,5,2],[1,5,5]]
//Output: 5
//Explanation: Choose event 2 for a sum of 5.
//Example 3:
//Input: events = [[1,5,3],[1,5,1],[6,6,5]]
//Output: 8
//Explanation: Choose events 0 and 2 for a sum of 3 + 5 = 8.
// 
//Constraints:
//	2 <= events.length <= 105
//	events[i].length == 3
//	1 <= startTimei <= endTimei <= 109
//	1 <= valuei <= 106
class Solution {
    public int maxTwoEvents(int[][] events) {
        int n = events.length;
        int[][] sortedEvents = Arrays.copyOf(events, n);
        Arrays.sort(sortedEvents, (a, b) -> b[2] - a[2]);
        
        int[] dp = new int[n];
        int[] ends = new int[n];
        
        for (int i = 0; i < n; i++) {
            ends[i] = sortedEvents[i][1];
        }
        
        Arrays.sort(ends);
        
        int ans = 0;
        int j = 0;
        
        for (int i = 0; i < n; i++) {
            while (j < n && ends[j] < sortedEvents[i][0]) {
                j++;
            }
            
            dp[i] = Math.max(dp[i], ans + sortedEvents[i][2]);
            ans = Math.max(ans, dp[i]);
        }
        
        return ans;
        
    }
}