#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//1�� �Լ� ����� ����
void select_movie_time(char** time_movie, int want_time, char* select_time) { //select_movie�� ���� �Լ�
	char(*p)[9] = time_movie;
	char answer[10];
	char c;
	do {
		if (want_time <= 9 && want_time >= 1) {
			printf("%s�� ������ �ð��� �½��ϱ�? (��, �ƴϿ��� ������ּ���) : ", select_time);
			scanf_s("%s", answer, sizeof(answer)); //answer�� ��� ���� �Ϸ� ������ ���ͱ��� answer ������ ����Ǵ� ��. �̰� �ذ��ؾ� �� ��.
			while ((c = getchar()) != '\n' && c != EOF); //���� ���� ����
			if (strcmp(answer, "��") == 0) { //���� ���ڰ� ���ԵǸ鼭 ���� �߻�
				printf("%s���� ���� �Ϸ� �Ǿ����ϴ�. ���� 10������ �������ּ���.\n", select_time);
				break;
			}
			else if (strcmp(answer, "�ƴϿ�") == 0) {
				printf("�׷��ٸ� ���ϴ� �ð��� �ٽ� ����ּ���.\n");
				printf("���� �ð�ǥ���� �ð��� ����ּ���(���� �ۼ�) : ");
				scanf_s("%d", &want_time);
				strcpy_s(select_time, sizeof(p[want_time - 1]), p[want_time - 1]); //select_time�� p[want_time]�ð� ����.
				continue;
			}
			else {
				printf("�亯�� �ٽ� �������ּ���.\n");
			}
		}
	} while (answer != "��");
}

void select_movie(char** time_movie) { //�Լ�ȭ ���Ѽ� �ϳ��� �� ����ϱ�. movie_theater�� ���� �Լ�
	char(*p)[9] = time_movie; //�迭 �����Ϳ� ���� �Ϸ�
	int want_time;
	int random;
	char select_time[10];
	char answer[10];
	char c;
	for (int i = 0; i < 9; i++) {
		//�ε����� �´� ���ں��� ��µ�. ������ �� ���Ŀ� ��� ������ ���ڰ� ����.
		//���ڿ��� ���Ⱑ ���ԵǾ� �־ �׷���. �� �׷����� ����
		printf("%d. %s\n", i + 1, p[i]);
	}
	printf("���� �ð�ǥ���� �ð��� ����ּ���(���� �ۼ�) : ");
	scanf_s("%d", &want_time);
	strcpy_s(select_time, sizeof(p[want_time - 1]), p[want_time - 1]); //select_time�� p[want_time]�ð� ����.
	select_movie_time(time_movie, want_time, select_time);
}

void movie_theater() { // ��ȭ�� �������� ���� ������ �Ǵ� �Լ�.
	int genre;
	char time_elemental[9][9] = { "10��20��", "11��00��" , "11��40��" , "12��40��" , "13��30��" , "14��20��" , "15��20��" , "16��10��" , "17��00��" };
	char time_frozen_kingdom[9][9] = { "10��30��", "11��10��" , "11��50��" , "12��50��" , "13��40��" , "14��30��" , "15��30��" , "16��20��" , "17��10��" };
	char time_minions[9][9] = { "10��40��", "11��10��" , "11��40��" , "12��50��" , "13��40��" , "14��20��" , "15��10��" , "16��20��" , "17��00��" };
	char time_avengers_endgame[9][9] = { "10��20��", "11��00��" , "11��40��" , "12��40��" , "13��30��" , "14��20��" , "15��20��" , "16��10��" , "17��00��" };
	char time_guardians_of_galaxy[9][9] = { "10��30��", "11��10��" , "11��50��" , "12��50��" , "13��40��" , "14��30��" , "15��30��" , "16��20��" , "17��10��" };
	char time_batman[9][9] = { "10��40��", "11��10��" , "11��40��" , "12��50��" , "13��40��" , "14��20��" , "15��10��" , "16��20��" , "17��00��" };
	char time_captain_america_winter_soldier[9][9] = { "10��20��", "11��00��" , "11��40��" , "12��40��" , "13��30��" , "14��20��" , "15��20��" , "16��10��" , "17��00��" };
	char time_the_roundup[9][9] = { "10��30��", "11��10��" , "11��50��" , "12��50��" , "13��40��" , "14��30��" , "15��30��" , "16��20��" , "17��10��" };
	char time_kingsman[9][9] = {"10��40��", "11��10��" , "11��40��" , "12��50��" , "13��40��" , "14��20��" , "15��10��" , "16��20��" , "17��00��"};
	while (1) {
		printf("������� �帣�� ����ּ���\n 1. �ִϸ��̼�\n 2. �����\n 3. �׼� \n 4. ����: ");
		scanf_s("%d", &genre);
		if (genre == 4) {
			break;
		}
		while (1) {
			if (genre == 1) {
				int movie_number;
				printf("������ ���� �����Ű���?\n 1. ������Ż\n 2. �ܿ�ձ�3\n 3. �̴Ͼ��� : ");
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
					printf("�ٽ� �������ּ���.");
				}
			}
			else if (genre == 2) {
				int movie_number;
				printf("������ ���� �����Ű���?\n 1. ����� �������\n 2. ������� ���� ������ 3\n 3. ��Ʈ�� : ");
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
					printf("�ٽ� �������ּ���.");
				}
			}
			else if (genre == 3) {
				int movie_number;
				printf("������ ���� �����Ű���?\n 1. ĸƾ �Ƹ޸�ī ���ͼ���\n 2. ���˵���2\n 3. ŷ���� : ");
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
					printf("�ٽ� �������ּ���.");
				}
			}
		}
	}
}
//1�� �Լ� ����� ��

//2�� �Լ� ����� ����
void shopping() {
	int purpose_shopping;
	char market_place[9][9] = { "����Ű", "�����̴�", "8seconds", "MLB", "FILA", "����Ŭ��","������", "���Ż�", "�Ƶ�ٽ�" };
	char clothes_brand[9][9] = { "�����̴�","����Ű","�Ƶ�ٽ�","MLB","8seconds","����Ŭ��","FILA","���Ż�","������" };
	char Luxury_brand[9][20] = { "CHANEL","DIOR","BALENCIAGA","GUCCI","Yves Saint Laurent","PRADA","Louis Vuitton","Hermes","Burberry" };
	char(*p)[9] = clothes_brand;
	char(*q)[20] = Luxury_brand;
	char brand_name[20];
	int brand_number;
	int j;
	printf("������ ǰ���� �����ΰ���?\n 1. ������ 2. �Ƿ� 3. ��ǰ 4. ����: ");
	scanf_s("%d", &purpose_shopping);
	while (1) {
		if (purpose_shopping == 1) {
			printf("���� 1���� �̸�Ʈ�� �ֽ��ϴ�.\n\n");
		}
		else if (purpose_shopping == 2) {
			printf("� �귣�带 ���Ͻʴϱ�?\n 1. �����̴� 2. ����Ű 3. �Ƶ�ٽ� 4. MLB 5. 8seconds 6. ����Ŭ�� 7. FILA 8. ���Ż� 9. ������ : ");
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
			printf("%s�� ���� ǥ�� %d���� �ֽ��ϴ�.\n\n", brand_name, brand_number);
		}
		else if (purpose_shopping == 3) {
			printf("� �귣�带 ���Ͻʴϱ�?\n 1. CHANEL 2. DIOR 3. BALENCIAGA 4. GUCCI 5. Yves Saint Laurent 6. PRADA 7. Louis Vuitton 8. Hermes 9. Burberry : ");
			scanf_s("%d", &brand_number);
			strcpy_s(brand_name, sizeof(brand_name), q[brand_number - 1]);
			for (int i = 0; i <= 8; i++) {
				printf("%d. %s", i + 1, q[i]); //3,5,7�� �Է½� ����
				if (i == 0) { //�� i==1���θ� ���������� �Ǹ鼭 i==0�� ���� �����ϸ� �� i==1�϶� ���� �ȵɱ�..?
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
			printf("%s�� ���� ǥ�� %d���� �ֽ��ϴ�.\n\n", brand_name, brand_number);
		}
		else if (purpose_shopping == 4) {
			break;
		}
		printf("������ ǰ���� �����ΰ���?\n 1. ������ 2. �Ƿ� 3. ��ǰ 4. ����: ");
		scanf_s("%d", &purpose_shopping);
	}
}
//2�� �Լ� ����� ��.
//���߿� ��� ������ ��ġ�� ������ �Ŀ� ��ġ�� �˷��ִ� �Լ��� ����� �͵� ������.

//3�� �Լ� ����� ����
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
			printf("%s %d���Դϴ�.\n", food.food_name[food_number - 1], food.food_price[food_number - 1]);
			break;
		}
		else if (yes_or_no == 2) {
			printf("�׷��ٸ� �޴��� �ٽ� ����ּ���.\n");
			for (int i = 0; i < 3; i++) {
				printf("%d. %s - %d�� ", i + 1, food.food_name[i], food.food_price[i]);
			}
			printf("\n");
			printf("���� �޴����� �ϳ� ����ּ��� : ");
			scanf_s("%d", &food_number);
			printf("���� �޴��� %s(��)�� �½��ϱ�?\t 1. �� 2. �ƴϿ� : ", food.food_name[food_number - 1]);
			scanf_s("%d", &yes_or_no);
			continue;
		}
		else {
			printf("�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���.\n");
			printf("���� �޴��� %s(��)�� �½��ϱ�? 1. �� 2. �ƴϿ� : ", food.food_name[food_number - 1]);
			scanf_s("%d", &yes_or_no);
			continue;
		}
	} while (1);
}
void select_japanese_menu(Jfood_price food, int yes_or_no, int food_number) {
	do {
		if (yes_or_no == 1) {
			printf("%s %d���Դϴ�.\n", food.food_name[food_number - 1], food.food_price[food_number - 1]);
			break;
		}
		else if (yes_or_no == 2) {
			printf("�׷��ٸ� �޴��� �ٽ� ����ּ���.\n");
			for (int i = 0; i < 3; i++) {
				printf("%d. %s - %d�� ", i + 1, food.food_name[i], food.food_price[i]);
			}
			printf("\n");
			printf("���� �޴����� �ϳ� ����ּ��� : ");
			scanf_s("%d", &food_number);
			printf("���� �޴��� %s(��)�� �½��ϱ�?\t 1. �� 2. �ƴϿ� : ", food.food_name[food_number - 1]);
			scanf_s("%d", &yes_or_no);
			continue;
		}
		else {
			printf("�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���.\n");
			printf("���� �޴��� %s(��)�� �½��ϱ�?\t 1. �� 2. �ƴϿ� : ", food.food_name[food_number - 1]);
			scanf_s("%d", &yes_or_no);
		}
	} while (1);
}
void select_chinese_menu(Cfood_price food, int yes_or_no, int food_number) {
	do {
		if (yes_or_no == 1) {
			printf("%s %d���Դϴ�.\n", food.food_name[food_number - 1], food.food_price[food_number - 1]);
			break;
		}
		else if (yes_or_no == 2) {
			printf("�׷��ٸ� �޴��� �ٽ� ����ּ���.\n");
			for (int i = 0; i < 3; i++) {
				printf("%d. %s - %d�� ", i + 1, food.food_name[i], food.food_price[i]);
			}
			printf("\n");
			printf("���� �޴����� �ϳ� ����ּ��� : ");
			scanf_s("%d", &food_number);
			printf("���� �޴��� %s(��)�� �½��ϱ�?\t 1. �� 2. �ƴϿ� : ", food.food_name[food_number - 1]);
			scanf_s("%d", &yes_or_no);
			continue;
		}
		else {
			printf("�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���.\n");
			printf("���� �޴��� %s(��)�� �½��ϱ�?\t 1. �� 2. �ƴϿ� : ", food.food_name[food_number - 1]);
			scanf_s("%d", &yes_or_no);
		}
	} while (1);
}

void cafeteria() {
	//����ü�� �� ����Ϸ�
	Kfood_price kfood = { {{"��������\0"},{"��ġ�"},{"���ܺ����"}}, {7000,6000,6000} };
	Jfood_price jfood = { {"���ī��","�����ҹ�","����ʹ�"}, {9000,9000,15000} };
	Cfood_price cfood = { {"¥���", "«��","������(��)"}, {5000, 7000, 10000} };
	int kind_of_food;
	printf("� ������ ������ ��ð� �����Ű���?\n 1. �ѽ� 2. �Ͻ� 3. �߽� :  ");
	scanf_s("%d", &kind_of_food);
	int food_number;
	int yes_or_no;
	if (kind_of_food == 1) {
		for (int i = 0; i < 3; i++) {
			printf("%d. %s - %d�� ", i + 1, kfood.food_name[i], kfood.food_price[i]);
		}
		printf("\n");
		printf("���� �޴����� �ϳ� ����ּ��� : ");
		scanf_s("%d", &food_number);
		printf("���� �޴��� %s(��)�� �½��ϱ�?\t 1. �� 2. �ƴϿ� : ", kfood.food_name[food_number - 1]);
		scanf_s("%d", &yes_or_no);
		select_korean_menu(kfood, yes_or_no, food_number);
	}
	if (kind_of_food == 2) {
		for (int i = 0; i < 3; i++) {
			printf("%d. %s - %d�� ", i + 1, jfood.food_name[i], jfood.food_price[i]);
		}
		printf("\n");
		printf("���� �޴����� �ϳ� ����ּ��� : ");
		scanf_s("%d", &food_number);
		printf("���� �޴��� %s(��)�� �½��ϱ�?\t 1. �� 2. �ƴϿ� : ", jfood.food_name[food_number - 1]);
		scanf_s("%d", &yes_or_no);
		select_japanese_menu(jfood, yes_or_no, food_number);
	}
	if (kind_of_food == 3) {
		for (int i = 0; i < 3; i++) {
			printf("%d. %s - %d�� ", i + 1, cfood.food_name[i], cfood.food_price[i]);
		}
		printf("\n");
		printf("���� �޴����� �ϳ� ����ּ��� : ");
		scanf_s("%d", &food_number);
		printf("���� �޴��� %s(��)�� �½��ϱ�?\t 1. �� 2. �ƴϿ� : ", cfood.food_name[food_number - 1]);
		scanf_s("%d", &yes_or_no);
		select_chinese_menu(cfood, yes_or_no, food_number);
	}
}
//3�� �Լ� ����� ��.

//4�� �Լ� ����� ����
typedef struct exercise_kind {
	char type[3][10];
	char exercise_place[3][10];
	char* place[3];
}Exerkind;

//����ü �ʱ�ȭ �Լ�
void initialize(Exerkind* exercise_kind) {
	const char* exerciseType[3] = { "�ｺ", "�౸", "�״Ͻ�" };
	const char* exercisePlace[3] = { "�ｺ��", "�౸","�״Ͻ�" };
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
	//�� ����� �ּ� ���� �Ϸ�
	for (int i = 0; i < 3; i++) {
		exercise_kind.place[i] = &exercise_kind.exercise_place[i];
	}
	printf("�ϰ��� �ϴ� ��� �����ΰ���? : ");
	scanf_s("%s", place_name, sizeof(place_name));
	while ((c = getchar()) != '\n' && c != EOF);
	if (strcmp(place_name,"�ｺ") == 0) {
		printf("%s�� %x��ġ�� �ֽ��ϴ�.\n", exercise_kind.exercise_place[0], exercise_kind.place[0]);
	}
	if (strcmp(place_name, "�౸") == 0) {
		printf("%s�� %x��ġ�� �ֽ��ϴ�.\n", exercise_kind.exercise_place[1], exercise_kind.place[1]);
	}
	if (strcmp(place_name, "�״Ͻ�") == 0) {
		printf("%s�� %x��ġ�� �ֽ��ϴ�.\n", exercise_kind.exercise_place[2], exercise_kind.place[2]);
	}
	free(place_name); //�̷��� �ϴϱ� �������µ�..?
}
//To_do �ϰ��� �ϴ� � �� �� �Է����� �� ����ó��, ���� �޸� �Ҵ��Ѱ� free�� �����ؾ��ϴµ� ������ �װ� �ذ�
int main() {
	int purpose_to_here;
	int place_matrix[3][3]= { {1,2,3},{4,5,6},{7,8,9} }; 
	printf("�̰��� �� ������ �����Դϱ�?\n 1. ��ȭ�� 2. ����(������, �Ƿ�) 3. �Ĵ� 4. �(�ｺ, �౸, �״Ͻ�) 5. ���� : ");
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
		printf("�̰��� �� ������ �����Դϱ�?\n 1. ��ȭ�� 2. ����(������, �Ƿ�) 3. �Ĵ� 4. �(�ｺ, �౸, �״Ͻ�) 5. ���� : ");
		scanf_s("%d", &purpose_to_here);
	}
	return 0;
}