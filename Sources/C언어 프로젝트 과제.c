#include <stdio.h>

void elemental_time(char** time_elemental) {
	char(*p)[9] = time_elemental; //배열 포인터에 저장 완료
	int want_time;
	printf("어떤 시간대를 원하시나요?\n 1. 오전\n 2. 오후 : ");
	scanf_s("%d", &want_time);

}

int main() {
	int purpose_to_here;
	int place_matrix[3][3]= { {1,2,3},{4,5,6},{7,8,9} };
	//일단 나 멀티플렉스 건물이 아니라 복합문화공간 이런식으로 이름 바꿔야할듯
	//쇼핑, 영화, 밥, 여가생활,  
	printf("이곳에 온 목적이 무엇입니까?\n 1. 영화관, 쇼핑(식자재, 의류)\n 2. 식당\n 3. 운동(헬스, 축구, 테니스) : ");
	scanf_s("%d", &purpose_to_here);
	/*if (purpose_to_here == 1) {
		movie_theater();
	}*/
	char time_elemental[9][9] = { "10:20", "11:00" , "11:40" , "12:40" , "13:30" , "14:20" , "15:20" , "16:10" , "17:00" };
	char time_frozen_kingdom[9][9] = { "10:30", "11:10" , "11:50" , "12:50" , "13:40" , "14:30" , "15:30" , "16:20" , "17:10" };
	char time_minions[9][9] = { "10:40", "11:10" , "11:40" , "12:50" , "13:40" , "14:20" , "15:10" , "16:20" , "17:00" };

	return 0;
}

void movie_theater() {
	int genre;
	char time_elemental[9][9] = { "10:20", "11:00" , "11:40" , "12:40" , "13:30" , "14:20" , "15:20" , "16:10" , "17:00" };
	char time_frozen_kingdom[9][9] = { "10:30", "11:10" , "11:50" , "12:50" , "13:40" , "14:30" , "15:30" , "16:20" , "17:10" };
	char time_minions[9][9] = { "10:40", "11:10" , "11:40" , "12:50" , "13:40" , "14:20" , "15:10" , "16:20" , "17:00" };
	printf("보고싶은 장르를 골라주세요\n(1. 애니메이션\n 2. 히어로\n 3. 로맨스코미디 : ");
	scanf_s("%d", &genre);
	if (genre == 1) {
		int movie_number;
		printf("무엇을 보고 싶으신가요?\n(1. 엘리멘탈\n 2. 겨울왕국3\n 3. 미니언즈 : ");
		scanf_s("%d", &movie_number);
	}
}