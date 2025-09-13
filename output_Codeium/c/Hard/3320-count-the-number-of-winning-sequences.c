/*
 Alice and Bob are playing a fantasy battle game consisting of n rounds where they summon one of three magical creatures each round: a Fire Dragon, a Water Serpent, or an Earth Golem. In each round, players simultaneously summon their creature and are awarded points as follows:
 If one player summons a Fire Dragon and the other summons an Earth Golem, the player who summoned the Fire Dragon is awarded a point.
 If one player summons a Water Serpent and the other summons a Fire Dragon, the player who summoned the Water Serpent is awarded a point.
 If one player summons an Earth Golem and the other summons a Water Serpent, the player who summoned the Earth Golem is awarded a point.
 If both players summon the same creature, no player is awarded a point.
 You are given a string s consisting of n characters 'F', 'W', and 'E', representing the sequence of creatures Alice will summon in each round:
 If s[i] == 'F', Alice summons a Fire Dragon.
 If s[i] == 'W', Alice summons a Water Serpent.
 If s[i] == 'E', Alice summons an Earth Golem.
 Bob’s sequence of moves is unknown, but it is guaranteed that Bob will never summon the same creature in two consecutive rounds. Bob beats Alice if the total number of points awarded to Bob after n rounds is strictly greater than the points awarded to Alice.
 Return the number of distinct sequences Bob can use to beat Alice.
 Since the answer may be very large, return it modulo 109 + 7.
 Example 1:
 Input: s = "FFF"
 Output: 3
 Explanation:
 Bob can beat Alice by making one of the following sequences of moves: "WFW", "FWF", or "WEW". Note that other winning sequences like "WWE" or "EWW" are invalid since Bob cannot make the same move twice in a row.
 Example 2:
 Input: s = "FWEFW"
 Output: 18
 Explanation:
 Bob can beat Alice by making one of the following sequences of moves: "FWFWF", "FWFWE", "FWEFE", "FWEWE", "FEFWF", "FEFWE", "FEFEW", "FEWFE", "WFEFE", "WFEWE", "WEFWF", "WEFWE", "WEFEF", "WEFEW", "WEWFW", "WEWFE", "EWFWE", or "EWEWE".
 Constraints:
 1 <= s.length <= 1000
 s[i] is one of 'F', 'W', or 'E'.
*/

#define MOD 1000000007

int countWinningSequences(char* s) {
    int n = strlen(s);
    int dp[n + 1][3][3]; // dp[i][j][k] represents the number of ways to arrange the sequence up to i with last two moves j and k
    memset(dp, 0, sizeof(dp));

    // Initialize for the first character in Alice's sequence
    for (int j = 0; j < 3; j++) {
        for (int k = 0; k < 3; k++) {
            if (j != k) {
                dp[1][j][k] = 1;
            }
        }
    }

    // Fill dp table
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (j != k) {
                    for (int l = 0; l < 3; l++) {
                        if (l != j) {
                            dp[i][j][k] = (dp[i][j][k] + dp[i-1][l][j]) % MOD;
                        }
                    }
                }
            }
        }
    }

    // Calculate the number of sequences that beat Alice
    int result = 0;
    for (int j = 0; j < 3; j++) {
        for (int k = 0; k < 3; k++) {
            if (j != k) {
                // Calculate Bob's score and Alice's score
                int bobScore = 0, aliceScore = 0;
                for (int i = 0; i < n; i++) {
                    if ((s[i] == 'F' && k == 1) || (s[i] == 'W' && k == 2) || (s[i] == 'E' && k == 0)) {
                        bobScore++;
                    } else if ((s[i] == 'F' && k == 2) || (s[i] == 'W' && k == 0) || (s[i] == 'E' && k == 1)) {
                        aliceScore++;
                    }
                }
                if (bobScore > aliceScore) {
                    result = (result + dp[n][j][k]) % MOD;
                }
            }
        }
    }


}