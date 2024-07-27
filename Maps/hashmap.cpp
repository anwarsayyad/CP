#include<bits/stdc++.h>
using namespace std;

void hashmap(){
	int n;
	cin >> n;
	int arr[n];
	
	// Orderd map
	// map<int, int> mapp;


	//unordered_map
	unordered_map<int, int> mapp;

	for(int i=0; i <n;i++){
		cin >> arr[i];
		// using map
		mapp[arr[i]]++;
	}

	//precalculate
	// int hash[20] = {0};
	// for(int i=0; i<n;i++){
	// 	hash[arr[i]] += 1;
	// }
	

	int q;
	cin >> q;
	while(q--){
		int n;
		cin >>n;

		//print
		cout<<mapp[n]<<endl;
		
	}
	
}

int main(){
	hashmap();
	return 0;
}
