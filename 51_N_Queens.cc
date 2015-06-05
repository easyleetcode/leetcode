#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        int sol[n];
        memset(sol, 0, n*sizeof(int));
        vector<vector<string>> ret;
        helper(n, 0, sol, ret);
        return ret;
    }

    void helper(int n, int index, int sol[], vector<vector<string>> ret) {
        if(index == n) {
            vector<string> sol_str;
            for(int i = 0; i < n; i++) {
                string str(n, '.');
                str[sol[i]] = 'G';
                sol_str.push_back(str);
            }
            ret.push_back(sol_str);
            return;
        }
        for(int i = 0; i < n; i++) {
            sol[index] = i;
            if(isValid(sol, index)) {
                helper(n, index+1, sol, ret);
            }
        }
    }

    bool isValid(int sol[], int index) {
        for(int i = 0; i < index; i++) {
            if(abs(i - index) == abs(sol[i] - sol[index]) || sol[i] == sol[index])
                return false;
        }
        return true;
    }
};

int main()
{
    Solution s;
    vector<vector<string>> ret;
    ret = s.solveNQueens(8);
    for(int i = 0; i < ret.size(); i++) {
        for(int j = 0; j < ret[i].size(); j++) {
            cout << ret[i][j];
        }
        cout << endl;
    }
    return 0;
}