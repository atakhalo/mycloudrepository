#pragma once
// ConsoleApplication2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <graphics.h>
#include <conio.h>
#include <time.h>

#define Height 680 
#define Width  1000
#define Count 20
#define HeroHeight 68
#define HeroWidth 40

typedef struct Skill//技能
{
	int mp;//消耗魔法
	int hp;//造成伤害
	int dodge;//闪避
	int keeptime;//持续时间
	int hurt_deepen;//伤害加深百分比
	int armor_bonus;//防御加成百分比
	int attack_bonus;//攻击加成
	char name[20];//技能名称
	char word[100];//技能描述
	Skill * next;//指向下个单元指针
}Skill;
typedef struct Armor//护甲
{
	int def;//防御值
	char name[20];//物品名称
	char word[100];//物品描述
	Armor *next;
}Armor;
typedef struct Arms//武器
{
	int adk;//攻击力
	char name[20];//物品名称
	char word[100];//物品描述
	Arms *next;
}Arms;
typedef struct Monster//敌人
{
	int mp;
	int hp;
	int exe;
	int level;
	char name[20];
	int adk;
	int def;
	int race;
	Monster *next;
}Monster;
typedef struct Hero//人物
{
	char name[20];//姓名
	int mp;//蓝量
	int hp;//血量
	int adk;//攻击力
	int def;//防御力
	int exe;//经验值
	int level;//等级
	int scene;//场景
	int skill;//技能
	Armor armor;//护甲
	Arms arms;//武器
}Hero;

IMAGE start1, start2, start3, start4, start5, start6, start7, start8;//用于加载start函数的图片
IMAGE menu1;//加载menu的图片
IMAGE wechat1;//微信图
IMAGE newhero1;//捏脸图
IMAGE transitions;//过场图
IMAGE img;//小人物图
IMAGE mask;//小掩码图
IMAGE door;//门
IMAGE scene1, scene2, scene3, scene4, scene5, scene6;//游戏场景图
IMAGE exit1;//退出图
IMAGE heroyuan ;//人物原图指针
IMAGE heroyan ;//人物掩码图指针
IMAGE monsteryuan1, monsteryuan2, monsteryuan3, monsteryuan4;//敌人原图指针
IMAGE monsteryan1, monsteryan2, monsteryan3, monsteryan4;//敌人掩码图指针
IMAGE fightscene;//战斗场景图
IMAGE getnewskill;//获得新技能
IMAGE getnewequipment;//获得装备
IMAGE useskillimage;

void loadall();//加载图片
void start();//开头动画
void getequipment(Hero *hero);//获得物品
void getskill(Hero *hero);//获得技能
void fight(Hero *hero, Monster monster);//战斗
int exitgame();//离开游戏
void TcharToChar(const TCHAR * tchar, char * _char);//TCHAR转换为char
void game(Hero *hero);//游戏场景
void readhero();//读取英雄
void newhero();//创建新人物
void wechatphoto();//我的信息
void menu();//菜单