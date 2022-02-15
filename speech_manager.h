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



//设计演讲管理类
class speech_manager {
public:
	/*构造函数*/
	speech_manager();

	//菜单功能
	void show_menu();

	//退出功能
	void exit_system();

	//模拟一场比赛
	void start_speech();

	//显示往届分数
	void show_record();

	//清空记录
	void clear_record();

	/*析构函数*/
	~speech_manager();
	
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

	//文件为空的标志
	bool file_is_empty;

	//往届记录
	std::map<int, std::vector<std::string>> m_record;

	//成员方法

	//初始化容器和属性
	void init_speech();

	//创建选手
	void create_speaker();

	//读取往届记录
	void load_record();

	//保存记录
	void save_record();

	//展示比赛结果
	void show_score();

	//抽签
	void speech_draw();

	//一轮比赛
	void speech_contest();

	//延时函数
	void delay();

};
