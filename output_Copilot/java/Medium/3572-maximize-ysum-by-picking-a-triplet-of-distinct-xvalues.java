/*
 You are given two integer arrays x and y, each of length n. You must choose three distinct indices i, j, and k such that:
 x[i] != x[j]
 x[j] != x[k]
 x[k] != x[i]
 Your goal is to maximize the value of y[i] + y[j] + y[k] under these conditions. Return the maximum possible sum that can be obtained by choosing such a triplet of indices.
 If no such triplet exists, return -1.
 Example 1:
 Input: x = [1,2,1,3,2], y = [5,3,4,6,2]
 Output: 14
 Explanation:
 Choose i = 0 (x[i] = 1, y[i] = 5), j = 1 (x[j] = 2, y[j] = 3), k = 3 (x[k] = 3, y[k] = 6).
 All three values chosen from x are distinct. 5 + 3 + 6 = 14 is the maximum we can obtain. Hence, the output is 14.
 Example 2:
 Input: x = [1,2,1,2], y = [4,5,6,7]
 Output: -1
 Explanation:
 There are only two distinct values in x. Hence, the output is -1.
 Constraints:
 n == x.length == y.length
 3 <= n <= 105
 1 <= x[i], y[i] <= 106
*/

class Solution {
    public int maxSumDistinctTriplet(int[] x, int[] y) {
        int n = x.length;
        if (n < 3) return -1;

        // Map to store the maximum y value for each distinct x value
        Map<Integer, Integer> maxYMap = new HashMap<>();
        
        for (int i = 0; i < n; i++) {
            maxYMap.put(x[i], Math.max(maxYMap.getOrDefault(x[i], 0), y[i]));
        }

        // If there are less than 3 distinct x values, return -1
        if (maxYMap.size() < 3) return -1;

        // Extract the maximum y values and sort them
        List<Integer> maxYValues = new ArrayList<>(maxYMap.values());
        Collections.sort(maxYValues, Collections.reverseOrder());

        // Return the sum of the top three maximum y values
        return maxYValues.get(0) + maxYValues.get(1) + maxYValues.get(2);        
    }
}