#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include<iostream> 

// 18:50 - 19:12
using namespace std;


int main(){
	char s1[100];
	char s2[100];
	scanf("%s %s", s1, s2);
	set<char> s_worn;
	vector<char> v_worn;
	int i=0, j=0;
	for(;s1[i]!='\0', s2[j]!='\0';){
		if(s1[i] == s2[j]){
			i++;
			j++; 
		}else{
			if(s_worn.count(toupper(s1[i])) == 0){
				s_worn.insert(toupper(s1[i]));
				v_worn.push_back(toupper(s1[i]));
			}
			i++;
		}
	}
	for(;s1[i] != '\0';i++){
		if(s_worn.count(toupper(s1[i])) == 0){
			s_worn.insert(toupper(s1[i]));
			v_worn.push_back(toupper(s1[i]));
		}
	}
	for(i=0;i<v_worn.size();i++){
		printf("%c", v_worn[i]);
	}
}
