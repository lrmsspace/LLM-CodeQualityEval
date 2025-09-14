/*
 You are given an integer eventTime denoting the duration of an event, where the event occurs from time t = 0 to time t = eventTime.
 You are also given two integer arrays startTime and endTime, each of length n. These represent the start and end time of n non-overlapping meetings, where the ith meeting occurs during the time [startTime[i], endTime[i]].
 You can reschedule at most k meetings by moving their start time while maintaining the same duration, to maximize the longest continuous period of free time during the event.
 The relative order of all the meetings should stay the same and they should remain non-overlapping.
 Return the maximum amount of free time possible after rearranging the meetings.
 Note that the meetings can not be rescheduled to a time outside the event.
 Example 1:
 Input: eventTime = 5, k = 1, startTime = [1,3], endTime = [2,5]
 Output: 2
 Explanation:
 Reschedule the meeting at [1, 2] to [2, 3], leaving no meetings during the time [0, 2].
 Example 2:
 Input: eventTime = 10, k = 1, startTime = [0,2,9], endTime = [1,4,10]
 Output: 6
 Explanation:
 Reschedule the meeting at [2, 4] to [1, 3], leaving no meetings during the time [3, 9].
 Example 3:
 Input: eventTime = 5, k = 2, startTime = [0,1,2,3,4], endTime = [1,2,3,4,5]
 Output: 0
 Explanation:
 There is no time during the event not occupied by meetings.
 Constraints:
 1 <= eventTime <= 109
 n == startTime.length == endTime.length
 2 <= n <= 105
 1 <= k <= n
 0 <= startTime[i] < endTime[i] <= eventTime
 endTime[i] <= startTime[i + 1] where i lies in the range [0, n - 2].
*/

int maxFreeTime(int eventTime, int k, int* startTime, int startTimeSize, int* endTime, int endTimeSize) {
    int* mergedStartTimes = (int*)malloc(sizeof(int) * (startTimeSize + endTimeSize));
    int* mergedEndTimes = (int*)malloc(sizeof(int) * (startTimeSize + endTimeSize));
    int mergedStartTimesSize = 0;
    int mergedEndTimesSize = 0;
    
    // Merge the start and end times
    for (int i = 0; i < startTimeSize; i++) {
        mergedStartTimes[mergedStartTimesSize++] = startTime[i];
        mergedEndTimes[mergedEndTimesSize++] = endTime[i];
    }
    for (int i = 0; i < endTimeSize; i++) {
        mergedStartTimes[mergedStartTimesSize++] = endTime[i];
        mergedEndTimes[mergedEndTimesSize++] = startTime[i] + eventTime;
    }
    
    // Sort the merged start and end times
    qsort(mergedStartTimes, mergedStartTimesSize, sizeof(int), compare);
    qsort(mergedEndTimes, mergedEndTimesSize, sizeof(int), compare);
    
    int maxFreeTime = 0;
    int currentFreeTime = 0;
    
    for (int i = 0; i < mergedStartTimesSize; i++) {
        if (i == 0 || mergedStartTimes[i] > mergedEndTimes[i - 1]) {
            currentFreeTime = mergedStartTimes[i] - mergedEndTimes[i - 1];
        } else {
            currentFreeTime = 0;
        }
        maxFreeTime = max(maxFreeTime, currentFreeTime);
        
        // If we have reached the maximum number of reschedulable meetings, break the loop
        if (k-- <= 0) {
            break;
        }
    }
    
    free(mergedStartTimes);
    free(mergedEndTimes);
    return maxFreeTime;
    
}