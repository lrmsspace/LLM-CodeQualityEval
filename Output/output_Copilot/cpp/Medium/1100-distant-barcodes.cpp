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
        unordered_map<int, int> m;
        for (int i = 0; i < barcodes.size(); i++) {
            m[barcodes[i]]++;
        }
        priority_queue<pair<int, int>> q;
        for (auto a : m) {
            q.push({a.second, a.first});
        }
        vector<int> res(barcodes.size());
        int i = 0;
        while (!q.empty()) {
            int cnt = min(2, (int)barcodes.size() - i);
            vector<pair<int, int>> tmp;
            for (int j = 0; j < cnt; j++) {
                if (q.empty()) return res;
                auto a = q.top(); q.pop();
                res[i++] = a.second;
                if (--a.first > 0) tmp.push_back(a);
            }
            for (auto a : tmp) q.push(a);
        }
        return res;        
    }
};