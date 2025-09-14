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

// Comparison function to sort events by end time, then start time
int compare(const void* a, const void* b) {
    int* eventA = *(int**)a;
    int* eventB = *(int**)b;
    if (eventA[1] != eventB[1]) {
        return eventA[1] - eventB[1];
    }
    return eventA[0] - eventB[0];
}

// Helper function to search for the best non-overlapping event
int binarySearch(int** events, int endIndex, int target) {
    int left = 0, right = endIndex;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (events[mid][1] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left - 1;
}

int maxTwoEvents(int** events, int eventsSize, int* eventsColSize) {
    // Sort events by end time
    qsort(events, eventsSize, sizeof(int*), compare);

    // Array to store maximum values up to each event
    int* dp = (int*)malloc(eventsSize * sizeof(int));
    dp[0] = events[0][2];
    for (int i = 1; i < eventsSize; i++) {
        dp[i] = events[i][2] > dp[i - 1] ? events[i][2] : dp[i - 1];
    }

    int maxSum = dp[eventsSize - 1];
    for (int i = 1; i < eventsSize; i++) {
        int j = binarySearch(events, i, events[i][0]);
        if (j != -1) {
            int currentSum = events[i][2] + dp[j];
            if (currentSum > maxSum) {
                maxSum = currentSum;
            }
        }
    }

    free(dp);
    return maxSum;
}

