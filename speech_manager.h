#pragma once
#include<iostream>
#include<vector>
#include<map>
#include"speaker.h"
#include<deque>
#include<functional>
#include<numeric>
#include<algorithm>
#include<iomanip>
#include<string>
#include<cmath>

const float eps = 1e-8;
#define Equ(a,b) (fabs( (a) - (b) ) < (eps) )

//����ݽ�������
class speech_manager {
public:
	/*���캯��*/
	speech_manager();

	//�˵�����
	void show_menu();

	//�˳�����
	void exit_system();

	/*��������*/
	~speech_manager();

	//��ʼ������������
	void init_speech();

	//����ѡ��
	void create_speaker();

	//��ʼ����
	void start_speech();

	//��ǩ
	void speech_draw();

	//����
	void speech_contest();

	//չʾ�������
	void show_score();

	
private:

	//��Ա����
	/*�����һ�ֱ���ѡ�ֱ������*/
	std::vector<int> v1;

	/*��һ�ֽ���ѡ�ֱ������*/
	std::vector<int> v2;

	/*ʤ��ǰ����ѡ�ֱ������*/
	std::vector<int> v3;

	/*��� ���-�����ѡ��(ID To Speaker) ��ӳ��*/
	std::map<int, speaker> ITS;

	//��ű�������
	int m_index;

};
