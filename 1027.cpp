#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

int n1, n2, n3;
char num_list[13] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C'};
string change(int n){
	string res;
	do{
		res += num_list[n%13];
		n/=13;
	}while(n!=0);
	int len = res.length();
	if(len<2){
		res+="0";
	}
	reverse(res.begin(), res.end());
	return res;
}

int main(){
	scanf("%d %d %d", &n1, &n2, &n3);
	printf("#%s%s%s", change(n1).c_str(), change(n2).c_str(), change(n3).c_str());
}
