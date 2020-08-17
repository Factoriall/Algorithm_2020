/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
#include <queue>

using namespace std;

int Answer;
int rocks[1000001];

int main(int argc, char** argv)
{
	int T, test_case;

	freopen("input.txt", "r", stdin);

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        
		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		//Greedy Algorithm 사용하면 된다!
		int N, K;
		cin >> N;
		
		for(int i=0; i<N; i++)
		    cin >> rocks[i];
		
		cin >> K;
		
		int idx = 0;//현재 array의 index
		int pnt = 0;//현재 위치
		while(1){//보낼 수 있는 가장 먼 곳을 잡아주고 도착할 때 까지 Answer 값 올려주기
		    pnt += K;
		    int prev = idx;
		    while(idx < N && pnt >= rocks[idx])//돌을 옮길 수 있을 때 까지 옮기기
		        idx += 1;
		    Answer += 1;
		    
		    if(prev == idx){//갈 수 있는 곳이 없으면 실패
		        Answer = -1;
		        break;
		    }
		    
		    if(idx == N)//도착
		        break;
		    
		    pnt = rocks[idx-1];
		}
		/////////////////////////////////////////////////////////////////////////////////////////////
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}