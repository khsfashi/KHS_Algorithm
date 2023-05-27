#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;
	int bag5 = N / 5;

	for (int i = bag5; i >= 0; --i)
	{
		int remain = N - (i * 5);
		if (remain % 3 == 0) {
			cout << i + remain / 3 << endl;
			return 0;
		}
	}

	cout << -1 << endl;
}