#include <iostream>
using namespace std;

int map[100][100];
int L;

bool dp(int y, int x){
    if(y >= L || x >= L)//거리 이상 가면 false
        return false;
    if(y == L-1 && x == L-1)//true 조건
        return true;
    if(map[y][x] == 0)//이미 도달한 곳이면 false 반환
        return false;
    int next = map[y][x];
    map[y][x] = 0;
    if(dp(y+next, x) || dp(y, x+next))//다음 dp 확인 후 true 확인
        return true;
}

int main(){
    int T;
    cin >> T;


    for(int t=0; t<T; t++){

        cin >> L;//L: 총 길이

        //입력
        for(int i=0; i<L; i++){
            for(int j=0; j<L; j++){
                cin >> map[i][j];
            }
        }

        if(dp(0,0))
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }

    return 0;
}