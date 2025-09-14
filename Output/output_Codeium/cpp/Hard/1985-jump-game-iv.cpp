/**https://leetcode.com/problems/jump-game-iv/ */
//Given an array of integers arr, you are initially positioned at the first index of the array.
//In one step you can jump from index i to index:
//	i + 1 where: i + 1 < arr.length.
//	i - 1 where: i - 1 >= 0.
//	j where: arr[i] == arr[j] and i != j.
//Return the minimum number of steps to reach the last index of the array.
//Notice that you can not jump outside of the array at any time.
// 
//Example 1:
//Input: arr = [100,-23,-23,404,100,23,23,23,3,404]
//Output: 3
//Explanation: You need three jumps from index 0 --> 4 --> 3 --> 9. Note that index 9 is the last index of the array.
//Example 2:
//Input: arr = [7]
//Output: 0
//Explanation: Start index is the last index. You do not need to jump.
//Example 3:
//Input: arr = [7,6,9,6,9,6,9,7]
//Output: 1
//Explanation: You can jump directly from index 0 to index 7 which is last index of the array.
// 
//Constraints:
//	1 <= arr.length <= 5 * 104
//	-108 <= arr[i] <= 108
class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int, vector<int>> pos;
        for (int i = 0; i < arr.size(); ++i) {
            pos[arr[i]].push_back(i);
        }
        queue<int> q;
        q.push(0);
        vector<bool> vis(arr.size(), false);
        vis[0] = true;
        int step = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                int cur = q.front(); q.pop();
                if (cur == arr.size() - 1) return step;
                for (int j : pos[arr[cur]]) {
                    if (!vis[j]) {
                        vis[j] = true;
                        q.push(j);
                    }
                }
                pos[arr[cur]].clear();
                if (cur + 1 < arr.size() && !vis[cur + 1]) {
                    vis[cur + 1] = true;
                    q.push(cur + 1);
                }
                if (cur - 1 >= 0 && !vis[cur - 1]) {
                    vis[cur - 1] = true;
                    q.push(cur - 1);
                }
            }
            ++step;
        }
        return -1;
    }
};