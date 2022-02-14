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

//设计演讲管理类
class speech_manager {
public:
	/*构造函数*/
	speech_manager();

	//菜单功能
	void show_menu();

	//退出功能
	void exit_system();

	/*析构函数*/
	~speech_manager();

	//初始化容器和属性
	void init_speech();

	//创建选手
	void create_speaker();

	//开始比赛
	void start_speech();

	//抽签
	void speech_draw();

	//比赛
	void speech_contest();

	//展示比赛结果
	void show_score();

	
private:

	//成员属性
	/*保存第一轮比赛选手编号容器*/
	std::vector<int> v1;

	/*第一轮晋级选手编号容器*/
	std::vector<int> v2;

	/*胜出前三名选手编号容器*/
	std::vector<int> v3;

	/*存放 编号-具体的选手(ID To Speaker) 的映射*/
	std::map<int, speaker> ITS;

	//存放比赛轮数
	int m_index;

};
