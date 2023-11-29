#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void select_elemental(char** time_elemental) {
	char(*p)[9] = time_elemental; //배열 포인터에 저장 완료
	int want_time;
	int random;
	char select_time[10];
	char answer[4];
	char c;
	for (int i = 0; i < 9; i++) {
		//인덱스에 맞는 숫자부터 출력됨. 하지만 그 이후에 계속 나오고 한자가 나옴.
		//문자열에 띄어쓰기가 포함되어 있어서 그랬음. 왜 그러는지 질문
		printf("%d. %s\n", i + 1, p[i]); 
	}
	do {
		printf("위의 시간표에서 시간을 골라주세요(숫자 작성) : ");
		scanf_s("%d", &want_time);
		strcpy_s(select_time, sizeof(p[want_time]), p[want_time]); //select_time에 p[want_time]시간 대입.
		if (want_time <= 9 && want_time >= 1) {
			printf("%s이 선택한 시간이 맞습니까? (예, 아니오로 대답해주세요) : ", select_time);
			scanf_s("%s", answer, sizeof(answer)); //answer에 대답 저장 완료 하지만 엔터까지 answer 변수에 저장되는 듯. 이걸 해결해야 할 듯.
			while ((c = getchar()) != '\n' && c != EOF); //계행 문자 삭제
			if (strcmp(answer, "예") == 0) { //계행 문자가 포함되면서 오류 발생
				printf("%s으로 예매 완료 되었습니다. 시작 10분전에 입장해주세요.\n",select_time);
				break;
			}
			else if (strcmp(answer, "예") < 0 || strcmp(answer, "예") > 0) {
				printf("그렇다면 원하는 시간을 다시 골라주세요.\n");
				continue;
			}
			else {
				printf("답변을 다시 선택해주세요.\n");
			}
		}
	} while (answer != "예");
	//To do : do-while 부분을 함수화 해서 다른 영화에서도 쓸수있도록 만들기
}

void movie_theater() {
	int genre;
	char time_elemental[9][9] = { "10시20분", "11시00분" , "11시40분" , "12시40분" , "13시30분" , "14시20분" , "15시20분" , "16시10분" , "17시00분" };
	char time_frozen_kingdom[9][9] = { "10시30분", "11시10분" , "11시50분" , "12시50분" , "13시40분" , "14시30분" , "15시30분" , "16시20분" , "17시10분" };
	char time_minions[9][9] = { "10시40분", "11시10분" , "11시40분" , "12시50분" , "13시40분" , "14시20분" , "15시10분" , "16시20분" , "17시00분" };
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
	char time_elemental[9][9] = { "10시20분", "11시00분" , "11시40분" , "12시40분" , "13시30분" , "14시20분" , "15시20분" , "16시10분" , "17시00분" };
	char time_frozen_kingdom[9][9] = { "10시30분", "11시10분" , "11시50분" , "12시50분" , "13시40분" , "14시30분" , "15시30분" , "16시20분" , "17시10분" };
	char time_minions[9][9] = { "10시40분", "11시10분" , "11시40분" , "12시50분" , "13시40분" , "14시20분" , "15시10분" , "16시20분" , "17시00분" };
	select_elemental(time_elemental);
	return 0;
}