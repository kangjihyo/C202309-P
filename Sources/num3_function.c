//���� ���� �� ���� ���� �ý���
void message_to_party() {
	int have_party;
	int ask_sequence;
	int phone_number = 0;
	int party_number;
	while (1) {
		printf("������ �ֳ���(1. �� 2. �ƴϿ�) : ");
		scanf_s("%d", &have_party);
		if (have_party == 1) {
			printf("���ຸ�� �����Գ���? (1. �� 2. �ƴϿ� 3. ��������) : ");
			scanf_s("%d", &ask_sequence);
			if (ask_sequence == 1) {
				printf("������ ��ȭ��ȣ�� �Է����ּ���( - �����ϰ� �Է�) : ");
				scanf_s("%d", &phone_number); //int�� 010�� 10���� �����
			}
			else if (ask_sequence == 2) {
				printf("������ ��ȭ��ȣ�� �Է����ּ���( - �����ϰ� �Է�) : ");
				scanf_s("%d", &party_number);
				if (party_number == phone_number) {
					printf("���࿡�� ���ڰ� ���۵ƽ��ϴ�.\n");
					break;
				}
				else if (party_number != phone_number) {
					printf("���� ���� ������ �����ϴ�.\n");
				}
			}
			else if (ask_sequence == 3) {
				continue;
			}
			else {
				printf("��ȣ�� �ٽ� �Է����ּ���.");
			}
		}
		else if (have_party == 2) { //2�� �Է½� ����
			break;
		}
		else { //����ó��
			printf("��ȣ�� �ٽ� �Է����ּ���.\n");
		}
	}
}