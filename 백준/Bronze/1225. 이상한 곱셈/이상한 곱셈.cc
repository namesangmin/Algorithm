#include <iostream>
#include <string>

using namespace std;

int main() {
	string A;
	string B;
	long long int temp_num1, temp_num2, A_length, B_length;
	
	long long int result=0;
	long long int temp_result=0;

	cin >> A >> B;
	
	A_length = A.length();
	B_length = B.length();
	if (A_length > 10000 && B_length > 10000) 
		return 0;
	if (A[0] == 0 && B[0] == 0)
		return 0;


	for (int i = 0; i < A_length; i++) {
		for (int j = 0; j < B_length; j++) {
			temp_num1 = A[i] - '0';
			temp_num2 = B[j] - '0';
			
			result += temp_num1 * temp_num2;
			//to_string(result);
			//temp_result = result;

			
		}
	}
	cout << result << endl;


	return 0;
}