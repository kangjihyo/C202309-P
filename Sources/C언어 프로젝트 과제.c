#include <stdio.h>

void select_elemental(char** time_elemental) {
	char(*p)[9] = time_elemental; //�迭 �����Ϳ� ���� �Ϸ�
	int want_time;
	int random;
	char select_time;
	char answer;
	for (int i = 0; i < 9; i++) {
		printf("%d. %s\n", i + 1, p[i]);
	}
	printf("���� �ð�ǥ���� �ð��� ����ּ��� : ");
	scanf_s("%d", &want_time);
	select_time = p[want_time];
	if (want_time <= 9 && want_time >= 1) {
		printf("%s�� ������ �ð��� �½��ϱ�? (��, �ƴϿ��� ������ּ���)", select_time);
		scanf_s("%s", &answer, sizeof(answer));
	}
	while (1) {
		if (answer == "��") {
			printf("%s���� ���� �Ϸ� �Ǿ����ϴ�. ���� 10������ �������ּ���.");
		}
		else if (answer == "�ƴϿ�") {
			printf("�׷��ٸ� ���ϴ� �ð��� �ٽ� ����ּ���.");
			select_elemental(time_elemental);
		}
		else {
			printf("�亯�� �ٽ� �������ּ���.");
		}
	}
}

void movie_theater() {
	int genre;
	char time_elemental[9][9] = { "10�� 20��", "11�� 00��" , "11�� 40��" , "12�� 40��" , "13�� 30��" , "14�� 20��" , "15�� 20��" , "16�� 10��" , "17�� 00��" };
	char time_frozen_kingdom[9][9] = { "10�� 30��", "11�� 10��" , "11�� 50��" , "12�� 50��" , "13�� 40��" , "14�� 30��" , "15�� 30��" , "16�� 20��" , "17�� 10��" };
	char time_minions[9][9] = { "10�� 40��", "11�� 10��" , "11�� 40��" , "12�� 50��" , "13�� 40��" , "14�� 20��" , "15�� 10��" , "16�� 20��" , "17�� 00��" };
	printf("������� �帣�� ����ּ���\n(1. �ִϸ��̼�\n 2. �����\n 3. �θǽ��ڹ̵� : ");
	scanf_s("%d", &genre);
	if (genre == 1) {
		int movie_number;
		printf("������ ���� �����Ű���?\n(1. ������Ż\n 2. �ܿ�ձ�3\n 3. �̴Ͼ��� : ");
		scanf_s("%d", &movie_number);
	}
	select_elemental(time_elemental);
}

int main() {
	int purpose_to_here;
	int place_matrix[3][3]= { {1,2,3},{4,5,6},{7,8,9} }; 
	printf("�̰��� �� ������ �����Դϱ�?\n 1. ��ȭ��, ����(������, �Ƿ�)\n 2. �Ĵ�\n 3. �(�ｺ, �౸, �״Ͻ�) : ");
	scanf_s("%d", &purpose_to_here);
	/*if (purpose_to_here == 1) {
		movie_theater();
	}*/
	char time_elemental[9][9] = { "10�� 20��", "11�� 00��" , "11�� 40��" , "12�� 40��" , "13�� 30��" , "14�� 20��" , "15�� 20��" , "16�� 10��" , "17�� 00��" };
	char time_frozen_kingdom[9][9] = { "10�� 30��", "11�� 10��" , "11�� 50��" , "12�� 50��" , "13�� 40��" , "14�� 30��" , "15�� 30��" , "16�� 20��" , "17�� 10��" };
	char time_minions[9][9] = { "10�� 40��", "11�� 10��" , "11�� 40��" , "12�� 50��" , "13�� 40��" , "14�� 20��" , "15�� 10��" , "16�� 20��" , "17�� 00��" };
	select_elemental(time_elemental);
	return 0;
}