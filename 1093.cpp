#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
#include<iostream> 

// 17:02 -  17:26
using namespace std;


struct node{
	int countp;
	int countt;
	node(int countp, int countt){
		this->countp = countp;
		this->countt = countt;
	}
}; 

int main(){
	string str;
	getline(cin, str);
	vector<node> a;
	int countp = 0, countt = 0;
	for(int i=0;i<str.length();i++){
		if(str[i] == 'P'){
			countp++;
		}else if(str[i] == 'A'){
			a.push_back(node(countp, countt));
		}else if(str[i] == 'T'){
			countt++;
		}
	}

	long long count = 0;
	for(int i=0;i<a.size();i++){
		count += a[i].countp * (countt-a[i].countt);
	}
	printf("%d", count%1000000007);
}
