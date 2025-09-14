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
int maxEvents(int** events, int eventsSize, int* eventsColSize){
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int* a = (int*)calloc(100001, sizeof(int));
    int* b = (int*)calloc(100001, sizeof(int));
    int* c = (int*)calloc(100001, sizeof(int));
    int* d = (int*)calloc(100001, sizeof(int));
    for (i = 0; i < eventsSize; i++) {
        a[events[i][0]]++;
        b[events[i][1]]++;
    }
    for (i = 1; i <= 100000; i++) {
        c[i] = c[i - 1] + a[i];
        d[i] = d[i - 1] + b[i];
    }
    for (i = 0; i < eventsSize; i++) {
        events[i][0] = c[events[i][0]];
        events[i][1] = d[events[i][1]];
    }
    qsort(events, eventsSize, sizeof(int*) * eventsColSize, (int(*)(const void*, const void*))([](const int* a, const int* b) { 
        return a[0] - b[0];
    });
    )
}