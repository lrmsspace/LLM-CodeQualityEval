/**https://leetcode.com/problems/array-of-doubled-pairs/ */
//Given an integer array of even length arr, return true if it is possible to reorder arr such that arr[2 * i + 1] = 2 * arr[2 * i] for every 0 <= i < len(arr) / 2, or false otherwise.
// 
//Example 1:
//Input: arr = [3,1,3,6]
//Output: false
//Example 2:
//Input: arr = [2,1,2,6]
//Output: false
//Example 3:
//Input: arr = [4,-2,2,-4]
//Output: true
//Explanation: We can take two groups, [-2,-4] and [2,4] to form [-2,-4,2,4] or [2,4,-2,-4].
// 
//Constraints:
//	2 <= arr.length <= 3 * 104
//	arr.length is even.
//	-105 <= arr[i] <= 105
class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int, int> count;
        for (int num : arr) {
            count[num]++;
        }
        
        priority_queue<int> pq;
        for (auto& [num, freq] : count) {
            pq.push(num);
        }
        
        while (!pq.empty()) {
            int num = pq.top();
            pq.pop();
            
            if (freq == 0) {
                continue;
            }
            
            if (num % 2 == 0) {
                if (count[num / 2] == 0) {
                    return false;
                }
                count[num / 2]--;
            } else {
                if (count[num * 2] == 0 || count[num * 2] < freq) {
                    return false;
                }
                count[num * 2] -= freq;
            }
            count[num]--;
        }
        
        return true;
        
    }
};