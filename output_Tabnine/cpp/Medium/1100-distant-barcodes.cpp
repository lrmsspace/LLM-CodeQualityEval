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
        int n = barcodes.size();
        unordered_map<int, int> count;
        for (int barcode : barcodes) {
            count[barcode]++;
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (auto& [barcode, freq] : count) {
            pq.push({freq, barcode});
        }
        
        vector<int> result;
        int prev = -1;
        while (!pq.empty()) {
            int freq1 = pq.top().first;
            int barcode1 = pq.top().second;
            pq.pop();
            
            if (prev!= -1) {
                pq.push({freq1 - 1, prev});
            }
            
            result.push_back(barcode1);
            prev = barcode1;
            
            if (freq1 > 1) {
                pq.push({freq1 - 1, barcode1});
            }
        }
        
        return result;
        
    }
};