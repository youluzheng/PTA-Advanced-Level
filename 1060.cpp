#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<string>
using namespace std;

#define MAXN 101
#define debug printf("-catch-\n");

struct fraction{
	string f;
	int index;
	fraction(char s[], int len){
		int pos = -1;
		int num = -1;
		int i = 0;
		for(i=0;s[i]!='\0';i++){
			if(num == -1 && s[i] != '0' && s[i] != '.'){
				num = i;
			}
			if(s[i] == '.'){
				pos = i;
			}
		}
		if(num == -1){
			f.append(len, '0');
			index = 0;
			return ;
		}
		if(pos != -1){
			if(pos < num){
				index = pos - num + 1;
			}else{
				index = pos - num;
			}
		}else{
			index = i - num;
		}
		f = s;
		if(pos != -1){
			f.erase(pos, 1);
			if(num > pos){
				num--;
			}
		}
		f = f.substr(num, f.length());
		if(f.length() < len){
			f.append(len-f.length(), '0');
		}else{
			f = f.substr(0, len);
		}
	}
};

void print(fraction f, int len) {
	printf("0.%s*10^%d", f.f.c_str(), f.index);
}

bool compare(fraction f1, fraction f2, int len){
	if(f1.index != f2.index){
		return false;
	}
	if(f1.f != f2.f){
		return false;
	}
	return true;
}

void toString(fraction f) {
	printf("f = %s, index = %d \n", f.f.c_str(), f.index);
}

bool cmp(char a, char b) {
	return a>b;
}

int main() {
	int n;
	char s1[MAXN], s2[MAXN];
	scanf("%d %s %s", &n, s1, s2);
	fraction f1(s1, n);
	fraction f2(s2, n);
	if(compare(f1, f2, n) == true){
		printf("YES ");
		print(f1, n);
	} else{
		printf("NO ");
		print(f1, n);
		printf(" ");
		print(f2, n);
	}
}
