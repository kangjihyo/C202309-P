#include <stdio.h>

int main() {
	char purpose_to_here[100];
	//일단 나 멀티플렉스 건물이 아니라 복합쇼핑몰 이런식으로 이름 바꿔야할듯
	//쇼핑, 영화, 밥, 여가생활,  
	printf("이곳에 온 목적이 무엇입니까?(영화관, 쇼핑,  : ");
	scanf_s("%s", purpose_to_here, sizeof(purpose_to_here));

}