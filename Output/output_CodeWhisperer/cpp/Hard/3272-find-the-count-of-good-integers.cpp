/*
 You are given two positive integers n and k.
 An integer x is called k-palindromic if:
 x is a palindrome.
 x is divisible by k.
 An integer is called good if its digits can be rearranged to form a k-palindromic integer. For example, for k = 2, 2020 can be rearranged to form the k-palindromic integer 2002, whereas 1010 cannot be rearranged to form a k-palindromic integer.
 Return the count of good integers containing n digits.
 Note that any integer must not have leading zeros, neither before nor after rearrangement. For example, 1010 cannot be rearranged to form 101.
 Example 1:
 Input: n = 3, k = 5
 Output: 27
 Explanation:
 Some of the good integers are:
 551 because it can be rearranged to form 515.
 525 because it is already k-palindromic.
 Example 2:
 Input: n = 1, k = 4
 Output: 2
 Explanation:
 The two good integers are 4 and 8.
 Example 3:
 Input: n = 5, k = 6
 Output: 2468
 Constraints:
 1 <= n <= 10
 1 <= k <= 9
*/
class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        // For single digit, just count numbers divisible by k
        if (n == 1) {
            int count = 0;
            for (int i = 1; i <= 9; i++) {
                if (i % k == 0) count++;
            }
            return count;
        }
        
        // For multiple digits:
        // 1. Generate all possible digit combinations
        // 2. Check if they can form k-palindrome
        vector<int> digits;
        long long count = 0;
        
        // Start from 1 to avoid leading zeros
        for (int i = 1; i <= 9; i++) {
            digits.clear();
            digits.push_back(i);
            backtrack(digits, n-1, k, count);
        }
        
        return count;
    }
    
private:
    void backtrack(vector<int>& digits, int remaining, int k, long long& count) {
        if (remaining == 0) {
            if (canFormKPalindrome(digits, k)) {
                count++;
            }
            return;
        }
        
        for (int i = 0; i <= 9; i++) {
            digits.push_back(i);
            backtrack(digits, remaining-1, k, count);
            digits.pop_back();
        }
    }
    
    bool canFormKPalindrome(vector<int>& digits, int k) {
        // Count frequency of each digit
        vector<int> freq(10, 0);
        long long sum = 0;
        for (int d : digits) {
            freq[d]++;
            sum = sum * 10 + d;
        }
        
        // Check if we can form a palindrome
        int oddCount = 0;
        for (int f : freq) {
            if (f % 2 == 1) oddCount++;
        }
        
        // For odd length, only one digit can have odd frequency
        // For even length, all digits must have even frequency
        if (digits.size() % 2 == 0 && oddCount > 0) return false;
        if (digits.size() % 2 == 1 && oddCount > 1) return false;
        
        // Try to construct palindrome and check divisibility
        vector<int> palindrome;
        vector<int> freqCopy = freq;
        
        // Add first half
        for (int i = 0; i < digits.size()/2; i++) {
            bool found = false;
            for (int d = 9; d >= 0; d--) {
                if (freqCopy[d] >= 2) {
                    palindrome.push_back(d);
                    freqCopy[d] -= 2;
                    found = true;
                    break;
                }
            }
            if (!found) return false;
        }
        
        // Add middle digit for odd length
        if (digits.size() % 2 == 1) {
            bool found = false;
            for (int d = 9; d >= 0; d--) {
                if (freqCopy[d] >= 1) {
                    palindrome.push_back(d);
                    freqCopy[d]--;
                    found = true;
                    break;
                }
            }
            if (!found) return false;
        }
        
        // Add second half
        for (int i = palindrome.size() - 1 - (digits.size() % 2); i >= 0; i--) {
            palindrome.push_back(palindrome[i]);
        }
        
        // Check if palindrome is divisible by k
        long long num = 0;
        for (int d : palindrome) {
            num = num * 10 + d;
        }
        
        return num % k == 0;
    }
};            