#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

struct num{
	char c1;
	char n1;
	string n2;
	char c2;
	int n3;
};

num assign(string tar){
	num res;
	res.c1 = tar[0];
	res.n1 = tar[1];
	int index = tar.find('E');
	res.n2 = tar.substr(3, index-3);
	index++;
	res.c2 = tar[index];
	index++;
	sscanf(tar.data()+index, "%d", &res.n3);
	return res;
} 

int main(){
	char s[10000];
	scanf("%s", s);
	string tar = s;
	num n = assign(tar);
	if(n.c1 == '-'){
		printf("%c", n.c1);
	}
	string res = n.n1 + n.n2;
	if(n.n3 == 0){
		res.insert(1, ".");
		printf("%s", res.data());
		return 0;
	}
	if(n.c2 == '+'){
		if(n.n3<res.length()-1){
			res.insert(n.n3+1, ".");
		}else if(n.n3>res.length()-1){
			res+=string(n.n3-res.length()+1, '0');
		}
		printf("%s", res.data());
	}else{
		res.insert(0, n.n3-1, '0');
		res.insert(0, "0.");
		printf("%s", res.data());
	}
}
