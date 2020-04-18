#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include<iostream> 

// 20:46 - 21:18
using namespace std;

bool cmp(pair<int, double> a, pair<int, double> b){
	return a.second > b.second;
}

int main(){
	int n;
	double all;
	double sum = 0;
	vector<double> counts;
	vector<double> price;
	vector<pair<int, double> > preprice; 
	scanf("%d %lf", &n, &all);
	for(int i=0;i<n;i++){
		double count;
		scanf("%lf", &count);
		counts.push_back(count);
	}
	for(int i=0;i<n;i++){
		double p;
		scanf("%lf", &p);
		price.push_back(p);
		preprice.push_back(make_pair(i, p/counts[i]));
	}
	sort(preprice.begin(), preprice.end(), cmp);
	for(int i=0;i<preprice.size();i++){
		if(all >= counts[preprice[i].first]){
			sum += price[preprice[i].first];
			all -= counts[preprice[i].first];
		}else if(all == 0){
			break;
		}else{
			sum += (all/counts[preprice[i].first])*price[preprice[i].first];
			all = 0;
			break;
		}
	}
	printf("%.2f", sum);
}
