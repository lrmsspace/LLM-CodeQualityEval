/*
 Bob is stuck in a dungeon and must break n locks, each requiring some amount of energy to break. The required energy for each lock is stored in an array called strength where strength[i] indicates the energy needed to break the ith lock.
 To break a lock, Bob uses a sword with the following characteristics:
 The initial energy of the sword is 0.
 The initial factor x by which the energy of the sword increases is 1.
 Every minute, the energy of the sword increases by the current factor x.
 To break the ith lock, the energy of the sword must reach at least strength[i].
 After breaking a lock, the energy of the sword resets to 0, and the factor x increases by a given value k.
 Your task is to determine the minimum time in minutes required for Bob to break all n locks and escape the dungeon.
 Return the minimum time required for Bob to break all n locks.
 Example 1:
 Input: strength = [3,4,1], k = 1
 Output: 4
 Explanation:
 Time
 Energy
 x
 Action
 Updated x
 0
 0
 1
 Nothing
 1
 1
 1
 1
 Break 3rd Lock
 2
 2
 2
 2
 Nothing
 2
 3
 4
 2
 Break 2nd Lock
 3
 4
 3
 3
 Break 1st Lock
 3
 The locks cannot be broken in less than 4 minutes; thus, the answer is 4.
 Example 2:
 Input: strength = [2,5,4], k = 2
 Output: 5
 Explanation:
 Time
 Energy
 x
 Action
 Updated x
 0
 0
 1
 Nothing
 1
 1
 1
 1
 Nothing
 1
 2
 2
 1
 Break 1st Lock
 3
 3
 3
 3
 Nothing
 3
 4
 6
 3
 Break 2nd Lock
 5
 5
 5
 5
 Break 3rd Lock
 7
 The locks cannot be broken in less than 5 minutes; thus, the answer is 5.
 Constraints:
 n == strength.length
 1 <= n <= 8
 1 <= K <= 10
 1 <= strength[i] <= 106
*/

/**
 * @param {number[]} strength
 * @param {number} k
 * @return {number}
 */
var findMinimumTime = function(strength, k) {
    const n = strength.length;
    let minTime = Infinity;

    // Helper function to calculate the time to break all locks with a given order
    const calculateTime = (order) => {
        let time = 0;
        let energy = 0;
        let factor = 1;

        for (let i = 0; i < n; i++) {
            const lockIndex = order[i];
            while (energy < strength[lockIndex]) {
                energy += factor;
                time++;
            }
            energy = 0; // Reset energy after breaking the lock
            factor += k; // Increase factor after breaking a lock
        }

        return time;
    };

    // Generate all permutations of lock indices
    const generatePermutations = (arr, start, end) => {
        if (start === end) {
            minTime = Math.min(minTime, calculateTime(arr));
        } else {
            for (let i = start; i <= end; i++) {
                [arr[start], arr[i]] = [arr[i], arr[start]]; // Swap
                generatePermutations(arr, start + 1, end);
                [arr[start], arr[i]] = [arr[i], arr[start]]; // Backtrack
            }
        }
    };

    generatePermutations(Array.from({ length: n }, (_, i) => i), 0, n - 1);

    return minTime;
        
};