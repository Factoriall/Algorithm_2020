#include <iostream>
#include <string>
using namespace std;

int block[4][2][2] =   {
                        {{0,1}, {1,1}}, 
                        {{1,0}, {1,1}},
                        {{1,0}, {1,-1}},
                        {{0,1}, {1,0}} 
                        }; // 블록 크기

char board[20][20]; // 보드판 
int maxTile; // 사용할 최대 타일 개수
int H,W; // 보드판 height, width

bool OutOfRange(int y, int x, int block[2]){//범위 밖 체크
    int ny = y + block[0];
    int nx = x + block[1];

    if(ny < 0 || ny >= H || nx < 0 || nx >= W)//범위 밖 나가는지 체크, Off-by-one 오류 범했음
        return true;
    if(board[ny][nx] != '.')//보드판이 흰색인지 체크
        return true;
    
    return false;//가능
}

void drawBoard(){//디버깅 위한 보드 그리기
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cout << board[i][j];
        }
        cout << '\n';
    }
    cout << '\n';
}

int boardCover(int tile){
    if(tile == maxTile)//기저 조건
        return 1;

    int y, x; // 시작 위치 타일

    //tile의 맨 위, 왼쪽 부분 확인
    bool flag = false;
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            if(board[i][j] == '.'){
                y = i; x = j;
                flag = true;
                break;
            }
        }
        if(flag)
            break;
    }

    //재귀 호출 통해 brute-force 실행
    int sum = 0;
    for(int k=0; k<4; k++){
        if(!OutOfRange(y, x, block[k][0]) && !OutOfRange(y, x, block[k][1])){//range를 벗어나지 않는다면 다음 단계 진행
            board[y][x] = '#';
            board[y + block[k][0][0]][x + block[k][0][1]] = '#';
            board[y + block[k][1][0]][x + block[k][1][1]] = '#';
            
            sum += boardCover(tile + 1);
            
            //다시 되돌리기
            board[y][x] = '.';
            board[y + block[k][0][0]][x + block[k][0][1]] = '.';
            board[y + block[k][1][0]][x + block[k][1][1]] = '.';
        }
    }
    
    return sum;
}

int main(){
    int T;
    cin >> T;

    for(int t=0; t<T; t++){
        cin >> H >> W;

        for(int i=0; i<H; i++)
            cin >> board[i];

        int white = 0;
        //흰 칸 개수 구하는 함수
        for(int i=0; i<H; i++){
            for(int j=0; j<W; j++){
                if(board[i][j] == '.')
                    white++;
            }
        }

        if(white % 3 != 0 || white == 0)//예외: 0일 경우에도 0으로 출력해줘야 한다!
            cout << 0 <<'\n';
        else{
            maxTile = white/3;//전체 사용할 타일 개수 저장
            cout << boardCover(0) << '\n';
        }
    }

    return 0;
}