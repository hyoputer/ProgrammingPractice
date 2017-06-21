#include<stdio.h>
#include<math.h>

int main() {
	double ix, iy, x, y, mx = 0, my = 0, mdis = 0, dis = 0;
	int n, i;
	scanf("%d",&n);
	
	scanf("%lf%lf",&ix, &iy);
	for (i = 0; i < n; i++) {
		scanf("%lf%lf",&x, &y);
		dis = sqrt((x - ix)*(x - ix) + (y - iy)*(y - iy));
		if(dis > mdis) {
			mdis = dis;
			mx = x;
			my = y;
		}
	}
	
	printf("The farthest point frm (%.2lf, %.2lf) is (%.2lf, %.2lf), and a distance between them is %.3lf\n", ix, iy, mx, my, mdis);

	return 0;
} 
