/**https://leetcode.com/problems/distant-barcodes/ */
//In a warehouse, there is a row of barcodes, where the ith barcode is barcodes[i].
//Rearrange the barcodes so that no two adjacent barcodes are equal. You may return any answer, and it is guaranteed an answer exists.
// 
//Example 1:
//Input: barcodes = [1,1,1,2,2,2]
//Output: [2,1,2,1,2,1]
//Example 2:
//Input: barcodes = [1,1,1,1,2,2,3,3]
//Output: [1,3,1,3,1,2,1,2]
// 
//Constraints:
//	1 <= barcodes.length <= 10000
//	1 <= barcodes[i] <= 10000
class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        priority_queue<pair<int, int>> q;
        unordered_map<int, int> count;
        for (int i : barcodes) ++count[i];
        for (auto& p : count) q.push({p.second, p.first});
        vector<int> ans;
        int prev = -1;
        while (!q.empty()) {
            auto t = q.top(); q.pop();
            if (ans.size() % 2 == 0) {
                if (prev != -1 && t.second == prev) {
                    if (q.empty()) return {};
                    auto next = q.top(); q.pop();
                    ans.push_back(next.second);
                    if (--next.first > 0) q.push(next);
                }
            }
            ans.push_back(t.second);
            prev = t.second;
            if (--t.first > 0) q.push(t);
        }
        return ans;
    }
};