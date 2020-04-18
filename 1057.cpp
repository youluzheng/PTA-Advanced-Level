#include<cstdio>
#include<vector>
#include<string>
#include<stack>

using namespace std;

struct node{
	string command;
	int value;
	node(string command, int value){
		this->command = command;
		this->value = value;
	}
};

int n;

stack<int> s;
vector<node> coms;
int nums[100001];
int index, big, small;

int main(){
	scanf("%d", &n);
	char com[20];
	int value;
	for(int i=0;i<n;i++){
		scanf("%s", com);
		string command(com);
		if(command == "Push"){
			scanf("%d", &value);
		}
		coms.push_back(node(command, value));
	}
	
	for(int i=0;i<n;i++){
		node nod = coms[i];
		if(nod.command == "Push"){
			s.push(nod.value);
			nums[nod.value]++;
			if(s.size() == 1){
				index = nod.value;
				small = 0;
				big = 0;
			}
			if(index != nod.value){
				if(nod.value > index){
					big++;
					if(big > small+nums[index]){
						small += nums[index];
						for(int j=index+1;;j++){
							if(nums[j] != 0){
								big-=nums[j];
								index = j;
								break;
							}
						}
					}
				}else if(nod.value < index){
					small++;
					if(small >= big+nums[index]){
						big += nums[index];
						for(int j=index-1;;j--){
							if(nums[j] != 0){
								small-=nums[j];
								index = j;
								break;
							}
						}
					}
				}
			}	
		}else if(nod.command == "Pop"){
			if(s.size() == 0){
				printf("Invalid\n");
			}else{
				value = s.top();
				printf("%d\n", value);
				s.pop();
				nums[value]--;
				if(value > index){
					big--;
				}else if(value < index){
					small--;
				}
				if(small >= big + nums[index]){
					big += nums[index];
					for(int j=index-1;;j--){
						if(nums[j] != 0){
							small-=nums[j];
							index = j;
							break;
						}
					}
				}else if(big > small+nums[index]){
					small += nums[index];
					for(int j=index+1;;j++){
						if(nums[j] != 0){
							big-=nums[j];
							index = j;
							break;
						}
					}
				}
			}
		}else{
			if(s.size() == 0){
				printf("Invalid\n");
			}else{
				printf("%d\n", index);	
			}
		}
	}
}
