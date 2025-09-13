/*
 You are given a string s. s[i] is either a lowercase English letter or '?'.
 For a string t having length m containing only lowercase English letters, we define the function cost(i) for an index i as the number of characters equal to t[i] that appeared before it, i.e. in the range [0, i - 1].
 The value of t is the sum of cost(i) for all indices i.
 For example, for the string t = "aab":
 cost(0) = 0
 cost(1) = 1
 cost(2) = 0
 Hence, the value of "aab" is 0 + 1 + 0 = 1.
 Your task is to replace all occurrences of '?' in s with any lowercase English letter so that the value of s is minimized.
 Return a string denoting the modified string with replaced occurrences of '?'. If there are multiple strings resulting in the minimum value, return the lexicographically smallest one.
 Example 1:
 Input:   s = "???" 
 Output:   "abc" 
 Explanation:  In this example, we can replace the occurrences of '?' to make s equal to "abc".
 For "abc", cost(0) = 0, cost(1) = 0, and cost(2) = 0.
 The value of "abc" is 0.
 Some other modifications of s that have a value of 0 are "cba", "abz", and, "hey".
 Among all of them, we choose the lexicographically smallest.
 Example 2:
 Input:  s = "a?a?"
 Output:  "abac"
 Explanation:  In this example, the occurrences of '?' can be replaced to make s equal to "abac".
 For "abac", cost(0) = 0, cost(1) = 0, cost(2) = 1, and cost(3) = 0.
 The value of "abac" is 1.
 Constraints:
 1 <= s.length <= 105
 s[i] is either a lowercase English letter or '?'.
*/

char* minimizeStringValue(char* s) {
    int n = strlen(s);
    int cost[n];
    cost[0] = s[0] == '?'? 1 : 0;
    for (int i = 1; i < n; ++i) {
        cost[i] = s[i] == '?'? cost[i - 1] + 1 : cost[i - 1];
    }
    
    int minCost = INT_MAX;
    int minIndex = -1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '?') {
            int newCost = cost[i] + (i > 0? cost[i - 1] : 0);
            if (newCost < minCost) {
                minCost = newCost;
                minIndex = i;
            }
        }
        else {
            break;
        }
        s[minIndex] = 'a';
        s[i] = 'b';
        s[i + 1] = 'c';
        if (i + 2 < n) {
            s[i + 2] = '?';
        }   
        minCost = INT_MAX;
        for (int j = minIndex + 1; j < n; ++j) {
            if (s[j] == '?') {
                int newCost = cost[j] + (j > minIndex + 1? cost[j - 1] : 0);
                if (newCost < minCost) {
                    minCost = newCost;
                    minIndex = j;
                }
            }
            else {
                break;
            }
        }
        s[minIndex] = 'c';  
        s[i] = 'b'; 
        s[i + 1] = 'a';
        if (i + 2 < n) {
            s[i + 2] = '?';
        }

        minCost = INT_MAX;
        for (int j = minIndex + 1; j < n; ++j) {
            if (s[j] == '?') {
                int newCost = cost[j] + (j > minIndex + 1? cost[j - 1] : 0);
                if (newCost < minCost) {
                    minCost = newCost;
                    minIndex = j;
                }
            }
            else {
                break;
            }
        }
        s[minIndex] = 'a';
        s[i] = 'c';
        s[i + 1] = 'b';
        if (i + 2 < n) {
            s[i + 2] = '?';
        }
    }   
    return s;
    
}