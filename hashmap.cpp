#include<iostream>
using namespace std;

void hashmap(){
	int n;
	cin>> n;

	int a[n];
	
	for(int i=0; i<n; i++){
		cin >>a[i];
	}

    for(int n: a){
        cout << n << endl;
    }


}

int main(){
	hashmap();
	return 0;
}
