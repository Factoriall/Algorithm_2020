#include <cstdio>
#include <algorithm>
using namespace std;

const bool clockSwitch[10][16] = { // const 선언 통해 고정
    {1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,1,0,0,0,1,0,1,0,1,0,0,0,0},
    {0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,1},
    {1,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,1,1,0,1,0,1,0,0,0},
    {1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1},
    {0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,1},
    {0,0,0,0,1,1,0,1,0,0,0,0,0,0,1,1},
    {0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,1,1,1,0,0,0,1,0,0,0,1,0,0}
};

const int INF = 9999;

int clocks[16];
int minimum;

bool isAligned(){
    for(int i=0; i<16; i++){
        if(clocks[i] != 12)
            return false;
    }
    return true;
}

void clockSync(int swt, int press){
    if(press >= minimum)
        return;
    if(swt == 10){
        if(isAligned())
            minimum = min(minimum, press);
        return;
    }

    clockSync(swt+1, press);//0일 때는 더할 필요 없음

    for(int i=1; i<4; i++){
        int tmp[16];//임시 저장 배열

        for(int k=0; k<16; k++){
            tmp[k] = clocks[k];//미리 저장
            if(clockSwitch[swt][k]){
                clocks[k] = (clocks[k] + 3*i);//시계 조정
                if(clocks[k] > 12)//12시 넘어가면 조정
                    clocks[k] = clocks[k] % 12;
            }
        }
        clockSync(swt+1, press+i);//재귀 호출

        for(int k=0; k<16; k++)//재귀 호출 전으로 돌려놓기
            clocks[k] = tmp[k];   
    }
}

int main(){
    int T;
    scanf("%d", &T);
    for(int t=0; t<T; t++){
        for(int i=0; i<16; i++){
            scanf("%d", &clocks[i]);
        }
        
        minimum = INF;
        clockSync(0, 0);

        if(minimum == INF)
            printf("-1\n");
        else
            printf("%d\n", minimum);
    }

    return 0;
}