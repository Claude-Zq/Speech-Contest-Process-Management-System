#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include<map>
#include"speaker.h"
#include<deque>
#include<functional>
#include<numeric>
#include<algorithm>
#include<iomanip>
#include<string>
#include<ctime>



//����ݽ�������
class speech_manager {
public:
	/*���캯��*/
	speech_manager();

	//�˵�����
	void show_menu();

	//�˳�����
	void exit_system();

	//ģ��һ������
	void start_speech();

	//��ʾ�������
	void show_record();

	//��ռ�¼
	void clear_record();

	/*��������*/
	~speech_manager();
	
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

	//�ļ�Ϊ�յı�־
	bool file_is_empty;

	//�����¼
	std::map<int, std::vector<std::string>> m_record;

	//��Ա����

	//��ʼ������������
	void init_speech();

	//����ѡ��
	void create_speaker();

	//��ȡ�����¼
	void load_record();

	//�����¼
	void save_record();

	//չʾ�������
	void show_score();

	//��ǩ
	void speech_draw();

	//һ�ֱ���
	void speech_contest();

	//��ʱ����
	void delay();

};
