#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>

#include "solution.hpp"

using namespace std;

typedef long long ll;

int n;
double alpha;
ll capacity;
vector<ll> items;

int main(int argc, char** argv) {
    if (argc < 3) {
        cout << "Usage: " << argv[0] << " <Instance> <Alpha>" << endl;
        return -1;
    }
    alpha = atof(argv[2]);
    ifstream fin(argv[1]);
    fin >> n >> capacity;
    cout << n << " " << capacity << endl;
    for (int i = 0; i < n; i++) {
        ll x;
        fin >> x;
        items.push_back(x);
    }
    ll best_solution = 0x7fffffff;
    for (int i = 0; i < 500; i++) {
        Solution solution(n, alpha);
        solution.constructionPhase();
        if (!solution.check()) {
            cout << "Error" << endl;
        }
        best_solution = min(best_solution, (ll)solution.getScore());
    }
    cout << "Best Solution size = " << best_solution << endl;
    return 0;
}