#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//1번 함수 만들기 시작
void select_movie_time(char** time_movie, int want_time, char* select_time) { //select_movie의 세부 함수
	char(*p)[9] = time_movie;
	char answer[10];
	char c;
	do {
		if (want_time <= 9 && want_time >= 1) {
			printf("%s이 선택한 시간이 맞습니까? (예, 아니오로 대답해주세요) : ", select_time);
			scanf_s("%s", answer, sizeof(answer)); //answer에 대답 저장 완료 하지만 엔터까지 answer 변수에 저장되는 듯. 이걸 해결해야 할 듯.
			while ((c = getchar()) != '\n' && c != EOF); //계행 문자 삭제
			if (strcmp(answer, "예") == 0) { //계행 문자가 포함되면서 오류 발생
				printf("%s으로 예매 완료 되었습니다. 시작 10분전에 입장해주세요.\n", select_time);
				break;
			}
			else if (strcmp(answer, "아니오") == 0) {
				printf("그렇다면 원하는 시간을 다시 골라주세요.\n");
				printf("위의 시간표에서 시간을 골라주세요(숫자 작성) : ");
				scanf_s("%d", &want_time);
				strcpy_s(select_time, sizeof(p[want_time - 1]), p[want_time - 1]); //select_time에 p[want_time]시간 대입.
				continue;
			}
			else {
				printf("답변을 다시 선택해주세요.\n");
			}
		}
	} while (answer != "예");
}

void select_movie(char** time_movie) { //함수화 시켜서 하나로 다 사용하기. movie_theater의 세부 함수
	char(*p)[9] = time_movie; //배열 포인터에 저장 완료
	int want_time;
	int random;
	char select_time[10];
	char answer[10];
	char c;
	for (int i = 0; i < 9; i++) {
		//인덱스에 맞는 숫자부터 출력됨. 하지만 그 이후에 계속 나오고 한자가 나옴.
		//문자열에 띄어쓰기가 포함되어 있어서 그랬음. 왜 그러는지 질문
		printf("%d. %s\n", i + 1, p[i]);
	}
	printf("위의 시간표에서 시간을 골라주세요(숫자 작성) : ");
	scanf_s("%d", &want_time);
	strcpy_s(select_time, sizeof(p[want_time - 1]), p[want_time - 1]); //select_time에 p[want_time]시간 대입.
	select_movie_time(time_movie, want_time, select_time);
}

void movie_theater() { // 영화를 선택했을 시의 메인이 되는 함수.
	int genre;
	char time_elemental[9][9] = { "10시20분", "11시00분" , "11시40분" , "12시40분" , "13시30분" , "14시20분" , "15시20분" , "16시10분" , "17시00분" };
	char time_frozen_kingdom[9][9] = { "10시30분", "11시10분" , "11시50분" , "12시50분" , "13시40분" , "14시30분" , "15시30분" , "16시20분" , "17시10분" };
	char time_minions[9][9] = { "10시40분", "11시10분" , "11시40분" , "12시50분" , "13시40분" , "14시20분" , "15시10분" , "16시20분" , "17시00분" };
	char time_avengers_endgame[9][9] = { "10시20분", "11시00분" , "11시40분" , "12시40분" , "13시30분" , "14시20분" , "15시20분" , "16시10분" , "17시00분" };
	char time_guardians_of_galaxy[9][9] = { "10시30분", "11시10분" , "11시50분" , "12시50분" , "13시40분" , "14시30분" , "15시30분" , "16시20분" , "17시10분" };
	char time_batman[9][9] = { "10시40분", "11시10분" , "11시40분" , "12시50분" , "13시40분" , "14시20분" , "15시10분" , "16시20분" , "17시00분" };
	char time_captain_america_winter_soldier[9][9] = { "10시20분", "11시00분" , "11시40분" , "12시40분" , "13시30분" , "14시20분" , "15시20분" , "16시10분" , "17시00분" };
	char time_the_roundup[9][9] = { "10시30분", "11시10분" , "11시50분" , "12시50분" , "13시40분" , "14시30분" , "15시30분" , "16시20분" , "17시10분" };
	char time_kingsman[9][9] = {"10시40분", "11시10분" , "11시40분" , "12시50분" , "13시40분" , "14시20분" , "15시10분" , "16시20분" , "17시00분"};
	while (1) {
		printf("보고싶은 장르를 골라주세요\n 1. 애니메이션\n 2. 히어로\n 3. 액션 \n 4. 종료: ");
		scanf_s("%d", &genre);
		if (genre == 4) {
			break;
		}
		while (1) {
			if (genre == 1) {
				int movie_number;
				printf("무엇을 보고 싶으신가요?\n 1. 엘리멘탈\n 2. 겨울왕국3\n 3. 미니언즈 : ");
				scanf_s("%d", &movie_number);
				printf("\n");
				if (movie_number == 1) {
					select_movie(time_elemental);
					break;
				}
				else if (movie_number == 2) {
					select_movie(time_frozen_kingdom);
					break;
				}
				else if (movie_number == 3) {
					select_movie(time_minions);
					break;
				}
				else {
					printf("다시 선택해주세요.");
				}
			}
			else if (genre == 2) {
				int movie_number;
				printf("무엇을 보고 싶으신가요?\n 1. 어벤져스 엔드게임\n 2. 가디언즈 오브 갤럭시 3\n 3. 배트맨 : ");
				scanf_s("%d", &movie_number);
				printf("\n");
				if (movie_number == 1) {
					select_movie(time_avengers_endgame);
					break;
				}
				else if (movie_number == 2) {
					select_movie(time_guardians_of_galaxy);
					break;
				}
				else if (movie_number == 3) {
					select_movie(time_batman);
					break;
				}
				else {
					printf("다시 선택해주세요.");
				}
			}
			else if (genre == 3) {
				int movie_number;
				printf("무엇을 보고 싶으신가요?\n 1. 캡틴 아메리카 윈터솔져\n 2. 범죄도시2\n 3. 킹스맨 : ");
				scanf_s("%d", &movie_number);
				printf("\n");
				if (movie_number == 1) {
					select_movie(time_captain_america_winter_soldier);
					break;
				}
				else if (movie_number == 2) {
					select_movie(time_the_roundup);
					break;
				}
				else if (movie_number == 3) {
					select_movie(time_kingsman);
					break;
				}
				else {
					printf("다시 선택해주세요.");
				}
			}
		}
	}
}
//1번 함수 만들기 끝

//2번 함수 만들기 시작
void shopping() {
	int purpose_shopping;
	char market_place[9][9] = { "나이키", "스파이더", "8seconds", "MLB", "FILA", "유니클로","스투시", "무신사", "아디다스" };
	char clothes_brand[9][9] = { "스파이더","나이키","아디다스","MLB","8seconds","유니클로","FILA","무신사","스투시" };
	char Luxury_brand[9][20] = { "CHANEL","DIOR","BALENCIAGA","GUCCI","Yves Saint Laurent","PRADA","Louis Vuitton","Hermes","Burberry" };
	char(*p)[9] = clothes_brand;
	char(*q)[20] = Luxury_brand;
	char brand_name[20];
	int brand_number;
	int j;
	printf("쇼핑할 품목이 무엇인가요?\n 1. 식자재 2. 의류 3. 명품 4. 종료: ");
	scanf_s("%d", &purpose_shopping);
	while (1) {
		if (purpose_shopping == 1) {
			printf("지하 1층에 이마트가 있습니다.\n\n");
		}
		else if (purpose_shopping == 2) {
			printf("어떤 브랜드를 원하십니까?\n 1. 스파이더 2. 나이키 3. 아디다스 4. MLB 5. 8seconds 6. 유니클로 7. FILA 8. 무신사 9. 스투시 : ");
			scanf_s("%d", &brand_number);
			strcpy_s(brand_name, sizeof(brand_name), p[brand_number - 1]);
			for (int i = 0; i <= 8; i++) {
				printf("%d. %s", i + 1, p[i]);
				if (i != 2 || i != 5) {
					printf("\t");
				}
				if (i == 3 || i == 6) {
					printf("\t");
				}
				if (i == 2 || i == 5) {
					printf("\n");
				}
			}
			printf("\n");
			printf("%s는 위의 표의 %d번에 있습니다.\n\n", brand_name, brand_number);
		}
		else if (purpose_shopping == 3) {
			printf("어떤 브랜드를 원하십니까?\n 1. CHANEL 2. DIOR 3. BALENCIAGA 4. GUCCI 5. Yves Saint Laurent 6. PRADA 7. Louis Vuitton 8. Hermes 9. Burberry : ");
			scanf_s("%d", &brand_number);
			strcpy_s(brand_name, sizeof(brand_name), q[brand_number - 1]);
			for (int i = 0; i <= 8; i++) {
				printf("%d. %s", i + 1, q[i]); //3,5,7번 입력시 오류
				if (i == 0) { //왜 i==1으로만 설정했을땐 되면서 i==0을 위에 설정하면 왜 i==1일때 탭이 안될까..?
					printf("\t");
				}
				if (i == 1) {
					printf("\t");
				}
				if (i == 2 || i == 5) {
					printf("\n");
				}
			}
			printf("\n");
			printf("%s는 위의 표의 %d번에 있습니다.\n\n", brand_name, brand_number);
		}
		else if (purpose_shopping == 4) {
			break;
		}
		printf("쇼핑할 품목이 무엇인가요?\n 1. 식자재 2. 의류 3. 명품 4. 종료: ");
		scanf_s("%d", &purpose_shopping);
	}
}
//2번 함수 만들기 끝.
//나중에 모든 매장의 위치를 저장한 후에 위치를 알려주는 함수를 만드는 것도 좋을듯.

//3번 함수 만들기 시작
typedef struct Korean_Food_price {
	char food_name[3][10];
	int food_price[3];
}Kfood_price;

typedef struct Japanese_Food_price {
	char food_name[3][10];
	int food_price[3];
}Jfood_price;

typedef struct Chinese_Food_price {
	char food_name[3][10];
	int food_price[3];
}Cfood_price;

void select_korean_menu(Kfood_price food, int yes_or_no, int food_number) {
	do {
		if (yes_or_no == 1) {
			printf("%s %d원입니다.\n", food.food_name[food_number - 1], food.food_price[food_number - 1]);
			break;
		}
		else if (yes_or_no == 2) {
			printf("그렇다면 메뉴를 다시 골라주세요.\n");
			for (int i = 0; i < 3; i++) {
				printf("%d. %s - %d원 ", i + 1, food.food_name[i], food.food_price[i]);
			}
			printf("\n");
			printf("위의 메뉴에서 하나 골라주세요 : ");
			scanf_s("%d", &food_number);
			printf("고르신 메뉴가 %s(이)가 맞습니까?\t 1. 예 2. 아니오 : ", food.food_name[food_number - 1]);
			scanf_s("%d", &yes_or_no);
			continue;
		}
		else {
			printf("잘못된 입력입니다. 다시 입력해주세요.\n");
			printf("고르신 메뉴가 %s(이)가 맞습니까? 1. 예 2. 아니오 : ", food.food_name[food_number - 1]);
			scanf_s("%d", &yes_or_no);
			continue;
		}
	} while (1);
}
void select_japanese_menu(Jfood_price food, int yes_or_no, int food_number) {
	do {
		if (yes_or_no == 1) {
			printf("%s %d원입니다.\n", food.food_name[food_number - 1], food.food_price[food_number - 1]);
			break;
		}
		else if (yes_or_no == 2) {
			printf("그렇다면 메뉴를 다시 골라주세요.\n");
			for (int i = 0; i < 3; i++) {
				printf("%d. %s - %d원 ", i + 1, food.food_name[i], food.food_price[i]);
			}
			printf("\n");
			printf("위의 메뉴에서 하나 골라주세요 : ");
			scanf_s("%d", &food_number);
			printf("고르신 메뉴가 %s(이)가 맞습니까?\t 1. 예 2. 아니오 : ", food.food_name[food_number - 1]);
			scanf_s("%d", &yes_or_no);
			continue;
		}
		else {
			printf("잘못된 입력입니다. 다시 입력해주세요.\n");
			printf("고르신 메뉴가 %s(이)가 맞습니까?\t 1. 예 2. 아니오 : ", food.food_name[food_number - 1]);
			scanf_s("%d", &yes_or_no);
		}
	} while (1);
}
void select_chinese_menu(Cfood_price food, int yes_or_no, int food_number) {
	do {
		if (yes_or_no == 1) {
			printf("%s %d원입니다.\n", food.food_name[food_number - 1], food.food_price[food_number - 1]);
			break;
		}
		else if (yes_or_no == 2) {
			printf("그렇다면 메뉴를 다시 골라주세요.\n");
			for (int i = 0; i < 3; i++) {
				printf("%d. %s - %d원 ", i + 1, food.food_name[i], food.food_price[i]);
			}
			printf("\n");
			printf("위의 메뉴에서 하나 골라주세요 : ");
			scanf_s("%d", &food_number);
			printf("고르신 메뉴가 %s(이)가 맞습니까?\t 1. 예 2. 아니오 : ", food.food_name[food_number - 1]);
			scanf_s("%d", &yes_or_no);
			continue;
		}
		else {
			printf("잘못된 입력입니다. 다시 입력해주세요.\n");
			printf("고르신 메뉴가 %s(이)가 맞습니까?\t 1. 예 2. 아니오 : ", food.food_name[food_number - 1]);
			scanf_s("%d", &yes_or_no);
		}
	} while (1);
}

void cafeteria() {
	//구조체에 값 저장완료
	Kfood_price kfood = { {{"제육볶음\0"},{"김치찌개"},{"돌솥비빔밥"}}, {7000,6000,6000} };
	Jfood_price jfood = { {"등심카츠","마제소바","모듬초밥"}, {9000,9000,15000} };
	Cfood_price cfood = { {"짜장면", "짬뽕","탕수육(소)"}, {5000, 7000, 10000} };
	int kind_of_food;
	printf("어떤 종류의 음식을 드시고 싶으신가요?\n 1. 한식 2. 일식 3. 중식 :  ");
	scanf_s("%d", &kind_of_food);
	int food_number;
	int yes_or_no;
	if (kind_of_food == 1) {
		for (int i = 0; i < 3; i++) {
			printf("%d. %s - %d원 ", i + 1, kfood.food_name[i], kfood.food_price[i]);
		}
		printf("\n");
		printf("위의 메뉴에서 하나 골라주세요 : ");
		scanf_s("%d", &food_number);
		printf("고르신 메뉴가 %s(이)가 맞습니까?\t 1. 예 2. 아니오 : ", kfood.food_name[food_number - 1]);
		scanf_s("%d", &yes_or_no);
		select_korean_menu(kfood, yes_or_no, food_number);
	}
	if (kind_of_food == 2) {
		for (int i = 0; i < 3; i++) {
			printf("%d. %s - %d원 ", i + 1, jfood.food_name[i], jfood.food_price[i]);
		}
		printf("\n");
		printf("위의 메뉴에서 하나 골라주세요 : ");
		scanf_s("%d", &food_number);
		printf("고르신 메뉴가 %s(이)가 맞습니까?\t 1. 예 2. 아니오 : ", jfood.food_name[food_number - 1]);
		scanf_s("%d", &yes_or_no);
		select_japanese_menu(jfood, yes_or_no, food_number);
	}
	if (kind_of_food == 3) {
		for (int i = 0; i < 3; i++) {
			printf("%d. %s - %d원 ", i + 1, cfood.food_name[i], cfood.food_price[i]);
		}
		printf("\n");
		printf("위의 메뉴에서 하나 골라주세요 : ");
		scanf_s("%d", &food_number);
		printf("고르신 메뉴가 %s(이)가 맞습니까?\t 1. 예 2. 아니오 : ", cfood.food_name[food_number - 1]);
		scanf_s("%d", &yes_or_no);
		select_chinese_menu(cfood, yes_or_no, food_number);
	}
}
//3번 함수 만들기 끝.

//4번 함수 만들기 시작
typedef struct exercise_kind {
	char type[3][10];
	char exercise_place[3][10];
	char* place[3];
}Exerkind;

//구조체 초기화 함수
void initialize(Exerkind* exercise_kind) {
	const char* exerciseType[3] = { "헬스", "축구", "테니스" };
	const char* exercisePlace[3] = { "헬스장", "축구","테니스" };
	for (int i = 0; i < 3; i++) {
		strcpy_s(exercise_kind->type[i], sizeof(exercise_kind->type[i]), exerciseType[i]);
		strcpy_s(exercise_kind->exercise_place[i], sizeof(exercise_kind->exercise_place[i]), exercisePlace[i]);
		exercise_kind->type[i][9] = "\0";
		exercise_kind->exercise_place[i][9] = "\0";
	}

}
void exercise() {
	Exerkind exercise_kind;
	initialize(&exercise_kind);
	int place_number;
	char c;
	char* place_name = (char*)malloc(sizeof(char) * strlen(exercise_kind.exercise_place[2]));
	//각 장소의 주소 저장 완료
	for (int i = 0; i < 3; i++) {
		exercise_kind.place[i] = &exercise_kind.exercise_place[i];
	}
	printf("하고자 하는 운동이 무엇인가요? : ");
	scanf_s("%s", place_name, sizeof(place_name));
	while ((c = getchar()) != '\n' && c != EOF);
	if (strcmp(place_name,"헬스") == 0) {
		printf("%s은 %x위치에 있습니다.\n", exercise_kind.exercise_place[0], exercise_kind.place[0]);
	}
	if (strcmp(place_name, "축구") == 0) {
		printf("%s은 %x위치에 있습니다.\n", exercise_kind.exercise_place[1], exercise_kind.place[1]);
	}
	if (strcmp(place_name, "테니스") == 0) {
		printf("%s는 %x위치에 있습니다.\n", exercise_kind.exercise_place[2], exercise_kind.place[2]);
	}
	free(place_name); //이렇게 하니까 오류나는데..?
}
//To_do 하고자 하는 운동 잘 못 입력했을 때 예외처리, 동적 메모리 할당한거 free로 해제해야하는데 오류남 그거 해결
int main() {
	int purpose_to_here;
	int place_matrix[3][3]= { {1,2,3},{4,5,6},{7,8,9} }; 
	printf("이곳에 온 목적이 무엇입니까?\n 1. 영화관 2. 쇼핑(식자재, 의류) 3. 식당 4. 운동(헬스, 축구, 테니스) 5. 종료 : ");
	scanf_s("%d", &purpose_to_here);
	while (1) {
		if (purpose_to_here == 1) {
			movie_theater();
		}
		else if (purpose_to_here == 2) {
			shopping();
		}
		else if (purpose_to_here == 3) {
			cafeteria();
		}
		else if (purpose_to_here == 4) {
			exercise();
		}
		else if (purpose_to_here == 5) {
			break;
		}
		printf("이곳에 온 목적이 무엇입니까?\n 1. 영화관 2. 쇼핑(식자재, 의류) 3. 식당 4. 운동(헬스, 축구, 테니스) 5. 종료 : ");
		scanf_s("%d", &purpose_to_here);
	}
	return 0;
}