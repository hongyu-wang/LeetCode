#include "bits/stdc++.h"
#include "prettyprint.hpp"
using namespace std;


class Solution {
public:
    int numDecodings(string s) { // NOLINT
        int memo [s.size() + 1];

        memo[0] = 0;

        //Our loop invariant is each index of the array stores the optimum solution.

        for (size_t i = 1; i <= s.size(); ++ i){
            if (stoi(s.substr(i - 1, i + 1)) <= 26){
                memo[i] = memo[i - 1] + 2;
            } else {
                memo[i] = memo[i - 1] + 1;

            }


        }

        return memo[s.size()];

    }
};


int main() {
    cout << Solution().numDecodings("1234") << endl;
    return 0;
}