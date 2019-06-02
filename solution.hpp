#ifndef _SOLUTION_H_
#define _SOLUTION_H_

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

extern ll capacity;
extern vector<ll> items;

class Solution {
    private:
        double alpha;
        int n;
        vector<int> aloc;
        vector<int> bins;

    public:
        Solution(int sz, double _alpha);

        void constructionPhase(bool pop);

        bool localSearch();

        bool check();

        int getScore();
};

#endif