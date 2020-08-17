/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int Answer;
int room[1000][1000];
bool isUsed[1000][1000];
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

bool isOut(int y, int x, int N){
    if(y < 0 || x < 0 || y >= N || x >= N)
        return true;
    return false;
}

int main(int argc, char** argv)
{
	int T, test_case;

	freopen("input.txt", "r", stdin);

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		int N;
		cin >> N;
		
		//거울 위치 및 거울을 셌는지 여부 저장
		for(int i=0; i<N; i++){
		    for(int j=0; j<N; j++){
		        scanf("%1d", &room[i][j]);
		        if(room[i][j] != 0)
		            isUsed[i][j] = false;
		        else
		            isUsed[i][j] = true;
		    }
		}
		
		int dir = 0;//동쪽
		int y = 0;
		int x = 0;
		while(!isOut(y,x,N)){//밖으로 나갈 때 까지 거울 반사시키면서 세기
		    if(room[y][x] == 0){//직진
		        y += dy[dir];
		        x += dx[dir];
		    }
		    else if(room[y][x] == 1){//우측 상단에서 좌측 하단으로 45도 기울어진 양면거울
		        if(!isUsed[y][x]){//거울 세지 않았다면 기록
		            isUsed[y][x] = true;
		            Answer += 1;
		        }
		        switch(dir){
		        case 0://동쪽 - 북쪽
		            y += dy[3];
		            x += dx[3];
		            dir = 3;
		            break;
		        case 1://남쪽 - 서쪽
		            y += dy[2];
		            x += dx[2];
		            dir = 2;
		            break;
		        case 2://서쪽 - 남쪽
		            y += dy[1];
		            x += dx[1];
		            dir = 1;
		            break;
		        case 3://북쪽 - 동쪽
		            y += dy[0];
		            x += dx[0];
		            dir = 0;
		            break;
		        }
		    }
		    else{//좌측 상단에서 우측 하단으로 45도 기울어진 양면거울
                if(!isUsed[y][x]){//거울 세지 않았다면 기록
		            isUsed[y][x] = true;
		            Answer += 1;
		        }
		        switch(dir){
		        case 0://동쪽 - 남쪽
		            y += dy[1];
		            x += dx[1];
		            dir = 1;
		            break;
		        case 1://남쪽 - 동쪽
		            y += dy[0];
		            x += dx[0];
		            dir = 0;
		            break;
		        case 2://서쪽 - 북쪽
		            y += dy[3];
		            x += dx[3];
		            dir = 3;
		            break;
		        case 3://북쪽 - 서쪽
		            y += dy[2];
		            x += dx[2];
		            dir = 2;
		            break;
		        }
		    }
		}
		/////////////////////////////////////////////////////////////////////////////////////////////
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}