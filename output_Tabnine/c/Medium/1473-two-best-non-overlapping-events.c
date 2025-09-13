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
int maxTwoEvents(int** events, int eventsSize, int* eventsColSize) {
    // Sort the events based on end time in ascending order
    qsort(events, eventsSize, sizeof(events[0]), compare);
    
    int maxSum = 0;
    int lastEndTime = 0;
    
    // Iterate through the sorted events
    for (int i = 0; i < eventsSize; i++) {
        int startTime = events[i][0];
        int endTime = events[i][1];
        int value = events[i][2];
        
        // If the current event starts after the last event's end time, update the last event's end time
        if (startTime > lastEndTime) {
            lastEndTime = endTime;
        }
        
        // If the current event ends before the last event's end time, add its value to the maximum sum
        if (endTime <= lastEndTime) {
            maxSum += value;
        }
    }
    
    return maxSum;
    
}