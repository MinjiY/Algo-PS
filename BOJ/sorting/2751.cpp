
#pragma warning(disable: 4996)
/*
	[BOJ] 2751 �� �����ϱ� 2
	https://www.acmicpc.net/problem/2751
*/

/*
#include <cstdio>


void merging(int arr[], int s1, int e1, int s2, int e2) {
	//arr�� s1~e1�� ���� ����, s2~e2�� ������ ������ ��,
	//�� ���� ���ļ� arr�� s1~e2�� ���ĵ� ����� ����� �Լ�

	//1 2 4 8  3 4 6 7
	//p        q

	//temp�迭 

	int p, q;
	int temp[1000001] = { 0, };
	int temp_inx = 0;

	p = s1;
	q = s2;

	while (p <= e1 && q <= e2) {
		if (arr[p] <= arr[q]) {
			temp[temp_inx++] = arr[p];
			p++;
		}
		else {
			temp[temp_inx++] = arr[q];
			q++;
		}

	}

	if (p > e1) {   //p�� ������ �������(��� �ֵ��� temp�� �ű� ���)
		for (int i = q; i <= e2; i++) {
			temp[temp_inx++] = arr[i];
		}
	}
	else {
		for (int i = p; i <= e1; i++)
			temp[temp_inx++] = arr[i];
	}
	//arr�� s1���� e2���� 
	for (int i = s1; i <= e2; i++) {
		arr[i] = temp[i - s1];
	}


}

void mergeSort(int arr[], int start, int end) {
	//arr�� start���� end������ �պ������ϴ� �Լ�

	if (start >= end)
		return;

	else {
		//1. ���������� �պ�����
		//2. ������ ������ �պ�����
		//3. �� ���� ��ģ��.
		int mid = (start + end) / 2;
		mergeSort(arr, start, mid);
		mergeSort(arr, mid + 1, end);

		//arr[start-mid], arr[mid-end]�� ������ �̹� �Ǿ�����
		merging(arr, start, mid, mid + 1, end);


	}


}

int main() {
	int n;
	int numbers[1000001] = { 0, };


	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &numbers[i]);

	mergeSort(numbers, 0, n - 1);

	for (int i = 0; i < n; i++)
		printf("%d\n", numbers[i]);

	return 0;
}*/
#include<cstdio>
using namespace std;

int N, arr[1000001];
int* arr2;

void merge(int left, int right)
{
	int mid = (left + right) / 2;

	int i = left;
	int j = mid + 1;
	int k = left;
	while (i <= mid && j <= right)
	{
		if (arr[i] <= arr[j])
			arr2[k++] = arr[i++];
		else
			arr2[k++] = arr[j++];
	}

	int tmp = i > mid ? j : i;

	while (k <= right) arr2[k++] = arr[tmp++];

	for (int i = left; i <= right; i++) arr[i] = arr2[i];
}

void partition(int left, int right)
{
	//arr�� begin���� end������ �պ������ϴ� �Լ� begin == left, end == right
	int mid;
	//1. ���������� �պ����� (�ɰ��� ����)
    //2. ������ ������ �պ�����
    //3. �� ���� ��ģ��.
	if (left < right)
	{
		mid = (left + right) / 2;
		partition(left, mid);
		partition(mid + 1, right);
		merge(left, right);
	}
}

int main()
{
	scanf("%d", &N);
	arr2 = new int[N];
	for (int i = 0; i < N; i++) scanf("%d", &arr[i]);

	partition(0, N - 1);

	for (int i = 0; i < N; i++) printf("%d\n", arr[i]);
	return 0;
}