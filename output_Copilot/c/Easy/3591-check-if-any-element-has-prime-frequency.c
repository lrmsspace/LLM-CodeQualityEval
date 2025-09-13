/*
 You are given an integer array nums.
 Return true if the frequency of any element of the array is prime, otherwise, return false.
 The frequency of an element x is the number of times it occurs in the array.
 A prime number is a natural number greater than 1 with only two factors, 1 and itself.
 Example 1:
 Input: nums = [1,2,3,4,5,4]
 Output: true
 Explanation:
 4 has a frequency of two, which is a prime number.
 Example 2:
 Input: nums = [1,2,3,4,5]
 Output: false
 Explanation:
 All elements have a frequency of one.
 Example 3:
 Input: nums = [2,2,2,4,4]
 Output: true
 Explanation:
 Both 2 and 4 have a prime frequency.
 Constraints:
 1 <= nums.length <= 100
 0 <= nums[i] <= 100
*/

bool checkPrimeFrequency(int* nums, int numsSize) {
    int frequency[101] = {0}; // Array to count frequencies of numbers from 0 to 100
    for (int i = 0; i < numsSize; i++) {
        frequency[nums[i]]++;
    }

    // Function to check if a number is prime
    bool isPrime(int n) {
        if (n <= 1) return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }

    // Check the frequency of each number
    for (int i = 0; i < 101; i++) {
        if (frequency[i] > 0 && isPrime(frequency[i])) {
            return true; // Found a prime frequency
        }
    }

    return false; // No prime frequency found
    
}