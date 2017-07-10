#include<stdio.h>
int result = 0;
int ans = 0;

void init();
void queen(int row,int lx,int rx);

int main(){
    int size = 24;
    result = (1 << size) - 1;
    ans = 0;
    queen(0,0,0);
    printf("%d\n",ans);
}

void queen(int row,int ld,int rd){
    if(row == result){
        ans++;
        return;
    }
    int pos,p;
    pos = result & (~(row | ld | rd));
    while(pos){
        p = pos & (~pos + 1);
        pos = pos - p;
        queen(row | p,(ld | p) << 1,(rd | p) >> 1);
    }
}