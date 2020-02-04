#include<iostream>
using namespace std;
/*
背景：公主被恶龙俘虏,等待程序员用智慧书写代码进行救援。
胜利条件:（析构公主后即胜利）
提示：可以创建dragon的实例。可以创建dragon的子类。
涉及:继承知识,成员属性权限 public和private和protected的区别 
不允许修改头文件中文本内容 
*/
class princess{						//公主
private:
	friend class dragon;
	princess(){
		cout << "公主被俘,等待救援." << endl;
	}
	~princess(){					
		cout << "公主成功被解救，胜利" << endl;
		exit(0);
	}
};


class dragon{						//恶龙，看守着一个公主
public:
	void tryRescue(){				//尝试进行救援
		cout << "救援失败." << endl;
	}
	dragon(){
		cout << "一条新的恶龙飞了过来" << endl;
	}
protected:
	void releaseThePrincess(){
		delete maid;
	}
private:
	static princess* maid;			//被看守的公主
};
princess* dragon::maid = new princess();