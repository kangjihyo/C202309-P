#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "num1_function.h"
#include "num2_function.h"     
#include "num3_function.h"
//헤더파일을 통해 메인 C 파일 정리 완료

int main() {
	int purpose_to_here;
	int parking_answer;
	int place_matrix[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
	printf("이곳에 온 목적이 무엇입니까?\n 1. 영화관 2. 쇼핑(식자재, 의류) 3. 식당 4. 운동(헬스, 축구, 테니스) 5. 종료 : ");
	scanf_s("%d", &purpose_to_here);
	while (1) {
		if (purpose_to_here == 1) {
			movie_theater();
			printf("\n");
		}
		else if (purpose_to_here == 2) {
			shopping();
			printf("\n");
		}
		else if (purpose_to_here == 3) {
			cafeteria();
			printf("\n");
		}
		else if (purpose_to_here == 4) {
			exercise();
			printf("\n");
		}
		else if (purpose_to_here == 5) {
			printf("이용해주셔서 감사합니다.\n\n");
			break;
		}
		printf("이곳에 온 목적이 무엇입니까?\n 1. 영화관 2. 쇼핑(식자재, 의류) 3. 식당 4. 운동(헬스, 축구, 테니스) 5. 종료 : ");
		scanf_s("%d", &purpose_to_here);
	}
	while (1) {
		printf("주차 자리가 필요하십니까? 1. 예 2. 아니오 : ");
		scanf_s("%d", &parking_answer);
		if (parking_answer == 1) {
			parking_lot(parking_answer);
			break;

		}
		else if (parking_answer == 2) {
			break;
		}
		else {
			printf("잘못 입력하셨습니다. 다시 입력해주세요.\n");
		}
	}
	message_to_party(); //일행에게 메시지 전송
	return 0;
}