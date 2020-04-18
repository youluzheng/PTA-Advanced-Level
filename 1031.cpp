#include<cstdio>
#include<string>

using namespace std;

int main(){
	char str[100];
	scanf("%s", str);
	string s = str;
	int n1, n2, n3; 
	n2 = (s.length()+2)/3;
	if(n2 < 3){
		n2 = 3;
	}
	while(1){
		if(s.length()%2 == 1){
			if(n2%2 == 0){
				n2++;
			}
		}
		n1 = (s.length()-n2)/2+1;
		if(2*n1+n2-2 == s.length() && n1 <= n2){
			n3 = n1;
			break;
		}
		n2++;
	}
	string res;
	int i = 0;
	for(i=0;i<n1-1;i++){
		res += s.substr(i, 1) + string(n2-2, ' ') + s.substr(s.length()-i-1, 1) + "\n";
	}
	for(i=0;i<n2;i++){
		res += s[i+n1-1];
	}
	printf("%s", res.c_str());
}
