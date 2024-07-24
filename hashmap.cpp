#include<iostream>
using namespace std;

void hashmap(){
	int n;
	cin >> n;
	int arr[n];
	
	for(int i=0; i <n;i++){
		cin >> arr[i];
	}

	//precalculate
	int hash[20] = {0};
	for(int i=0; i<n;i++){
		hash[arr[i]] += 1;
	}
	

	int q;
	cin >> q;
	while(q--){
		int n;
		cin >>n;

		//print
		cout<<hash[n]<<endl;
	}
	
}

int main(){
	hashmap();
	return 0;
}
