#ifndef __LINKEDLIST__
#define __LINKEDLIST__

#include <iostream>
using namespace std;

//LinkedList Node
template <class T>
class Node{
	public:
		//데이터를 저장할 변수
		T data;
		//노드구조체 이용; 다음노드의 주소를 저장할 포인터
		Node<T> *link;

		Node(T element){
		  data = element;
		  link = 0;
		}
	};

//LinkedList Class
template <class T>
class LinkedList{
	protected:
		//첫번째 노드의 주소를 저장할 포인터
		Node<T> *first;
		int current_size;
	public:
		//생성자, 초기화 
		LinkedList<T>(){
			first = 0;
			current_size = 0;
		};

		//노드 개수를 리턴
		int GetSize(){
			return current_size;
		};

		//맨 앞에 원소를 삽입, LinkedList와 Stack 둘다 같다
		void Insert(T element);
		
		//맨 뒤의 원소를 삭제, 제일 나중에 들어온 원소 삭제  - LinkedList
		virtual bool Delete(T &element);

		//리스트 출력
		void Print();
};


//새 노드를 맨 앞에 붙이고 값을 넣음
template <class T>
void LinkedList<T>::Insert(T element){
	//노드 생성
	Node<T> *newnode = new Node<T>(element);

	//새 노드가 첫번째 노드를 가리킴
	//newnode는 포인터이기 때문에 -> 를 사용해 함수, 변수를 불러옴 newnode.link와 뜻은 같다
	newnode -> link = first;
	first = newnode;
	current_size++;
}

//마지막 노드의 값을 리턴하면서 메모리에서 할당 해제
template <class T>
bool LinkedList<T>::Delete(T &element){

	//노드가 없으면 first가 0이므로 에러메세지 출력과  동시에 false 리턴
	if (first == 0) {
		cout << "There is nothing in LinkedList.\n";
		return false;
	}

	//노드 삭제 시 데이터 값 없어지지 않도록 임시로 노드 생성
	Node<T> *current = first;
	Node<T> *previous = 0;
	
	//마지막 노드까지 찾아가는 반복문
	while(1){
		if (current->link == 0){  //current가 마지막 노드인 경우
			if (previous) //노드가 하나인 경우
				previous -> link = current -> link;
			else //노드가 여러 개인 경우
				first = first -> link;
			break;
		}
		
		//다음 노드로 이동
		previous = current;
		current = current -> link;
	}
	element = current -> data; //element에 삭제할 노드의 데이터 저장
	delete current; //current에 할당한 메모리 삭제
	current_size--; //노드 하나 삭제했으므로 크기 1 감소

	return true;
}

//리스트를 출력하는 Print 함수
template <class T>
void LinkedList<T>::Print(){
	Node<T> *i;
	int index = 1; //몇 번째 노드인지 저장할 정수형 index

	if (current_size != 0){ //노드가 하나도 없다면 출력할 리스트가 없음
		for( i = first; i != NULL; i=i->link){ //i가 마지막 노드에 도달할 때까지 반복문 수행
			if (index == current_size){ //마지막 노드에 대한 출력
				cout << "[" << index << "|";
				cout << i -> data <<"]"; //마지막 노드이므로 화살표 출력 하지 않음
			}
			
			else { //마지막 노드 이외의 노드에 대한 출력
				cout << "[" << index << "|";
				cout << i -> data << "]->";
				index++;
			}
		}
		cout << endl;
	}

}
#endif
