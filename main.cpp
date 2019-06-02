#include <iostream>
#include <algorithm>
#include <fstream>
#include <string.h>
#include <vector>
#include <chrono>

#include "solution.hpp"

using namespace std;

typedef long long ll;

int n;
double alpha;
ll capacity;
vector<ll> items;
bool pop = false; // Proximate Optimality Principle

int main(int argc, char** argv) {
    if (argc < 4) {
        cout << "Usage: " << argv[0] << " <Instance> <Alpha> <POP>" << endl;
        return -1;
    }
    alpha = atof(argv[2]);
    ifstream fin(argv[1]);
    pop = strcmp(argv[3], "1") == 0;
    fin >> n >> capacity;
    for (int i = 0; i < n; i++) {
        ll x;
        fin >> x;
        items.push_back(x);
    }
    ll best_solution_cost = 0x7fffffff;
    Solution best_solution(n, alpha);
    int stopwatch= 0;
    auto start = std::chrono::system_clock::now();
    for (int i = 0; stopwatch < 600; i++) {
        Solution solution(n, alpha);
        solution.constructionPhase(pop);
        while (solution.localSearch());
        if (!solution.check()) {
            cout << "Error" << endl;
        }
        auto end = std::chrono::system_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(end - start);
        stopwatch = (int)elapsed.count();
        if (solution.getScore() < best_solution_cost) {
            cout << "Iteration: " << i << " Time in secs: " << stopwatch << " Score: " << solution.getScore() << endl;
            best_solution_cost = (ll)solution.getScore();
            best_solution = solution;
        }
    }
    cout << "Best Solution size = " << best_solution_cost << endl;
    return 0;
}