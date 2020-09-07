#include <iostream>
#include <string.h>
using namespace std;

void rec(int from, int to, int level) {

	if (level == 1) {
		cout << from << " " << to << '\n';
		return;
	}

	int bridge = 0;
	int arr[3] = { 1,2,3 };
	for (int i = 0; i < 3; i++) {
		if (arr[i] != from && arr[i] != to) {
			bridge = arr[i];
			break;
		}
	}


	rec(from, bridge, level - 1);
	cout << from << " " << to << '\n';
	rec(bridge, to, level - 1);
	return;
}


char* deleteZero(const char* num) {
	int len=0;
	for (int i = strlen(num)-1; i >= 0; i--) {
		if (num[i] != '0') {
			len = i;
			break;
		}
	}
	len += 1;

	char* newNum = (char*)malloc(sizeof(char) * len + 1);
	memcpy(newNum, num, len);
	newNum[len] = NULL;
	return newNum;
}

char* add(const char* num1, const char* num2) {
	int num1Len = strlen(num1), num2Len = strlen(num2);
	int len = (num1Len > num2Len ? num1Len + 1 : num2Len + 1);

	char num1Pointer[2] = { NULL, NULL };
	char num2Pointer[2] = { NULL, NULL };

	char* resultPointer = (char*)malloc(sizeof(char) * (len + 1));
	memset(resultPointer, '0', len);
	resultPointer[len] = NULL;

	int bigLen, smallLen;
	const char* bigNum, *smallNum;
	if (num1Len >= num2Len) {
		bigLen = num1Len;
		smallLen = num2Len;

		bigNum = num1;
		smallNum = num2;
	}
	else {
		bigLen = num2Len;
		smallLen = num1Len;

		bigNum = num2;
		smallNum = num1;
	}

	// 덧셈하기
	int result;
	for (int i = 0; i < smallLen; i++) {
		result = resultPointer[i] + num1[i] + num2[i] - 48 * 3;
		resultPointer[i] = (result % 10) + 48;
		if (result / 10 > 0) {
			resultPointer[i+1] = '1';
		}
	}

	for (int i = smallLen; i < bigLen; i++) {
		resultPointer[i] = resultPointer[i] + bigNum[i] - 48;
	}

	char* deleteZeroPointer = deleteZero(resultPointer);
	free(resultPointer);
	return deleteZeroPointer;
}

char* multiple(const char* num1, const char* num2) {
	int zeroNum=0, cur_count=0;
	int len = strlen(num1) + strlen(num2) + 1;
	int result, carry, rest;
	char num1Pointer[2] = { NULL, NULL };
	char num2Pointer[2] = { NULL, NULL };
	char* resultPointer = (char*)malloc(sizeof(char) * (len+1));

	memset(resultPointer, '0', len + 1);
	resultPointer[len] = NULL;

	for (int i = 0; i < strlen(num2) ; i++) {
		for (int j = 0; j < strlen(num1) ; j++) {
			num1Pointer[0] = num1[j];
			num2Pointer[0] = num2[i];
			result = atoi(num1Pointer) * atoi(num2Pointer);
			carry =  result / 10;
			rest =  result % 10;
			
			//resultPointer[len - 1 - zeroNum] = result;
			resultPointer[zeroNum+j+1] += carry;
			resultPointer[zeroNum+j] += rest;
		}
		zeroNum++;
	}

	// 올림을 처리해주는 루틴
	for (int i = 0; i < len; i++) {
		resultPointer[i + 1] += (resultPointer[i]-48) / 10;
		resultPointer[i] = (resultPointer[i]-48) % 10 + 48;
	}

	char* deleteZeroPointer = deleteZero(resultPointer);
	free(resultPointer);

	return deleteZeroPointer;
}

int main() {
	int num;
	char* tmp=NULL, *next=NULL, *prev, *mul=NULL;
	cin >> num;

	prev = (char*)malloc(sizeof(char) * 2);
	prev[0] = '1';
	prev[1] = NULL;

	for (int i = 1; i < num; i++) {
		tmp = next;
		mul = multiple(prev, "2");
		next = add(mul, "1");
		free(prev);
		free(mul);
		prev = next;
	}

	for (int i = strlen(next) - 1; i >= 0; i--)
		cout << next[i];
	cout << '\n';
	if (num <= 20)
		rec(1, 3, num);
	return 0;
}