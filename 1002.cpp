
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
		// 원 안에 원이 있는 경우 원이 동일한 경우 무한대를 갖는다.
		if (r1 == r2 && x1==x2 && y1==y2) { printf("-1\n"); }				

		// 원 안에서 서로 만나지 않는 경우
		else if (r2 - r1 > d) { printf("0\n"); }						

		//원 안에서 원이 맞닿아 있는 경우
		else if (r2 - r1 == d) printf("1\n");	

		//원이 밖에서 맞닿아 있는경우
		else if (r1 + r2 == d) printf("1\n");

		//원이 밖에서 떨어져 있는 경우
		else if (r1 + r2 < d) printf("0\n");

		//원이 중첩되는 경우
		else if (r2 - r1 < d || r1 + r2 > d) printf("2\n");
	}
}