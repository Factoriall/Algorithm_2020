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
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */	

	freopen("input.txt", "r", stdin);

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        
		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		int N, K;
		cin >> N;
		
		for(int i=0; i<N; i++)
		    cin >> rocks[i];
		
		cin >> K;
		
		int idx = 0;//현재 arr의 
		int pnt = 0;
		while(1){
		    pnt += K;
		    int prev = idx;
		    while(idx < N && pnt >= rocks[idx])
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