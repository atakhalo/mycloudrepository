#pragma once
// ConsoleApplication2.cpp : �������̨Ӧ�ó������ڵ㡣
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

typedef struct Skill//����
{
	int mp;//����ħ��
	int hp;//����˺�
	int dodge;//����
	int keeptime;//����ʱ��
	int hurt_deepen;//�˺�����ٷֱ�
	int armor_bonus;//�����ӳɰٷֱ�
	int attack_bonus;//�����ӳ�
	char name[20];//��������
	char word[100];//��������
	Skill * next;//ָ���¸���Ԫָ��
}Skill;
typedef struct Armor//����
{
	int def;//����ֵ
	char name[20];//��Ʒ����
	char word[100];//��Ʒ����
	Armor *next;
}Armor;
typedef struct Arms//����
{
	int adk;//������
	char name[20];//��Ʒ����
	char word[100];//��Ʒ����
	Arms *next;
}Arms;
typedef struct Monster//����
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
typedef struct Hero//����
{
	char name[20];//����
	int mp;//����
	int hp;//Ѫ��
	int adk;//������
	int def;//������
	int exe;//����ֵ
	int level;//�ȼ�
	int scene;//����
	int skill;//����
	Armor armor;//����
	Arms arms;//����
}Hero;

IMAGE start1, start2, start3, start4, start5, start6, start7, start8;//���ڼ���start������ͼƬ
IMAGE menu1;//����menu��ͼƬ
IMAGE wechat1;//΢��ͼ
IMAGE newhero1;//����ͼ
IMAGE transitions;//����ͼ
IMAGE img;//С����ͼ
IMAGE mask;//С����ͼ
IMAGE door;//��
IMAGE scene1, scene2, scene3, scene4, scene5, scene6;//��Ϸ����ͼ
IMAGE exit1;//�˳�ͼ
IMAGE heroyuan ;//����ԭͼָ��
IMAGE heroyan ;//��������ͼָ��
IMAGE monsteryuan1, monsteryuan2, monsteryuan3, monsteryuan4;//����ԭͼָ��
IMAGE monsteryan1, monsteryan2, monsteryan3, monsteryan4;//��������ͼָ��
IMAGE fightscene;//ս������ͼ
IMAGE getnewskill;//����¼���
IMAGE getnewequipment;//���װ��
IMAGE useskillimage;

void loadall();//����ͼƬ
void start();//��ͷ����
void getequipment(Hero *hero);//�����Ʒ
void getskill(Hero *hero);//��ü���
void fight(Hero *hero, Monster monster);//ս��
int exitgame();//�뿪��Ϸ
void TcharToChar(const TCHAR * tchar, char * _char);//TCHARת��Ϊchar
void game(Hero *hero);//��Ϸ����
void readhero();//��ȡӢ��
void newhero();//����������
void wechatphoto();//�ҵ���Ϣ
void menu();//�˵�