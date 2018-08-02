#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int fIntro();
int fFrom();
int fTo(int from);
int fSchedule(int from, int to);
void fSeat(int from, int to, int num);
int fPersnal(int from, int to, int num, int seatA, int seatB);
int fChange();

char city[4][10] = { "��    ��","ȣ    ��","ĳ �� ��","���ѹα�" };

int main()
{
	while (1)
	{
		int from;
		int to;
		int num;
		int ch = fIntro();
		if (ch == 1) {
			while (1) {
				from = fFrom();
				if (from != -1)
					break;
			}
			while (1) {
				to = fTo(from);
				if (to != -1)
					break;
			}
			while (1) {
				num = fSchedule(from, to);
				if (num != -1)
					break;
			}
			fSeat(from, to, num);
		}
		else if (ch == 2) {
			break;
		}
		else if (ch == 3) {
			fChange();
		}
	}

	return 0;
}

int fIntro() {
	int ch = 0;
	FILE * file = fopen("Person.txt", "r");
	printf("\n\n\t\t��������������������������������������������������\t\t\n");
	printf("\t\t��         �����ǥ ���� ���α׷� �Դϴ�.       ��\t\t\n");
	printf("\t\t��                                              ��\t\t\n");
	printf("\t\t��                  1.��   ��                   ��\t\t\n");
	printf("\t\t��                  2.��   ��                   ��\t\t\n");
	if (file != NULL)
	{
		printf("\t\t��                  3.��ȸ �� ����              ��\t\t\n");
	}
	printf("\t\t��                                              ��\t\t\n");
	printf("\t\t��������������������������������������������������\t\t\n");
	printf("\n\t\t>>");
	scanf("%d", &ch);
	system("cls");

	return ch;
}

int fFrom() {
	printf("\n\n\t\t��������������������������������������������������\t\t\n");
	printf("\t\t��             ������� �������ּ���            ��\t\t\n");
	printf("\t\t��                                              ��\n\n");
	for (int i = 0; i < 4; i++)
	{
		printf("\t\t��                   %s                   ��\t\t\t\n", city[i]);
	}
	printf("\t\t��������������������������������������������������\t\t\n");
	printf("\n\t\t>>");
	char str[20];
	scanf("%s", &str);
	system("cls");
	if (!strcmp(str, "�Ϻ�"))
	{
		return 0;
	}
	else if (!strcmp(str, "ȣ��"))
	{
		return 1;
	}
	else if (!strcmp(str, "ĳ����"))
	{
		return 2;
	}
	else if (!strcmp(str, "���ѹα�"))
	{
		return 3;
	}
	else
	{
		printf("�� �� ���� ����");
		return -1;
	}
}

int fTo(int from) {
	printf("\n\n\t\t��������������������������������������������������\t\t\n");
	printf("\t\t��             �������� �������ּ���            ��\t\t\n");
	printf("\t\t��                                              ��\n\n");
	for (int i = 0; i < 4; i++)
	{
		if (i != from) {
			printf("\t\t��                   %s                   ��\t\t\t\n", city[i]);
		}
	}
	printf("\t\t��������������������������������������������������\t\t\n");
	char str[20];
	printf("\n\t\t>>");
	scanf("%s", &str);
	system("cls");
	if (!strcmp(str, "�Ϻ�") && from != 0)
	{
		return 0;
	}
	else if (!strcmp(str, "ȣ��") && from != 1)
	{
		return 1;
	}
	else if (!strcmp(str, "ĳ����") && from != 2)
	{
		return 2;
	}
	else if (!strcmp(str, "���ѹα�") && from != 3)
	{
		return 3;
	}
	else
	{
		return -1;
	}
}

int fSchedule(int from, int to)
{
	FILE * file = fopen("Schedule.txt", "r");
	int r_from;
	int r_to;
	char r_day[5];
	char r_time[6];
	char r_company[11];
	int num = 1;

	printf("\n\n\t\t��������������������������������������������������\t\t\n");
	printf("\t\t��               �ð��� �������ּ���            ��\t\t\n");
	printf("\t\t��                                              ��\n\n");
	while (!feof(file))
	{
		fscanf(file, "%d %d %s %s %s\n", &r_from, &r_to, &r_day, &r_time, &r_company);
		if (r_from == from && r_to == to)
		{
			printf("\t\t��    %2d      %5s�� %s %s          ��\n\n", num, r_day, r_time, r_company);
			num++;
		}
	}
	printf("\t\t��������������������������������������������������\t\t\n");
	fclose(file);

	int ch;
	printf("\n\t\t>>");
	scanf("%d", &ch);

	system("cls");
	if (num < ch || ch < 1)
	{
		printf("�ùٸ��� ���� �ð����Դϴ�.");
		return -1;
	}

	return ch;
}

void fSeat(int from, int to, int num)
{
	int seat[15][7] = { 0 }; //�¼�
	char number[30];
	int seatA;
	int seatB;

	FILE * file = fopen("Person.txt", "r");
	if (file != NULL) {
		//fprintf(file, "%d %d %d %d %s %d %s %d %s\n", &from, &to, &num, &seatA, &seatB, &money, &name, &birth, &phone);
		while (!feof(file))
		{
			int r_from, r_to, r_num, r_seatA, r_seatB;
			//�������� �и��� ���� �б�
			fscanf(file, "%d %d %d %d %d %*d %*s %*d %*s\n", &r_from, &r_to, &r_num, &r_seatA, &r_seatB);

			if (from == r_from && to == r_to && num == r_num) {
				seat[r_seatA - 1][r_seatB - 1] = 1;
			}
		}
		fclose(file);
	}
	while (1) {
		printf("\n\n\t\t��������������������������������������������������\t\t\n");
		printf("\t\t�� �¼��� �������ּ��� (1~3���� �۽�Ʈ�� �Դϴ�)��\t\t\n");
		printf("\t\t��������������������������������������������������\t\t\n");

		printf("\t\t\t\t    A B    C D E   F G\t\t\n");
		for (int i = 0; i < 15; i++) {
			printf("\t\t\t\t %2d ", i + 1);
			for (int j = 0; j < 7; j++) {
				if (seat[i][j] == 0)
				{
					printf("��");
				}
				else
				{
					printf("��");
				}
				if (j == 1 || j == 4)
					printf("  ");
			}
			printf("\n");
		}


		printf("\t\t\tex)1A\n\t\t\t\t>>");
		scanf("%3s", number);
		system("cls");
		if (strlen(number) == 2) {
			seatA = number[0] - 48;
			seatB = number[1] - 64;
		}
		else if (strlen(number) >= 3) {
			seatA = atoi(number);
			seatB = number[2] - 64;
		}
		if (seat[seatA - 1][seatB - 1] == 0)
		{
			break;
		}
		else
		{
			system("cls");
			printf("�߸��� �¼��Դϴ�.");
		}
	}
	fPersnal(from, to, num, seatA, seatB);
}

int fPersnal(int from, int to, int num, int seatA, int seatB)
{
	char name[20];
	int birth;
	char phone[15];
	printf("\t\t************�������� �Է�****************  \n");

	printf("\t\t�̸�:");
	scanf("%s", name);

	printf("\t\t������� ex)19990101 :");
	scanf("%d", &birth);

	printf("\t\t��ȭ��ȣ ex)000-1111-2222 :");
	scanf("%s", phone);



	system("cls");

	int money = 0; // ����հ�
	int y;
	int pay[4][4] = {
		{ 0, 500000, 352000, 531000 },//�Ϻ� -> ȣ�� ĳ���� �ѱ�
		{ 535000, 0, 1080000, 535000 },//ȣ�� -> �Ϻ� ĳ���� �ѱ�
		{ 406000, 782000, 0, 535000 },
		{ 305000, 478000, 470000, 0 } };
	money = money + pay[from][to];

	//���̿�ݰ��
	if (birth <= 19990101)//���ο��
		money = money + 50000;
	else if (birth > 19981231) //û�ҳ���
		money = money + 30000;



	//�¼���ݰ��
	if (seatA <= 3) //�۽�Ʈ
		money = money + 100000;
	else //����Ͻ�
		money = money + 50000;


	printf("\n\n\t\t�� ����� %d�Դϴ�.\n\n", money);
	printf("\t\t1. �����ϱ�   2.��� \n");
	printf("\t\t>>");
	scanf("%d", &y);

	system("cls");
	if (y == 1)
	{
		FILE * file = fopen("Person.txt", "a");
		if (file == NULL)
		{
			//���� ó��
		}
		fprintf(file, "%d %d %d %d %d %d %s %d %s\n", from, to, num, seatA, seatB, money, name, birth, phone);
		fclose(file);
		return 0;
	}
	else
	{
		printf("���� ���, ó�� ȭ������ �ǵ��ư��ϴ�");
		return -1;
	}
}

int fChange() {
	int from;
	int to;
	int schd;
	while (1) {
		printf("\n\t\t��������������������������������������������������\t\t\n");
		printf("\t\t��            ������ ���� �����մϴ�            ��\t\t\n");
		printf("\t\t��������������������������������������������������\t\t\n");
		from = fFrom();
		if (from != -1)
			break;
	}
	while (1) {
		printf("\n\t\t��������������������������������������������������\t\t\n");
		printf("\t\t��            ������ ���� �����մϴ�            ��\t\t\n");
		printf("\t\t��������������������������������������������������\t\t\n");
		to = fTo(from);
		if (to != -1)
			break;
	}
	while (1) {
		printf("\n\n\t\t��������������������������������������������������\t\t\n");
		printf("\t\t��            ������ ���� �����մϴ�            ��\t\t\n");
		printf("\t\t��������������������������������������������������\t\t\n");	
		schd = fSchedule(from, to);
		if (schd != -1)
			break;
	}

	int seat[15][7] = { 0 }; //�¼�
	char number[30];
	int seatA;
	int seatB;

	FILE * file = fopen("Person.txt", "r+");
	while (!feof(file))
	{
		int r_from, r_to, r_num, r_seatA, r_seatB;
		//�������� �и��� ���� �б����� ���� ����
		fscanf(file, "%d %d %d %d %d %*d %*s %*d %*s\n", &r_from, &r_to, &r_num, &r_seatA, &r_seatB);
		
		if (from == r_from && to == r_to && schd == r_num) {
			seat[r_seatA - 1][r_seatB - 1] = 1;
		}
	}
	while (1) {
		printf("\n\n\t\t��������������������������������������������������\t\t\n");
		printf("\t\t��            ������ ���� �����մϴ�            ��\t\t\n");
		printf("\t\t��������������������������������������������������\t\t\n");
		
		printf("\n\n\t\t��������������������������������������������������\t\t\n");
		printf("\t\t�� �¼��� �������ּ��� (1~3���� �۽�Ʈ�� �Դϴ�)��\t\t\n");
		printf("\t\t��������������������������������������������������\t\t\n");

		printf("\t\t\t\t    A B    C D E   F G\t\t\n");
		for (int i = 0; i < 15; i++) {
			printf("\t\t\t\t %2d ", i + 1);
			for (int j = 0; j < 7; j++) {
				if (seat[i][j] == 0)
				{
					printf("��");
				}
				else
				{
					printf("��");
				}
				if (j == 1 || j == 4)
					printf("  ");
			}
			printf("\n");
		}


		printf("\t\t\tex)1A\n\t\t\t\t>>");
		scanf("%3s", number);
		system("cls");
		if (strlen(number) == 2) {
			seatA = number[0] - 48;
			seatB = number[1] - 64;
		}
		else if (strlen(number) >= 3) {
			seatA = atoi(number); //���� ���� �������� ��ƿ��� �Լ�
			seatB = number[2] - 64;
		}
		if (seat[seatA - 1][seatB - 1] == 1)
		{
			break;
		}
		else
		{
			system("cls");
			printf("�߸��� �¼��Դϴ�.");
		}
	}
	rewind(file);
	int r_from, r_to, r_num, r_seatA, r_seatB, r_money, r_birth; //�б� ���� ����
	char r_name[20], r_phone[15];
	int count = 0;
	while (!feof(file))
	{
		//�������� �и��� ���� �б�
		fscanf(file, "%d %d %d %d %d %d %s %d %s\n", &r_from, &r_to, &r_num, &r_seatA, &r_seatB, &r_money, r_name, &r_birth, r_phone);
		printf("�ش� �¼� ã����");
		if (from == r_from && to == r_to && schd == r_num && seatA == r_seatA && seatB == r_seatB) {
			rewind(file);
			break;
		}
		count++;;
	}
	fclose(file); // ��ȸ
	while (1) {
		system("cls");
		int ch;
		char seatBB = (char)(r_seatB + 64); //��ȸ�� ������ ���ٸ� ����Ǿ��ִ� �����͸� ȣ��
		printf("\t\t�̸� : %s\n", r_name);
		printf("\t\t%s -> %s | �¼� : %d%c\n", city[r_from], city[r_to], r_seatA, seatBB);
		printf("\t\t������� : %d | ��ȭ��ȣ : %s\n", r_birth, r_phone);
		printf("\t\t�ݾ� : %d\n\n", r_money);
		int count = 0;
		printf("\n\n\t\t1. ����\n");
		printf("\t\t2. ���\n"); //���� ��� ����
		printf("\n\t\t>>");
		scanf("%d", &ch);

		//������ ��
		if (ch == 1) {
			FILE * file = fopen("Person.txt", "rt");
			FILE * temp = fopen("Temp.txt", "w+"); //������ ������ Temp�� �ű�
			while (!feof(file))//������ ���� ���� �� ������
			{
				fscanf(file, "%d %d %d %d %d %d %s %d %s\n", &r_from, &r_to, &r_num, &r_seatA, &r_seatB, &r_money, r_name, &r_birth, r_phone);
				if (from == r_from && to == r_to && schd == r_num && seatA == r_seatA && seatB == r_seatB) {
				}
				else {
					fprintf(temp, "%d %d %d %d %d %d %s %d %s\n", r_from, r_to, r_num, r_seatA, r_seatB, r_money, r_name, r_birth, r_phone);
					count++;
				}
			}
			fclose(temp);
			fclose(file); //���� �ݾ��ֱ�

			temp = fopen("Temp.txt", "r+"); //r+�� �б�/���� ����̴� ���� ������ ������ ����
			file = fopen("Person.txt", "w+"); //Person.txt w+ �����ڸ� �̿��ؼ� ���� ���� ����
			int from = NULL, to, num, seatA, seatB, money, birth;
			char name[20], phone[15];
			while (!feof(temp)) {
				fscanf(temp, "%d %d %d %d %d %d %s %d %s\n", &from, &to, &num, &seatA, &seatB, &money, name, &birth, phone);
				if (count != 0) {
					fprintf(file, "%d %d %d %d %d %d %s %d %s\n", from, to, num, seatA, seatB, money, name, birth, phone);//������
				}
			}
			fprintf(file, "\n");//��ĭ ��
			fclose(temp);
			fclose(file);
			break;
		}
		//������ �ƴ϶�� �׳� ����������
		else if (ch == 2) {
			break;
		}
	}

	return 0;
}
