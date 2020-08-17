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
		/////////////////////////////////////////////////////////////////////////////////////////////
		int N;
		cin >> N;
		
		Answer = N-1;
		
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
        
        if(!isFinished){
            for(int i=last; i>0; i--){
                if(N % i == 0){
                    Answer = (N/i) - 1;
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