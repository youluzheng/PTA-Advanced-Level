#include<cstdio>
#include<vector>
#include<string>

using namespace std;

int n;
int order[55];
vector<string> cards;

void init_cares(){
	cards.push_back(""); //ռλ 
	for(int i=1;i<=13;i++){
		cards.push_back("S"+to_string(i));
	}
	for(int i=1;i<=13;i++){
		cards.push_back("H"+to_string(i));
	}
	for(int i=1;i<=13;i++){
		cards.push_back("C"+to_string(i));
	}
	for(int i=1;i<=13;i++){
		cards.push_back("D"+to_string(i));
	}
	cards.push_back("J1"); 
	cards.push_back("J2"); 
}

void shuffling(){
	vector<string> temp(55, "");
	for(int i=1;i<=54;i++){
		temp[order[i]] = cards[i];
	}
	cards = temp;
}

int main(){
	init_cares();
	scanf("%d", &n);
	for(int i=1;i<=54;i++){
		scanf("%d", &order[i]);
	}
	for(int i=0;i<n;i++){
		shuffling();
	}
	for(int i=1;i<54;i++){
		printf("%s ", cards[i].c_str());
	}
	printf("%s", cards[54].c_str());
}
