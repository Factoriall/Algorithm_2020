/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
#include <cmath>

using namespace std;

int Answer;

int main(int argc, char** argv)
{
	int T, test_case;

	freopen("input.txt", "r", stdin);

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		수학을 사용한 구현 문제 

		1. 대부분의 Answer은 11(n진수)일 때 균일수가 무조건 형성되므로 이를 최소로 잡음
		2. 3자리 수 이상까지 일단 N^(0.5)까지의 값까지 해서 존재하는지 확인
		3. 1번에서 없을 시 2자리 수에 있을 확률 존재 + 자리수는 N^(0.5)보다 낮을 것임
		4. 예외 처리, N = 1,2일 시 2진수 이상이라는 조건으로 인해 1번 성립 안하므로 N+1로 처리 

		*/
		int N;
		cin >> N;
		
		//1번
		Answer = N-1;
		
		//2번
		int last = (int)floor(sqrt(N));
        if(last * last == N)
            last -= 1;
	
        bool isFinished = false;
		for(int i=2; i<=last; i++){
		    int equal = N % i;
		    if(equal == 0)
		        continue;
		        
		    int divident = N / i;
		    int modular = equal;
		    while(divident >= i && modular == equal){
                modular = divident % i;
		        divident /= i;
            }
		    
		    if(modular != equal)
		        continue;
		    
		    if(divident == equal){
                isFinished = true;
		        Answer = i;
		        break;
		    }
		}
        
		//3번
        if(!isFinished){
            for(int i=last; i>0; i--){
                if(N % i == 0){
                    Answer = (N/i) - 1;
                    break;
                }
            }
        }

		//4번
        if(N == 2)
            Answer = 3;
        if(N == 1)
            Answer = 2;


		/////////////////////////////////////////////////////////////////////////////////////////////
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}