/**https://leetcode.com/problems/pass-the-pillow/ */
//There are n people standing in a line labeled from 1 to n. The first person in the line is holding a pillow initially. Every second, the person holding the pillow passes it to the next person standing in the line. Once the pillow reaches the end of the line, the direction changes, and people continue passing the pillow in the opposite direction.
//	For example, once the pillow reaches the nth person they pass it to the n - 1th person, then to the n - 2th person and so on.
//Given the two positive integers n and time, return the index of the person holding the pillow after time seconds.
// 
//Example 1:
//Input: n = 4, time = 5
//Output: 2
//Explanation: People pass the pillow in the following way: 1 -> 2 -> 3 -> 4 -> 3 -> 2.
//After five seconds, the 2nd person is holding the pillow.
//Example 2:
//Input: n = 3, time = 2
//Output: 3
//Explanation: People pass the pillow in the following way: 1 -> 2 -> 3.
//After two seconds, the 3rd person is holding the pillow.
// 
//Constraints:
//	2 <= n <= 1000
//	1 <= time <= 1000
// 
//Note: This question is the same as  3178: Find the Child Who Has the Ball After K Seconds.
class Solution {
    public int passThePillow(int n, int time) {
        int[] arr = new int[n];
        int i = 0;
        int j = 0;
        int k = 0;
        int l = 0;
        int m = 0;
        int p = 0;
        int q = 0;
        int r = 0;
        int s = 0;
        int t = 0;
        int u = 0;
        int v = 0;
        int w = 0;
        int x = 0;
        int y = 0;
        int z = 0;
        int a = 0;
        int b = 0;
        int c = 0;
        int d =0;
        while(time > 0){
            time--;
            i++;
            j++;
            k++;
            l++;
            m++;
            p++;
            q++;
            r++;
            s++;
            t++;
            u++;
            v++;
            w++;
            x++;
            y++;
            z++;
            a++;
            b++;
            c++;
            d++;
        }
        return 0;
    }
}