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
int maxValue(int** events, int eventsSize, int* eventsColSize, int k) {
    // Sort events based on endDay
    qsort(events, eventsSize, sizeof(events[0]), cmp);
    
    int n = eventsSize;
    int dp[n];
    memset(dp, 0, sizeof(dp));
    
    // Iterate through each event
    for (int i = 0; i < n; i++) {
        int endDay = events[i][1];
        
        // Find the maximum sum of values that can be achieved by attending events up to the current endDay
        int maxSum = 0;
        for (int j = 0; j < i; j++) {
            if (events[j][1] >= endDay) {
                maxSum = fmax(maxSum, dp[j]);
            }
        }
        
        // Update the maximum sum of values that can be achieved by attending the current event
        dp[i] = events[i][2] + maxSum;
    }
    
    // Return the maximum sum of values that can be achieved by attending events
    return *max_element(dp, dp + n);
    
}