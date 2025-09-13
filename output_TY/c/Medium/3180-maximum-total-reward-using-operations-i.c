/*
 You are given an integer array rewardValues of length n, representing the values of rewards.
 Initially, your total reward x is 0, and all indices are unmarked. You are allowed to perform the following operation any number of times:
 Choose an unmarked index i from the range [0, n - 1].
 If rewardValues[i] is greater than your current total reward x, then add rewardValues[i] to x (i.e., x = x + rewardValues[i]), and mark the index i.
 Return an integer denoting the maximum total reward you can collect by performing the operations optimally.
 Example 1:
 Input: rewardValues = [1,1,3,3]
 Output: 4
 Explanation:
 During the operations, we can choose to mark the indices 0 and 2 in order, and the total reward will be 4, which is the maximum.
 Example 2:
 Input: rewardValues = [1,6,4,3,2]
 Output: 11
 Explanation:
 Mark the indices 0, 2, and 1 in order. The total reward will then be 11, which is the maximum.
 Constraints:
 1 <= rewardValues.length <= 2000
 1 <= rewardValues[i] <= 2000
*/

int maxTotalReward(int* rewardValues, int rewardValuesSize) {
    
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;
    
    int sum = 0;
    int max = 0;
    int index = 0;

    for (i = 0; i < rewardValuesSize; i++) {
        sum += rewardValues[i];
        if (rewardValues[i] > max) {
            max = rewardValues[i];
            index = i;
        }
    }
    return sum - max + rewardValues[index];

}