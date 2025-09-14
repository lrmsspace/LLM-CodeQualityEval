/*
 You are given an integer array coins representing coins of different denominations and an integer k.
 You have an infinite number of coins of each denomination. However, you are not allowed to combine coins of different denominations.
 Return the kth smallest amount that can be made using these coins.
 Example 1:
 Input: coins = [3,6,9], k = 3
 Output:  9
 Explanation: The given coins can make the following amounts:
 Coin 3 produces multiples of 3: 3, 6, 9, 12, 15, etc.
 Coin 6 produces multiples of 6: 6, 12, 18, 24, etc.
 Coin 9 produces multiples of 9: 9, 18, 27, 36, etc.
 All of the coins combined produce: 3, 6, 9, 12, 15, etc.
 Example 2:
 Input: coins = [5,2], k = 7
 Output: 12 
 Explanation: The given coins can make the following amounts:
 Coin 5 produces multiples of 5: 5, 10, 15, 20, etc.
 Coin 2 produces multiples of 2: 2, 4, 6, 8, 10, 12, etc.
 All of the coins combined produce: 2, 4, 5, 6, 8, 10, 12, 14, 15, etc.
 Constraints:
 1 <= coins.length <= 15
 1 <= coins[i] <= 25
 1 <= k <= 2 * 109
 coins contains pairwise distinct integers.
*/

class Solution {
    public long findKthSmallest(int[] coins, int k) {
        // create a priority queue to store the amount of money
        PriorityQueue<Long> pq = new PriorityQueue<>();
        // add the 0 amount of money to the priority queue
        pq.offer(0L);
        // keep track of the visited amounts of money
        Set<Long> visited = new HashSet<>();
        // keep track of the kth amount of money
        long kthAmount = 0;
        // loop until the kth amount of money is found
        while (k > 0) {
            // get the smallest amount of money from the priority queue
            long amount = pq.poll();
            // if the amount of money has not been visited
            if (!visited.contains(amount)) {
                // add it to the visited set
                visited.add(amount);
                // loop through the coins
                for (int coin : coins) {
                    // calculate the new amount of money
                    long newAmount = amount + coin;
                    // add the new amount of money to the priority queue
                    pq.offer(newAmount);
                }
                // decrement k
                k--;
                // if k is 0, set the kth amount of money
                if (k == 0) {
                    kthAmount = amount;
                }
            }
        }
        // return the kth amount of money
        return kthAmount;
    }
}