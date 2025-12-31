#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
string Time;

struct xy {
	int value, x, y;
};
vector<xy> v;
void init() {
	v.push_back({ 0, 4, 2 });
	int i = 1;
	for (int r = 1; r <= 3; r++) {
		for (int c = 1; c <= 3; c++) {
			v.push_back({ i++, r, c });
		}
	}
}
int effort(int hour, int minute) {
	int e=0;
	int a = hour / 10;
	int b = hour % 10;
	int c = minute / 10;
	int d = minute % 10;
	xy first = v[a];
	xy second = v[b];
	xy third = v[c];
	xy fourth = v[d];

	e = abs(first.x - second.x) + abs(first.y - second.y);
	e += abs(second.x - third.x) + abs(second.y - third.y);
	e += abs(third.x - fourth.x) + abs(third.y - fourth.y);

	return e;
}
void check() {
	int hour, minute, tempMax = 0;
	int ans = 9999999, ansHour = 0, ansMinute = 0;

	hour = stoi(Time.substr(0, 2)) % 24;
	minute = stoi(Time.substr(3, 2)) %  60;

	for (int h = hour; h <= 99; h += 24) {
		for (int m = minute; m <= 99; m += 60) {
			tempMax = effort(h, m);
			if (tempMax < ans) {
				ans = tempMax;
				ansHour = h;
				ansMinute = m;
			}
		}
	}
	printf("%02d:%02d\n", ansHour, ansMinute);
}
int main() {
	init();
	cin >> Time;
	
	// 24 씩 증가, 60씩 증가
	// 최솟값
	check();
	return 0;
}