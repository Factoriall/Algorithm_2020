#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void normalize(vector<int>& num);
vector<int> multiply(const vector<int>& a, const vector<int> b);

void addTo(vector<int>& a, vector<int>& b, int k);
void subFrom(vector<int>& a, vector<int>& b);
vector<int> karatsuba(const vector<int>& a, const vector<int>& b);

vector<int> numToVec(long long num);
void printResult(vector<int> v);

int main(){
    long long a,b;
    vector<int> n1, n2;

    cin >> a >> b;

    n1 = numToVec(a);
    n2 = numToVec(b);

    vector<int> result = karatsuba(n1, n2);
    printResult(result);

    return 0;
}

void normalize(vector<int>& num){ // vector의 자리수 정규화시키는 함수
    num.push_back(0);

    for(int i=0; i<=num.size(); i++){
        if(num[i] < 0){//음수일 시 내림 처리
            int borrow = (abs(num[i]) + 9) / 10;
            num[i+1] -= borrow;
            num[i] += borrow * 10;
        }
        else{//양수일 시 올림 처리
            num[i+1] += num[i] / 10;
            num[i] = num[i] % 10;
        }
    }

    while(num.size() > 1 && num.back() == 0) num.pop_back();//맨 위 자리수가 0인 것은 다 빼주기
}

vector<int> multiply(const vector<int>& a, const vector<int> b){//a*b 구현
    vector<int> c(a.size() + b.size() + 1, 0);
    for(int i=0; i<a.size(); i++){
        for(int j=0; j<b.size(); j++){
            c[i+j] += a[i] * b[j];
        }
    }
    normalize(c);
    return c;
}

void addTo(vector<int>& a, vector<int>& b, int k){// a += b*(10^k) 구현
    vector<int> addResult(max(a.size(), b.size()+k) + 1, 0);
    for(int i=0; i<a.size(); i++){
        for(int j=k; j<b.size() + k; j++){
            addResult[i+j] += a[i] + b[j];
        }
    }
    normalize(addResult);
    a = addResult;
}

void subFrom(vector<int>& a, vector<int>& b){ // a-= b 구현
    vector<int> subResult(max(a.size(), b.size()), 0);
    for(int i=0; i<a.size(); i++){
        for(int j=0; j<b.size(); j++){
            subResult[i+j] += a[i] - b[j];
        }
    }
    normalize(subResult);
    a = subResult;
}

vector<int> karatsuba(const vector<int>& a, const vector<int>& b){
    int an = a.size(); int bn = b.size();
    if(an < bn) return karatsuba(b, a);
    if(an == 0 || bn == 0){ 
        return vector<int>();
    }
    if(an <= 50) return multiply(a,b);
    int half = an/2;
    //cout << "an: "<< an << '\n';
    //cout << "bn: "<< bn << '\n';

    
    vector<int> a0(a.begin(), a.begin() + half);
    vector<int> a1(a.begin()+half, a.end());
    vector<int> b0(b.begin(), b.begin() + min<int>(b.size(), half));
    vector<int> b1(b.begin() + min<int>(b.size(), half), b.end());

    cout << "a0: "<< a0.size() << '\n';
    cout << "a1: "<< a1.size() << '\n';
    cout << "b0: "<< b0.size() << '\n';
    cout << "b1: "<< b1.size() << '\n';


    vector<int> z2 = karatsuba(a1, b1);
    vector<int> z0 = karatsuba(a0, b0);
    addTo(a0, a1, 0); addTo(b0, b1, 0);
    vector<int> z1 = karatsuba(a0, b0);
    subFrom(z1, z0);
    subFrom(z1, z2);

    vector<int> ret;
    addTo(ret, z0, 0);
    addTo(ret, z1, half);
    addTo(ret, z2, half + half);
    return ret;
}

vector<int> numToVec(long long num){
    vector<int> v;
    while(num){
        v.push_back(num%10);
        num /= 10;
    }
    return v;
}

void printResult(vector<int> v){
    for(int i=v.size()-1; i>=0; i--){
        cout<<v[i];
    }
    cout << '\n';
}