#include <stdio.h>
#include "Stack.h"
#include <string>
#include "LinkedList.h"

using namespace std;

void prnMenu(){
	cout<<"*******************************************"<<endl;
	cout<<"* 1. 삽입    2. 삭제    3. 출력   4. 종료 *"<<endl;
	cout<<"*******************************************"<<endl;
	cout<<endl;
	cout<<"원하시는 메뉴를 골라주세요: ";
}

int main(){
	    int mode, selectNumber, tmpItem;
		LinkedList<int> *p;
		bool flag = false; //종료 커맨드 입력 시 차별화하기 위한 boolean형 변수

		cout<<"자료구조 선택(1: Stack, Other: Linked List): ";
		cin>>mode;
						    
		if(mode == 1)
			p = new Stack<int>();    // 정수를 저장하는 스택
			
		else
			p = new LinkedList<int>(); //정수를 저장하는 링크드리스트


		do{
			prnMenu(); //기본 메뉴얼 출력
			cin>>selectNumber; //입력 숫자에 해당하는 옵션 수행
			
			switch(selectNumber){ 
				case 1: // class에 원소 삽입
					cout<<"원하시는 값을 입력해주세요: ";
					cin>>tmpItem;    p->Insert(tmpItem);
					cout<<tmpItem<<"가 삽입되었습니다."<<endl;
					break;
					
				case 2: // class의 원소 삭제, 자료구조에 따라 삭제되는 원소 위치 다름
					if(p->Delete(tmpItem)==true)
						cout<<tmpItem<<"가 삭제되었습니다."<<endl;
						
					else cout<<"비어있습니다. 삭제 실패"<<endl;
					break;
					
				case 3: // class에 있는 노드 목록 출력
					cout<<"크기: "<<p->GetSize()<<endl;
					p->Print();
					break;
					
				case 4: // 프로그램 종료
					flag = true;     break;
					
				default: // 옵션 숫자들 이외의 숫자가 잘못 입력된 경우
					cout<<"잘못 입력하셨습니다."<<endl;
					break;
			
			}
			
			if(flag) break;
			
		} while(1);
		
		return 0;
}

