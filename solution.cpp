#include "solution.hpp"

Solution::Solution(int sz, double _alpha) {
    alpha = _alpha;
    n = sz;
    aloc = vector<int>(n, -1);
}

void Solution::constructionPhase() {
    for (int i = 0; i < n; i++) {
        vector<pair<ll, int> > v;
        v.push_back(make_pair(capacity - items[i], bins.size()));
        for (int j = 0; j < bins.size(); j++) {
            if (capacity - bins[j] >= items[i]) {
                v.push_back(make_pair(capacity - items[i] - bins[j], j));
            }
        }
        sort(v.begin(), v.end());
        double smaller = v[0].first;
        double bigger = v.back().first;
        double threshold = smaller + (bigger - smaller) * (alpha / 100.0);
        int left = 0, right = v.size();
        while (left < right) {
            int mid = (left + right) / 2;
            if (v[mid].first > threshold) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        int choosen = rand() % left;
        if (v[choosen].second == bins.size()) {
            bins.push_back(items[i]);
        } else {
            bins[v[choosen].second] += items[i];
        }
        aloc[i] = v[choosen].second;
    }
}

bool Solution::check() {
    ll total_sum = 0;
    for (int i = 0; i < n; i++) {
        if (aloc[i] < 0 || aloc[i] >= bins.size()) return false;
        total_sum += items[i];
    }
    ll bins_sum = 0;
    for (int i = 0; i < bins.size(); i++) {
        bins_sum += bins[i];
        ll current_bin_sum = 0;
        for (int j = 0; j < n; j++) {
            if (aloc[j] == i) {
                current_bin_sum += items[j];
            }
        }
        if (current_bin_sum != bins[i]) return false;
    }
    return bins_sum == total_sum;
}

int Solution::getScore() {
    return bins.size();
}