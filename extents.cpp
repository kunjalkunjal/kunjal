#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    // Speed up I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<unsigned int> starts;
    vector<unsigned int> ends;

    ifstream extFile("extents.txt");
    unsigned int x, y;

    while (extFile >> x >> y) {
        if (x > y) swap(x, y); // Ensure valid range [min, max]
        starts.push_back({x});
        ends.push_back({y});
    }
    extFile.close();

    sort(starts.begin(), starts.end());
    sort(ends.begin(), ends.end());

    ifstream numFile("numbers.txt");
    unsigned int point;

    while (numFile >> point) {
        auto it_start = upper_bound(starts.begin(), starts.end(), point);
        long long started = distance(starts.begin(), it_start);

        auto it_end = lower_bound(ends.begin(), ends.end(), point);
        long long ended = distance(ends.begin(), it_end);

        cout << (started - ended) << "\n";
    }
    numFile.close();

    return 0;
}
