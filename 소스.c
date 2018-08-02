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

char city[4][10] = { "ÀÏ    º»","È£    ÁÖ","Ä³ ³ª ´Ù","´ëÇÑ¹Î±¹" };

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
	printf("\n\n\t\t¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤\t\t\n");
	printf("\t\t¦¢         ºñÇà±âÇ¥ ¿¹¸Å ÇÁ·Î±×·¥ ÀÔ´Ï´Ù.       ¦¢\t\t\n");
	printf("\t\t¦¢                                              ¦¢\t\t\n");
	printf("\t\t¦¢                  1.¿¹   ¸Å                   ¦¢\t\t\n");
	printf("\t\t¦¢                  2.Á¾   ·á                   ¦¢\t\t\n");
	if (file != NULL)
	{
		printf("\t\t¦¢                  3.Á¶È¸ ¹× ¼öÁ¤              ¦¢\t\t\n");
	}
	printf("\t\t¦¢                                              ¦¢\t\t\n");
	printf("\t\t¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥\t\t\n");
	printf("\n\t\t>>");
	scanf("%d", &ch);
	system("cls");

	return ch;
}

int fFrom() {
	printf("\n\n\t\t¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤\t\t\n");
	printf("\t\t¦¢             Ãâ¹ßÁö¸¦ ¼±ÅÃÇØÁÖ¼¼¿ä            ¦¢\t\t\n");
	printf("\t\t¦¢                                              ¦¢\n\n");
	for (int i = 0; i < 4; i++)
	{
		printf("\t\t¦¢                   %s                   ¦¢\t\t\t\n", city[i]);
	}
	printf("\t\t¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥\t\t\n");
	printf("\n\t\t>>");
	char str[20];
	scanf("%s", &str);
	system("cls");
	if (!strcmp(str, "ÀÏº»"))
	{
		return 0;
	}
	else if (!strcmp(str, "È£ÁÖ"))
	{
		return 1;
	}
	else if (!strcmp(str, "Ä³³ª´Ù"))
	{
		return 2;
	}
	else if (!strcmp(str, "´ëÇÑ¹Î±¹"))
	{
		return 3;
	}
	else
	{
		printf("¾Ë ¼ö ¾ø´Â ±¹°¡");
		return -1;
	}
}

int fTo(int from) {
	printf("\n\n\t\t¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤\t\t\n");
	printf("\t\t¦¢             µµÂøÁö¸¦ ¼±ÅÃÇØÁÖ¼¼¿ä            ¦¢\t\t\n");
	printf("\t\t¦¢                                              ¦¢\n\n");
	for (int i = 0; i < 4; i++)
	{
		if (i != from) {
			printf("\t\t¦¢                   %s                   ¦¢\t\t\t\n", city[i]);
		}
	}
	printf("\t\t¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥\t\t\n");
	char str[20];
	printf("\n\t\t>>");
	scanf("%s", &str);
	system("cls");
	if (!strcmp(str, "ÀÏº»") && from != 0)
	{
		return 0;
	}
	else if (!strcmp(str, "È£ÁÖ") && from != 1)
	{
		return 1;
	}
	else if (!strcmp(str, "Ä³³ª´Ù") && from != 2)
	{
		return 2;
	}
	else if (!strcmp(str, "´ëÇÑ¹Î±¹") && from != 3)
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

	printf("\n\n\t\t¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤\t\t\n");
	printf("\t\t¦¢               ½Ã°£À» ¼±ÅÃÇØÁÖ¼¼¿ä            ¦¢\t\t\n");
	printf("\t\t¦¢                                              ¦¢\n\n");
	while (!feof(file))
	{
		fscanf(file, "%d %d %s %s %s\n", &r_from, &r_to, &r_day, &r_time, &r_company);
		if (r_from == from && r_to == to)
		{
			printf("\t\t¦¢    %2d      %5sÀÏ %s %s          ¦¢\n\n", num, r_day, r_time, r_company);
			num++;
		}
	}
	printf("\t\t¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥\t\t\n");
	fclose(file);

	int ch;
	printf("\n\t\t>>");
	scanf("%d", &ch);

	system("cls");
	if (num < ch || ch < 1)
	{
		printf("¿Ã¹Ù¸£Áö ¸øÇÑ ½Ã°£´ëÀÔ´Ï´Ù.");
		return -1;
	}

	return ch;
}

void fSeat(int from, int to, int num)
{
	int seat[15][7] = { 0 }; //ÁÂ¼®
	char number[30];
	int seatA;
	int seatB;

	FILE * file = fopen("Person.txt", "r");
	if (file != NULL) {
		//fprintf(file, "%d %d %d %d %s %d %s %d %s\n", &from, &to, &num, &seatA, &seatB, &money, &name, &birth, &phone);
		while (!feof(file))
		{
			int r_from, r_to, r_num, r_seatA, r_seatB;
			//°ø¹éÀ¸·Î ºÐ¸®µÈ ÆÄÀÏ ÀÐ±â
			fscanf(file, "%d %d %d %d %d %*d %*s %*d %*s\n", &r_from, &r_to, &r_num, &r_seatA, &r_seatB);

			if (from == r_from && to == r_to && num == r_num) {
				seat[r_seatA - 1][r_seatB - 1] = 1;
			}
		}
		fclose(file);
	}
	while (1) {
		printf("\n\n\t\t¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤\t\t\n");
		printf("\t\t¦¢ ÁÂ¼®À» ¼±ÅÃÇØÁÖ¼¼¿ä (1~3ÇàÀº ÆÛ½ºÆ®¼® ÀÔ´Ï´Ù)¦¢\t\t\n");
		printf("\t\t¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥\t\t\n");

		printf("\t\t\t\t    A B    C D E   F G\t\t\n");
		for (int i = 0; i < 15; i++) {
			printf("\t\t\t\t %2d ", i + 1);
			for (int j = 0; j < 7; j++) {
				if (seat[i][j] == 0)
				{
					printf("¡à");
				}
				else
				{
					printf("¡á");
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
			printf("Àß¸øµÈ ÁÂ¼®ÀÔ´Ï´Ù.");
		}
	}
	fPersnal(from, to, num, seatA, seatB);
}

int fPersnal(int from, int to, int num, int seatA, int seatB)
{
	char name[20];
	int birth;
	char phone[15];
	printf("\t\t************°³ÀÎÁ¤º¸ ÀÔ·Â****************  \n");

	printf("\t\tÀÌ¸§:");
	scanf("%s", name);

	printf("\t\t»ý³â¿ùÀÏ ex)19990101 :");
	scanf("%d", &birth);

	printf("\t\tÀüÈ­¹øÈ£ ex)000-1111-2222 :");
	scanf("%s", phone);



	system("cls");

	int money = 0; // ¿ä±ÝÇÕ°è
	int y;
	int pay[4][4] = {
		{ 0, 500000, 352000, 531000 },//ÀÏº» -> È£ÁÖ Ä³³ª´Ù ÇÑ±¹
		{ 535000, 0, 1080000, 535000 },//È£ÁÖ -> ÀÏº» Ä³³ª´Ù ÇÑ±¹
		{ 406000, 782000, 0, 535000 },
		{ 305000, 478000, 470000, 0 } };
	money = money + pay[from][to];

	//³ªÀÌ¿ä±Ý°è»ê
	if (birth <= 19990101)//¼ºÀÎ¿ä±Ý
		money = money + 50000;
	else if (birth > 19981231) //Ã»¼Ò³â¿ä±Ý
		money = money + 30000;



	//ÁÂ¼®¿ä±Ý°è»ê
	if (seatA <= 3) //ÆÛ½ºÆ®
		money = money + 100000;
	else //ºñÁî´Ï½º
		money = money + 50000;


	printf("\n\n\t\tÃÑ ¿ä±ÝÀº %dÀÔ´Ï´Ù.\n\n", money);
	printf("\t\t1. °áÁ¦ÇÏ±â   2.Ãë¼Ò \n");
	printf("\t\t>>");
	scanf("%d", &y);

	system("cls");
	if (y == 1)
	{
		FILE * file = fopen("Person.txt", "a");
		if (file == NULL)
		{
			//¿¡·¯ Ã³¸®
		}
		fprintf(file, "%d %d %d %d %d %d %s %d %s\n", from, to, num, seatA, seatB, money, name, birth, phone);
		fclose(file);
		return 0;
	}
	else
	{
		printf("°áÁ¦ Ãë¼Ò, Ã³À½ È­¸éÀ¸·Î µÇµ¹¾Æ°©´Ï´Ù");
		return -1;
	}
}

int fChange() {
	int from;
	int to;
	int schd;
	while (1) {
		printf("\n\t\t¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤\t\t\n");
		printf("\t\t¦¢            ¼öÁ¤ÇÒ °÷À» ¼±ÅÃÇÕ´Ï´Ù            ¦¢\t\t\n");
		printf("\t\t¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥\t\t\n");
		from = fFrom();
		if (from != -1)
			break;
	}
	while (1) {
		printf("\n\t\t¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤\t\t\n");
		printf("\t\t¦¢            ¼öÁ¤ÇÒ °÷À» ¼±ÅÃÇÕ´Ï´Ù            ¦¢\t\t\n");
		printf("\t\t¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥\t\t\n");
		to = fTo(from);
		if (to != -1)
			break;
	}
	while (1) {
		printf("\n\n\t\t¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤\t\t\n");
		printf("\t\t¦¢            ¼öÁ¤ÇÒ °÷À» ¼±ÅÃÇÕ´Ï´Ù            ¦¢\t\t\n");
		printf("\t\t¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥\t\t\n");	
		schd = fSchedule(from, to);
		if (schd != -1)
			break;
	}

	int seat[15][7] = { 0 }; //ÁÂ¼®
	char number[30];
	int seatA;
	int seatB;

	FILE * file = fopen("Person.txt", "r+");
	while (!feof(file))
	{
		int r_from, r_to, r_num, r_seatA, r_seatB;
		//°ø¹éÀ¸·Î ºÐ¸®µÈ ÆÄÀÏ ÀÐ±âÀü¿ë º¯¼ö ¼±¾ð
		fscanf(file, "%d %d %d %d %d %*d %*s %*d %*s\n", &r_from, &r_to, &r_num, &r_seatA, &r_seatB);
		
		if (from == r_from && to == r_to && schd == r_num) {
			seat[r_seatA - 1][r_seatB - 1] = 1;
		}
	}
	while (1) {
		printf("\n\n\t\t¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤\t\t\n");
		printf("\t\t¦¢            ¼öÁ¤ÇÒ °÷À» ¼±ÅÃÇÕ´Ï´Ù            ¦¢\t\t\n");
		printf("\t\t¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥\t\t\n");
		
		printf("\n\n\t\t¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤\t\t\n");
		printf("\t\t¦¢ ÁÂ¼®À» ¼±ÅÃÇØÁÖ¼¼¿ä (1~3ÇàÀº ÆÛ½ºÆ®¼® ÀÔ´Ï´Ù)¦¢\t\t\n");
		printf("\t\t¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥\t\t\n");

		printf("\t\t\t\t    A B    C D E   F G\t\t\n");
		for (int i = 0; i < 15; i++) {
			printf("\t\t\t\t %2d ", i + 1);
			for (int j = 0; j < 7; j++) {
				if (seat[i][j] == 0)
				{
					printf("¡à");
				}
				else
				{
					printf("¡á");
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
			seatA = atoi(number); //¹®ÀÚ »©°í Á¤¼ö¸¸À» Àâ¾Æ¿À´Â ÇÔ¼ö
			seatB = number[2] - 64;
		}
		if (seat[seatA - 1][seatB - 1] == 1)
		{
			break;
		}
		else
		{
			system("cls");
			printf("Àß¸øµÈ ÁÂ¼®ÀÔ´Ï´Ù.");
		}
	}
	rewind(file);
	int r_from, r_to, r_num, r_seatA, r_seatB, r_money, r_birth; //ÀÐ±â Àü¿ë º¯¼ö
	char r_name[20], r_phone[15];
	int count = 0;
	while (!feof(file))
	{
		//°ø¹éÀ¸·Î ºÐ¸®µÈ ÆÄÀÏ ÀÐ±â
		fscanf(file, "%d %d %d %d %d %d %s %d %s\n", &r_from, &r_to, &r_num, &r_seatA, &r_seatB, &r_money, r_name, &r_birth, r_phone);
		printf("ÇØ´ç ÁÂ¼® Ã£´ÂÁß");
		if (from == r_from && to == r_to && schd == r_num && seatA == r_seatA && seatB == r_seatB) {
			rewind(file);
			break;
		}
		count++;;
	}
	fclose(file); // Á¶È¸
	while (1) {
		system("cls");
		int ch;
		char seatBB = (char)(r_seatB + 64); //Á¶È¸ÇÑ ³»¿ëÀÌ °°´Ù¸é ÀúÀåµÇ¾îÀÖ´ø µ¥ÀÌÅÍ¸¦ È£Ãâ
		printf("\t\tÀÌ¸§ : %s\n", r_name);
		printf("\t\t%s -> %s | ÁÂ¼® : %d%c\n", city[r_from], city[r_to], r_seatA, seatBB);
		printf("\t\t»ý³â¿ùÀÏ : %d | ÀüÈ­¹øÈ£ : %s\n", r_birth, r_phone);
		printf("\t\t±Ý¾× : %d\n\n", r_money);
		int count = 0;
		printf("\n\n\t\t1. »èÁ¦\n");
		printf("\t\t2. Ãë¼Ò\n"); //»èÁ¦ Ãë¼Ò °áÁ¤
		printf("\n\t\t>>");
		scanf("%d", &ch);

		//»èÁ¦ÇÒ ¶§
		if (ch == 1) {
			FILE * file = fopen("Person.txt", "rt");
			FILE * temp = fopen("Temp.txt", "w+"); //»èÁ¦ÇÒ ÆÄÀÏÀ» Temp¿¡ ¿Å±è
			while (!feof(file))//ÆÄÀÏÀÇ ³¡¿¡ µµ´Þ ÇÒ ¶§±îÁö
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
			fclose(file); //ÆÄÀÏ ´Ý¾ÆÁÖ±â

			temp = fopen("Temp.txt", "r+"); //r+´Â ÀÐ±â/¾²±â ¸ðµåÀÌ´Ù ÀÌÀü ÆÄÀÏÀÌ ¾øÀ¸¸é ¿¡·¯
			file = fopen("Person.txt", "w+"); //Person.txt w+ ¿¬»êÀÚ¸¦ ÀÌ¿ëÇØ¼­ ÆÄÀÏ »õ·Î »ý¼º
			int from = NULL, to, num, seatA, seatB, money, birth;
			char name[20], phone[15];
			while (!feof(temp)) {
				fscanf(temp, "%d %d %d %d %d %d %s %d %s\n", &from, &to, &num, &seatA, &seatB, &money, name, &birth, phone);
				if (count != 0) {
					fprintf(file, "%d %d %d %d %d %d %s %d %s\n", from, to, num, seatA, seatB, money, name, birth, phone);//Áö¿öÁÜ
				}
			}
			fprintf(file, "\n");//ÇÑÄ­ ¶Ü
			fclose(temp);
			fclose(file);
			break;
		}
		//»èÁ¦°¡ ¾Æ´Ï¶ó¸é ±×³É ºüÁ®³ª°£´Ù
		else if (ch == 2) {
			break;
		}
	}

	return 0;
}
