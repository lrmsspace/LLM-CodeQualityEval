/*
 You are given an integer n and an array sick sorted in increasing order, representing positions of infected people in a line of n people.
 At each step, one uninfected person adjacent to an infected person gets infected. This process continues until everyone is infected.
 An infection sequence is the order in which uninfected people become infected, excluding those initially infected.
 Return the number of different infection sequences possible, modulo 109+7.
 Example 1:
 Input: n = 5, sick = [0,4]
 Output: 4
 Explanation:
 There is a total of 6 different sequences overall.
 Valid infection sequences are [1,2,3], [1,3,2], [3,2,1] and [3,1,2].
 [2,3,1] and [2,1,3] are not valid infection sequences because the person at index 2 cannot be infected at the first step.
 Example 2:
 Input: n = 4, sick = [1]
 Output: 3
 Explanation:
 There is a total of 6 different sequences overall.
 Valid infection sequences are [0,2,3], [2,0,3] and [2,3,0].
 [3,2,0], [3,0,2], and [0,3,2] are not valid infection sequences because the infection starts at the person at index 1, then the order of infection is 2, then 3, and hence 3 cannot be infected earlier than 2.
 Constraints:
 2 <= n <= 105
 1 <= sick.length <= n - 1
 0 <= sick[i] <= n - 1
 sick is sorted in increasing order.
*/

int numberOfSequence(int n, int* sick, int sickSize) {
    int left, right, result = 1;

    for (int i = 0; i <= sickSize; i++) {
        if (i == 0) {
            left = sick[i];
        } else {
            left = sick[i] - sick[i - 1] - 1;
        }
        if (i == sickSize) {
            right = n - sick[i - 1] - 1;
        } else {
            right = sick[i] - sick[i - 1] - 1;
        }

        if (i > 0 && left > 0) {
            result = (result * (left + 1)) % MOD;
        }
        if (i < sickSize && right > 0) {
            result = (result * (right + 1)) % MOD;
        }
    }

    return result;
}

