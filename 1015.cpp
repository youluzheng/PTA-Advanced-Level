#include<stdio.h>
#include<math.h>

int isPrime(int num){
	if(num < 2){
		return 0;
	}
	for(int i=2;i<=num/2;i++){
		if(num%i == 0){
			return 0;
		}
	}
	return 1;
}

int reverse(int num, int d, int &count){
	if(num < d){
		return num*pow(d, count++);
	}else{
		return reverse(num/d, d, count) + (num%d)*pow(d, count++);
	}
}

int main(){
	int order = 0;
	int num, d;
	while(1){
		order = 0;
		scanf("%d", &num);
		if(num < 0){
			break;
		}
		scanf("%d", &d);
		if(isPrime(num) && isPrime(reverse(num, d, order))){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
	return 0;	
}
