#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "num1_function.h"
#include "num2_function.h"     
#include "num3_function.h"
//��������� ���� ���� C ���� ���� �Ϸ�

int main() {
	int purpose_to_here;
	int parking_answer;
	int place_matrix[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
	printf("�̰��� �� ������ �����Դϱ�?\n 1. ��ȭ�� 2. ����(������, �Ƿ�) 3. �Ĵ� 4. �(�ｺ, �౸, �״Ͻ�) 5. ���� : ");
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
			printf("�̿����ּż� �����մϴ�.\n\n");
			break;
		}
		printf("�̰��� �� ������ �����Դϱ�?\n 1. ��ȭ�� 2. ����(������, �Ƿ�) 3. �Ĵ� 4. �(�ｺ, �౸, �״Ͻ�) 5. ���� : ");
		scanf_s("%d", &purpose_to_here);
	}
	while (1) {
		printf("���� �ڸ��� �ʿ��Ͻʴϱ�? 1. �� 2. �ƴϿ� : ");
		scanf_s("%d", &parking_answer);
		if (parking_answer == 1) {
			parking_lot(parking_answer);
			break;

		}
		else if (parking_answer == 2) {
			break;
		}
		else {
			printf("�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.\n");
		}
	}
	message_to_party(); //���࿡�� �޽��� ����
	return 0;
}