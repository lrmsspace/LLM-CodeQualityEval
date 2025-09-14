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
int maxEvents(int** events, int eventsSize, int* eventsColSize) {
    int i, j, k, max = 0, max_end = 0, max_start = 0, max_index = 0;
    int *dp = (int *)malloc(sizeof(int) * 100001);
    memset(dp, 0, sizeof(int) * 100001);
    for (i = 0; i < eventsSize; i++) {
        if (events[i][1] > max_end) {
            max_end = events[i][1];
        }
    }
    for (i = 0; i < eventsSize; i++) {
        if (events[i][0] > max_start) {
            max_start = events[i][0];
        }
    }
    for (i = 0; i < eventsSize; i++) {
        if (events[i][1] == max_end) {
            max_index++;
        }
    }
    for (i = 0; i < eventsSize; i++) {
        for (j = events[i][0]; j <= events[i][1]; j++) {
            dp[j]++;
        }
    }
    for (i = 0; i <= max_end; i++) {
        if (dp[i] != 0) {
            max++;
            dp[i]--;
        }
    }
    for (i = 0; i < max_index; i++) {
        for (j = max_end - 1; j >= max_start; j--) {
            if (dp[j] != 0) {
                max++;
                dp[j]--;
                break;
            }
        }
    }
    return max;    
}