#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> time(N);
	for (int i = 0; i < N; ++i)
		cin >> time[i];

	sort(time.begin(), time.end());
	int sum = 0;
	int accumulate = 0;
	for (int i : time)
	{
		accumulate += i;
		sum += accumulate;
	}
	cout << sum << endl;
}