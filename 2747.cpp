#include <stdio.h>

int main() {
	int i, n;
	long long int arr[45] = { 1, 1};

	scanf("%d", &n);
	if (n == 1) {
		printf("1");
		return 0;
	}
	if (n == 2) {
		printf("1");
		return 0;
	}

	for (i = 2; i < n; i++) {
		arr[i] = arr[i - 2] + arr[i - 1];
	}
	printf("%lld\n", arr[i-1]);
	return 0;
}