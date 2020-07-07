#include<stdio.h>
#include<iostream>
#include<string> 
#include<vector>
using namespace std;

int main(){
//	string s;
//	getline(cin,s);
//	cout<<s;

//	int a;
//	cin>>a;
//	cout<<a;
	
	vector<int> res;
	int temp;
	while(cin>>temp){
		res.push_back(temp);
		if(cin.get() == '\n') break;
	}
	int size = res.size();
	for(int i = 0; i < size; i++)
		cout<<res[i]<<' ';
	cout<<endl;
	return 0;
}

