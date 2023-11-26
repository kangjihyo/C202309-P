#include <stdio.h>

void select_elemental(char** time_elemental) {
	char(*p)[9] = time_elemental; //배열 포인터에 저장 완료
	int want_time;
	int random;
	char select_time;
	char answer;
	for (int i = 0; i < 9; i++) {
		printf("%d. %s\n", i + 1, p[i]);
	}
	printf("위의 시간표에서 시간을 골라주세요 : ");
	scanf_s("%d", &want_time);
	select_time = p[want_time];
	if (want_time <= 9 && want_time >= 1) {
		printf("%s가 선택한 시간이 맞습니까? (예, 아니오로 대답해주세요)", select_time);
		scanf_s("%s", &answer, sizeof(answer));
	}
	while (1) {
		if (answer == "예") {
			printf("%s으로 예매 완료 되었습니다. 시작 10분전에 입장해주세요.");
		}
		else if (answer == "아니오") {
			printf("그렇다면 원하는 시간을 다시 골라주세요.");
			select_elemental(time_elemental);
		}
		else {
			printf("답변을 다시 선택해주세요.");
		}
	}
}

void movie_theater() {
	int genre;
	char time_elemental[9][9] = { "10시 20분", "11시 00분" , "11시 40분" , "12시 40분" , "13시 30분" , "14시 20분" , "15시 20분" , "16시 10분" , "17시 00분" };
	char time_frozen_kingdom[9][9] = { "10시 30분", "11시 10분" , "11시 50분" , "12시 50분" , "13시 40분" , "14시 30분" , "15시 30분" , "16시 20분" , "17시 10분" };
	char time_minions[9][9] = { "10시 40분", "11시 10분" , "11시 40분" , "12시 50분" , "13시 40분" , "14시 20분" , "15시 10분" , "16시 20분" , "17시 00분" };
	printf("보고싶은 장르를 골라주세요\n(1. 애니메이션\n 2. 히어로\n 3. 로맨스코미디 : ");
	scanf_s("%d", &genre);
	if (genre == 1) {
		int movie_number;
		printf("무엇을 보고 싶으신가요?\n(1. 엘리멘탈\n 2. 겨울왕국3\n 3. 미니언즈 : ");
		scanf_s("%d", &movie_number);
	}
	select_elemental(time_elemental);
}

int main() {
	int purpose_to_here;
	int place_matrix[3][3]= { {1,2,3},{4,5,6},{7,8,9} }; 
	printf("이곳에 온 목적이 무엇입니까?\n 1. 영화관, 쇼핑(식자재, 의류)\n 2. 식당\n 3. 운동(헬스, 축구, 테니스) : ");
	scanf_s("%d", &purpose_to_here);
	/*if (purpose_to_here == 1) {
		movie_theater();
	}*/
	char time_elemental[9][9] = { "10시 20분", "11시 00분" , "11시 40분" , "12시 40분" , "13시 30분" , "14시 20분" , "15시 20분" , "16시 10분" , "17시 00분" };
	char time_frozen_kingdom[9][9] = { "10시 30분", "11시 10분" , "11시 50분" , "12시 50분" , "13시 40분" , "14시 30분" , "15시 30분" , "16시 20분" , "17시 10분" };
	char time_minions[9][9] = { "10시 40분", "11시 10분" , "11시 40분" , "12시 50분" , "13시 40분" , "14시 20분" , "15시 10분" , "16시 20분" , "17시 00분" };
	select_elemental(time_elemental);
	return 0;
}