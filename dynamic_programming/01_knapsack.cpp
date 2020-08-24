#include <bits/stdc++.h>

using namespace std;

int knapsack(int weights[], int values[], int solution[], int qnt, int max_weight) {

    int dp[qnt + 1][max_weight + 1];

    for (int i = 0; i <= qnt; i++) {
        for (int j = 0; j <= max_weight; j++) {

            if (i == 0 or j == 0) {
                dp[i][j] = 0;
                continue;
            }

            int without = dp[i - 1][j];
            int with = 0;

            if (weights[i] <= j) {
                with = values[i] + dp[i - 1][j - weights[i]];
            }

            dp[i][j] = max(without, with);
        }
    }

    int weight_left = max_weight;

    for (int i = qnt; i > 0; i--) {
        solution[i] = 0;

        if (dp[i][weight_left] != dp[i - 1][weight_left]) {
            solution[i] = 1;
            weight_left -= weights[i];
        }
    }

    // debug
    // printf("   ");
    // for (int j = 0; j <= max_weight; j++)
    //     printf("%5d", j);
    // cout << endl;

    // printf("---");
    // for (int j = 0; j <= max_weight; j++)
    //     printf("-----");
    // cout << endl;


    // for (int i = 0; i <= qnt; i++) {
    //     printf("%d |", i);
    //     for (int j = 0; j <= max_weight; j++) {
    //         printf("%5d", dp[i][j]);
    //     }
    //     cout << endl;
    // }

    return dp[qnt][max_weight];
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int max_weigth = 5;
    int qnt = 4;

    int weights[] = { NULL, 5, 3, 4, 2 };
    int values[] = { NULL, 60, 50, 70, 30 };
    int solution[qnt + 1];

    int best = knapsack(weights, values, solution, qnt, max_weigth);

    cout << best << endl;

    for (int i = 1; i <= qnt; i++) 
        if (solution[i]) cout << i << " ";    
    cout << endl;

    return 0;
}
