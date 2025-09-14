/*
 You are given a string initialCurrency, and you start with 1.0 of initialCurrency.
 You are also given four arrays with currency pairs (strings) and rates (real numbers):
 pairs1[i] = [startCurrencyi, targetCurrencyi] denotes that you can convert from startCurrencyi to targetCurrencyi at a rate of rates1[i] on day 1.
 pairs2[i] = [startCurrencyi, targetCurrencyi] denotes that you can convert from startCurrencyi to targetCurrencyi at a rate of rates2[i] on day 2.
 Also, each targetCurrency can be converted back to its corresponding startCurrency at a rate of 1 / rate.
 You can perform any number of conversions, including zero, using rates1 on day 1, followed by any number of additional conversions, including zero, using rates2 on day 2.
 Return the maximum amount of initialCurrency you can have after performing any number of conversions on both days in order.
 Note: Conversion rates are valid, and there will be no contradictions in the rates for either day. The rates for the days are independent of each other.
 Example 1:
 Input: initialCurrency = "EUR", pairs1 = [["EUR","USD"],["USD","JPY"]], rates1 = [2.0,3.0], pairs2 = [["JPY","USD"],["USD","CHF"],["CHF","EUR"]], rates2 = [4.0,5.0,6.0]
 Output: 720.00000
 Explanation:
 To get the maximum amount of EUR, starting with 1.0 EUR:
 On Day 1:
 Convert EUR to USD to get 2.0 USD.
 Convert USD to JPY to get 6.0 JPY.
 On Day 2:
 Convert JPY to USD to get 24.0 USD.
 Convert USD to CHF to get 120.0 CHF.
 Finally, convert CHF to EUR to get 720.0 EUR.
 Example 2:
 Input: initialCurrency = "NGN", pairs1 = [["NGN","EUR"]], rates1 = [9.0], pairs2 = [["NGN","EUR"]], rates2 = [6.0]
 Output: 1.50000
 Explanation:
 Converting NGN to EUR on day 1 and EUR to NGN using the inverse rate on day 2 gives the maximum amount.
 Example 3:
 Input: initialCurrency = "USD", pairs1 = [["USD","EUR"]], rates1 = [1.0], pairs2 = [["EUR","JPY"]], rates2 = [10.0]
 Output: 1.00000
 Explanation:
 In this example, there is no need to make any conversions on either day.
 Constraints:
 1 <= initialCurrency.length <= 3
 initialCurrency consists only of uppercase English letters.
 1 <= n == pairs1.length <= 10
 1 <= m == pairs2.length <= 10
 pairs1[i] == [startCurrencyi, targetCurrencyi]
 pairs2[i] == [startCurrencyi, targetCurrencyi]
 1 <= startCurrencyi.length, targetCurrencyi.length <= 3
 startCurrencyi and targetCurrencyi consist only of uppercase English letters.
 rates1.length == n
 rates2.length == m
 1.0 <= rates1[i], rates2[i] <= 10.0
 The input is generated such that there are no contradictions or cycles in the conversion graphs for either day.
 The input is generated such that the output is at most 5 * 1010.
*/

/**
 * @param {string} initialCurrency
 * @param {string[][]} pairs1
 * @param {number[]} rates1
 * @param {string[][]} pairs2
 * @param {number[]} rates2
 * @return {number}
 */
var maxAmount = function(initialCurrency, pairs1, rates1, pairs2, rates2) {
    const graph1 = new Map();
    const graph2 = new Map();
    for (let i = 0; i < pairs1.length; i++) {
        if (!graph1.has(pairs1[i][0])) {
            graph1.set(pairs1[i][0], new Map());
        }
        graph1.get(pairs1[i][0]).set(pairs1[i][1], rates1[i]);
        if (!graph1.has(pairs1[i][1])) {
            graph1.set(pairs1[i][1], new Map());
        }
        graph1.get(pairs1[i][1]).set(pairs1[i][0], 1 / rates1[i]);
    }
    for (let i = 0; i < pairs2.length; i++) {
        if (!graph2.has(pairs2[i][0])) {
            graph2.set(pairs2[i][0], new Map());
        }
        graph2.get(pairs2[i][0]).set(pairs2[i][1], rates2[i]);
        if (!graph2.has(pairs2[i][1])) {
            graph2.set(pairs2[i][1], new Map());
        }
        graph2.get(pairs2[i][1]).set(pairs2[i][0], 1 / rates2[i]);
    }
    const dfs = (currency, graph, visited) => {
        if (!graph.has(currency)) {
            return 1;
        }
        if (visited.has(currency)) {
            return 1;
        }
        visited.add(currency);
        let max = 0;
        for (let [nextCurrency, rate] of graph.get(currency)) {
            max = Math.max(max, rate * dfs(nextCurrency, graph, visited));
        }
        visited.delete(currency);
        return 1 + max;
    };
    return Math.max(dfs(initialCurrency, graph1, new Set()), dfs(initialCurrency, graph2, new Set()));    
};