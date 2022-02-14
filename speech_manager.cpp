#include"speech_manager.h"




speech_manager::speech_manager() {
	/*��ʼ������������*/
	init_speech();
	
	/*����ѡ��*/
	create_speaker();
}

void speech_manager::show_menu() {
	
	std::cout << "**************************************" << std::endl;
	std::cout << "**************************************" << std::endl;
	std::cout << "*********** ��ӭ�μ��ݽ����� *********" << std::endl;
	std::cout << "*********** 1.��ʼ�ݽ����� ***********" << std::endl;
	std::cout << "*********** 2.�鿴�����¼ ***********" << std::endl;
	std::cout << "*********** 3.��ձ�����¼ ***********" << std::endl;
	std::cout << "*********** 0.�˳��������� ***********" << std::endl;
	std::cout << "**************************************" << std::endl;
	std::cout << "**************************************" << std::endl;
	std::cout << std::endl;

}

void speech_manager::exit_system(){
	std::cout << "��ӭ�´�ʹ��" << std::endl;
	system("pause");
	exit(0);
}

void speech_manager::init_speech() {
	//�����ÿ�
	v1.clear();
	v2.clear();
	v3.clear();
	ITS.clear();
	/*��������*/
	m_index = 1;
}

void speech_manager::create_speaker() {
	std::string name_seed = "ABCDEFGHIJKL";
	for (int i = 0; i < name_seed.size(); i++) {
		std::string name = "ѡ��";
		name += name_seed[i];
		
		speaker sp;
		sp.m_name = name;
		for (int i = 0; i < 2; i++) sp.m_score[i] = 0;

		//12��ѡ�ֱ��
		v1.push_back(i + 10001);
		//ѡ�ֱ�� �Լ���Ӧ��ѡ�֣��浽map������
		ITS.insert(std::pair<int, speaker>(i + 10001, sp));
	}
}

void speech_manager::start_speech() {
	//��һ�ֱ���

	//1.��ǩ
	speech_draw();

	//2.����
	speech_contest();

	//3.��ʾ�������
	show_score();

	system("pause");
	system("cls"); /*�������������*/
	show_menu();

	m_index++;

	//�ڶ��ֱ���

	//1.��ǩ
	speech_draw();

	//2.����
	speech_contest();

	//3.��ʾ���ս��
	show_score();

	system("pause");
	system("cls"); /*�������������*/

	//4.�������
}

void speech_manager::speech_draw(){
	std::cout << "��<<" << m_index << ">>��\nѡ�����ڳ�ǩ" << std::endl;
	std::cout << "-----------------------------------------------------" << std::endl;
	std::cout << "��ǩ�������" << std::endl;
	
	if (m_index == 1) {/*��һ��*/
		std::random_shuffle(v1.begin(), v1.end()); /*����˳��*/
		for (std::vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
			std::cout << *it << " ";
		}
	}
	else {/*�ڶ���*/
		std::random_shuffle(v2.begin(), v2.end());
		for (std::vector<int>::iterator it = v2.begin(); it != v2.end(); it++) {
			std::cout << *it << " ";
		}
	}
	std::cout << "\n-----------------------------------------------------" << std::endl;
	system("pause");

}

void speech_manager::speech_contest() {
	std::cout << "----��<<" << m_index << ">>�ֱ�����ʽ��ʼ----" << std::endl;
	for (int i = 0; i < 95; i++) std::cout.put('-'); std::cout << std::endl;/*�ָ���*/

	//���С��ɼ�����ʱ����(score to id)
	std::multimap<double, int, std::greater<double>> STI;
	int num = 0;//��¼��Ա����

	/*����ѡ�ֵ�����*/
	std::vector<int> v = (m_index == 1 ? v1 : v2);

	std::cout << "���\t" << "�ݽ���" << "\t\t\t\t����\t\t\t\t��߷�\t��ͷ�\tƽ����" << std::endl;
	for (int i = 0; i < 95; i++) std::cout.put('-'); std::cout << std::endl;/*�ָ���*/
	//��������ѡ��
	for (auto it = v.begin(); it != v.end(); it++) {
		
		num++;
		std::deque<double> d; /*��¼ÿλ��ί�Ĵ��*/
		std::cout << *it << "\t" << ITS[*it].m_name << "\t";/*�����ź�����*/
		std::cout << std::setiosflags(std::ios::fixed);
		std::cout << std::setprecision(1);/*�������һλС��*/
		for (int i = 0; i < 10; i++) {
			double score = (rand() % 401 + 600) / 10.f; //�������60.0��100.0�ķ���
			std::cout  << score <<' ';
			d.push_back(score);
		}
		std::sort(d.begin(), d.end(), std::greater<double>());//����

		std::cout <<'\t' << d.front() << '\t' << d.back() << '\t';
		d.pop_front();d.pop_back();/*ȥ����߷ֺ���ͷ�*/

		double sum = std::accumulate(d.begin(), d.end(), 0.0f);
		double avg = sum / (double)d.size();
		std::cout << avg << std::endl;/*���ƽ����*/

		ITS[*it].m_score[m_index - 1] = avg;//��ƽ���ַ��뵽ITS(id to speaker)������
		STI.insert(std::make_pair(avg, *it));
		for (int i = 0; i < 95; i++) std::cout.put('-'); std::cout << std::endl;/*�ָ���*/

		//ÿ��������ȡ��ǰ����
		if (num % 6 == 0) {
			std::cout << "��<<" << num / 6 << ">>С��������Σ�" << std::endl
				<< "���\t" << "����\t" << "�ɼ�" << std::endl;
			for (auto it = STI.begin(); it != STI.end(); it++) {
				std::cout << it->second<<'\t'
					<< ITS[it->second].m_name <<'\t'
					<< it->first << std::endl;
			}
			for (int i = 0; i < 95; i++) std::cout.put('-'); std::cout << std::endl;/*�ָ���*/
			
			
			int cnt = 0; /*ȡ��ǰ����*/
			for (auto it = STI.begin(); it != STI.end() && cnt < 3; it++,cnt++) {
				if(m_index ==2) v3.push_back(it->second);
				else v2.push_back(it->second);
			}
			
			STI.clear();/*�����ʱ����*/
		}

	}
	
	std::cout << "----------��" << m_index << "�ֱ������----------" << std::endl;
	system("pause");
}

void speech_manager::show_score() {
	
	std::vector<int> v = (m_index == 1) ? v2 : v3;
	if (m_index == 1) std::cout << "----------��һ��ѡ�ֽ���ѡ����Ϣ����-----------" << std::endl;
	else std::cout << "-----------���ճɼ�����----------" << std::endl;

	std::cout << "���\t����\t�ɼ�" << std::endl;
	for (int i = 0; i < v.size(); i++) {
		
		std::cout << v[i] 
			<< '\t' << ITS[v[i]].m_name 
			<< '\t' << ITS[v[i]].m_score[m_index - 1]<< std::endl;
	}
	std::cout << std::endl;
}

speech_manager::~speech_manager() {

}