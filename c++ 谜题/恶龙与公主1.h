#include<iostream>
using namespace std;
/*
������������������²,�ȴ�����Ա���ǻ���д������о�Ԯ��
ʤ������:������������ʤ����
��ʾ�����Դ���dragon��ʵ�������Դ���dragon�����ࡣ
�漰:�̳�֪ʶ,��Ա����Ȩ�� public��private��protected������ 
�������޸�ͷ�ļ����ı����� 
*/
class princess{						//����
private:
	friend class dragon;
	princess(){
		cout << "��������,�ȴ���Ԯ." << endl;
	}
	~princess(){					
		cout << "�����ɹ�����ȣ�ʤ��" << endl;
		exit(0);
	}
};


class dragon{						//������������һ������
public:
	void tryRescue(){				//���Խ��о�Ԯ
		cout << "��Ԯʧ��." << endl;
	}
	dragon(){
		cout << "һ���µĶ������˹���" << endl;
	}
protected:
	void releaseThePrincess(){
		delete maid;
	}
private:
	static princess* maid;			//�����صĹ���
};
princess* dragon::maid = new princess();