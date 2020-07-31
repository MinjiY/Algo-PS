/*
	[BOJ] 12015 가장 긴 증가하는 부분 수열 2
	https://www.acmicpc.net/problem/12015
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	vector<int> a(n + 1);
	vector<int> lis;

	for(int i=0; i<n; ++i){
		cin >> a[i];

		if (i == 0) lis.push_back(a[i]);
		else if (lis.back() < a[i]) lis.push_back(a[i]);
		else {
			int idx = lower_bound(lis.begin(), lis.end(), a[i]) - lis.begin();
			lis[idx] = a[i];
		}
	}
	cout << lis.size() << "\n";

	return 0;
}

/*
int main() {
	int arr[10] = { 1,1,3,4,5,6,7,8,9 };

	cout << lower_bound(arr, arr + 10, 2) - arr << "\n";		//2출력 2보다 큰 가장 작은 정수값
	return 0;
}*/
