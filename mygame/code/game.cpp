// ConsoleApplication2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <graphics.h>
#include <conio.h>
#include <time.h>
#include "game2.0.h"

void loadall()//加载图片
{
	loadimage(&start1, _T("天下大乱.jpg"), Width, Height);
	loadimage(&start2, _T("妖魔横生.jpg"), Width, Height);
	loadimage(&start3, _T("鲲鹏.jpg"), Width, Height);
	loadimage(&start4, _T("幽冥.jpg"), Width, Height);
	loadimage(&start5, _T("妖僧.jpg"), Width, Height);
	loadimage(&start6, _T("暴君.jpg"), Width, Height);
	loadimage(&start7, _T("生灵涂炭.jpg"), Width, Height);
	loadimage(&start8, _T("圣光.jpg"), Width, Height);
	loadimage(&menu1, _T("1.jpg"), Width, Height);
	loadimage(&wechat1, _T("wechat1.jpg"), 600, 800);
	loadimage(&newhero1, _T("捏脸.jpg"), Width, Height);
	loadimage(&transitions, _T("过场1.jpg"), Width, Height);
	loadimage(&img, _T("人物原图.jpg"), HeroWidth, HeroHeight);//加载人物图
	loadimage(&mask, _T("人物掩码图.jpg"), HeroWidth, HeroHeight);//加载掩码图
	loadimage(&door, _T("传送门.jpg"), 100, 100);//加载传送门
	loadimage(&scene1, _T("场景1.jpg"), Width, Height);
	loadimage(&scene2, _T("场景2.jpg"), Width, Height);
	loadimage(&scene3, _T("场景3.jpg"), Width, Height);
	loadimage(&scene4, _T("场景4.jpg"), Width, Height);
	loadimage(&scene5, _T("场景5.jpg"), Width, Height);
	loadimage(&scene6, _T("场景6.jpg"), Width, Height);
	loadimage(&exit1, _T("退出游戏.jpg"), Width, Height);
	loadimage(&heroyuan, _T("人物原图.jpg"), HeroWidth * 5, HeroHeight * 5);//加载人物原图
	loadimage(&heroyan, _T("人物掩码图.jpg"), HeroWidth * 5, HeroHeight * 5);//加载人物掩码图
	loadimage(&monsteryuan1, _T("恶狼原图.jpg"), HeroWidth * 5, HeroHeight * 5);//加载敌人原图
	loadimage(&monsteryan1, _T("恶狼掩码图.jpg"), HeroWidth * 5, HeroHeight * 5);//加载敌人掩码图
	loadimage(&monsteryuan2, _T("将军原图.jpg"), HeroWidth * 5, HeroHeight * 5);//加载敌人原图
	loadimage(&monsteryan2, _T("将军掩码图.jpg"), HeroWidth * 5, HeroHeight * 5);//加载敌人掩码图
	loadimage(&monsteryuan3, _T("鬼魂原图.jpg"), HeroWidth * 5, HeroHeight * 5);//加载敌人原图
	loadimage(&monsteryan3, _T("鬼魂掩码图.jpg"), HeroWidth * 5, HeroHeight * 5);//加载敌人掩码图
	loadimage(&monsteryuan4, _T("妖僧原图.jpg"), HeroWidth * 5, HeroHeight * 5);//加载敌人原图
	loadimage(&monsteryan4, _T("妖僧掩码图.jpg"), HeroWidth * 5, HeroHeight * 5);//加载敌人掩码图
	loadimage(&fightscene, _T("战斗场景1.jpg"), Width, Height);//绘制战斗背景
	loadimage(&getnewskill, _T("getskill.jpg"), Width, Height);
	loadimage(&getnewequipment, _T("宝箱.jpg"), Width, Height);
	loadimage(&useskillimage, _T("羊皮纸.jpg"), Width, Height);
}

void start()															//开头动画
{
	initgraph(Width, Height);//开始图形窗口
	RECT r = { 0, 0, Width,Height };//范围
	setbkmode(TRANSPARENT);//设置背景透明
	settextcolor(RGB(255, 255, 255));//设置字体颜色
	settextstyle(40, 0, _T("楷体"));//字体，大小
	putimage(0, 0, &start1);
	drawtext(_T("时天下大乱"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);//文字
	Sleep(3000);//等候
	cleardevice();
	putimage(0, 0, &start2);
	drawtext(_T("妖魔横生"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	Sleep(3000);
	cleardevice();
	putimage(0, 0, &start3);
	drawtext(_T("北冥鲲鹏"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	Sleep(3000);
	cleardevice();
	putimage(0, 0, &start4);
	drawtext(_T("南海幽冥"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	Sleep(3000);
	putimage(0, 0, &start5);
	drawtext(_T("西天妖僧"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	Sleep(3000);
	putimage(0, 0, &start6);
	drawtext(_T("东方暴君"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	Sleep(3000);
	putimage(0, 0, &start7);
	drawtext(_T("八荒六合，众生皆苦。"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	Sleep(3000);
	putimage(0, 0, &start8);
	drawtext(_T("忽一日，圣光天降，玉字隐现："), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	Sleep(3000);
	putimage(0, 0, &start8);
	settextcolor(RGB(175, 238, 238));
	drawtext(_T("英雄圣临，披坚持锐，勇者无畏，战魂不屈。"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	Sleep(3000);
	cleardevice();
	closegraph();
}

void CharToTchar(const char * _char, TCHAR * tchar)//char转TCHAR
{
	int iLength;

	iLength = MultiByteToWideChar(CP_ACP, 0, _char, strlen(_char) + 1, NULL, 0);
	MultiByteToWideChar(CP_ACP, 0, _char, strlen(_char) + 1, tchar, iLength);
}

void getequipment(Hero *hero)//获得物品
{
	RECT top = { 0,0,Width,Height };
	RECT middle = { 0 , Height / 2 - 140 ,Width, Height };//用于显示居中文字
	RECT middle1 = { 0 , Height / 2 - 80 ,Width, Height };//用于显示居中第二行文字
	RECT middle2 = { 0 , Height / 2 - 20  ,Width, Height };//用于显示居中第三行文字
	RECT change = { Width / 2 - 50  ,Height / 2 + 100, Width / 2 + 50 ,Height };
	RECT abondon = { Width / 2 - 50 ,Height / 2 + 170 , Width / 2 + 50 ,Height };
	
	FILE *EQUIPMENT;//装备文件指针
	Arms temp;
	TCHAR name[20];
	TCHAR equipmentword[100];
	char filename[20];
	MOUSEMSG mouse;
	srand((unsigned)time(0));
	int choice = rand() % 2;//随机选择护甲和武器
	
	if (choice == 0) //获得护甲
		strcpy_s(filename, "armors.txt");
	else			//获得武器
		strcpy_s(filename, "arms.txt");
	int random  = rand()%10;//随机获得装备
	int iseof;//判断文件结束；
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
	putimage(0, 0, &getnewequipment);//绘制背景
	drawtext(_T("你得到了"), &middle, DT_CENTER);
	drawtext(name, &middle1, DT_CENTER );
	drawtext(equipmentword, &middle2, DT_CENTER);
	drawtext(_T("装备"), &change, DT_CENTER);
	drawtext(_T("扔掉"), &abondon, DT_CENTER);
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
				drawtext(_T("装备成功"), &top, DT_CENTER);
				Sleep(1000);
				return;
			}
			else if (mouse.x >= Width / 2 - 50 && mouse.x <= Width / 2 + 50 && mouse.y >= Height / 2 + 170 && mouse.y <= Height / 2 + 200 && mouse.mkLButton)
			{
				drawtext(_T("成功扔掉"), &top, DT_CENTER);
				Sleep(1000);
				return;
			}
			else continue;
		}
	}
	return;
}

void getskill(Hero *hero)//获得技能
{
	RECT middle = { 0 , Height / 2 - 100 ,Width, Height };//用于显示居中文字
	RECT middle1 = { 0 , Height / 2 - 40 ,Width, Height };//用于显示居中第二行文字
	RECT middle2 = { 0 , Height / 2 + 20  ,Width, Height };//用于显示居中第三行文字
	FILE *SKILL;//技能文件指针
	Skill skill;
	TCHAR name[20];
	TCHAR skillword[100];
	int iseof = 0;
	hero->skill++;//技能+1
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
	putimage(0, 0, &getnewskill);//绘制背景
	drawtext(_T("你学会了"), &middle, DT_CENTER );
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
	FILE *SKILL;//技能文件指针
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
	drawtext(_T("返回"), &back, DT_CENTER);
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
						drawtext(_T("魔法不足"), &tips, DT_CENTER);
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

void fight(Hero *hero, Monster monster)//战斗
{
	RECT atackrect = { Width / 2 - 50,Height / 2 - 100,Width / 2 + 50,Height / 2 };
	RECT skillrect = { Width / 2 - 50,Height / 2,Width / 2 + 50,Height / 2 + 100 };
	RECT runrect = { Width / 2 - 100,Height / 2 + 100,Width / 2 + 100,Height / 2 + 200 };
	RECT middle = { 0 , 0 ,Width, Height };//用于显示居中文字
	RECT middle1 = { 0,30,Width,Height };
	RECT middle2 = { 0,60,Width,Height };
	RECT middle3 = { 0,90,Width,Height };
	RECT middle4 = { 0,120,Width,Height };
	MOUSEMSG mouse;//鼠标
	IMAGE monsteryuan;
	IMAGE monsteryan;

	float hurt = 0;//伤害量
	int dodge = 5;//闪避几率
	Skill skill;
	skill.armor_bonus = 0;
	skill.attack_bonus = 0;
	skill.dodge = 0;
	skill.hp = 0;
	skill.hurt_deepen = 0;
	skill.keeptime = 0;
	skill.mp = 0;
	int crit = 0;//暴击
	int isblock = 0;
	int isdodge = 0;
	int a = 0;
	int isclink = 0;
	settextcolor(WHITE);//设置字体颜色
	
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
		FlushMouseMsgBuffer();//清除鼠标缓存
		 /*人物进攻阶段*/
		while (1)
		{
			hurt = 0;//初始化伤害量
			crit = 0;//初始化暴击
			isblock = 0;//初始化格挡
			if (skill.dodge > 0)
				dodge += skill.dodge;//闪避几率初始值加上技能闪避几率
			else dodge = 5;
			BeginBatchDraw();//开始批量绘制
			putimage(0, 0, &fightscene);//战斗背景
			rectangle(0, 0, 200, 16);//血条边框
			rectangle(0, 24, 200, 41);//蓝条边框
			rectangle(Width - 200, 0, Width, 16);//敌人血条边框
			rectangle(Width - 200, 24, Width, 41);//敌人蓝条边框
			setfillcolor(RGB(255, 0, 0));//设置血条颜色
			solidrectangle(1, 1, (int)((float)((float)hero->hp / (float)(hero->level * 2 + 98)) * 200) - 1, 15);//血条
			solidrectangle(Width + 1 - (int)((float)((float)monster.hp / (float)(monster.level * 2 + 98)) * 200), 1, Width - 1, 15);//敌人血条
			setfillcolor(BLUE); //设置蓝条颜色;
			solidrectangle(1, 25, (int)((float)((float)hero->mp / (float)(hero->level * 2 + 98)) * 200) - 1, 40);//蓝条
			solidrectangle(Width + 1 - (int)((float)((float)monster.mp / (float)(monster.level * 2 + 98)) * 200), 25, Width - 1, 40);//敌人蓝条
			putimage(100, 100, &heroyan, SRCAND);//绘制人物掩码图
			putimage(100, 100, &heroyuan, SRCPAINT);//绘制人物原图
			putimage(Width - HeroWidth * 5 - 100, 100, &monsteryan, SRCAND);//绘制敌人掩码图
			putimage(Width - HeroWidth * 5 - 100, 100, &monsteryuan, SRCPAINT);//绘制敌人原图
			drawtext(_T("攻击"), &atackrect, DT_CENTER);
			drawtext(_T("技能"), &skillrect, DT_CENTER);
			drawtext(_T("逃跑"), &runrect, DT_CENTER);
			EndBatchDraw();//绘制图
			if (MouseHit())
			{
				isclink = 0;
				mouse = GetMouseMsg();//获得鼠标信息
				if ((mouse.x >= Width / 2 - 50 && mouse.x <= Width / 2 + 50) && (mouse.y >= Height / 2 - 100 && mouse.y <= Height / 2) && mouse.mkLButton)//攻击
				{
					isclink = 1;
					BeginBatchDraw();
					putimage(0, 0, &fightscene);
					rectangle(0, 0, 200, 16);//血条边框
					rectangle(0, 24, 200, 41);//蓝条边框
					rectangle(Width - 200, 0, Width, 16);//敌人血条边框
					rectangle(Width - 200, 24, Width, 41);//敌人蓝条边框
					setfillcolor(RGB(255, 0, 0));//设置血条颜色
					solidrectangle(1, 1, (int)((float)((float)hero->hp / (float)(hero->level * 2 + 98)) * 200) - 1, 15);//血条
					solidrectangle(Width + 1 - (int)((float)((float)monster.hp / (float)(monster.level * 2 + 98)) * 200), 1, Width - 1, 15);//敌人血条
					setfillcolor(BLUE); //设置蓝条颜色;
					solidrectangle(1, 25, (int)((float)((float)hero->mp / (float)(hero->level * 2 + 98)) * 200) - 1, 40);//蓝条
					solidrectangle(Width + 1 - (int)((float)((float)monster.mp / (float)(monster.level * 2 + 98)) * 200), 25, Width - 1, 40);//敌人蓝条
					putimage(Width - HeroWidth * 5 - 200, 100, &heroyan, SRCAND);//绘制人物掩码图
					putimage(Width - HeroWidth * 5 - 200, 100, &heroyuan, SRCPAINT);//绘制人物原图
					EndBatchDraw();
					srand((unsigned)time(0));
					if (rand() % dodge == 0)//敌人一定几率闪避
					{
						BeginBatchDraw();
						putimage(Width - HeroWidth * 5, 100, &monsteryan, SRCAND);//绘制敌人掩码图
						putimage(Width - HeroWidth * 5, 100, &monsteryuan, SRCPAINT);//绘制敌人原图
						drawtext(_T("敌人躲过了你的攻击"), &middle, DT_CENTER);//文字说明
						EndBatchDraw();
						Sleep(1000);
					}
					else
					{
						BeginBatchDraw();
						putimage(Width - HeroWidth * 5 - 100, 100, &monsteryan, SRCAND);//绘制敌人掩码图
						putimage(Width - HeroWidth * 5 - 100, 100, &monsteryuan, SRCPAINT);//绘制敌人原图
						if (rand() % 4 == 0)//暴击几率
						{
							crit = 200;
							drawtext(_T("你暴击了敌人"), &middle, DT_CENTER);
						}
						else
						{
							drawtext(_T("你攻击了敌人"), &middle, DT_CENTER);
						}
						EndBatchDraw();
						Sleep(1000);
						if (rand() % 3 == 0)
						{
							isblock = 1;
							drawtext(_T("敌人格挡了攻击"), &middle1, DT_CENTER);
							Sleep(1000);
						}
						hurt = (float)((hero->adk + hero->arms.adk) * (100 + skill.attack_bonus + crit) / 100 - monster.def) * (float)(100 + skill.hurt_deepen) / 100;//计算伤害
						if (isblock) hurt /= 2;
						hurt = hurt > 0 ? hurt : 0;//确保伤害为正值
						monster.hp -= (int)hurt;//敌人血条变化
						
						if (skill.keeptime > 0)
						{
							if (skill.hp > 0) monster.hp -= skill.hp;
							else hero->hp += -skill.hp;
							skill.keeptime--;
						}
						if (skill.keeptime == 0)//技能持续时间为零时效果归零
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
				else if ((mouse.x >= Width / 2 - 50 && mouse.x <= Width / 2 + 50) && (mouse.y >= Height / 2 && mouse.y <= Height / 2 + 100) && mouse.mkLButton)//使用技能
				{
					isclink = 1;
					if (hero->skill == 0)
					{
						drawtext(_T("你还没学会一种技能"), &middle, DT_CENTER);
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
				else if ((mouse.x >= Width / 2 - 50 && mouse.x <= Width / 2 + 50) && (mouse.y >= Height / 2 + 100 && mouse.y <= Height / 2 + 200) && mouse.mkLButton)//逃跑
				{
					return;
				}
				if (monster.hp <= 0)//敌人死亡
				{
					drawtext(_T("你击败了敌人"), &middle2, DT_CENTER);
					hero->exe += monster.exe;//获得经验
					Sleep(1000);
					if (hero->exe >= hero->level * 10)//升级
					{
						drawtext(_T("你升级了！！"), &middle3, DT_CENTER);
						Sleep(1000);
						hero->level++;//升级
						hero->hp = hero->mp = hero->level * 2 + 98;//血蓝回满
						hero->adk = hero->level * 2 + 5;
						hero->def = hero->level * 2 + 1;
						hero->exe = 0;
						if (hero->level % 5 == 0)//每五级学会一个新技能
						{
							getskill(hero);
						}
					}
					if (rand() % 10 == 0)
					{
						drawtext(_T("掉落物品"), &runrect, DT_CENTER);
						Sleep(1000);
						getequipment(hero);
					}
					return;//结束战斗
				}
				else if(isclink)
				{
					setfillcolor(RGB(220, 0, 0));//设置血条颜色
					solidrectangle(Width + 1 - (int)((float)((float)monster.hp / (float)(monster.level * 2 + 98)) * 200), 1, Width - 1, 15);//敌人血条
					Sleep(1000);
					break;
				}
				else continue;
			}
		}
		/*人物防守阶段*/
		FlushMouseMsgBuffer();//清除鼠标缓存
		while (1)
		{
			BeginBatchDraw();
			putimage(0, 0, &fightscene);//绘制战斗背景
			rectangle(0, 0, 200, 16);//血条边框
			rectangle(0, 24, 200, 41);//蓝条边框
			rectangle(Width - 200, 0, Width, 16);//敌人血条边框
			rectangle(Width - 200, 24, Width, 41);//敌人蓝条边框
			setfillcolor(RGB(255, 0, 0));//设置血条颜色
			solidrectangle(1, 1, (int)((float)((float)hero->hp / (float)(hero->level * 2 + 98)) * 200) - 1, 15);//血条
			solidrectangle(Width + 1 - (int)((float)((float)monster.hp / (float)(monster.level * 2 + 98)) * 200), 1, Width - 1, 15);//敌人血条
			setfillcolor(BLUE); //设置蓝条颜色;
			solidrectangle(1, 25, (int)((float)((float)hero->mp / (float)(hero->level * 2 + 98)) * 200) - 1, 40);//蓝条
			solidrectangle(Width + 1 - (int)((float)((float)monster.mp / (float)(monster.level * 2 + 98)) * 200), 25, Width - 1, 40);//敌人蓝条
			putimage(100, 100, &heroyan, SRCAND);//绘制人物掩码图
			putimage(100, 100, &heroyuan, SRCPAINT);//绘制人物原图
			putimage(Width - HeroWidth * 5 - 100, 100, &monsteryan, SRCAND);//绘制敌人掩码图
			putimage(Width - HeroWidth * 5 - 100, 100, &monsteryuan, SRCPAINT);//绘制敌人原图
			drawtext(_T("格挡"), &atackrect, DT_CENTER);
			drawtext(_T("闪避"), &skillrect, DT_CENTER);
			EndBatchDraw();
			hurt = 0;//初始化伤害
			crit = 0;//初始化暴击
			isdodge = -1;//初始化闪避
			isblock = -1;//初始化格挡
			if(skill.dodge >= 0)
			dodge = 5;
			else dodge = 5 + skill.dodge < 0 ? 0 : 5 + skill.dodge;
			srand((unsigned)time(0));
			if (MouseHit())
			{
				mouse = GetMouseMsg();//获得鼠标信息
				if ((mouse.x >= Width / 2 - 50 && mouse.x <= Width / 2 + 50) && (mouse.y >= Height / 2 - 100 && mouse.y <= Height / 2) && mouse.mkLButton)//攻击
				{
					
					if (rand() % 3 == 0)
						isblock = 1;    //格挡成功
					else
						isblock = 0;	//格挡失败
				}
				else if ((mouse.x >= Width / 2 - 50 && mouse.x <= Width / 2 + 50) && (mouse.y >= Height / 2 && mouse.y <= Height / 2 + 100) && mouse.mkLButton)
				{
					
					if (rand() % dodge == 0)
						isdodge = 1;	//闪避成功
					else
						isdodge = 0;	//闪避失败
				}
				else continue;

				BeginBatchDraw();
				putimage(0, 0, &fightscene);//绘制战斗背景
				rectangle(0, 0, 200, 16);//血条边框
				rectangle(0, 24, 200, 41);//蓝条边框
				rectangle(Width - 200, 0, Width, 16);//敌人血条边框
				rectangle(Width - 200, 24, Width, 41);//敌人蓝条边框
				setfillcolor(RGB(255, 0, 0));//设置血条颜色
				solidrectangle(1, 1, (int)((float)((float)hero->hp / (float)(hero->level * 2 + 98)) * 200) - 1, 15);//血条
				solidrectangle(Width + 1 - (int)((float)((float)monster.hp / (float)(monster.level * 2 + 98)) * 200), 1, Width - 1, 15);//敌人血条
				setfillcolor(BLUE); //设置蓝条颜色;
				solidrectangle(1, 25, (int)((float)((float)hero->mp / (float)(hero->level * 2 + 98)) * 200) - 1, 40);//蓝条
				solidrectangle(Width + 1 - (int)((float)((float)monster.mp / (float)(monster.level * 2 + 98)) * 200), 25, Width - 1, 40);//敌人蓝条
				putimage(150, 100, &monsteryan, SRCAND);//绘制敌人掩码图
				putimage(150, 100, &monsteryuan, SRCPAINT);//绘制敌人原图
				if (isdodge == 1)//闪避成功时人物左移
				{
					putimage(0, 100, &heroyan, SRCAND);//绘制人物掩码图
					putimage(0, 100, &heroyuan, SRCPAINT);//绘制人物原图
					drawtext(_T("闪避成功"), &middle, DT_CENTER);
					EndBatchDraw();
					Sleep(1000);
					break;
				}
				else
				{
					
					putimage(100, 100, &heroyan, SRCAND);//绘制人物掩码图
					putimage(100, 100, &heroyuan, SRCPAINT);//绘制人物原图

					srand((unsigned)time(0));//设置随机种子
					if (rand() % 4 == 0)//暴击几率
					{
						crit = 200;
						drawtext(_T("敌人暴击了你"), &middle, DT_CENTER);
					}
					else
					{
						drawtext(_T("敌人攻击了你"), &middle, DT_CENTER);
					}
					if(isdodge == 0) drawtext(_T("闪避失败"), &middle1, DT_CENTER);
					else if(isblock == 1) drawtext(_T("格挡成功"), &middle1, DT_CENTER);
					else if(isblock == 0) drawtext(_T("格挡失败"), &middle1, DT_CENTER);
					else continue;
					EndBatchDraw();
					Sleep(1000);
					hurt = (float)(monster.adk  * (100 + crit) / 100 - hero->def * (100 + skill.armor_bonus) / 100); //计算伤害
					if (isblock) hurt /= 2;
					hurt = hurt > 0 ? hurt : 0;//确保伤害为正值
					hero->hp -= (int)hurt;//人物血条变化
					if (hero->hp <= 0)//人物死亡
					{
						drawtext(_T("胜败乃兵家常事，请重新开始"), &middle, DT_CENTER);
					
						Sleep(3000);
						exit(1);
					}
					else
					{
						setfillcolor(RGB(220, 0, 0));//设置血条颜色
						solidrectangle(1, 1, (int)((float)((float)hero->hp / (float)(hero->level * 2 + 98)) * 200) - 1, 15);//血条
						Sleep(1000);
					}

					break;
				}
			}
		}
	}
}

int exitgame()//离开游戏
{
	MOUSEMSG mouse;
	
	RECT exit = { Width / 2 - 150,Height / 2 - 100,Width / 2 + 150,Height / 2 };
	RECT yes = { Width / 2 - 50,Height / 2,Width / 2 + 50,Height / 2 + 100 };
	RECT no = { Width / 2 - 50,Height / 2 + 100,Width / 2 + 50,Height / 2 + 200 };
	BeginBatchDraw();
	putimage(0, 0, &exit1);
	drawtext(_T("你真的要走吗"), &exit, DT_CENTER);
	drawtext(_T("确定"), &yes, DT_CENTER);
	drawtext(_T("取消"), &no, DT_CENTER);
	EndBatchDraw();
	FlushMouseMsgBuffer();//清除鼠标缓存
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

void TcharToChar(const TCHAR * tchar, char * _char)//TCHAR转换为char
{
	int iLength;
	//获取字节长度   
	iLength = WideCharToMultiByte(CP_ACP, 0, tchar, -1, NULL, 0, NULL, NULL);
	//将tchar值赋给_char    
	WideCharToMultiByte(CP_ACP, 0, tchar, -1, _char, iLength, NULL, NULL);
}

void game(Hero *hero)//游戏场景
{
	putimage(0, 0, &transitions);//绘制过场图
	Sleep(3000);
	FILE *MONSTER;//敌人文件指针
	Monster *head, *temp;
	int i = 0, j = 0, random = 0;
	Monster monster[Count];//敌人种类数组
	int hero_x = 0, hero_y = 0;//人物坐标
	char direction = 0;//按键
	RECT archive = { Width - 100,0,Width,100 };//存档文字区域
	RECT exit = { Width - 100,100,Width,200 };//退出文字区域
	RECT middle = { 0,0, Width ,Height };
	MOUSEMSG mouse;
	head = temp = (Monster *)malloc(sizeof(Monster));//敌人列表头节点
	fopen_s(&MONSTER, "monster.txt", "r");//只读打开文件
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
		if (temp->level >= (hero->scene - 1) * 20 && temp->level <= hero->scene * 20)//筛选出当前场景的敌人
			monster[j++] = *temp;//存放敌人种类
		if (j >= Count)break;
	}
	temp->next = NULL;

	FlushMouseMsgBuffer();//清除鼠标缓存
	while (1)
	{
	again:
		BeginBatchDraw();
		if (hero->scene == 1)
		{
			putimage(0, 0, &scene1);//场景1
		}
		else if (hero->scene == 2)
		{
			putimage(0, 0, &scene2);//场景2
		}
		else if (hero->scene == 3)
		{
			putimage(0, 0, &scene3);//场景3
		}
		else if (hero->scene == 4)
		{
			putimage(0, 0, &scene4);//场景4
		}
		else if (hero->scene == 5)
		{
			putimage(0, 0, &scene5);//场景5
		}
		else if (hero->scene == 6)
		{
			putimage(0, 0, &scene6);//场景6
		}
		putimage(Width - 100, Height - 100, &door);//绘制通往下一关的门
		putimage(0, Height - 100, &door);//绘制通往上一关的门
		drawtext(_T("存档"), &archive, DT_CENTER);
		drawtext(_T("退出"), &exit, DT_CENTER);
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
			direction = _getch();//获取按键
			direction = tolower(direction);//转换为小写
			if (direction == 'w' && hero_y != 0) hero_y -= 5;
			if (direction == 'a' && hero_x != 0) hero_x -= 5;
			if (direction == 's' && hero_y + HeroHeight != Height) hero_y += 5;
			if (direction == 'd' && hero_x + HeroWidth != Width) hero_x += 5;
			srand((unsigned)time(0));
			if (rand() % 5 == 0)//在场景中有几率碰到敌人
			{
				srand((unsigned)time(0));//设置随机种子
				random = rand() % j;//随机敌人种类
				if (monster[random].level > hero->level + 5 )
					drawtext(_T("你遇到了一个强大的敌人"), &middle, DT_CENTER);
				else drawtext(_T("你遇到了一个敌人"), &middle, DT_CENTER);
				EndBatchDraw();
				Sleep(1000);
				fight(hero, monster[random]);//交战
				putimage(0, 0, &transitions);//过场图
				Sleep(3000);
				goto again;
			}
			else if (rand() % 4 == 0)
			{
				drawtext(_T("你获得了+10血瓶  hp +10"), &middle, DT_CENTER);
				Sleep(1000);
				hero->hp += 10;
				hero->hp = hero->hp >= hero->level * 2 + 98 ? hero->level * 2 + 98 : hero->hp;
			}
			else if (rand() % 4 == 1)
			{
				drawtext(_T("你获得了+10蓝瓶  mp +10"), &middle, DT_CENTER);
				Sleep(1000);
				hero->mp += 10;
				hero->mp = hero->mp >= hero->level * 2 + 98 ? hero->level * 2 + 98 : hero->mp;
			}
			else if (rand() % 40 == 0)
			{
				drawtext(_T("你捡到了一件装备"), &middle, DT_CENTER);
				getequipment(hero);
			}
			
		}
		BeginBatchDraw();
		putimage(hero_x, hero_y, &mask, SRCAND);//绘制人物掩码图
		putimage(hero_x, hero_y, &img, SRCPAINT);//绘制人物原图
		EndBatchDraw();
		if (hero_x >= Width - 100 && hero_y >= Height - 100 && hero->scene < 6)
		{
			hero->scene++;//下一关
			hero_x = 0, hero_y = 0;
			goto again;
		}
		else if (hero_x >= 0 && hero_y >= Height - 100 && hero->scene > 1)
		{
			hero->scene--;//上一关
			hero_x = 0, hero_y = 0;
			goto again;
		}
	}
}

void readhero()//读取英雄
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

void newhero()//创建新人物
{
	Hero hero;
	Armor armor;
	Arms arms;
	MOUSEMSG mouse;
	putimage(0, 0, &newhero1);//捏脸图
	armor.def = 0;
	strcpy_s(armor.name, "布衣");
	strcpy_s(armor.word, "起码不是衣不蔽体");
	arms.adk = 2;
	strcpy_s(arms.name, "破碎匕首");
	strcpy_s(arms.word, "可能赤手更好");
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
		FlushMouseMsgBuffer();//清除鼠标缓存
		mouse = GetMouseMsg();
		if (mouse.mkLButton)
			break;//点击跳出
	}
	TCHAR s[20];
	InputBox(s, 20, _T("假捏人系统，别点了!\n\n\n名字:"));
	TcharToChar(s, hero.name);
	game(&hero);
	return;
}

void wechatphoto()//我的信息
{
	MOUSEMSG mouse;
	FlushMouseMsgBuffer();
	cleardevice();
	putimage(200, 0, &wechat1);
	RECT back = { 0,Height - 100,100,Height };//返回文字区域
	drawtext(_T("返回"), &back, DT_CENTER);
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

void menu()//菜单
{	
	MOUSEMSG mouse;//鼠标
	initgraph(Width, Height);//窗口
	setbkmode(TRANSPARENT);//背景透明
	settextstyle(40, 0, _T("楷体"));//字体，大小
	settextcolor(WHITE);//设置字体颜色

	RECT start = { Width / 2 - 100,Height / 2 - 50,Width / 2 + 100,Height / 2 + 25 };
	RECT read = { Width / 2 - 100,Height / 2 + 25,Width / 2 + 100,Height / 2 + 100 };
	RECT wechat = { Width / 2 - 100,Height / 2 + 100,Width / 2 + 100,Height / 2 + 175 };
	RECT exit = { Width / 2 - 100,Height / 2 + 175,Width / 2 + 100,Height / 2 + 250 };
	FlushMouseMsgBuffer();//清除鼠标缓存
	while (1)
	{

	label:	
		BeginBatchDraw();//开始批量绘图
		putimage(0,0, &menu1);//开始界面
		drawtext(_T("宝剑出鞘"), &start, DT_CENTER);
		drawtext(_T("卷土归来"), &read, DT_CENTER);
		drawtext(_T("开发人员"), &wechat, DT_CENTER);
		drawtext(_T("狠心离开"), &exit, DT_CENTER);
		EndBatchDraw();//结束批量绘图
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
	initgraph(Width, Height);//开始图形窗口
	loadall ();
	start();//开始
	menu();
	closegraph();
	
	return 0;
}

