#include <iostream>

using namespace std;
int hour, minute, cook;

void input() {
	cin >> hour >> minute >> cook;
}
void func() {
	int hour_to_min = hour * 60;
	int tot_min = hour_to_min + minute + cook;
	hour = (tot_min / 60) % 24;
	minute = tot_min % 60;
	cout << hour << " " << minute << "\n";
}
int main() {
	input();
	func();
	return 0;
}