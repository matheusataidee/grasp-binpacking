#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

typedef long long ll;

int n;
ll capacity;
vector<ll> items;

int main(int argc, char** argv) {
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " <Instance>" << endl;
        return -1;
    }
    ifstream fin(argv[1]);
    fin >> n >> capacity;
    cout << n << " " << capacity << endl;
    for (int i = 0; i < n; i++) {
        ll x;
        fin >> x;
        items.push_back(x);
    }
    return 0;
}