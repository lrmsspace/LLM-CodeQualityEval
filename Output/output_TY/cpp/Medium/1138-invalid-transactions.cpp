/**https://leetcode.com/problems/invalid-transactions/ */
//A transaction is possibly invalid if:
//	the amount exceeds $1000, or;
//	if it occurs within (and including) 60 minutes of another transaction with the same name in a different city.
//You are given an array of strings transaction where transactions[i] consists of comma-separated values representing the name, time (in minutes), amount, and city of the transaction.
//Return a list of transactions that are possibly invalid. You may return the answer in any order.
// 
//Example 1:
//Input: transactions = ["alice,20,800,mtv","alice,50,100,beijing"]
//Output: ["alice,20,800,mtv","alice,50,100,beijing"]
//Explanation: The first transaction is invalid because the second transaction occurs within a difference of 60 minutes, have the same name and is in a different city. Similarly the second one is invalid too.
//Example 2:
//Input: transactions = ["alice,20,800,mtv","alice,50,1200,mtv"]
//Output: ["alice,50,1200,mtv"]
//Example 3:
//Input: transactions = ["alice,20,800,mtv","bob,50,1200,mtv"]
//Output: ["bob,50,1200,mtv"]
// 
//Constraints:
//	transactions.length <= 1000
//	Each transactions[i] takes the form "{name},{time},{amount},{city}"
//	Each {name} and {city} consist of lowercase English letters, and have lengths between 1 and 10.
//	Each {time} consist of digits, and represent an integer between 0 and 1000.
//	Each {amount} consist of digits, and represent an integer between 0 and 2000.
class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        unordered_map<string, vector<pair<int, int>>> m;
        vector<string> ans;
        for(auto t : transactions){
            stringstream ss(t);
            string name, city;
            int time, amount;
            ss >> name >> time >> amount >> city;
            if(amount > 1000){
                ans.push_back(t);
            }
            m[name].push_back({time, amount});
        }
        for(auto& [name, times] : m){
            for(int i = 0; i < times.size(); i++){
                for(int j = i + 1; j < times.size(); j++){
                    if(abs(times[i].first - times[j].first) <= 60){
                        if(times[i].second > 1000){
                            ans.push_back(transactions[i]);
                        }
                        if(times[j].second > 1000){
                            ans.push_back(transactions[j]);
                        }
                    }
                }
            }
        }
        return ans;
    }
};