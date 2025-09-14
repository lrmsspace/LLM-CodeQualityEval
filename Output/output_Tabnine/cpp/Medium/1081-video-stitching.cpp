/**https://leetcode.com/problems/video-stitching/ */
//You are given a series of video clips from a sporting event that lasted time seconds. These video clips can be overlapping with each other and have varying lengths.
//Each video clip is described by an array clips where clips[i] = [starti, endi] indicates that the ith clip started at starti and ended at endi.
//We can cut these clips into segments freely.
//	For example, a clip [0, 7] can be cut into segments [0, 1] + [1, 3] + [3, 7].
//Return the minimum number of clips needed so that we can cut the clips into segments that cover the entire sporting event [0, time]. If the task is impossible, return -1.
// 
//Example 1:
//Input: clips = [[0,2],[4,6],[8,10],[1,9],[1,5],[5,9]], time = 10
//Output: 3
//Explanation: We take the clips [0,2], [8,10], [1,9]; a total of 3 clips.
//Then, we can reconstruct the sporting event as follows:
//We cut [1,9] into segments [1,2] + [2,8] + [8,9].
//Now we have segments [0,2] + [2,8] + [8,10] which cover the sporting event [0, 10].
//Example 2:
//Input: clips = [[0,1],[1,2]], time = 5
//Output: -1
//Explanation: We cannot cover [0,5] with only [0,1] and [1,2].
//Example 3:
//Input: clips = [[0,1],[6,8],[0,2],[5,6],[0,4],[0,3],[6,7],[1,3],[4,7],[1,4],[2,5],[2,6],[3,4],[4,5],[5,7],[6,9]], time = 9
//Output: 3
//Explanation: We can take clips [0,4], [4,7], and [6,9].
// 
//Constraints:
//	1 <= clips.length <= 100
//	0 <= starti <= endi <= 100
//	1 <= time <= 100
class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        vector<pair<int, int>> events; // start, end
        for (auto& clip : clips) {
            events.push_back({clip[0], 1}); // start event
            events.push_back({clip[1], -1}); // end event
        }
        sort(events.begin(), events.end());
        int maxEnd = 0, ans = 0;
        for (auto& event : events) {
            maxEnd = max(maxEnd, event.first);
            if (--event.second == 0) ans++;
        }
        return maxEnd >= time? ans : -1;       
    }
};