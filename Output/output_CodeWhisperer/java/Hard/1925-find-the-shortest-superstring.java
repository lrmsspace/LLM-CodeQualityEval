/**https://leetcode.com/problems/find-the-shortest-superstring/ */
//Given an array of strings words, return the smallest string that contains each string in words as a substring. If there are multiple valid strings of the smallest length, return any of them.
//You may assume that no string in words is a substring of another string in words.
// 
//Example 1:
//Input: words = ["alex","loves","leetcode"]
//Output: "alexlovesleetcode"
//Explanation: All permutations of "alex","loves","leetcode" would also be accepted.
//Example 2:
//Input: words = ["catg","ctaagt","gcta","ttca","atgcatc"]
//Output: "gctaagttcatgcatc"
// 
//Constraints:
//	1 <= words.length <= 12
//	1 <= words[i].length <= 20
//	words[i] consists of lowercase English letters.
//	All the strings of words are unique.
import java.util.Stack;
import java.util.Arrays;
class Solution {
    public String shortestSuperstring(String[] words) 
    {
        int n = words.length;
        int[][] cost = new int[n][n];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cost[i][j] = calcCost(words[i], words[j]);
            }
        }
        int[][] dp = new int[1 << n][n];
        int[][] path = new int[1 << n][n];
        int last = -1, min = Integer.MAX_VALUE;
        for (int i = 1; i < (1 << n); i++)
        {
            Arrays.fill(dp[i], Integer.MAX_VALUE);
            for (int j = 0; j < n; j++)
            {
                if ((i & (1 << j)) > 0)
                {
                    int prev = i - (1 << j);
                    if (prev == 0)
                    {
                        dp[i][j] = words[j].length();
                    }
                    else
                    {
                        for (int k = 0; k < n; k++)
                        {
                            if (dp[prev][k] < Integer.MAX_VALUE && dp[prev][k] + cost[k][j] < dp[i][j])
                            {
                                dp[i][j] = dp[prev][k] + cost[k][j];
                                path[i][j] = k;
                            }
                        }
                    }
                }
                if (i == (1 << n) - 1 && dp[i][j] < min)
                {
                    min = dp[i][j];
                    last = j;
                }
            }
        }
        StringBuilder sb = new StringBuilder();
        int cur = (1 << n) - 1;
        Stack<Integer> stack = new Stack<>();
        while (cur > 0)
        {
            stack.push(last);
            int temp = cur;
            cur -= (1 << last);
            last = path[temp][last];
        }
        int i = stack.pop();
        sb.append(words[i]);
        while (!stack.isEmpty())
        {
            int j = stack.pop();
            sb.append(words[j].substring(words[j].length() - cost[i][j]));
            i = j;
        }
        return sb.toString();
    }
}