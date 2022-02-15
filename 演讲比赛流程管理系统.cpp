#include<iostream>
#include"speech_manager.h"
#include<ctime>



int main() {

	//随机数种子
	srand((unsigned int)time(NULL));

	speech_manager sm;

	while (true) {
		int choice;
		sm.show_menu();
		std::cout << "请输入您的选择：" << std::endl;
		/*对输入进行合法性检查*/
		while (!(std::cin >> choice)) {
			std::cout << "输入有误,请重新输入" << std::endl;
			std::cin.clear();/*清空输入缓冲区*/
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "请输入您的选择：" << std::endl;
		}

		switch (choice) {
		case 1://开始比赛
			sm.start_speech();
			break;
		case 2://查看记录
			sm.show_record();
			break;
		case 3://清空记录
			sm.clear_record();
			break;
		case 0://退出系统
			sm.exit_system();
			break;
		default:
		{
			std::cout << "无该选项" << std::endl;
			std::system("pause");
			system("cls");//清屏
			break;
		}
			
		}
	}

	return 0;
}