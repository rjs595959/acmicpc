
#include <stdio.h>
#include <math.h>

int main() {
	int c, x1, y1, r1, x2, y2, r2, tmp;
	double d = 0;
	scanf("%d", &c);
	while (c--) {
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
		if (x2 < x1) {
			tmp = x2;
			x2 = x1;
			x1 = tmp;
		}
		if (y2 < y1) {
			tmp = y2;
			y2 = y1;
			y1 = tmp;
		}
		if (r2 < r1) {
			tmp = r2;
			r2 = r1;
			r1 = tmp;
		}
		
		d = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
;
		// �� �ȿ� ���� �ִ� ��� ���� ������ ��� ���Ѵ븦 ���´�.
		if (r1 == r2 && x1==x2 && y1==y2) { printf("-1\n"); }				

		// �� �ȿ��� ���� ������ �ʴ� ���
		else if (r2 - r1 > d) { printf("0\n"); }						

		//�� �ȿ��� ���� �´�� �ִ� ���
		else if (r2 - r1 == d) printf("1\n");	

		//���� �ۿ��� �´�� �ִ°��
		else if (r1 + r2 == d) printf("1\n");

		//���� �ۿ��� ������ �ִ� ���
		else if (r1 + r2 < d) printf("0\n");

		//���� ��ø�Ǵ� ���
		else if (r2 - r1 < d || r1 + r2 > d) printf("2\n");
	}
}