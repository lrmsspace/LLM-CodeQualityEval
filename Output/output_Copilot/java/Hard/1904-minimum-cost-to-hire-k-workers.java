/**https://leetcode.com/problems/minimum-cost-to-hire-k-workers/ */
//There are n workers. You are given two integer arrays quality and wage where quality[i] is the quality of the ith worker and wage[i] is the minimum wage expectation for the ith worker.
//We want to hire exactly k workers to form a paid group. To hire a group of k workers, we must pay them according to the following rules:
//	Every worker in the paid group must be paid at least their minimum wage expectation.
//	In the group, each worker's pay must be directly proportional to their quality. This means if a worker’s quality is double that of another worker in the group, then they must be paid twice as much as the other worker.
//Given the integer k, return the least amount of money needed to form a paid group satisfying the above conditions. Answers within 10-5 of the actual answer will be accepted.
// 
//Example 1:
//Input: quality = [10,20,5], wage = [70,50,30], k = 2
//Output: 105.00000
//Explanation: We pay 70 to 0th worker and 35 to 2nd worker.
//Example 2:
//Input: quality = [3,1,10,10,1], wage = [4,8,2,2,7], k = 3
//Output: 30.66667
//Explanation: We pay 4 to 0th worker, 13.33333 to 2nd and 3rd workers separately.
// 
//Constraints:
//	n == quality.length == wage.length
//	1 <= k <= n <= 104
//	1 <= quality[i], wage[i] <= 104
class Solution {
    public double mincostToHireWorkers(int[] quality, int[] wage, int k) {
        int n = quality.length;
        double[][] workers = new double[n][2];
        for (int i = 0; i < n; i++) {
            workers[i][0] = (double) wage[i] / quality[i]; // ratio of wage to quality
            workers[i][1] = quality[i]; // quality
        }
        Arrays.sort(workers, (a, b) -> Double.compare(a[0], b[0])); // sort by ratio

        PriorityQueue<Double> pq = new PriorityQueue<>(Collections.reverseOrder()); // max heap for quality
        double sumQuality = 0;
        double minCost = Double.MAX_VALUE;

        for (int i = 0; i < n; i++) {
            pq.offer(workers[i][1]); // add quality to the heap
            sumQuality += workers[i][1]; // add to total quality

            if (pq.size() > k) { // if we have more than k workers, remove the one with the highest quality
                sumQuality -= pq.poll();
            }

            if (pq.size() == k) { // if we have exactly k workers, calculate the cost
                minCost = Math.min(minCost, sumQuality * workers[i][0]);
            }
        }

        return minCost;        
    }
}