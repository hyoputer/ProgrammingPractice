#include<stdio.h>


int bot, top;

typedef struct dir {
	int x, y, dis;
} dir;

typedef struct queue {
	dir arr[100];
	void push(dir value) {
		arr[top++] = value;
	}

	void pop() {
		if (bot < top)
		{
			bot++;
			return;
		}
		else
			return;
	}

} queue;

queue knight = { 0 };
queue horse = { 0 };

int grid[1000][1000] = { 0 }, dis1[1000][1000] = { 0 }, dis2[1000][1000] = { 0 }, confirm[1000][1000] = { 0 };

void check(queue queue,int x, int y, int n, int dis) {
	dir dir;
	if ((((0 <= x && x < (n * n)) && grid[x][y] != 1) && (0 <= y && y < (n * n))) && (confirm[x][y] != 1)) {
		dir.x = x, dir.y = y, dir.dis = dis;
		knight.push(dir);
		confirm[x][y] = 1;
		dis1[x][y] = dis;
		return;
	}
	else
		return;
	

}

int main() {


	dir dir; 
	int n = 0, k = 0, x = 0, y = 0, dis = 0;
	scanf("%d%d", &n, &k);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &grid[i][j]);
	scanf("%d%d", &x, &y);
	dir.x = x - 1, dir.y = y - 1, dir.dis = 0;
	knight.push(dir), horse.push(dir);
	confirm[dir.x][dir.y] = 1;
	dis1[dir.x][dir.y] = 0;
	dis2[dir.x][dir.y] = 0;

	do {
		int inx = (knight.arr[bot]).x, iny = (knight.arr[bot]).y;
		x = inx - 2, y = iny + 1;
		check(knight, x, y, n, dis);
		y = iny - 1;
		check(knight, x, y, n, dis);
		y = iny - 2, x = inx + 1;
		check(knight, x, y, n, dis);
		x = inx - 1;
		check(knight, x, y, n, dis);
		x = inx + 2, y = iny + 1;
		check(knight, x, y, n, dis);
		y = iny - 1;
		check(knight, x, y, n, dis);
		y = iny + 2, inx + 1;
		check(knight, x, y, n, dis);
		x = inx - 1;
		check(knight, x, y, n, dis);
		knight.pop();
		dir.dis = knight.arr[bot].dis + 1;
		
	} while (bot < top);

	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++)
			printf("%d ", dis1[i][j]);
		printf("\n");
	}
	
	
	return 0;
}
