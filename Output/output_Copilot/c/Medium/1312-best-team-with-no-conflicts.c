/**https://leetcode.com/problems/best-team-with-no-conflicts/ */
//You are the manager of a basketball team. For the upcoming tournament, you want to choose the team with the highest overall score. The score of the team is the sum of scores of all the players in the team.
//However, the basketball team is not allowed to have conflicts. A conflict exists if a younger player has a strictly higher score than an older player. A conflict does not occur between players of the same age.
//Given two lists, scores and ages, where each scores[i] and ages[i] represents the score and age of the ith player, respectively, return the highest overall score of all possible basketball teams.
// 
//Example 1:
//Input: scores = [1,3,5,10,15], ages = [1,2,3,4,5]
//Output: 34
//Explanation: You can choose all the players.
//Example 2:
//Input: scores = [4,5,6,5], ages = [2,1,2,1]
//Output: 16
//Explanation: It is best to choose the last 3 players. Notice that you are allowed to choose multiple people of the same age.
//Example 3:
//Input: scores = [1,2,3,5], ages = [8,9,10,1]
//Output: 6
//Explanation: It is best to choose the first 3 players. 
// 
//Constraints:
//	1 <= scores.length, ages.length <= 1000
//	scores.length == ages.length
//	1 <= scores[i] <= 106
//	1 <= ages[i] <= 1000
int bestTeamScore(int* scores, int scoresSize, int* ages, int agesSize) {
    // Combine ages and scores into a single array of pairs
    typedef struct {
        int age;
        int score;
    } Player;

    Player players[scoresSize];
    for (int i = 0; i < scoresSize; i++) {
        players[i].age = ages[i];
        players[i].score = scores[i];
    }

    // Sort players by age, and by score if ages are the same
    int compare(const void* a, const void* b) {
        Player* p1 = (Player*)a;
        Player* p2 = (Player*)b;
        if (p1->age == p2->age) {
            return p1->score - p2->score;
        }
        return p1->age - p2->age;
    }
    qsort(players, scoresSize, sizeof(Player), compare);

    // Use dynamic programming to find the best team score
    int dp[scoresSize];
    int maxScore = 0;

    for (int i = 0; i < scoresSize; i++) {
        dp[i] = players[i].score;
        for (int j = 0; j < i; j++) {
            if (players[j].score <= players[i].score) {
                dp[i] = dp[i] > dp[j] + players[i].score ? dp[i] : dp[j] + players[i].score;
            }
        }
        maxScore = maxScore > dp[i] ? maxScore : dp[i];
    }

    return maxScore;
}   