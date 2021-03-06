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

char city[4][10] = { "橾    獄","��    輿","議 釭 棻","渠и團措" };

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
	printf("\n\n\t\t忙式式式式式式式式式式式式式式式式式式式式式式式忖\t\t\n");
	printf("\t\t弛         綠ч晦ル 蕨衙 Щ煎斜極 殮棲棻.       弛\t\t\n");
	printf("\t\t弛                                              弛\t\t\n");
	printf("\t\t弛                  1.蕨   衙                   弛\t\t\n");
	printf("\t\t弛                  2.謙   猿                   弛\t\t\n");
	if (file != NULL)
	{
		printf("\t\t弛                  3.褻�� 塽 熱薑              弛\t\t\n");
	}
	printf("\t\t弛                                              弛\t\t\n");
	printf("\t\t戌式式式式式式式式式式式式式式式式式式式式式式式戎\t\t\n");
	printf("\n\t\t>>");
	scanf("%d", &ch);
	system("cls");

	return ch;
}

int fFrom() {
	printf("\n\n\t\t忙式式式式式式式式式式式式式式式式式式式式式式式忖\t\t\n");
	printf("\t\t弛             轎嫦雖蒂 摹鷗п輿撮蹂            弛\t\t\n");
	printf("\t\t弛                                              弛\n\n");
	for (int i = 0; i < 4; i++)
	{
		printf("\t\t弛                   %s                   弛\t\t\t\n", city[i]);
	}
	printf("\t\t戌式式式式式式式式式式式式式式式式式式式式式式式戎\t\t\n");
	printf("\n\t\t>>");
	char str[20];
	scanf("%s", &str);
	system("cls");
	if (!strcmp(str, "橾獄"))
	{
		return 0;
	}
	else if (!strcmp(str, "��輿"))
	{
		return 1;
	}
	else if (!strcmp(str, "議釭棻"))
	{
		return 2;
	}
	else if (!strcmp(str, "渠и團措"))
	{
		return 3;
	}
	else
	{
		printf("憲 熱 橈朝 措陛");
		return -1;
	}
}

int fTo(int from) {
	printf("\n\n\t\t忙式式式式式式式式式式式式式式式式式式式式式式式忖\t\t\n");
	printf("\t\t弛             紫雜雖蒂 摹鷗п輿撮蹂            弛\t\t\n");
	printf("\t\t弛                                              弛\n\n");
	for (int i = 0; i < 4; i++)
	{
		if (i != from) {
			printf("\t\t弛                   %s                   弛\t\t\t\n", city[i]);
		}
	}
	printf("\t\t戌式式式式式式式式式式式式式式式式式式式式式式式戎\t\t\n");
	char str[20];
	printf("\n\t\t>>");
	scanf("%s", &str);
	system("cls");
	if (!strcmp(str, "橾獄") && from != 0)
	{
		return 0;
	}
	else if (!strcmp(str, "��輿") && from != 1)
	{
		return 1;
	}
	else if (!strcmp(str, "議釭棻") && from != 2)
	{
		return 2;
	}
	else if (!strcmp(str, "渠и團措") && from != 3)
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

	printf("\n\n\t\t忙式式式式式式式式式式式式式式式式式式式式式式式忖\t\t\n");
	printf("\t\t弛               衛除擊 摹鷗п輿撮蹂            弛\t\t\n");
	printf("\t\t弛                                              弛\n\n");
	while (!feof(file))
	{
		fscanf(file, "%d %d %s %s %s\n", &r_from, &r_to, &r_day, &r_time, &r_company);
		if (r_from == from && r_to == to)
		{
			printf("\t\t弛    %2d      %5s橾 %s %s          弛\n\n", num, r_day, r_time, r_company);
			num++;
		}
	}
	printf("\t\t戌式式式式式式式式式式式式式式式式式式式式式式式戎\t\t\n");
	fclose(file);

	int ch;
	printf("\n\t\t>>");
	scanf("%d", &ch);

	system("cls");
	if (num < ch || ch < 1)
	{
		printf("螢夥腦雖 跤и 衛除渠殮棲棻.");
		return -1;
	}

	return ch;
}

void fSeat(int from, int to, int num)
{
	int seat[15][7] = { 0 }; //謝戮
	char number[30];
	int seatA;
	int seatB;

	FILE * file = fopen("Person.txt", "r");
	if (file != NULL) {
		//fprintf(file, "%d %d %d %d %s %d %s %d %s\n", &from, &to, &num, &seatA, &seatB, &money, &name, &birth, &phone);
		while (!feof(file))
		{
			int r_from, r_to, r_num, r_seatA, r_seatB;
			//奢寥戲煎 碟葬脹 だ橾 檗晦
			fscanf(file, "%d %d %d %d %d %*d %*s %*d %*s\n", &r_from, &r_to, &r_num, &r_seatA, &r_seatB);

			if (from == r_from && to == r_to && num == r_num) {
				seat[r_seatA - 1][r_seatB - 1] = 1;
			}
		}
		fclose(file);
	}
	while (1) {
		printf("\n\n\t\t忙式式式式式式式式式式式式式式式式式式式式式式式忖\t\t\n");
		printf("\t\t弛 謝戮擊 摹鷗п輿撮蹂 (1~3ч擎 ぷ蝶お戮 殮棲棻)弛\t\t\n");
		printf("\t\t戌式式式式式式式式式式式式式式式式式式式式式式式戎\t\t\n");

		printf("\t\t\t\t    A B    C D E   F G\t\t\n");
		for (int i = 0; i < 15; i++) {
			printf("\t\t\t\t %2d ", i + 1);
			for (int j = 0; j < 7; j++) {
				if (seat[i][j] == 0)
				{
					printf("﹤");
				}
				else
				{
					printf("﹥");
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
			printf("澀跤脹 謝戮殮棲棻.");
		}
	}
	fPersnal(from, to, num, seatA, seatB);
}

int fPersnal(int from, int to, int num, int seatA, int seatB)
{
	char name[20];
	int birth;
	char phone[15];
	printf("\t\t************偃檣薑爾 殮溘****************  \n");

	printf("\t\t檜葷:");
	scanf("%s", name);

	printf("\t\t儅喇錯橾 ex)19990101 :");
	scanf("%d", &birth);

	printf("\t\t瞪�食醽� ex)000-1111-2222 :");
	scanf("%s", phone);



	system("cls");

	int money = 0; // 蹂旎м啗
	int y;
	int pay[4][4] = {
		{ 0, 500000, 352000, 531000 },//橾獄 -> ��輿 議釭棻 и措
		{ 535000, 0, 1080000, 535000 },//��輿 -> 橾獄 議釭棻 и措
		{ 406000, 782000, 0, 535000 },
		{ 305000, 478000, 470000, 0 } };
	money = money + pay[from][to];

	//釭檜蹂旎啗骯
	if (birth <= 19990101)//撩檣蹂旎
		money = money + 50000;
	else if (birth > 19981231) //羶模喇蹂旎
		money = money + 30000;



	//謝戮蹂旎啗骯
	if (seatA <= 3) //ぷ蝶お
		money = money + 100000;
	else //綠鍔棲蝶
		money = money + 50000;


	printf("\n\n\t\t識 蹂旎擎 %d殮棲棻.\n\n", money);
	printf("\t\t1. 唸薯ж晦   2.鏃模 \n");
	printf("\t\t>>");
	scanf("%d", &y);

	system("cls");
	if (y == 1)
	{
		FILE * file = fopen("Person.txt", "a");
		if (file == NULL)
		{
			//縑楝 籀葬
		}
		fprintf(file, "%d %d %d %d %d %d %s %d %s\n", from, to, num, seatA, seatB, money, name, birth, phone);
		fclose(file);
		return 0;
	}
	else
	{
		printf("唸薯 鏃模, 籀擠 �飛橉虞� 腎給嬴骨棲棻");
		return -1;
	}
}

int fChange() {
	int from;
	int to;
	int schd;
	while (1) {
		printf("\n\t\t忙式式式式式式式式式式式式式式式式式式式式式式式忖\t\t\n");
		printf("\t\t弛            熱薑й 夠擊 摹鷗м棲棻            弛\t\t\n");
		printf("\t\t戌式式式式式式式式式式式式式式式式式式式式式式式戎\t\t\n");
		from = fFrom();
		if (from != -1)
			break;
	}
	while (1) {
		printf("\n\t\t忙式式式式式式式式式式式式式式式式式式式式式式式忖\t\t\n");
		printf("\t\t弛            熱薑й 夠擊 摹鷗м棲棻            弛\t\t\n");
		printf("\t\t戌式式式式式式式式式式式式式式式式式式式式式式式戎\t\t\n");
		to = fTo(from);
		if (to != -1)
			break;
	}
	while (1) {
		printf("\n\n\t\t忙式式式式式式式式式式式式式式式式式式式式式式式忖\t\t\n");
		printf("\t\t弛            熱薑й 夠擊 摹鷗м棲棻            弛\t\t\n");
		printf("\t\t戌式式式式式式式式式式式式式式式式式式式式式式式戎\t\t\n");	
		schd = fSchedule(from, to);
		if (schd != -1)
			break;
	}

	int seat[15][7] = { 0 }; //謝戮
	char number[30];
	int seatA;
	int seatB;

	FILE * file = fopen("Person.txt", "r+");
	while (!feof(file))
	{
		int r_from, r_to, r_num, r_seatA, r_seatB;
		//奢寥戲煎 碟葬脹 だ橾 檗晦瞪辨 滲熱 摹樹
		fscanf(file, "%d %d %d %d %d %*d %*s %*d %*s\n", &r_from, &r_to, &r_num, &r_seatA, &r_seatB);
		
		if (from == r_from && to == r_to && schd == r_num) {
			seat[r_seatA - 1][r_seatB - 1] = 1;
		}
	}
	while (1) {
		printf("\n\n\t\t忙式式式式式式式式式式式式式式式式式式式式式式式忖\t\t\n");
		printf("\t\t弛            熱薑й 夠擊 摹鷗м棲棻            弛\t\t\n");
		printf("\t\t戌式式式式式式式式式式式式式式式式式式式式式式式戎\t\t\n");
		
		printf("\n\n\t\t忙式式式式式式式式式式式式式式式式式式式式式式式忖\t\t\n");
		printf("\t\t弛 謝戮擊 摹鷗п輿撮蹂 (1~3ч擎 ぷ蝶お戮 殮棲棻)弛\t\t\n");
		printf("\t\t戌式式式式式式式式式式式式式式式式式式式式式式式戎\t\t\n");

		printf("\t\t\t\t    A B    C D E   F G\t\t\n");
		for (int i = 0; i < 15; i++) {
			printf("\t\t\t\t %2d ", i + 1);
			for (int j = 0; j < 7; j++) {
				if (seat[i][j] == 0)
				{
					printf("﹤");
				}
				else
				{
					printf("﹥");
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
			seatA = atoi(number); //僥濠 貍堅 薑熱虜擊 濩嬴螃朝 л熱
			seatB = number[2] - 64;
		}
		if (seat[seatA - 1][seatB - 1] == 1)
		{
			break;
		}
		else
		{
			system("cls");
			printf("澀跤脹 謝戮殮棲棻.");
		}
	}
	rewind(file);
	int r_from, r_to, r_num, r_seatA, r_seatB, r_money, r_birth; //檗晦 瞪辨 滲熱
	char r_name[20], r_phone[15];
	int count = 0;
	while (!feof(file))
	{
		//奢寥戲煎 碟葬脹 だ橾 檗晦
		fscanf(file, "%d %d %d %d %d %d %s %d %s\n", &r_from, &r_to, &r_num, &r_seatA, &r_seatB, &r_money, r_name, &r_birth, r_phone);
		printf("п渡 謝戮 瓊朝醞");
		if (from == r_from && to == r_to && schd == r_num && seatA == r_seatA && seatB == r_seatB) {
			rewind(file);
			break;
		}
		count++;;
	}
	fclose(file); // 褻��
	while (1) {
		system("cls");
		int ch;
		char seatBB = (char)(r_seatB + 64); //褻�裔� 頂辨檜 偽棻賊 盪濰腎橫氈湍 等檜攪蒂 ��轎
		printf("\t\t檜葷 : %s\n", r_name);
		printf("\t\t%s -> %s | 謝戮 : %d%c\n", city[r_from], city[r_to], r_seatA, seatBB);
		printf("\t\t儅喇錯橾 : %d | 瞪�食醽� : %s\n", r_birth, r_phone);
		printf("\t\t旎擋 : %d\n\n", r_money);
		int count = 0;
		printf("\n\n\t\t1. 餉薯\n");
		printf("\t\t2. 鏃模\n"); //餉薯 鏃模 唸薑
		printf("\n\t\t>>");
		scanf("%d", &ch);

		//餉薯й 陽
		if (ch == 1) {
			FILE * file = fopen("Person.txt", "rt");
			FILE * temp = fopen("Temp.txt", "w+"); //餉薯й だ橾擊 Temp縑 衡梯
			while (!feof(file))//だ橾曖 部縑 紫殖 й 陽梱雖
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
			fclose(file); //だ橾 殘嬴輿晦

			temp = fopen("Temp.txt", "r+"); //r+朝 檗晦/噙晦 賅萄檜棻 檜瞪 だ橾檜 橈戲賊 縑楝
			file = fopen("Person.txt", "w+"); //Person.txt w+ 翱骯濠蒂 檜辨п憮 だ橾 億煎 儅撩
			int from = NULL, to, num, seatA, seatB, money, birth;
			char name[20], phone[15];
			while (!feof(temp)) {
				fscanf(temp, "%d %d %d %d %d %d %s %d %s\n", &from, &to, &num, &seatA, &seatB, &money, name, &birth, phone);
				if (count != 0) {
					fprintf(file, "%d %d %d %d %d %d %s %d %s\n", from, to, num, seatA, seatB, money, name, birth, phone);//雖錶邀
				}
			}
			fprintf(file, "\n");//и蘊 嗎
			fclose(temp);
			fclose(file);
			break;
		}
		//餉薯陛 嬴棲塭賊 斜傖 緒螳釭除棻
		else if (ch == 2) {
			break;
		}
	}

	return 0;
}
