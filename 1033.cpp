#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include<iostream> 

// 21:51 - 23:12
using namespace std;

struct station{
	double price;
	double distance;
	station(double price, double distance){
		this->price = price;
		this->distance = distance;
	}
};

double c, d, davg;
int n;
vector<station> s;

bool cmp(station a, station b){
	return a.distance < b.distance;
}

int main(){
	scanf("%lf %lf %lf %d", &c, &d, &davg, &n);
	for(int i=0;i<n;i++){
		double price, distance;
		scanf("%lf %lf", &price, &distance);
		s.push_back(station(price, distance));
	}
	s.push_back(station(0, d));
	n++;
	sort(s.begin(), s.end(), cmp);
	if(s[0].distance != 0){
		printf("The maximum travel distance = 0.00");
		return 0;
	}
	
	double sum = 0;
	double now_c = 0;
	
	int i = 0;
	int pos = 0;
	double dis = c*davg; //Ò»´Î×îÔ¶¾àÀë 
	while(1){
		int index = -1;
		double min_price = 0x7fffffff;
		for(i=pos+1;i<n && s[i].distance-s[pos].distance<=dis;i++){
			if(s[i].price < s[pos].price){
				index = i;
				break;
			}
			if(s[i].price < min_price){
				min_price = s[i].price;
				index = i;
			}
		}
		if(i == n){
			printf("%.2f", sum);
			break;
		}
		if(index == -1){
			printf("The maximum travel distance = %.2f", s[pos].distance + dis);
			return 0;
		}
		if(s[pos].price < s[index].price){
			double need = (s[index].distance - s[pos].distance) / davg;
			sum += (c - now_c)*s[pos].price;
			now_c = c - need;
		}else{
			double need = (s[index].distance - s[pos].distance) / davg;
			if(need > now_c){
				sum += (need - now_c) * s[pos].price;
			}
			now_c = 0;
		}
		pos = index;
	}
}
