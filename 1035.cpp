#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>

// 13:06-13:24 18 
using namespace std;

#define MAXN 1001

int n;

struct user{
	string name;
	string pwd;
}u[MAXN];

bool replace(string& pwd){
	bool flag = false;
	for(int i=0;i<pwd.length();i++){
		switch(pwd[i]){
			case '1':{
				pwd[i] = '@';
				flag = true;
				break;
			}
			case '0':{
				pwd[i] = '%';
				flag = true;
				break;
			}
			case 'l':{
				pwd[i] = 'L';
				flag = true;
				break;
			}
			case 'O':{
				pwd[i] = 'o';
				flag = true;
				break;
			}
			default:{
				break;
			}	
		}
	}
	return flag;
}

int main(){
	scanf("%d", &n);
	char name[100], pwd[100];
	for(int i=0;i<n;i++){
		scanf("%s %s", name, pwd);
		u[i] = {name, pwd};
	}
	vector<int> c_u;	
	for(int i=0;i<n;i++){
		if(replace(u[i].pwd)){
			c_u.push_back(i);
		}
	}
	if(c_u.size() == 0){
		if(n == 1){
			printf("There is 1 account and no account is modified\n");
		}else{
			printf("There are %d accounts and no account is modified\n", n);
		}
	}else{
		printf("%d\n", c_u.size());
		for(int i=0;i<c_u.size();i++){
			printf("%s %s\n", u[c_u[i]].name.data(), u[c_u[i]].pwd.data());
		} 
	} 
}
