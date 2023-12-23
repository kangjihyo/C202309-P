//일행 입장 시 문자 전송 시스템
void message_to_party() {
	int have_party;
	int ask_sequence;
	int phone_number = 0;
	int party_number;
	while (1) {
		printf("일행이 있나요(1. 예 2. 아니요) : ");
		scanf_s("%d", &have_party);
		if (have_party == 1) {
			printf("일행보다 먼저왔나요? (1. 예 2. 아니요 3. 이전질문) : ");
			scanf_s("%d", &ask_sequence);
			if (ask_sequence == 1) {
				printf("본인의 전화번호를 입력해주세요( - 제외하고 입력) : ");
				scanf_s("%d", &phone_number); //int라서 010이 10으로 저장됨
			}
			else if (ask_sequence == 2) {
				printf("일행의 전화번호를 입력해주세요( - 제외하고 입력) : ");
				scanf_s("%d", &party_number);
				if (party_number == phone_number) {
					printf("일행에게 문자가 전송됐습니다.\n");
					break;
				}
				else if (party_number != phone_number) {
					printf("먼저 들어온 일행이 없습니다.\n");
				}
			}
			else if (ask_sequence == 3) {
				continue;
			}
			else {
				printf("번호를 다시 입력해주세요.");
			}
		}
		else if (have_party == 2) { //2번 입력시 종료
			break;
		}
		else { //예외처리
			printf("번호를 다시 입력해주세요.\n");
		}
	}
}