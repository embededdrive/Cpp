#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(int left, int right) {
	return left > right;
}

bool cmp1(int left, int right) {
	if (left > right)
		return true;
	if (left < right)
		return false;
	return false;
}

struct Student {
	string name;
	int age;
	int grade;
};


bool ssafycmp(Student left, Student right) {
	// #1 시험 점수 높은 사람
	if (left.grade > right.grade)
		return true;
	if (left.grade < right.grade)
		return false;
	// #2 나이가 많은 사람
	if (left.age > right.age)
	return true;
	if (left.age < right.age)
		return false;
	// #3 이름이 사전순으로 빠른 사람
	if (left.name < right.name)
		return true;
	if (left.name > right.name)
		return false;
	// 마지막
	return false;
}

int main()
{
	int arr[] = { 1, 3, 5, 4, 2 };
	// 정렬방법

	// #1 오름차순 정렬
	/*
	sort(arr, arr + 5);
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << ' ';
	}
	*/

	// #2 내림차순 정렬
	/*
	sort(arr, arr + 5, cmp);
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << ' ';
	}
	*/

	// #3 사용자 정의 정렬
	// struct 정렬

	Student ssafy[5];
	// 시험 점수 높은 사람 중 , 나이가 많은 사람, 이름이 사전순으로 빠른 사람
	ssafy[0] = { "송유빈", 3, 100 };
	ssafy[1] = { "박준형", 4, 100 };
	ssafy[2] = { "김택우", 2, 100 };
	ssafy[3] = { "김기덕", 4, 100 };
	ssafy[4] = { "이득화", 7, 25 };

	sort(ssafy, ssafy + 5, ssafycmp);

	for (int i = 0; i < 5; i++)
	{
		cout << ssafy[i].name << ' ' << ssafy[i].age << ' ' << ssafy[i].grade << '\n';
	}
	
	return 0;
}