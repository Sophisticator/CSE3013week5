#ifndef __STACK__
#define __STACK__

#include "LinkedList.h"
#include <iostream>
using namespace std;

//1. 템플릿 클래스로 확장해야함
//2. Stack형식으로 Delete 함수 재정의해야함
//주의: first, current_size는 class의 멤버 변수이기 때문에 this 포인터를 사용하여 가져와야함

//LinkedList class를 상속받음
template <class T>
class Stack : public LinkedList<T>{
	public:
		virtual bool Delete (T &element){
			//first가 0이면 에러메세지 출력과 함께 false반환
			if (this->first == 0) {
				cout << "There is nothing in Stack.\n";
				return false;
			}

			// LinkedList와 달리 Stack은 current가 가리키는 곳을 삭제
			else {
				Node<T>* target = this->first;

				//포인터를 두 번째 노드로 이동시키며 첫 번째 노드 삭제
				element = target->data;
				this->first = target->link;
				delete target;
				this->current_size--;
				return true;
			}
		}
};
#endif
