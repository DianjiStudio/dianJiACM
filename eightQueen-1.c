#include<stdio.h>
#include<stdlib.h>

int size = 0;
int* map;
int ans;

void init();
int isVaild(int count,int col);
void queen(int count);

int main(int argc,char** argv){
    size = atoi(argv[1]);
    map = (int*)malloc(sizeof(int) * size);
    queen(0);
    printf("%d\n",ans);
}

int isVaild(int count,int col){
    int i;
    for(i = 0;i < count;i++){
        if(map[i] == col) return 0;
        if(abs(count-i) == abs(col-map[i])) return 0;
    }
    return 1;
}

void queen(int count){
    if(count > size-1) {
        ans++;
        return;
    }
    int i;
    for(i = 0;i < size;i++){
        if(isVaild(count,i)){
            map[count] = i;
            queen(count+1);
        }
    }
}