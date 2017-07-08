#include<stdio.h>
#include<stdlib.h>

int map[8][8];
int ans = 0;

void init();
int isVaild(int x,int y);
void queen(int count);
int getMark(int x,int y);

int main(){
	init();
	queen(1);
	printf("%d\n",ans);
}

void init(){
	int i,j;
	for(i = 0;i < 8;i++){
		for(j = 0;j < 8;j++){
			map[i][j] = 0;
		}
	}
}

int isVaild(int x,int y){
	int i;
	for(i = 0;i < 8;i++){
		if(map[i][y] != 0) return 0;
		int up = x-i;
		int right = y+i;
		int left = y-i;
		int down = x+i;
		if(getMark(up,right) > 0) return 0;
		if(getMark(up,left) > 0) return 0;
		if(getMark(down,right) > 0) return 0;
		if(getMark(down,left) > 0) return 0;
	}
	return 1;
}

int getMark(int x,int y){
	if(x > -1 && x < 8 && y > -1 && y < 8){
		return map[x][y];
	}
	else return -1;
}

void queen(int count){
	if(count > 8){
		ans++;
		return;
	}
	int i;
	for(i = 0;i < 8;i++){
		if(isVaild(count-1,i)){
			map[count-1][i] = count;
			queen(count+1);
			map[count-1][i] = 0;
		}
	}
	return;
}
