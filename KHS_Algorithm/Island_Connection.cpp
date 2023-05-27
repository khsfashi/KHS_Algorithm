#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> costs) {
    int cost = 0;
    vector<int> island(n);

    sort(costs.begin(), costs.end(), [](const vector<int>& a, const vector<int>& b) {return a[2] < b[2]; });

    for (auto cost : costs)
    {
        int island1 = cost[0];
        int island2 = cost[1];
    }

    int answer = 0;
    return answer;
}