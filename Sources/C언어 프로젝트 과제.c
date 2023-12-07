#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void movie_theater() { // ��ȭ�� �������� ���� ������ �Ǵ� �Լ�. ���߿� ����, �ο� �� ���Խ��Ѽ� ����ü ���� �Ŀ� �ٽ� �����.
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
				printf("������ ���� �����Ű���?\n 1. ����� �������\n 2. ������� ���� ������ 3\n 3. ��Ʈ��");
				scanf_s("%d", &movie_number);
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
				printf("������ ���� �����Ű���?\n 1. ĸƾ �Ƹ޸�ī ���ͼ���\n 2. ���˵���2\n 3. ŷ����");
				scanf_s("%d", &movie_number);
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
		
		/*if (genre == 1) {
			int movie_number;
			printf("������ ���� �����Ű���?\n 1. ������Ż\n 2. �ܿ�ձ�3\n 3. �̴Ͼ��� : ");
			scanf_s("%d", &movie_number);
			if (movie_number == 1) {
				select_movie(time_elemental);
			}
			else if (movie_number == 2) {
				select_movie(time_frozen_kingdom);
			}
			else if (movie_number == 3) {
				select_movie(time_minions);
			}
			else {

			}
		}*/
	}
}
void shopping() {
	int purpose_shopping;
	char market_place[9][9] = { "����Ű", "�����̴�", "8seconds", "MLB", "FILA", "����Ŭ��","������", "���Ż�", "�Ƶ�ٽ�" };
	char clothes_brand[9][9] = { "�����̴�","����Ű","�Ƶ�ٽ�","MLB","8seconds","����Ŭ��","FILA","���Ż�","������" };
	char(*p)[9] = clothes_brand;
	char brand_name[10] = "";
	int brand_number;
	int j;
	printf("������ ǰ���� �����ΰ���?\n 1. ������ 2. �Ƿ� 3. ��ǰ : ");
	scanf_s("%d", &purpose_shopping);
	if (purpose_shopping == 1) {
		printf("���� 1���� �̸�Ʈ�� �ֽ��ϴ�.");
	}
	else if (purpose_shopping == 2) {
		printf("� �귣�带 ���Ͻʴϱ�?\n 1. �����̴� 2. ����Ű 3. �Ƶ�ٽ� 4. MLB 5. 8seconds 6. ����Ŭ�� 7. FILA 8. ���Ż� 9. ������ : ");
		scanf_s("%d", &brand_number);
		strcpy_s(brand_name, sizeof(brand_name), p[brand_number-1]);
		for (int i = 0; i <= 8; i++) {
			printf("%d. %s", i+1, p[i]);
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
		printf("%s�� ���� ǥ�� %d���� �ֽ��ϴ�.", brand_name, brand_number);
	}
}
//To_do : ���� 3�� ��� �����
//���߿� ��� ������ ��ġ�� ������ �Ŀ� ��ġ�� �˷��ִ� �Լ��� ����� �͵� ������.

int main() {
	int purpose_to_here;
	int place_matrix[3][3]= { {1,2,3},{4,5,6},{7,8,9} }; 
	printf("�̰��� �� ������ �����Դϱ�?\n 1. ��ȭ�� 2. ����(������, �Ƿ�) 3. �Ĵ� 4. �(�ｺ, �౸, �״Ͻ�) : ");
	scanf_s("%d", &purpose_to_here);
	if (purpose_to_here == 1) {
		movie_theater();
	}
	else if (purpose_to_here == 2) {
		shopping();
	}
	return 0;
}

//void select_elemental(char** time_elemental) {
//	char(*p)[9] = time_elemental; //�迭 �����Ϳ� ���� �Ϸ�
//	int want_time;
//	int random;
//	char select_time[10];
//	char answer[10];
//	char c;
//	for (int i = 0; i < 9; i++) {
//		//�ε����� �´� ���ں��� ��µ�. ������ �� ���Ŀ� ��� ������ ���ڰ� ����.
//		//���ڿ��� ���Ⱑ ���ԵǾ� �־ �׷���. �� �׷����� ����
//		printf("%d. %s\n", i + 1, p[i]); 
//	}
//	printf("���� �ð�ǥ���� �ð��� ����ּ���(���� �ۼ�) : ");
//	scanf_s("%d", &want_time);
//	strcpy_s(select_time, sizeof(p[want_time - 1]), p[want_time - 1]); //select_time�� p[want_time]�ð� ����.
//	select_movie_time(time_elemental, want_time, select_time);
//}