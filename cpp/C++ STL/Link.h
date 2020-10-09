#ifndef LINK_H_
#define LINK_H_

#include "Node.h"

/*
 * ��LinkedList������У������˸���ָ��front��rear��������ĽṹΪfront->a1->a2->...->rear
 *ֻ�������������в�ɾ��������ָ�룬����ʱ��������ָ�붼�Ǵ��ڵģ����е�����ʼ��Ϊ0�����洢�û�����
 */

template <class T> class LinkedList {
private:
  Node<T> *front, *rear; //��ͷ�ͱ�βָ��
  Node<T> *prevPtr, *currPtr; //��¼��ǰ����λ�õ�ָ�룬�ɲ����ɾ����������
  int size;     //����Ԫ�ظ���
  int position; //��ǰԪ���ڱ��е�λ����š��ɺ���resetʹ��

  Node<T> *newNode(
      const T &item,
      Node<T> *ptrNext = nullptr); //�����½ڵ㣬������Ϊitem��ָ����ΪprtNext
  void freeNode(Node<T> *p); //�ͷŽ��

  void copy(
      const LinkedList<T> &
          L); //������L���Ƶ���ǰ�����赱ǰ��Ϊ�գ��������ƹ��캯����ooperator=����
public:
  LinkedList();                                     //���캯��
  LinkedList(const LinkedList<T> &L);               //���ƹ��캯��
  ~LinkedList();                                    //��������
  LinkedList<T> &operator=(const LinkedList<T> &L); //���ظ�ֵ�����

  int getSize() const;  //����������Ԫ�ظ���
  bool isEmpty() const; //�����Ƿ�Ϊ��

  void reset(int pos = 0);     //��ʼ���α�λ��
  void next();                 //ʹ�α��ƶ�����һ���ڵ�
  bool endOfList() const;      //�α��Ƿ��ƶ�����β
  int currentPosition() const; //�����α굱ǰλ��

  void insertFront(const T &item); //�ڱ�ͷ����ڵ�
  void insertRear(const T &item);  //�ڱ�β����ڵ�
  void insertAt(const T &item);    //�ڵ�ǰ�ڵ�֮ǰ����ڵ�
  void insertAfter(const T &item); //�ڵ�ǰ�ڵ�֮�����ڵ�

  T deleteFront();      //ɾ���ڵ�ͷ
  void deleteCurrent(); //ɾ����ǰ�ڵ�

  T &data();             //���ضԵ�ǰ�ڵ��Ա���ݵ�����
  const T &data() const; //���ضԵ�ǰ�ڵ��Ա���ݵĳ�����

  void clear(); //��������ͷ����нڵ���ڴ�ռ䣬������������ooperator=ʹ��
};

//�����½ڵ㣬������Ϊitem��ָ����ΪprtNext
template <class T>
Node<T> *LinkedList<T>::newNode(const T &item, Node<T> *ptrNext) {
  Node<T> *n = new Node<T>(item, ptrNext);
  return n;
}

//�ͷŽڵ�
template <class T> void LinkedList<T>::freeNode(Node<T> *p) {
  Node<T> *temp = front;
  while (temp->next != p) {
    temp = temp->next;
    if (temp == currPtr)
      position++;
  }
  temp->next = p->next;
  if (currPtr == p)
    currPtr = currPtr->next;
  if (prevPtr == p) {
    prevPtr = prevPtr->next;
    currPtr = currPtr->next;
  }
  delete p;
  size--;
  position--;
}

//������L���Ƶ���ǰ�����赱ǰ��Ϊ�գ��������ƹ��캯����operator=����
template <class T> void LinkedList<T>::copy(const LinkedList<T> &L) {
  Node<T> *temp = L.front, *ptr = front;
  while (temp != L.rear) {
    ptr->next = new Node<T>(temp->getData, nullptr);
    ptr = ptr->next;
    temp = temp->next;
  }
  ptr->next = rear;
  size = L.getSize();
  position = L.currentPosition();
}

//���캯��
template <class T> LinkedList<T>::LinkedList() {
  front = new Node<T>();
  rear = new Node<T>();
  front->next = rear;
  prevPtr = front;
  size = 0; //������front��rear
  position = 0;
}

//���ƹ��캯��
template <class T> LinkedList<T>::LinkedList(const LinkedList<T> &L) {
  clear();
  copy();
}

//��������
template <class T> LinkedList<T>::~LinkedList() {
  LinkedList::clear();
  delete front;
  delete rear;
}

//���ظ�ֵ�����
template <class T>
LinkedList<T> &LinkedList::operator=(const LinkedList<T> &L) {
  clear();
  copy(L);
}

//����������Ԫ�ظ���
template <class T> int LinkedList<T>::getSize() const { return size; }

//�����Ƿ�Ϊ��
template <class T> bool LinkedList<T>::isEmpty() const { return (size == 0); }

//��ʼ���α�λ��
tempalte<class T> void LinkedList<T>::reset(int pos) {
  //��ʼ���α�λ��
  if (pos > size) {
    cout << "Խ�磬�޷�����" << endl;
  }
}

#endif LINK_H_