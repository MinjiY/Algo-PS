/*
    [BOJ] 11047 동전0
    https://www.acmicpc.net/problem/11047
    출처: https://blog.encrypted.gg/755?category=773649
 */
#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[10];
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k; 
  for (int i = 0; i < n; i++)
	cin >> a[i];
  int num = 0;
  for (int i = n - 1; i >= 0; i--) {
    int t = k / a[i];
    num += t;
    k -= t*a[i];
  }
  cout << num;
}