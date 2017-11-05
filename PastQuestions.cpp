#include <cstddef>
#include <cstring>
#include <vector>

using namespace std;
//
// Created by Hongyu Wang on 11/2/2017.
//

int maxProfit(vector<int>& prices) {

    int minPrice = prices[0];

    int maxProfit = 0;

    for (int i : prices){
        if (i < minPrice){
            minPrice = i;
        }
        maxProfit = max(maxProfit, i - minPrice);
    }
    return maxProfit;
}


//max length of a sub array
int findLength(vector<int>& A, vector<int>& B) {


    size_t a_len = A.size();
    size_t b_len = B.size();

    int memo [a_len + 1][b_len + 1];

    memset(memo, 0, sizeof(int)*(a_len + 1) * (b_len + 1));

    int max_val = 0;
    for (int i = a_len - 1; i >= 0; i --){
        for (int j = b_len - 1; j >= 0; j --){
            if (A[i] == B[j]){

                memo[i][j] = memo[i+1][j+1] + 1;
                max_val = max(max_val, memo[i][j]);
            }
        }
    }

    return max_val;
}