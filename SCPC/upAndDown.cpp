/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <cstdio>

int Answer;
long long arr[2097152];
const int start = 1048576;//2^20

long long dynamicProgramming(int n){
    if(n == 1)//base
        return 0;
        
    long long &ret = arr[start + n - 1];
    if(ret != 0){//dp에 이미 저장
        return ret;
    }
    
    long long total;
    if(n % 2 == 0)
        total = dynamicProgramming(n/2) + 1;
    else
        total = dynamicProgramming(n+1) + 1;

    return ret = total;
}

//세그먼트 트리에서 합 구간 찾기
long long sum(int L, int R, int nodeNum, int nodeL, int nodeR){
    if(R < nodeL || nodeR < L) return 0;
    if(L <= nodeL && nodeR <= R) return arr[nodeNum];
    long long mid = (nodeL + nodeR) / 2;
    return sum(L, R, nodeNum*2, nodeL, mid) + sum(L, R, nodeNum*2+1, mid+1, nodeR);
}

int main(int argc, char** argv)
{
	int T, test_case;
    /*
	   - DP + 세그먼트 트리
        DP만으로는 10만 * 1만 = 10억으로 1초 내에 계산 불가능.
        그러므로 세그먼트 트리를 생성해서 10만을 log로 줄여서 계산.

        cin, cout으론 시간 초과 but scanf, printf로 교체하니 넉넉하게 성공
        - 되도록 scanf, printf로 푸는 습관을 들여야 한다!
	*/	
	scanf("%d", &T);

    //세그먼트 트리 구축 과정
	for (int i = start; i < start + 1000000; i++)
		arr[i] = dynamicProgramming(i - start + 1);
    for (int i = start - 1; i > 0; i--)
		arr[i] = arr[i * 2] + arr[i * 2 + 1];

	for(test_case = 0; test_case < T; test_case++)
	{
		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
        
        //알고리즘 구현
	    int n1, n2;
	    scanf("%d %d", &n1, &n2);
        Answer = sum(n1 - 1, n2 - 1, 1, 0, start - 1);//세그먼트 트리 사용한 결과 찾기

		/////////////////////////////////////////////////////////////////////////////////////////////
		
		// Print the answer to standard output(screen).
		printf("Case #%d\n", test_case+1);
        printf("%d\n", Answer);
	}

	return 0;//Your program should return 0 on normal termination.
}