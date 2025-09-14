/*
 Given a string s, find the sum of the 3 largest unique prime numbers that can be formed using any of its substrings.
 Return the sum of the three largest unique prime numbers that can be formed. If fewer than three exist, return the sum of all available primes. If no prime numbers can be formed, return 0.
 Note: Each prime number should be counted only once, even if it appears in multiple substrings. Additionally, when converting a substring to an integer, any leading zeros are ignored.
 Example 1:
 Input: s = "12234"
 Output: 1469
 Explanation:
 The unique prime numbers formed from the substrings of "12234" are 2, 3, 23, 223, and 1223.
 The 3 largest primes are 1223, 223, and 23. Their sum is 1469.
 Example 2:
 Input: s = "111"
 Output: 11
 Explanation:
 The unique prime number formed from the substrings of "111" is 11.
 Since there is only one prime number, the sum is 11.
 Constraints:
 1 <= s.length <= 10
 s consists of only digits.
*/

class Solution {
    public long sumOfLargestPrimes(String s) {
        // Convert the string to an integer without leading zeros
        int num = Integer.parseInt(s.replaceAll("^0+(?!$)", ""));
        
        // Initialize variables
        long sum = 0;
        int count = 0;
        
        // Helper function to check if a number is prime
        boolean isPrime(int n) {
            if (n <= 1) return false;
            for (int i = 2; i * i <= n; i++) {
                if (n % i == 0) return false;
            }
            return true;
        }
        
        // Helper function to find the largest prime number in a substring
        int findLargestPrime(String substring) {
            int num = Integer.parseInt(substring.replaceAll("^0+(?!$)", ""));
            for (int i = num; i >= 2; i--) {
                if (isPrime(i)) return i;
            }
            return -1;
        }
        // Iterate through all substrings of the given string   
        for (int i = 0; i < s.length(); i++) {
            for (int j = i + 1; j <= s.length(); j++) {
                String substring = s.substring(i, j);
                int largestPrime = findLargestPrime(substring);
                
                // Check if the largest prime number is unique and not already counted
                if (largestPrime > 0 &&!isPrime(largestPrime) && count < 3) {
                    sum += largestPrime;
                    count++;
                }
            }
        }
        
        // Return the sum of the three largest unique prime numbers
        return sum;
        
        
    }
}