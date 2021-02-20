#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
	int p = 0;
	scanf("%d", &p);
	int arr[6];//원래 순서대로 수가 들어갈 배열
	int bubble[6];//내림차순으로 수가 들어갈 배열
	int pa = p;
	
	for (int i = 5;i >=0;i--) {
		bubble[i] = pa / pow(10, i);
		pa = pa % (int)pow(10, i);
	}
	
	for(int i=0;i<n;i++) {
		arr[i]=bubble[i];
		for (int j = 0;j < n - i - 1;j++) {
			if (arr[j] < arr[j + 1]) {
				temp = bubble[j];
				bubble[j] = bubble[j + 1];
				bubble[j + 1] = temp;
			}
		}
			
	//내림차순으로 수가 배열되어있으면 0을 출력하고 exit
	int k=0;
	while(){
		if(arr[i]!=bubble[i])
			break;
		if(k==5){
			printf("0");
			exit(1);
		}
		k++;	
	}
		
	//뒷자리가 앞자리보다 크면 두 숫자를 바꾼 뒤, 나머지 숫자는 작은 숫자가 먼저 오게 배열한다.
	int temp;
	if(arr[0]>arr[1]){
		temp=arr[0];
		arr[0]=arr[1];
		arr[1]=temp;
		//버블정렬
		for(int i=2;i<n;i++) 
		for (int j = 0;j < n - i - 1;j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}else if(){//앞자리가 뒷자리보다 클때
		
	}
	
	
}
