//주차타워 층수마다 몇대 주차 가능한지 출력하기.
//층수를 받아서 층수마다 딱 몇 층만 출력하기 ex) 1층인 경우 1층만 출력하기
//주차타워 제작 중...
void parking_lot(int parking_answer) {
	int parking_lot[5][50] = { 0 }; //여기서 다시 초기화 해서 아래에서 값을 바꿔도 초기화가 되는 바람에 결국 값이 안바뀜
	int want_number_parking_floor;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 50; j++) {
			parking_lot[i][j] = j;
		}
	} //배열에 값 초기화 완료
	while (1)
	{
		if (parking_answer == 1) {
			printf("주차를 하고 싶은 층을 말해주세요 (1 ~ 5층 숫자만입력, 종료 : 6) : ");
			scanf_s("%d", &want_number_parking_floor);
			if (want_number_parking_floor <= 0 || want_number_parking_floor >= 7) { //예외 처리
				printf("층을 다시 입력해주세요\n\n");
				continue;
			}
			printf("\n");
			if (want_number_parking_floor == 6) {
				break;
			}
			printf("%d층\n", want_number_parking_floor);
			for (int j = 0; j < 50; j++) {
				if ((j + 1) / 10 == 0) {
					printf(" ");
				}
				printf("%d ", parking_lot[want_number_parking_floor - 1][j] + 1);
				if ((j + 1) % 5 == 0) {
					printf("\n");
				}
			}
			printf("\n");
			int want_number_parking_number;
			printf("주차 하고 싶은 자리를 골라주세요(0을 누르면 층을 다시 고를 수 있습니다) : "); //층 잘못골랐을 때 다시 고를 수 있게 함.
			scanf_s("%d", &want_number_parking_number); //이거 index번호 아니다. -1해서 사용해야함
			if (want_number_parking_number == 0) {
				continue;
			}
			while (1)
			{
				if (want_number_parking_number < 0 || want_number_parking_number > 50) {
					printf("번호를 다시 입력해주세요.\n");
					printf("주차 하고 싶은 자리를 골라주세요 : ");
					scanf_s("%d", &want_number_parking_number);
				}
				else {
					parking_lot[want_number_parking_floor - 1][want_number_parking_number - 1] = -1;
					break;
				}
			}
		}
	}
} //주차타워 제작 완료