//����Ÿ�� �������� ��� ���� �������� ����ϱ�.
//������ �޾Ƽ� �������� �� �� ���� ����ϱ� ex) 1���� ��� 1���� ����ϱ�
//����Ÿ�� ���� ��...
void parking_lot(int parking_answer) {
	int parking_lot[5][50] = { 0 }; //���⼭ �ٽ� �ʱ�ȭ �ؼ� �Ʒ����� ���� �ٲ㵵 �ʱ�ȭ�� �Ǵ� �ٶ��� �ᱹ ���� �ȹٲ�
	int want_number_parking_floor;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 50; j++) {
			parking_lot[i][j] = j;
		}
	} //�迭�� �� �ʱ�ȭ �Ϸ�
	while (1)
	{
		if (parking_answer == 1) {
			printf("������ �ϰ� ���� ���� �����ּ��� (1 ~ 5�� ���ڸ��Է�, ���� : 6) : ");
			scanf_s("%d", &want_number_parking_floor);
			if (want_number_parking_floor <= 0 || want_number_parking_floor >= 7) { //���� ó��
				printf("���� �ٽ� �Է����ּ���\n\n");
				continue;
			}
			printf("\n");
			if (want_number_parking_floor == 6) {
				break;
			}
			printf("%d��\n", want_number_parking_floor);
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
			printf("���� �ϰ� ���� �ڸ��� ����ּ���(0�� ������ ���� �ٽ� �� �� �ֽ��ϴ�) : "); //�� �߸������ �� �ٽ� �� �� �ְ� ��.
			scanf_s("%d", &want_number_parking_number); //�̰� index��ȣ �ƴϴ�. -1�ؼ� ����ؾ���
			if (want_number_parking_number == 0) {
				continue;
			}
			while (1)
			{
				if (want_number_parking_number < 0 || want_number_parking_number > 50) {
					printf("��ȣ�� �ٽ� �Է����ּ���.\n");
					printf("���� �ϰ� ���� �ڸ��� ����ּ��� : ");
					scanf_s("%d", &want_number_parking_number);
				}
				else {
					parking_lot[want_number_parking_floor - 1][want_number_parking_number - 1] = -1;
					break;
				}
			}
		}
	}
} //����Ÿ�� ���� �Ϸ�