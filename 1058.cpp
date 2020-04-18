#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<string>

using namespace std;

struct num{
	int n1;
	int n2;
	int n3;
	num(){
	}
	num(int n1, int n2, int n3){
		this->n1 = n1;
		this->n2 = n2;
		this->n3 = n3;
	}
};

num add(num a, num b){
	num c;
	int flag1 = 0, flag2 = 0;
	if(a.n3 + b.n3 >= 29){
		flag1 = 1;
	}
	c.n3 = (a.n3 + b.n3) % 29;
	if(a.n2 + b.n2 + flag1 < 17){
		flag2 = 0;
	}else{
		flag2 = 1;
	}
	c.n2 = (a.n2 + b.n2 + flag1) % 17;
	c.n1 = a.n1 + b.n1 + flag2;
	return c;
}

int n1, n2, n3;
int main(){
	scanf("%d.%d.%d", &n1, &n2, &n3);
	num a(n1, n2, n3);
	scanf("%d.%d.%d", &n1, &n2, &n3);
	num b(n1, n2, n3);
	num c = add(a, b);
	printf("%d.%d.%d", c.n1, c.n2, c.n3);
}
