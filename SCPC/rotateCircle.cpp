/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <cstdio>
#include <cmath>

double Answer;
double PI = 2*acos(0.0);//PI 값 구하기

double AmbiguousDistance(int r, int h){//반지름이 높이보다 작을 시 거리를 따로 구해야함
    return sqrt(r*r - (r-h) * (r-h));
}

int main(int argc, char** argv)
{
	int T, test_case;
	/*
	   장애물의 높이와 원의 크기와 비교해서 상황에 따라 다르게 구성하는 수학 구현 문제
	   기본적으로 모두 double형으로 구현해야됨.
	 */	

	scanf("%d", &T);
	for(test_case = 0; test_case < T; test_case++)
	{
		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		int R, S, E;//원의 반지름, 시작, 끝 지점
		int n;
		scanf("%d %d %d", &R, &S, &E);
		scanf("%d", &n);
		
		//int center = S;
		double center = S;//center가 double형이 될 수 있다는 것 간과...
		for(int t=0; t<n; t++){
		    int s, e, h;
		    scanf("%d %d %d", &s, &e, &h);
		    
		    //1 - 장애물까지 거리
            if(h > R)
		        Answer += ((s - R) - center);
            else
                Answer += (s - AmbiguousDistance(R, h) - center);
            
		    //2 - 올라가고 내려가는 거리
		    if(h > R)
		        Answer += 2 * (h - R);
		        
		    //3 - 꼭짓점에서 회전하는 거리
		    if(h > R)
		        Answer += 2 * (0.5 * PI * R);
            else
                Answer += 2 * (R * acos((R-h)/(double)R));
            
            //4 - 장애물 위에서 움직이는 거리
            Answer += (e - s);

            //5 - center 다시 설정
            if(h > R)
                center = e + R;
            else
                center = e + AmbiguousDistance(R, h);
		}

        //맨 끝까지의 거리
        Answer += (E - center);
		 
		/////////////////////////////////////////////////////////////////////////////////////////////
		
		// Print the answer to standard output(screen).
		printf("Case #%d\n", test_case+1);
		printf("%lf\n", Answer);
	}

	return 0;//Your program should return 0 on normal termination.
}