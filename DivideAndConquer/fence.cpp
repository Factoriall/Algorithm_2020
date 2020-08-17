#include <iostream>
#include <algorithm>
using namespace std;

int fence[20000];
int n;

int solve(int start, int end){
    if(start == end){
        return fence[start];
    }
    int mid = (start + end) / 2;
    int ret = max(solve(start, mid), solve(mid+1, end));

    int lo = mid;
    int hi = mid+1;
    int width = 2;
    int height = min(fence[lo], fence[hi]);
    int maxSize =  height * width;
    
    while(lo != start || hi != end){
        if(hi == end){
            height = min(height, fence[--lo]);
        }
        else if(lo == start){
            height = min(height, fence[++hi]);
        }
        else if(fence[lo-1] >= fence[hi+1]){
            height = min(height, fence[--lo]);
        }
        else{
            height = min(height, fence[++hi]);
        }
        width++;
        maxSize = max(maxSize, height * width);
    }
     
    ret = max(ret, maxSize);

    return ret;
}

int main(){
    int T;
    cin >> T;
    for(int t=0; t<T; t++){
        cin >> n;
        
        for(int i=0; i<n; i++){
            cin >> fence[i];
        }
        cout << solve(0, n-1) << '\n';
    }

    return 0;
}