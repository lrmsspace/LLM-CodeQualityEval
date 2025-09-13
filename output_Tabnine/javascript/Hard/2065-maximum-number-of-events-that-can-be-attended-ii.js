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
/**
 * @param {number[][]} events
 * @param {number} k
 * @return {number}
 */
var maxValue = function(events, k) {
    // Sort events by end day
    events.sort((a, b) => a[1] - b[1]);
    
    // Initialize a priority queue to store the end day of events
    const pq = [];
    
    let maxSum = 0;
    let count = 0;
    
    // Iterate through events
    for (let i = 0; i < events.length; i++) {
        // While there are events in the priority queue and their end day is earlier than the current event's start day
        while (pq.length > 0 && pq[0] <= events[i][0]) {
            // Pop the earliest event from the priority queue
            maxSum -= pq.shift();
        }
        
        // Add the current event's value to the priority queue
        pq.push(events[i][2]);
        
        // If the priority queue size exceeds k, remove the oldest event
        if (pq.length > k) {
            maxSum -= pq.shift();
        }
        
        // Update the count of events attended
        count++;
    }
    
    return maxSum;
    
};