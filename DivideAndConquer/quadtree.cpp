#include <iostream>
#include <string>
using namespace std;

string treeArrange(string::iterator& it){
    char head = *it;
    it++;
    if(head == 'b' || head == 'w'){
        return string(1, head);
    }
    string s1 = treeArrange(it);
    string s2 = treeArrange(it);
    string s3 = treeArrange(it);
    string s4 = treeArrange(it);

    return string("x") + s3 + s4 + s1 + s2;
}

int main(){
    int T;
    cin >> T;
    for(int t=0; t<T; t++){
        string tree;
        cin >> tree;
        
        string::iterator it = tree.begin();
        string result = treeArrange(it);
        
        cout << result << '\n';
    }
    return 0;
}
