#include"speech_manager.h"




speech_manager::speech_manager() {
	/*初始化容器和属性*/
	init_speech();
	
	/*创建选手*/
	create_speaker();
}

void speech_manager::show_menu() {
	
	std::cout << "**************************************" << std::endl;
	std::cout << "**************************************" << std::endl;
	std::cout << "*********** 欢迎参加演讲比赛 *********" << std::endl;
	std::cout << "*********** 1.开始演讲比赛 ***********" << std::endl;
	std::cout << "*********** 2.查看往届记录 ***********" << std::endl;
	std::cout << "*********** 3.清空比赛记录 ***********" << std::endl;
	std::cout << "*********** 0.退出比赛程序 ***********" << std::endl;
	std::cout << "**************************************" << std::endl;
	std::cout << "**************************************" << std::endl;
	std::cout << std::endl;

}

void speech_manager::exit_system(){
	std::cout << "欢迎下次使用" << std::endl;
	system("pause");
	exit(0);
}

void speech_manager::init_speech() {
	//容器置空
	v1.clear();
	v2.clear();
	v3.clear();
	ITS.clear();
	/*比赛轮数*/
	m_index = 1;
}

void speech_manager::create_speaker() {
	std::string name_seed = "ABCDEFGHIJKL";
	for (int i = 0; i < name_seed.size(); i++) {
		std::string name = "选手";
		name += name_seed[i];
		
		speaker sp;
		sp.m_name = name;
		for (int i = 0; i < 2; i++) sp.m_score[i] = 0;

		//12名选手编号
		v1.push_back(i + 10001);
		//选手编号 以及对应的选手，存到map容器中
		ITS.insert(std::pair<int, speaker>(i + 10001, sp));
	}
}

void speech_manager::start_speech() {
	//第一轮比赛

	//1.抽签
	speech_draw();

	//2.比赛
	speech_contest();

	//3.显示晋级结果
	show_score();

	system("pause");
	system("cls"); /*按任意键后清屏*/
	show_menu();

	m_index++;

	//第二轮比赛

	//1.抽签
	speech_draw();

	//2.比赛
	speech_contest();

	//3.显示最终结果
	show_score();

	system("pause");
	system("cls"); /*按任意键后清屏*/

	//4.保存分数
}

void speech_manager::speech_draw(){
	std::cout << "第<<" << m_index << ">>轮\n选手正在抽签" << std::endl;
	std::cout << "-----------------------------------------------------" << std::endl;
	std::cout << "抽签结果如下" << std::endl;
	
	if (m_index == 1) {/*第一轮*/
		std::random_shuffle(v1.begin(), v1.end()); /*打乱顺序*/
		for (std::vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
			std::cout << *it << " ";
		}
	}
	else {/*第二轮*/
		std::random_shuffle(v2.begin(), v2.end());
		for (std::vector<int>::iterator it = v2.begin(); it != v2.end(); it++) {
			std::cout << *it << " ";
		}
	}
	std::cout << "\n-----------------------------------------------------" << std::endl;
	system("pause");

}

void speech_manager::speech_contest() {
	std::cout << "----第<<" << m_index << ">>轮比赛正式开始----" << std::endl;
	for (int i = 0; i < 95; i++) std::cout.put('-'); std::cout << std::endl;/*分割线*/

	//存放小组成绩的临时容器(score to id)
	std::multimap<double, int, std::greater<double>> STI;
	int num = 0;//记录人员个数

	/*比赛选手的容器*/
	std::vector<int> v = (m_index == 1 ? v1 : v2);

	std::cout << "编号\t" << "演讲者" << "\t\t\t\t分数\t\t\t\t最高分\t最低分\t平均分" << std::endl;
	for (int i = 0; i < 95; i++) std::cout.put('-'); std::cout << std::endl;/*分割线*/
	//遍历所有选手
	for (auto it = v.begin(); it != v.end(); it++) {
		
		num++;
		std::deque<double> d; /*记录每位评委的打分*/
		std::cout << *it << "\t" << ITS[*it].m_name << "\t";/*输出编号和姓名*/
		std::cout << std::setiosflags(std::ios::fixed);
		std::cout << std::setprecision(1);/*输出保留一位小数*/
		for (int i = 0; i < 10; i++) {
			double score = (rand() % 401 + 600) / 10.f; //随机生成60.0到100.0的分数
			std::cout  << score <<' ';
			d.push_back(score);
		}
		std::sort(d.begin(), d.end(), std::greater<double>());//排序

		std::cout <<'\t' << d.front() << '\t' << d.back() << '\t';
		d.pop_front();d.pop_back();/*去掉最高分和最低分*/

		double sum = std::accumulate(d.begin(), d.end(), 0.0f);
		double avg = sum / (double)d.size();
		std::cout << avg << std::endl;/*输出平均分*/

		ITS[*it].m_score[m_index - 1] = avg;//将平均分放入到ITS(id to speaker)容器中
		STI.insert(std::make_pair(avg, *it));
		for (int i = 0; i < 95; i++) std::cout.put('-'); std::cout << std::endl;/*分割线*/

		//每六个人呢取出前三名
		if (num % 6 == 0) {
			std::cout << "第<<" << num / 6 << ">>小组比赛名次：" << std::endl
				<< "编号\t" << "姓名\t" << "成绩" << std::endl;
			for (auto it = STI.begin(); it != STI.end(); it++) {
				std::cout << it->second<<'\t'
					<< ITS[it->second].m_name <<'\t'
					<< it->first << std::endl;
			}
			for (int i = 0; i < 95; i++) std::cout.put('-'); std::cout << std::endl;/*分割线*/
			
			
			int cnt = 0; /*取出前三名*/
			for (auto it = STI.begin(); it != STI.end() && cnt < 3; it++,cnt++) {
				if(m_index ==2) v3.push_back(it->second);
				else v2.push_back(it->second);
			}
			
			STI.clear();/*清空临时容器*/
		}

	}
	
	std::cout << "----------第" << m_index << "轮比赛完毕----------" << std::endl;
	system("pause");
}

void speech_manager::show_score() {
	
	std::vector<int> v = (m_index == 1) ? v2 : v3;
	if (m_index == 1) std::cout << "----------第一轮选手晋级选手信息如下-----------" << std::endl;
	else std::cout << "-----------最终成绩如下----------" << std::endl;

	std::cout << "编号\t姓名\t成绩" << std::endl;
	for (int i = 0; i < v.size(); i++) {
		
		std::cout << v[i] 
			<< '\t' << ITS[v[i]].m_name 
			<< '\t' << ITS[v[i]].m_score[m_index - 1]<< std::endl;
	}
	std::cout << std::endl;
}

speech_manager::~speech_manager() {

}