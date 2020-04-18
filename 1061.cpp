#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

string s1, s2, s3, s4; 

string week[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int main(){
	char cs1[61], cs2[61], cs3[61], cs4[61];
	scanf("%s %s %s %s", cs1, cs2, cs3, cs4);
	s1 = cs1;
	s2 = cs2;
	s3 = cs3;
	s4 = cs4;
	int i=0;
	int len = min(s1.length(), s2.length());
	char c1, c2;
	for(i=0;i<len;i++){
		if(s1[i] == s2[i] && s1[i] >= 'A' && s1[i] <= 'G'){
			c1 = s1[i];
			break;
		}
	}
	i++;
	for(;i<len;i++){
		if(s1[i] == s2[i] && (s1[i] >= 'A' && s1[i] <= 'N' || isdigit(s1[i]))){
			c2 = s1[i];
			break;
		}
	}
	len = min(s3.length(), s4.length());
	for(i=0;i<len;i++){
		if(s3[i] == s4[i] && isalpha(s3[i])){
			break;
		}
	}
	printf("%s ", week[c1-'A'].c_str());
	if(isalpha(c2)){
		printf("%d:", c2-'A'+10);
	}else{
		printf("%02d:", c2-'0');
	}
	printf("%02d", i);
}
