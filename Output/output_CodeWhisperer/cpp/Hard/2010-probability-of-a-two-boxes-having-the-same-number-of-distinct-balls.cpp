/**https://leetcode.com/problems/probability-of-a-two-boxes-having-the-same-number-of-distinct-balls/ */
//Given 2n balls of k distinct colors. You will be given an integer array balls of size k where balls[i] is the number of balls of color i.
//All the balls will be shuffled uniformly at random, then we will distribute the first n balls to the first box and the remaining n balls to the other box (Please read the explanation of the second example carefully).
//Please note that the two boxes are considered different. For example, if we have two balls of colors a and b, and two boxes [] and (), then the distribution [a] (b) is considered different than the distribution [b] (a) (Please read the explanation of the first example carefully).
//Return the probability that the two boxes have the same number of distinct balls. Answers within 10-5 of the actual value will be accepted as correct.
// 
//Example 1:
//Input: balls = [1,1]
//Output: 1.00000
//Explanation: Only 2 ways to divide the balls equally:
//- A ball of color 1 to box 1 and a ball of color 2 to box 2
//- A ball of color 2 to box 1 and a ball of color 1 to box 2
//In both ways, the number of distinct colors in each box is equal. The probability is 2/2 = 1
//Example 2:
//Input: balls = [2,1,1]
//Output: 0.66667
//Explanation: We have the set of balls [1, 1, 2, 3]
//This set of balls will be shuffled randomly and we may have one of the 12 distinct shuffles with equal probability (i.e. 1/12):
//[1,1 / 2,3], [1,1 / 3,2], [1,2 / 1,3], [1,2 / 3,1], [1,3 / 1,2], [1,3 / 2,1], [2,1 / 1,3], [2,1 / 3,1], [2,3 / 1,1], [3,1 / 1,2], [3,1 / 2,1], [3,2 / 1,1]
//After that, we add the first two balls to the first box and the second two balls to the second box.
//We can see that 8 of these 12 possible random distributions have the same number of distinct colors of balls in each box.
//Probability is 8/12 = 0.66667
//Example 3:
//Input: balls = [1,2,1,2]
//Output: 0.60000
//Explanation: The set of balls is [1, 2, 2, 3, 4, 4]. It is hard to display all the 180 possible random shuffles of this set but it is easy to check that 108 of them will have the same number of distinct colors in each box.
//Probability = 108 / 180 = 0.6
// 
//Constraints:
//	1 <= balls.length <= 8
//	1 <= balls[i] <= 6
//	sum(balls) is even. 
class Solution {
    public:
        double getProbability(vector<int>& balls) {
            int k = balls.size();
            int totalBalls = accumulate(balls.begin(), balls.end(), 0);
            int halfBalls = totalBalls / 2;
            
            // Calculate total ways to distribute balls
            vector<double> fact(totalBalls + 1, 1.0);
            for (int i = 1; i <= totalBalls; i++) {
                fact[i] = fact[i - 1] * i;
            }
            
            // Calculate total number of ways to distribute balls
            double totalWays = fact[totalBalls];
            for (int b : balls) {
                totalWays /= fact[b];
            }
            totalWays = totalWays / pow(2, totalBalls); // Divide by 2^n for each ball's position
            
            // Calculate favorable outcomes
            double favorableWays = solve(balls, 0, 0, 0, 0, 0, halfBalls, fact);
            
            return favorableWays / totalWays;
        }
        
    private:
        unordered_map<string, double> memo;
        
        double solve(vector<int>& balls, int idx, int b1, int b2, int d1, int d2, int halfBalls, 
                    vector<double>& fact) {
            // Base case: all colors distributed
            if (idx == balls.size()) {
                if (b1 == b2 && d1 == d2) {
                    // Calculate permutations for this distribution
                    double ways = fact[b1];
                    for (int i = 0; i < idx; i++) {
                        if (balls[i] > 0) ways /= fact[balls[i]];
                    }
                    return ways * ways; // Ways for both boxes
                }
                return 0;
            }
            
            // Create a unique key for memoization
            string key = to_string(idx) + "," + to_string(b1) + "," + to_string(b2) + "," + 
                         to_string(d1) + "," + to_string(d2);
            if (memo.find(key) != memo.end()) {
                return memo[key];
            }
            
            double ways = 0;
            
            // Try different distributions for current color
            for (int i = 0; i <= balls[idx]; i++) {
                int j = balls[idx] - i;
                
                // Skip invalid distributions
                if (b1 + i > halfBalls || b2 + j > halfBalls) continue;
                
                // Calculate new distinct color counts
                int nd1 = d1 + (i > 0 ? 1 : 0);
                int nd2 = d2 + (j > 0 ? 1 : 0);
                
                // Temporarily modify balls array
                int original = balls[idx];
                balls[idx] = i;
                double waysLeft = solve(balls, idx + 1, b1 + i, b2 + j, nd1, nd2, halfBalls, fact);
                balls[idx] = original;
                
                // Calculate combinations for this distribution
                double c = fact[original] / (fact[i] * fact[j]);
                ways += c * waysLeft;
            }
            
            memo[key] = ways;
            return ways;
        }
    };
    