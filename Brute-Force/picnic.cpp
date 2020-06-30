#include <cstdio>
#include <utility>
using namespace std;

typedef pair<int, int> P;//utility 사용 시 사용 가능
int n, m;

P friends[50];
bool alreadyPaired[10];


int friendPair(int num, int order){//num: 페어 수, order: 현재 조사한 friends의 위치
    if(num == n/2)//기저 조건
        return 1;

    //재귀 호출로 brute-force 실행
    int sum = 0;
    for(int i = order; i<m; i++){//정렬 순서대로(order) 진행해서 중복을 방지한다 
        int f1 = friends[i].first;
        int f2 = friends[i].second;

        if(!alreadyPaired[f1] && !alreadyPaired[f2]){//페어 확인
            alreadyPaired[f1] = true;
            alreadyPaired[f2] = true;
            sum += friendPair(num+1, i);

            //되돌리기
            alreadyPaired[f1] = false;
            alreadyPaired[f2] = false;
        }
    }
    return sum;
}

int main(){
    int T;
    scanf("%d", &T);

    for(int t=0; t<T; t++){
        scanf("%d %d", &n, &m);
        for(int i=0; i<m; i++){
            scanf("%d %d", &friends[i].first, &friends[i].second);
        }

        printf("%d\n", friendPair(0, 0));

        //초기화
        for(int i=0; i<10; i++)
            alreadyPaired[i] = false;
    }

    return 0;
}