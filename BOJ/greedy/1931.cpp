/*
    [BOJ] 1931 회의실 배정
    https://www.acmicpc.net/problem/193
    출처: https://blog.encrypted.gg/755?category=773649
 */
#include <bits/stdc++.h>
using namespace std;
int n;
pair<int, int> s[100005]; // schedule, 정렬의 편의를 위해 {끝 시간, 시작 시간}으로 저장할 예정
#define X first
#define Y second
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> s[i].Y >> s[i].X;
  }
  sort(s,s+n); // 먼저 끝나는 시간을 비교하고, 끝나는 시간이 동일하면 시작 시간 순으로 정렬된다.
  int ans = 0;
  int t = 0; // 현재 시간
  for(int i = 0; i < n; i++){
    if(t > s[i].Y) continue; // 시작 시간이 현재 시간보다 이전인 회의라면 무시하고 넘어간다.
    ans++; // 시작 시간이 현재 시간 이후인 회의를 찾았으므로 회의의 수에 1을 증가한다.
    t = s[i].X; // 현재 시간을 s[i]의 끝나는 시간으로 변경한다.
  }
  cout << ans;
}