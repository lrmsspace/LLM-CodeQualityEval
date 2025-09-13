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
    public int[] rearrangeBarcodes(int[] barcodes) {
        int[] count = new int[10001];
        for (int barcode : barcodes) {
            count[barcode]++;
        }
        
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> b[1] - a[1]);
        for (int i = 1; i <= 10000; i++) {
            if (count[i] > 0) {
                pq.offer(new int[]{i, count[i]});
            }
        }
        
        int[] result = new int[barcodes.length];
        int index = 0;
        while (!pq.isEmpty()) {
            int[] pair = pq.poll();
            result[index++] = pair[0];
            if (pair[1] > 1) {
                pq.offer(new int[]{pair[0], pair[1] - 1});
            }
            
            if (!pq.isEmpty()) {
                pair = pq.poll();
                result[index++] = pair[0];
                if (pair[1] > 1) {
                    pq.offer(new int[]{pair[0], pair[1] - 1});
                }
            }
        }
        
        return result;
        
    }
}