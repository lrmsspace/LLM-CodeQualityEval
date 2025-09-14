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
        int n = barcodes.length;
        int[] count = new int[10001];
        for (int c : barcodes) {
            count[c]++;
        }
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> b[1] - a[1]);
        for (int i = 0; i < 10001; i++) {
            if (count[i] > 0) {
                pq.offer(new int[]{i, count[i]});
            }
        }
        int[] res = new int[n];
        int i = 0;
        while (pq.size() > 1) {
            int[] a = pq.poll();
            int[] b = pq.poll();
            res[i++] = a[0];
            res[i++] = b[0];
            if (--a[1] > 0) {
                pq.offer(a);
            }
            if (--b[1] > 0) {
                pq.offer(b);
            }
        }
        if (pq.size() > 0) {
            res[i] = pq.poll()[0];
        }
        return res;
    }
}