#include "solution.hpp"

Solution::Solution(int sz, double _alpha) {
    alpha = _alpha;
    n = sz;
    aloc = vector<int>(n, -1);
}

void Solution::constructionPhase(bool pop) {
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
        if (pop && (i == (2 * (n / 5)) || i == (4 * (n / 5)))) {
            while (localSearch());
        } 
    }
}

bool Solution::localSearch() {
    vector<pair<int, int> > v;
    for (int i = 0; i < bins.size(); i++) {
        v.push_back(make_pair(bins[i], i));
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        ll acc = 0;
        int cur = 0;
        bool cond = true;
        for (int j = 0; cond && j < n; j++) {
            if (aloc[j] == v[i].second) {
                while (cur == i || acc + bins[v[cur].second] + items[j] > capacity) {
                    cur++;
                    acc = 0;
                    if (cur == v.size()) {
                        cond = false;
                        break;
                    }
                }
                acc += items[j];
            }
        }
        if (cond) {
            cur = 0;
            for (int j = 0; j < n; j++) {
                if (aloc[j] == v[i].second) {
                    while (cur == i || bins[v[cur].second] + items[j] > capacity) {
                        cur++;
                        acc = 0;
                    }
                    aloc[j] = v[cur].second;
                    bins[v[cur].second] += items[j];
                }
            }
            for (int j = 0; j < n; j++) {
                if (aloc[j] == bins.size() - 1) {
                    aloc[j] = v[i].second;
                }
            }
            swap(bins[v[i].second], bins[bins.size() - 1]);
            bins.pop_back();
            return true;
        }
    }
    return false;
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