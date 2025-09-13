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
        int n = events.size();
        int maxDay = 0;
        for (int i = 0; i < n; i++) {
            maxDay = max(maxDay, events[i][1]);
        }
        vector<vector<int>> days(maxDay + 1, vector<int>());
        for (int i = 0; i < n; i++) {
            days[events[i][0]].push_back(i);
        }
        priority_queue<int, vector<int>, greater<int>> pq;
        int res = 0;
        for (int i = 1; i <= maxDay; i++) {
            for (int j = 0; j < days[i].size(); j++) {
                pq.push(events[days[i][j]][1]);
            }
            while (!pq.empty() && pq.top() < i) {
                pq.pop();
            }
            if (!pq.empty()) {
                pq.pop();
                res++;
            }
        }
        return res;
    }
};