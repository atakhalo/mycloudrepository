// ConsoleApplication2.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <graphics.h>
#include <conio.h>
#include <time.h>
#include "game2.0.h"

void loadall()//����ͼƬ
{
	loadimage(&start1, _T("���´���.jpg"), Width, Height);
	loadimage(&start2, _T("��ħ����.jpg"), Width, Height);
	loadimage(&start3, _T("����.jpg"), Width, Height);
	loadimage(&start4, _T("��ڤ.jpg"), Width, Height);
	loadimage(&start5, _T("��ɮ.jpg"), Width, Height);
	loadimage(&start6, _T("����.jpg"), Width, Height);
	loadimage(&start7, _T("����Ϳ̿.jpg"), Width, Height);
	loadimage(&start8, _T("ʥ��.jpg"), Width, Height);
	loadimage(&menu1, _T("1.jpg"), Width, Height);
	loadimage(&wechat1, _T("wechat1.jpg"), 600, 800);
	loadimage(&newhero1, _T("����.jpg"), Width, Height);
	loadimage(&transitions, _T("����1.jpg"), Width, Height);
	loadimage(&img, _T("����ԭͼ.jpg"), HeroWidth, HeroHeight);//��������ͼ
	loadimage(&mask, _T("��������ͼ.jpg"), HeroWidth, HeroHeight);//��������ͼ
	loadimage(&door, _T("������.jpg"), 100, 100);//���ش�����
	loadimage(&scene1, _T("����1.jpg"), Width, Height);
	loadimage(&scene2, _T("����2.jpg"), Width, Height);
	loadimage(&scene3, _T("����3.jpg"), Width, Height);
	loadimage(&scene4, _T("����4.jpg"), Width, Height);
	loadimage(&scene5, _T("����5.jpg"), Width, Height);
	loadimage(&scene6, _T("����6.jpg"), Width, Height);
	loadimage(&exit1, _T("�˳���Ϸ.jpg"), Width, Height);
	loadimage(&heroyuan, _T("����ԭͼ.jpg"), HeroWidth * 5, HeroHeight * 5);//��������ԭͼ
	loadimage(&heroyan, _T("��������ͼ.jpg"), HeroWidth * 5, HeroHeight * 5);//������������ͼ
	loadimage(&monsteryuan1, _T("����ԭͼ.jpg"), HeroWidth * 5, HeroHeight * 5);//���ص���ԭͼ
	loadimage(&monsteryan1, _T("��������ͼ.jpg"), HeroWidth * 5, HeroHeight * 5);//���ص�������ͼ
	loadimage(&monsteryuan2, _T("����ԭͼ.jpg"), HeroWidth * 5, HeroHeight * 5);//���ص���ԭͼ
	loadimage(&monsteryan2, _T("��������ͼ.jpg"), HeroWidth * 5, HeroHeight * 5);//���ص�������ͼ
	loadimage(&monsteryuan3, _T("���ԭͼ.jpg"), HeroWidth * 5, HeroHeight * 5);//���ص���ԭͼ
	loadimage(&monsteryan3, _T("�������ͼ.jpg"), HeroWidth * 5, HeroHeight * 5);//���ص�������ͼ
	loadimage(&monsteryuan4, _T("��ɮԭͼ.jpg"), HeroWidth * 5, HeroHeight * 5);//���ص���ԭͼ
	loadimage(&monsteryan4, _T("��ɮ����ͼ.jpg"), HeroWidth * 5, HeroHeight * 5);//���ص�������ͼ
	loadimage(&fightscene, _T("ս������1.jpg"), Width, Height);//����ս������
	loadimage(&getnewskill, _T("getskill.jpg"), Width, Height);
	loadimage(&getnewequipment, _T("����.jpg"), Width, Height);
	loadimage(&useskillimage, _T("��Ƥֽ.jpg"), Width, Height);
}

void start()															//��ͷ����
{
	initgraph(Width, Height);//��ʼͼ�δ���
	RECT r = { 0, 0, Width,Height };//��Χ
	setbkmode(TRANSPARENT);//���ñ���͸��
	settextcolor(RGB(255, 255, 255));//����������ɫ
	settextstyle(40, 0, _T("����"));//���壬��С
	putimage(0, 0, &start1);
	drawtext(_T("ʱ���´���"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);//����
	Sleep(3000);//�Ⱥ�
	cleardevice();
	putimage(0, 0, &start2);
	drawtext(_T("��ħ����"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	Sleep(3000);
	cleardevice();
	putimage(0, 0, &start3);
	drawtext(_T("��ڤ����"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	Sleep(3000);
	cleardevice();
	putimage(0, 0, &start4);
	drawtext(_T("�Ϻ���ڤ"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	Sleep(3000);
	putimage(0, 0, &start5);
	drawtext(_T("������ɮ"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	Sleep(3000);
	putimage(0, 0, &start6);
	drawtext(_T("��������"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	Sleep(3000);
	putimage(0, 0, &start7);
	drawtext(_T("�˻����ϣ������Կࡣ"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	Sleep(3000);
	putimage(0, 0, &start8);
	drawtext(_T("��һ�գ�ʥ���콵���������֣�"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	Sleep(3000);
	putimage(0, 0, &start8);
	settextcolor(RGB(175, 238, 238));
	drawtext(_T("Ӣ��ʥ�٣��������������η��ս�겻����"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	Sleep(3000);
	cleardevice();
	closegraph();
}

void CharToTchar(const char * _char, TCHAR * tchar)//charתTCHAR
{
	int iLength;

	iLength = MultiByteToWideChar(CP_ACP, 0, _char, strlen(_char) + 1, NULL, 0);
	MultiByteToWideChar(CP_ACP, 0, _char, strlen(_char) + 1, tchar, iLength);
}

void getequipment(Hero *hero)//�����Ʒ
{
	RECT top = { 0,0,Width,Height };
	RECT middle = { 0 , Height / 2 - 140 ,Width, Height };//������ʾ��������
	RECT middle1 = { 0 , Height / 2 - 80 ,Width, Height };//������ʾ���еڶ�������
	RECT middle2 = { 0 , Height / 2 - 20  ,Width, Height };//������ʾ���е���������
	RECT change = { Width / 2 - 50  ,Height / 2 + 100, Width / 2 + 50 ,Height };
	RECT abondon = { Width / 2 - 50 ,Height / 2 + 170 , Width / 2 + 50 ,Height };
	
	FILE *EQUIPMENT;//װ���ļ�ָ��
	Arms temp;
	TCHAR name[20];
	TCHAR equipmentword[100];
	char filename[20];
	MOUSEMSG mouse;
	srand((unsigned)time(0));
	int choice = rand() % 2;//���ѡ�񻤼׺�����
	
	if (choice == 0) //��û���
		strcpy_s(filename, "armors.txt");
	else			//�������
		strcpy_s(filename, "arms.txt");
	int random  = rand()%10;//������װ��
	int iseof;//�ж��ļ�������
	fopen_s(&EQUIPMENT, filename, "r");
	
	while (random + 1 != 0)
	{
		fscanf_s(EQUIPMENT, "%d", &temp.adk);
		fscanf_s(EQUIPMENT, "%s", &temp.name, 20);
		iseof = fscanf_s(EQUIPMENT, "%s", &temp.word, 100);
		if (temp.adk >= (hero->scene-1) * 20 && temp.adk <= hero->scene *21)
			random--;
		if (iseof == EOF)
			break;
	}
	fclose(EQUIPMENT);
	CharToTchar(temp.name, name);
	CharToTchar(temp.word, equipmentword);
	setcolor(BLACK);
	BeginBatchDraw();
	putimage(0, 0, &getnewequipment);//���Ʊ���
	drawtext(_T("��õ���"), &middle, DT_CENTER);
	drawtext(name, &middle1, DT_CENTER );
	drawtext(equipmentword, &middle2, DT_CENTER);
	drawtext(_T("װ��"), &change, DT_CENTER);
	drawtext(_T("�ӵ�"), &abondon, DT_CENTER);
	EndBatchDraw();
	setcolor(WHITE);
	FlushMouseMsgBuffer();
	while (1)
	{
		if (MouseHit())
		{
			mouse = GetMouseMsg();
			if (mouse.x >= Width / 2 - 50 && mouse.x <= Width / 2 + 50 && mouse.y >= Height / 2 + 100 && mouse.y <= Height / 2 + 130 && mouse.mkLButton)
			{
				if (choice == 0)
				{
					hero->armor.def = temp.adk;
					strcpy_s(hero->armor.name , temp.name);
					strcpy_s(hero->armor.word , temp.word);
				}
				else
				{
					hero->arms.adk = temp.adk;
					strcpy_s(hero->arms.name , temp.name);
					strcpy_s(hero->arms.word , temp.word);
				}
				drawtext(_T("װ���ɹ�"), &top, DT_CENTER);
				Sleep(1000);
				return;
			}
			else if (mouse.x >= Width / 2 - 50 && mouse.x <= Width / 2 + 50 && mouse.y >= Height / 2 + 170 && mouse.y <= Height / 2 + 200 && mouse.mkLButton)
			{
				drawtext(_T("�ɹ��ӵ�"), &top, DT_CENTER);
				Sleep(1000);
				return;
			}
			else continue;
		}
	}
	return;
}

void getskill(Hero *hero)//��ü���
{
	RECT middle = { 0 , Height / 2 - 100 ,Width, Height };//������ʾ��������
	RECT middle1 = { 0 , Height / 2 - 40 ,Width, Height };//������ʾ���еڶ�������
	RECT middle2 = { 0 , Height / 2 + 20  ,Width, Height };//������ʾ���е���������
	FILE *SKILL;//�����ļ�ָ��
	Skill skill;
	TCHAR name[20];
	TCHAR skillword[100];
	int iseof = 0;
	hero->skill++;//����+1
	int i = hero->skill;
	fopen_s(&SKILL, "skill.txt", "r");
	while (i)
	{
		fscanf_s(SKILL, "%d", &skill.armor_bonus);
		fscanf_s(SKILL, "%d", &skill.attack_bonus);
		fscanf_s(SKILL, "%d", &skill.dodge);
		fscanf_s(SKILL, "%d", &skill.hp);
		fscanf_s(SKILL, "%d", &skill.hurt_deepen);
		fscanf_s(SKILL, "%d", &skill.keeptime);
		fscanf_s(SKILL, "%d", &skill.mp);
		fscanf_s(SKILL, "%s", &skill.name,20);
		iseof = fscanf_s(SKILL, "%s", &skill.word,100);
		if (skill.mp >= 0)
			i--;
		if (iseof == EOF)
			break;
	}
	fclose(SKILL);
	CharToTchar(skill.name, name);
	CharToTchar(skill.word, skillword);
	BeginBatchDraw();
	putimage(0, 0, &getnewskill);//���Ʊ���
	drawtext(_T("��ѧ����"), &middle, DT_CENTER );
	drawtext(name,&middle1,DT_CENTER );
	drawtext(skillword, &middle2, DT_CENTER);
	EndBatchDraw();
	Sleep(3000);
}

int mouseclinkrect(MOUSEMSG *mouse, RECT rect)
{
	if (mouse->x >= rect.left && mouse->x <= rect.right && mouse->y >= rect.top && mouse->y <= rect.bottom && mouse->mkLButton)
		return 1;
	else return 0;
}

int useskill(Skill *useskill,Hero *hero)
{
	if (hero->skill == 0)return 0;
	RECT skillname[20];
	RECT back = { Width / 2 - 50 , Height - 40 ,Width / 2 + 50 ,Height };
	RECT tips = { 0 , Height - 100 ,Width ,Height - 40 };
	MOUSEMSG mouse;
	int i = hero->skill -1 ;
	while (i <= 20 && i != -1)
	{
		if (i < 10)
			skillname[i] = { 0,20 + i * 40,Width / 2,60 + i * 40 };
		else 
			skillname[i] = { Width / 2 ,20 + i * 30,Width,50 + i * 30 };
		i--;
	}
	FILE *SKILL;//�����ļ�ָ��
	Skill skill[20];
	TCHAR name[20];
	TCHAR skillword[100];
	int iseof = 0;
	fopen_s(&SKILL, "skill.txt", "r");
	i = hero->skill - 1;
	while (i != -1)
	{
		fscanf_s(SKILL, "%d", &skill[i].armor_bonus);
		fscanf_s(SKILL, "%d", &skill[i].attack_bonus);
		fscanf_s(SKILL, "%d", &skill[i].dodge);
		fscanf_s(SKILL, "%d", &skill[i].hp);
		fscanf_s(SKILL, "%d", &skill[i].hurt_deepen);
		fscanf_s(SKILL, "%d", &skill[i].keeptime);
		fscanf_s(SKILL, "%d", &skill[i].mp);
		fscanf_s(SKILL, "%s", &skill[i].name, 20);
		iseof = fscanf_s(SKILL, "%s", &skill[i].word, 100);
		if (skill[i].mp >= 0)
			i--;
		if (iseof == EOF)
			break;
	}
	fclose(SKILL);
	i = hero->skill - 1;
	BeginBatchDraw();
	putimage(0, 0, &useskillimage);
	setcolor(BLACK);
	while (i != -1)
	{
		CharToTchar(skill[i].name, name);
		drawtext(name, &skillname[i], DT_CENTER);
		i--;
	}
	drawtext(_T("����"), &back, DT_CENTER);
	EndBatchDraw();
	FlushMouseMsgBuffer();
	setcolor(WHITE);
	while (1)
	{
		if (MouseHit())
		{
			mouse = GetMouseMsg();
			if (mouseclinkrect(&mouse, back))
				return 0;
			i = hero->skill - 1;
			while (i != -1)
			{
				if (mouseclinkrect(&mouse, skillname[i]))
				{
					if (hero->mp < skill[i].mp)
					{
						drawtext(_T("ħ������"), &tips, DT_CENTER);
						Sleep(1000);
						break;
					}
					else
					{
						*useskill = skill[i];
						return 1;
					}
				}
				i--;
			}
		}
	}
	return 0;
}

void fight(Hero *hero, Monster monster)//ս��
{
	RECT atackrect = { Width / 2 - 50,Height / 2 - 100,Width / 2 + 50,Height / 2 };
	RECT skillrect = { Width / 2 - 50,Height / 2,Width / 2 + 50,Height / 2 + 100 };
	RECT runrect = { Width / 2 - 100,Height / 2 + 100,Width / 2 + 100,Height / 2 + 200 };
	RECT middle = { 0 , 0 ,Width, Height };//������ʾ��������
	RECT middle1 = { 0,30,Width,Height };
	RECT middle2 = { 0,60,Width,Height };
	RECT middle3 = { 0,90,Width,Height };
	RECT middle4 = { 0,120,Width,Height };
	MOUSEMSG mouse;//���
	IMAGE monsteryuan;
	IMAGE monsteryan;

	float hurt = 0;//�˺���
	int dodge = 5;//���ܼ���
	Skill skill;
	skill.armor_bonus = 0;
	skill.attack_bonus = 0;
	skill.dodge = 0;
	skill.hp = 0;
	skill.hurt_deepen = 0;
	skill.keeptime = 0;
	skill.mp = 0;
	int crit = 0;//����
	int isblock = 0;
	int isdodge = 0;
	int a = 0;
	int isclink = 0;
	settextcolor(WHITE);//����������ɫ
	
	if (monster.race == 1)
	{
		monsteryuan = monsteryuan1;
		monsteryan = monsteryan1;
	}
	else if (monster.race == 2)
	{
		monsteryuan = monsteryuan2;
		monsteryan = monsteryan2;
	}
	else if (monster.race == 3)
	{
		monsteryuan = monsteryuan3;
		monsteryan = monsteryan3;
	}
	else if (monster.race == 4)
	{
		monsteryuan = monsteryuan4;
		monsteryan = monsteryan4;
	}

	while (1)
	{
		FlushMouseMsgBuffer();//�����껺��
		 /*��������׶�*/
		while (1)
		{
			hurt = 0;//��ʼ���˺���
			crit = 0;//��ʼ������
			isblock = 0;//��ʼ����
			if (skill.dodge > 0)
				dodge += skill.dodge;//���ܼ��ʳ�ʼֵ���ϼ������ܼ���
			else dodge = 5;
			BeginBatchDraw();//��ʼ��������
			putimage(0, 0, &fightscene);//ս������
			rectangle(0, 0, 200, 16);//Ѫ���߿�
			rectangle(0, 24, 200, 41);//�����߿�
			rectangle(Width - 200, 0, Width, 16);//����Ѫ���߿�
			rectangle(Width - 200, 24, Width, 41);//���������߿�
			setfillcolor(RGB(255, 0, 0));//����Ѫ����ɫ
			solidrectangle(1, 1, (int)((float)((float)hero->hp / (float)(hero->level * 2 + 98)) * 200) - 1, 15);//Ѫ��
			solidrectangle(Width + 1 - (int)((float)((float)monster.hp / (float)(monster.level * 2 + 98)) * 200), 1, Width - 1, 15);//����Ѫ��
			setfillcolor(BLUE); //����������ɫ;
			solidrectangle(1, 25, (int)((float)((float)hero->mp / (float)(hero->level * 2 + 98)) * 200) - 1, 40);//����
			solidrectangle(Width + 1 - (int)((float)((float)monster.mp / (float)(monster.level * 2 + 98)) * 200), 25, Width - 1, 40);//��������
			putimage(100, 100, &heroyan, SRCAND);//������������ͼ
			putimage(100, 100, &heroyuan, SRCPAINT);//��������ԭͼ
			putimage(Width - HeroWidth * 5 - 100, 100, &monsteryan, SRCAND);//���Ƶ�������ͼ
			putimage(Width - HeroWidth * 5 - 100, 100, &monsteryuan, SRCPAINT);//���Ƶ���ԭͼ
			drawtext(_T("����"), &atackrect, DT_CENTER);
			drawtext(_T("����"), &skillrect, DT_CENTER);
			drawtext(_T("����"), &runrect, DT_CENTER);
			EndBatchDraw();//����ͼ
			if (MouseHit())
			{
				isclink = 0;
				mouse = GetMouseMsg();//��������Ϣ
				if ((mouse.x >= Width / 2 - 50 && mouse.x <= Width / 2 + 50) && (mouse.y >= Height / 2 - 100 && mouse.y <= Height / 2) && mouse.mkLButton)//����
				{
					isclink = 1;
					BeginBatchDraw();
					putimage(0, 0, &fightscene);
					rectangle(0, 0, 200, 16);//Ѫ���߿�
					rectangle(0, 24, 200, 41);//�����߿�
					rectangle(Width - 200, 0, Width, 16);//����Ѫ���߿�
					rectangle(Width - 200, 24, Width, 41);//���������߿�
					setfillcolor(RGB(255, 0, 0));//����Ѫ����ɫ
					solidrectangle(1, 1, (int)((float)((float)hero->hp / (float)(hero->level * 2 + 98)) * 200) - 1, 15);//Ѫ��
					solidrectangle(Width + 1 - (int)((float)((float)monster.hp / (float)(monster.level * 2 + 98)) * 200), 1, Width - 1, 15);//����Ѫ��
					setfillcolor(BLUE); //����������ɫ;
					solidrectangle(1, 25, (int)((float)((float)hero->mp / (float)(hero->level * 2 + 98)) * 200) - 1, 40);//����
					solidrectangle(Width + 1 - (int)((float)((float)monster.mp / (float)(monster.level * 2 + 98)) * 200), 25, Width - 1, 40);//��������
					putimage(Width - HeroWidth * 5 - 200, 100, &heroyan, SRCAND);//������������ͼ
					putimage(Width - HeroWidth * 5 - 200, 100, &heroyuan, SRCPAINT);//��������ԭͼ
					EndBatchDraw();
					srand((unsigned)time(0));
					if (rand() % dodge == 0)//����һ����������
					{
						BeginBatchDraw();
						putimage(Width - HeroWidth * 5, 100, &monsteryan, SRCAND);//���Ƶ�������ͼ
						putimage(Width - HeroWidth * 5, 100, &monsteryuan, SRCPAINT);//���Ƶ���ԭͼ
						drawtext(_T("���˶������Ĺ���"), &middle, DT_CENTER);//����˵��
						EndBatchDraw();
						Sleep(1000);
					}
					else
					{
						BeginBatchDraw();
						putimage(Width - HeroWidth * 5 - 100, 100, &monsteryan, SRCAND);//���Ƶ�������ͼ
						putimage(Width - HeroWidth * 5 - 100, 100, &monsteryuan, SRCPAINT);//���Ƶ���ԭͼ
						if (rand() % 4 == 0)//��������
						{
							crit = 200;
							drawtext(_T("�㱩���˵���"), &middle, DT_CENTER);
						}
						else
						{
							drawtext(_T("�㹥���˵���"), &middle, DT_CENTER);
						}
						EndBatchDraw();
						Sleep(1000);
						if (rand() % 3 == 0)
						{
							isblock = 1;
							drawtext(_T("���˸��˹���"), &middle1, DT_CENTER);
							Sleep(1000);
						}
						hurt = (float)((hero->adk + hero->arms.adk) * (100 + skill.attack_bonus + crit) / 100 - monster.def) * (float)(100 + skill.hurt_deepen) / 100;//�����˺�
						if (isblock) hurt /= 2;
						hurt = hurt > 0 ? hurt : 0;//ȷ���˺�Ϊ��ֵ
						monster.hp -= (int)hurt;//����Ѫ���仯
						
						if (skill.keeptime > 0)
						{
							if (skill.hp > 0) monster.hp -= skill.hp;
							else hero->hp += -skill.hp;
							skill.keeptime--;
						}
						if (skill.keeptime == 0)//���ܳ���ʱ��Ϊ��ʱЧ������
						{
							skill.armor_bonus = 0;
							skill.attack_bonus = 0;
							skill.dodge = 0;
							skill.hp = 0;
							skill.hurt_deepen = 0;
							skill.keeptime = 0;
							skill.mp = 0;
						}
					}
					
				}
				else if ((mouse.x >= Width / 2 - 50 && mouse.x <= Width / 2 + 50) && (mouse.y >= Height / 2 && mouse.y <= Height / 2 + 100) && mouse.mkLButton)//ʹ�ü���
				{
					isclink = 1;
					if (hero->skill == 0)
					{
						drawtext(_T("�㻹ûѧ��һ�ּ���"), &middle, DT_CENTER);
						Sleep(1000);
					}
					else 
					{	
						cleardevice();
						if (useskill(&skill, hero) == 1)
						{
							hero->mp -= skill.mp;
							if (skill.hp >= 0)
							{
								monster.hp -= skill.hp;
							}
							else hero->hp += -skill.hp;
							break;
						}
						else continue;
					}
				}
				else if ((mouse.x >= Width / 2 - 50 && mouse.x <= Width / 2 + 50) && (mouse.y >= Height / 2 + 100 && mouse.y <= Height / 2 + 200) && mouse.mkLButton)//����
				{
					return;
				}
				if (monster.hp <= 0)//��������
				{
					drawtext(_T("������˵���"), &middle2, DT_CENTER);
					hero->exe += monster.exe;//��þ���
					Sleep(1000);
					if (hero->exe >= hero->level * 10)//����
					{
						drawtext(_T("�������ˣ���"), &middle3, DT_CENTER);
						Sleep(1000);
						hero->level++;//����
						hero->hp = hero->mp = hero->level * 2 + 98;//Ѫ������
						hero->adk = hero->level * 2 + 5;
						hero->def = hero->level * 2 + 1;
						hero->exe = 0;
						if (hero->level % 5 == 0)//ÿ�弶ѧ��һ���¼���
						{
							getskill(hero);
						}
					}
					if (rand() % 10 == 0)
					{
						drawtext(_T("������Ʒ"), &runrect, DT_CENTER);
						Sleep(1000);
						getequipment(hero);
					}
					return;//����ս��
				}
				else if(isclink)
				{
					setfillcolor(RGB(220, 0, 0));//����Ѫ����ɫ
					solidrectangle(Width + 1 - (int)((float)((float)monster.hp / (float)(monster.level * 2 + 98)) * 200), 1, Width - 1, 15);//����Ѫ��
					Sleep(1000);
					break;
				}
				else continue;
			}
		}
		/*������ؽ׶�*/
		FlushMouseMsgBuffer();//�����껺��
		while (1)
		{
			BeginBatchDraw();
			putimage(0, 0, &fightscene);//����ս������
			rectangle(0, 0, 200, 16);//Ѫ���߿�
			rectangle(0, 24, 200, 41);//�����߿�
			rectangle(Width - 200, 0, Width, 16);//����Ѫ���߿�
			rectangle(Width - 200, 24, Width, 41);//���������߿�
			setfillcolor(RGB(255, 0, 0));//����Ѫ����ɫ
			solidrectangle(1, 1, (int)((float)((float)hero->hp / (float)(hero->level * 2 + 98)) * 200) - 1, 15);//Ѫ��
			solidrectangle(Width + 1 - (int)((float)((float)monster.hp / (float)(monster.level * 2 + 98)) * 200), 1, Width - 1, 15);//����Ѫ��
			setfillcolor(BLUE); //����������ɫ;
			solidrectangle(1, 25, (int)((float)((float)hero->mp / (float)(hero->level * 2 + 98)) * 200) - 1, 40);//����
			solidrectangle(Width + 1 - (int)((float)((float)monster.mp / (float)(monster.level * 2 + 98)) * 200), 25, Width - 1, 40);//��������
			putimage(100, 100, &heroyan, SRCAND);//������������ͼ
			putimage(100, 100, &heroyuan, SRCPAINT);//��������ԭͼ
			putimage(Width - HeroWidth * 5 - 100, 100, &monsteryan, SRCAND);//���Ƶ�������ͼ
			putimage(Width - HeroWidth * 5 - 100, 100, &monsteryuan, SRCPAINT);//���Ƶ���ԭͼ
			drawtext(_T("��"), &atackrect, DT_CENTER);
			drawtext(_T("����"), &skillrect, DT_CENTER);
			EndBatchDraw();
			hurt = 0;//��ʼ���˺�
			crit = 0;//��ʼ������
			isdodge = -1;//��ʼ������
			isblock = -1;//��ʼ����
			if(skill.dodge >= 0)
			dodge = 5;
			else dodge = 5 + skill.dodge < 0 ? 0 : 5 + skill.dodge;
			srand((unsigned)time(0));
			if (MouseHit())
			{
				mouse = GetMouseMsg();//��������Ϣ
				if ((mouse.x >= Width / 2 - 50 && mouse.x <= Width / 2 + 50) && (mouse.y >= Height / 2 - 100 && mouse.y <= Height / 2) && mouse.mkLButton)//����
				{
					
					if (rand() % 3 == 0)
						isblock = 1;    //�񵲳ɹ�
					else
						isblock = 0;	//��ʧ��
				}
				else if ((mouse.x >= Width / 2 - 50 && mouse.x <= Width / 2 + 50) && (mouse.y >= Height / 2 && mouse.y <= Height / 2 + 100) && mouse.mkLButton)
				{
					
					if (rand() % dodge == 0)
						isdodge = 1;	//���ܳɹ�
					else
						isdodge = 0;	//����ʧ��
				}
				else continue;

				BeginBatchDraw();
				putimage(0, 0, &fightscene);//����ս������
				rectangle(0, 0, 200, 16);//Ѫ���߿�
				rectangle(0, 24, 200, 41);//�����߿�
				rectangle(Width - 200, 0, Width, 16);//����Ѫ���߿�
				rectangle(Width - 200, 24, Width, 41);//���������߿�
				setfillcolor(RGB(255, 0, 0));//����Ѫ����ɫ
				solidrectangle(1, 1, (int)((float)((float)hero->hp / (float)(hero->level * 2 + 98)) * 200) - 1, 15);//Ѫ��
				solidrectangle(Width + 1 - (int)((float)((float)monster.hp / (float)(monster.level * 2 + 98)) * 200), 1, Width - 1, 15);//����Ѫ��
				setfillcolor(BLUE); //����������ɫ;
				solidrectangle(1, 25, (int)((float)((float)hero->mp / (float)(hero->level * 2 + 98)) * 200) - 1, 40);//����
				solidrectangle(Width + 1 - (int)((float)((float)monster.mp / (float)(monster.level * 2 + 98)) * 200), 25, Width - 1, 40);//��������
				putimage(150, 100, &monsteryan, SRCAND);//���Ƶ�������ͼ
				putimage(150, 100, &monsteryuan, SRCPAINT);//���Ƶ���ԭͼ
				if (isdodge == 1)//���ܳɹ�ʱ��������
				{
					putimage(0, 100, &heroyan, SRCAND);//������������ͼ
					putimage(0, 100, &heroyuan, SRCPAINT);//��������ԭͼ
					drawtext(_T("���ܳɹ�"), &middle, DT_CENTER);
					EndBatchDraw();
					Sleep(1000);
					break;
				}
				else
				{
					
					putimage(100, 100, &heroyan, SRCAND);//������������ͼ
					putimage(100, 100, &heroyuan, SRCPAINT);//��������ԭͼ

					srand((unsigned)time(0));//�����������
					if (rand() % 4 == 0)//��������
					{
						crit = 200;
						drawtext(_T("���˱�������"), &middle, DT_CENTER);
					}
					else
					{
						drawtext(_T("���˹�������"), &middle, DT_CENTER);
					}
					if(isdodge == 0) drawtext(_T("����ʧ��"), &middle1, DT_CENTER);
					else if(isblock == 1) drawtext(_T("�񵲳ɹ�"), &middle1, DT_CENTER);
					else if(isblock == 0) drawtext(_T("��ʧ��"), &middle1, DT_CENTER);
					else continue;
					EndBatchDraw();
					Sleep(1000);
					hurt = (float)(monster.adk  * (100 + crit) / 100 - hero->def * (100 + skill.armor_bonus) / 100); //�����˺�
					if (isblock) hurt /= 2;
					hurt = hurt > 0 ? hurt : 0;//ȷ���˺�Ϊ��ֵ
					hero->hp -= (int)hurt;//����Ѫ���仯
					if (hero->hp <= 0)//��������
					{
						drawtext(_T("ʤ���˱��ҳ��£������¿�ʼ"), &middle, DT_CENTER);
					
						Sleep(3000);
						exit(1);
					}
					else
					{
						setfillcolor(RGB(220, 0, 0));//����Ѫ����ɫ
						solidrectangle(1, 1, (int)((float)((float)hero->hp / (float)(hero->level * 2 + 98)) * 200) - 1, 15);//Ѫ��
						Sleep(1000);
					}

					break;
				}
			}
		}
	}
}

int exitgame()//�뿪��Ϸ
{
	MOUSEMSG mouse;
	
	RECT exit = { Width / 2 - 150,Height / 2 - 100,Width / 2 + 150,Height / 2 };
	RECT yes = { Width / 2 - 50,Height / 2,Width / 2 + 50,Height / 2 + 100 };
	RECT no = { Width / 2 - 50,Height / 2 + 100,Width / 2 + 50,Height / 2 + 200 };
	BeginBatchDraw();
	putimage(0, 0, &exit1);
	drawtext(_T("�����Ҫ����"), &exit, DT_CENTER);
	drawtext(_T("ȷ��"), &yes, DT_CENTER);
	drawtext(_T("ȡ��"), &no, DT_CENTER);
	EndBatchDraw();
	FlushMouseMsgBuffer();//�����껺��
	while (1)
	{
		if (MouseHit())
		{
			mouse = GetMouseMsg();
			if ((mouse.x >= Width / 2 - 50 && mouse.x <= Width / 2 + 50) && (mouse.y >= Height / 2 && mouse.y <= Height / 2 + 100) && mouse.mkLButton)
				return 1;
			else if ((mouse.x >= Width / 2 - 50 && mouse.x <= Width / 2 + 50) && (mouse.y >= Height / 2 + 100 && mouse.y <= Height / 2 + 200) && mouse.mkLButton)
				return 0;
		}
	}
	return 0;
}

void TcharToChar(const TCHAR * tchar, char * _char)//TCHARת��Ϊchar
{
	int iLength;
	//��ȡ�ֽڳ���   
	iLength = WideCharToMultiByte(CP_ACP, 0, tchar, -1, NULL, 0, NULL, NULL);
	//��tcharֵ����_char    
	WideCharToMultiByte(CP_ACP, 0, tchar, -1, _char, iLength, NULL, NULL);
}

void game(Hero *hero)//��Ϸ����
{
	putimage(0, 0, &transitions);//���ƹ���ͼ
	Sleep(3000);
	FILE *MONSTER;//�����ļ�ָ��
	Monster *head, *temp;
	int i = 0, j = 0, random = 0;
	Monster monster[Count];//������������
	int hero_x = 0, hero_y = 0;//��������
	char direction = 0;//����
	RECT archive = { Width - 100,0,Width,100 };//�浵��������
	RECT exit = { Width - 100,100,Width,200 };//�˳���������
	RECT middle = { 0,0, Width ,Height };
	MOUSEMSG mouse;
	head = temp = (Monster *)malloc(sizeof(Monster));//�����б�ͷ�ڵ�
	fopen_s(&MONSTER, "monster.txt", "r");//ֻ�����ļ�
	while (i != EOF)
	{
		temp->next = (Monster*)malloc(sizeof(Monster));
		temp = temp->next;
		fscanf_s(MONSTER, "%d", &temp->adk);
		fscanf_s(MONSTER, "%d", &temp->def);
		fscanf_s(MONSTER, "%d", &temp->exe);
		fscanf_s(MONSTER, "%d", &temp->hp);
		fscanf_s(MONSTER, "%d", &temp->level);
		fscanf_s(MONSTER, "%d", &temp->mp);
		fscanf_s(MONSTER, "%d", &temp->race);
		i = fscanf_s(MONSTER, "%s", temp->name, 20);
		if (temp->level >= (hero->scene - 1) * 20 && temp->level <= hero->scene * 20)//ɸѡ����ǰ�����ĵ���
			monster[j++] = *temp;//��ŵ�������
		if (j >= Count)break;
	}
	temp->next = NULL;

	FlushMouseMsgBuffer();//�����껺��
	while (1)
	{
	again:
		BeginBatchDraw();
		if (hero->scene == 1)
		{
			putimage(0, 0, &scene1);//����1
		}
		else if (hero->scene == 2)
		{
			putimage(0, 0, &scene2);//����2
		}
		else if (hero->scene == 3)
		{
			putimage(0, 0, &scene3);//����3
		}
		else if (hero->scene == 4)
		{
			putimage(0, 0, &scene4);//����4
		}
		else if (hero->scene == 5)
		{
			putimage(0, 0, &scene5);//����5
		}
		else if (hero->scene == 6)
		{
			putimage(0, 0, &scene6);//����6
		}
		putimage(Width - 100, Height - 100, &door);//����ͨ����һ�ص���
		putimage(0, Height - 100, &door);//����ͨ����һ�ص���
		drawtext(_T("�浵"), &archive, DT_CENTER);
		drawtext(_T("�˳�"), &exit, DT_CENTER);
		if (MouseHit())
		{
			mouse = GetMouseMsg();
			if ((mouse.x >= Width - 100 && mouse.x <= Width) && (mouse.y >= 0 && mouse.y <= 100) && mouse.mkLButton)
			{
				FILE * HERO;
				fopen_s(&HERO, "hero.txt", "w");
				fprintf_s(HERO, "%d %d %s %s %d %s %s %d %d %d %d %d %s %d %d", hero->adk, hero->armor.def, hero->armor.name, hero->armor.word, hero->arms.adk, hero->arms.name, hero->arms.word, hero->def, hero->exe, hero->hp, hero->level, hero->mp, hero->name, hero->scene, hero->skill);
				fclose(HERO);
			}
			else if ((mouse.x >= Width - 100 && mouse.x <= Width) && (mouse.y >= 100 && mouse.y <= 200) && mouse.mkLButton)
			{

				if (exitgame())
					return;
				else goto again;
			}
		}
		if (_kbhit())
		{
			direction = _getch();//��ȡ����
			direction = tolower(direction);//ת��ΪСд
			if (direction == 'w' && hero_y != 0) hero_y -= 5;
			if (direction == 'a' && hero_x != 0) hero_x -= 5;
			if (direction == 's' && hero_y + HeroHeight != Height) hero_y += 5;
			if (direction == 'd' && hero_x + HeroWidth != Width) hero_x += 5;
			srand((unsigned)time(0));
			if (rand() % 5 == 0)//�ڳ������м�����������
			{
				srand((unsigned)time(0));//�����������
				random = rand() % j;//�����������
				if (monster[random].level > hero->level + 5 )
					drawtext(_T("��������һ��ǿ��ĵ���"), &middle, DT_CENTER);
				else drawtext(_T("��������һ������"), &middle, DT_CENTER);
				EndBatchDraw();
				Sleep(1000);
				fight(hero, monster[random]);//��ս
				putimage(0, 0, &transitions);//����ͼ
				Sleep(3000);
				goto again;
			}
			else if (rand() % 4 == 0)
			{
				drawtext(_T("������+10Ѫƿ  hp +10"), &middle, DT_CENTER);
				Sleep(1000);
				hero->hp += 10;
				hero->hp = hero->hp >= hero->level * 2 + 98 ? hero->level * 2 + 98 : hero->hp;
			}
			else if (rand() % 4 == 1)
			{
				drawtext(_T("������+10��ƿ  mp +10"), &middle, DT_CENTER);
				Sleep(1000);
				hero->mp += 10;
				hero->mp = hero->mp >= hero->level * 2 + 98 ? hero->level * 2 + 98 : hero->mp;
			}
			else if (rand() % 40 == 0)
			{
				drawtext(_T("�����һ��װ��"), &middle, DT_CENTER);
				getequipment(hero);
			}
			
		}
		BeginBatchDraw();
		putimage(hero_x, hero_y, &mask, SRCAND);//������������ͼ
		putimage(hero_x, hero_y, &img, SRCPAINT);//��������ԭͼ
		EndBatchDraw();
		if (hero_x >= Width - 100 && hero_y >= Height - 100 && hero->scene < 6)
		{
			hero->scene++;//��һ��
			hero_x = 0, hero_y = 0;
			goto again;
		}
		else if (hero_x >= 0 && hero_y >= Height - 100 && hero->scene > 1)
		{
			hero->scene--;//��һ��
			hero_x = 0, hero_y = 0;
			goto again;
		}
	}
}

void readhero()//��ȡӢ��
{
	FILE *HERO;
	Hero hero;
	int i = 0;
	fopen_s(&HERO, "hero.txt", "r");
	// fscanf_s(HERO, "%d %d %s %s %d %s %s %d %d %d %d %d %s %d %d", &hero.adk, &hero.armor.def, hero.armor.name, hero.armor.word, &hero.arms.adk, hero.arms.name, hero.arms.word, &hero.def, &hero.exe, &hero.hp, &hero.level, &hero.mp, hero.name, &hero.scene, &hero.skill);

	fscanf_s(HERO, "%d ", &hero.adk);
	fscanf_s(HERO, "%d ", &hero.armor.def);
	fscanf_s(HERO, "%s", hero.armor.name, 20);
	fscanf_s(HERO, "%s", hero.armor.word, 100);
	fscanf_s(HERO, "%d", &hero.arms.adk);
	fscanf_s(HERO, "%s", hero.arms.name, 20);
	fscanf_s(HERO, "%s", hero.arms.word, 100);
	fscanf_s(HERO, "%d", &hero.def);
	fscanf_s(HERO, "%d", &hero.exe);
	fscanf_s(HERO, "%d", &hero.hp);
	fscanf_s(HERO, "%d", &hero.level);
	fscanf_s(HERO, "%d", &hero.mp);
	fscanf_s(HERO, "%s", hero.name, 20);
	fscanf_s(HERO, "%d", &hero.scene);
	fscanf_s(HERO, "%d", &hero.skill);

	fclose(HERO);
	game(&hero);
}

void newhero()//����������
{
	Hero hero;
	Armor armor;
	Arms arms;
	MOUSEMSG mouse;
	putimage(0, 0, &newhero1);//����ͼ
	armor.def = 0;
	strcpy_s(armor.name, "����");
	strcpy_s(armor.word, "���벻���²�����");
	arms.adk = 2;
	strcpy_s(arms.name, "����ذ��");
	strcpy_s(arms.word, "���ܳ��ָ���");
	hero.hp = 100;
	hero.mp = 100;
	hero.def = 3;
	hero.adk = 5;
	hero.armor = armor;
	hero.arms = arms;
	hero.exe = 0;
	hero.level = 1;
	hero.scene = 1;
	hero.skill = 0;
	while (1)
	{
		FlushMouseMsgBuffer();//�����껺��
		mouse = GetMouseMsg();
		if (mouse.mkLButton)
			break;//�������
	}
	TCHAR s[20];
	InputBox(s, 20, _T("������ϵͳ�������!\n\n\n����:"));
	TcharToChar(s, hero.name);
	game(&hero);
	return;
}

void wechatphoto()//�ҵ���Ϣ
{
	MOUSEMSG mouse;
	FlushMouseMsgBuffer();
	cleardevice();
	putimage(200, 0, &wechat1);
	RECT back = { 0,Height - 100,100,Height };//������������
	drawtext(_T("����"), &back, DT_CENTER);
	while (1)
	{
		if (MouseHit())
		{
			mouse = GetMouseMsg();
			if ((mouse.x >= 0 && mouse.x <= 100) && (mouse.y >= Height - 100 && mouse.y <= Height) && mouse.mkLButton)
			{
				return;
			}
		}
	}
}

void menu()//�˵�
{	
	MOUSEMSG mouse;//���
	initgraph(Width, Height);//����
	setbkmode(TRANSPARENT);//����͸��
	settextstyle(40, 0, _T("����"));//���壬��С
	settextcolor(WHITE);//����������ɫ

	RECT start = { Width / 2 - 100,Height / 2 - 50,Width / 2 + 100,Height / 2 + 25 };
	RECT read = { Width / 2 - 100,Height / 2 + 25,Width / 2 + 100,Height / 2 + 100 };
	RECT wechat = { Width / 2 - 100,Height / 2 + 100,Width / 2 + 100,Height / 2 + 175 };
	RECT exit = { Width / 2 - 100,Height / 2 + 175,Width / 2 + 100,Height / 2 + 250 };
	FlushMouseMsgBuffer();//�����껺��
	while (1)
	{

	label:	
		BeginBatchDraw();//��ʼ������ͼ
		putimage(0,0, &menu1);//��ʼ����
		drawtext(_T("��������"), &start, DT_CENTER);
		drawtext(_T("��������"), &read, DT_CENTER);
		drawtext(_T("������Ա"), &wechat, DT_CENTER);
		drawtext(_T("�����뿪"), &exit, DT_CENTER);
		EndBatchDraw();//����������ͼ
		if (MouseHit())
		{

			mouse = GetMouseMsg();
			if ((mouse.x >= Width / 2 - 100 && mouse.x <= Width / 2 + 100) && (mouse.y >= Height / 2 - 50 && mouse.y <= Height / 2 + 25) && mouse.mkLButton)
				newhero();

			else if ((mouse.x >= Width / 2 - 100 && mouse.x <= Width / 2 + 100) && (mouse.y >= Height / 2 + 25 && mouse.y <= Height / 2 + 100) && mouse.mkLButton)
				readhero();

			else if ((mouse.x >= Width / 2 - 100 && mouse.x <= Width / 2 + 100) && (mouse.y >= Height / 2 + 100 && mouse.y <= Height / 2 + 175) && mouse.mkLButton)
			{
				wechatphoto();
				goto label;
			}
			else if ((mouse.x >= Width / 2 - 100 && mouse.x <= Width / 2 + 100) && (mouse.y >= Height / 2 + 175 && mouse.y <= Height / 2 + 250) && mouse.mkLButton)
				return;
		}
	}
	closegraph();
}

int main()
{
	initgraph(Width, Height);//��ʼͼ�δ���
	loadall ();
	start();//��ʼ
	menu();
	closegraph();
	
	return 0;
}

