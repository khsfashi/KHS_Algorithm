#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {

    sort(routes.begin(), routes.end(), [](const vector<int>& a, const vector<int>& b) {return a[1] < b[1]; });
    int camera = 0;
    int cameraPos = -30001;
    for (auto route : routes)
    {
        int entry = route[0];
        int exit = route[1];
        if (entry > cameraPos)
        {
            camera++;
            cameraPos = exit;
        }
    }

    return camera;
}