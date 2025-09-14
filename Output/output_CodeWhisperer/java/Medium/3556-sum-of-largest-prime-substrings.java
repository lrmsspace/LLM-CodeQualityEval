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
        long sum = 0;
        int n = s.length();
        boolean[] isPrime = new boolean[n];
        Arrays.fill(isPrime, true);
        isPrime[0] = false;
        isPrime[1] = false;
        for (int i = 2; i < n; i++) {
            if (isPrime[i]) {
                for (int j = i * 2; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        Set<Integer> set = new HashSet<>();
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                String sub = s.substring(i, j + 1);
                int num = Integer.parseInt(sub);
                if (isPrime[num]) {
                    set.add(num);
                }
            }
        }
        List<Integer> list = new ArrayList<>(set);
        Collections.sort(list);
        if (list.size() >= 3) {
            sum = list.get(list.size() - 1) + list.get(list.size() - 2) + list.get(list.size() - 3);
        } else {
            for (int num : list) {
                sum += num;
            }
        }
        return sum;
            
    }
}