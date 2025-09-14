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
    public List<String> invalidTransactions(String[] transactions) {
        Map<String, List<String[]>> map = new HashMap<>();
        for (String transaction : transactions) {
            String[] info = transaction.split(",");
            map.computeIfAbsent(info[0], k -> new ArrayList<>()).add(info);
        }
        List<String> result = new ArrayList<>();
        for (List<String[]> list : map.values()) {
            for (int i = 0; i < list.size(); i++) {
                for (int j = i + 1; j < list.size(); j++) {
                    if (Integer.parseInt(list[i][1]) - Integer.parseInt(list[j][1]) <= 60
                            && !list[i][3].equals(list[j][3])) {
                        result.add(list[i][0] + "," + list[i][1] + "," + list[i][2] + "," + list[i][3]);
                        result.add(list[j][0] + "," + list[j][1] + "," + list[j][2] + "," + list[j][3]);
                    }
                }
            }
        }
        return result;
    }
}