#include<bits/stdc++.h>
using namespace std;

bool is_constant(string a){


    for(int i = 0; i < a.size(); i++){
        if(a[i] >= '0' && a[i] <= '9'){

        }else{
            return false;
        }

    }

    return true;

}

int main(){

    string a; cin >> a;
    if(is_constant(a)){
        cout << "Its numeric constant\n";
    }else{
        cout << "Its not numeric constant\n";
    }

}

