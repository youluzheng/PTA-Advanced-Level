#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

bool isPalindromicNumber(vector<string> res){
	vector<string> res1 = res;
	reverse(res1.begin(), res1.end());
	if(res1 == res){
		return true;
	}else{
		return false;
	}
}

void change(int num, int b){
	vector<string> res;
	while(num != 0){
		res.push_back(to_string(num%b));
		num /= b;
	}
	reverse(res.begin(), res.end());
	if(isPalindromicNumber(res)){
		printf("Yes\n");
	}else{
		printf("No\n");
	}
	int i = 0;
	for(i=0;i<res.size()-1;i++){
		printf("%s ", res[i].c_str());
	}
	printf("%s", res[i].c_str());
}

int main(){
	int num;
	int b;
	scanf("%d %d", &num, &b);
	if(num == 0){
		printf("Yes\n0");
		return 0;
	}
	change(num, b);
}
