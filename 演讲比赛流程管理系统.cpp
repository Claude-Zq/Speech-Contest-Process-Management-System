#include<iostream>
#include"speech_manager.h"
#include<ctime>



int main() {

	//���������
	srand((unsigned int)time(NULL));

	speech_manager sm;

	while (true) {
		int choice;
		sm.show_menu();
		std::cout << "����������ѡ��" << std::endl;
		/*��������кϷ��Լ��*/
		while (!(std::cin >> choice)) {
			std::cout << "��������,����������" << std::endl;
			std::cin.clear();/*������뻺����*/
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "����������ѡ��" << std::endl;
		}

		switch (choice) {
		case 1://��ʼ����
			sm.start_speech();
			break;
		case 2://�鿴��¼
			sm.show_record();
			break;
		case 3://��ռ�¼
			sm.clear_record();
			break;
		case 0://�˳�ϵͳ
			sm.exit_system();
			break;
		default:
		{
			std::cout << "�޸�ѡ��" << std::endl;
			std::system("pause");
			system("cls");//����
			break;
		}
			
		}
	}

	return 0;
}