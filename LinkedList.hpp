#ifndef LINKEDLIST
#define LINKEDLIST


class LinkedList {
private:
  void** ptr;
  int reserve_size;

  // ADDRESS ���� -> char �^�ϐ�
  // ADDRESS �ȏ� -> �I�u�W�F�N�g
  // �C���̗]�n���肩�H
  enum { PTR_SIZE = sizeof(char*),
	 ADDRESS = 5000000
  };
  

public:
  LinkedList();
  ~LinkedList();


public:
  // �w�肳�ꂽ�ʒu�Ɏw�肳�ꂽ�v�f��ǉ�
  void add(int index, void* arg_ptr);
  

  // ���X�g�̍Ō�Ɏw�肳�ꂽ�v�f��ǉ�
    bool add(void* arg_ptr);

  // �w�肳�ꂽ LinkedList �I�u�W�F�N�g���̂��ׂĂ̗v�f���A���X�g�̎w�肳�ꂽ�ʒu�ɑ}������B�l�n��
  bool addAll(int index, LinkedList* ll);


  // ���X�g�̐擪�ɁA�w�肳�ꂽ�v�f��}���B�l�n��
  void addFirst(void* arg_ptr);


  // ���X�g�̍Ō�ɁA�w�肳�ꂽ�v�f��ǉ��B�l�n��
  void addLast(void* arg_ptr);


  // ���X�g���炷�ׂĂ̗v�f���폜
  void clear();


  // LinkedList �̃V�����[�R�s�[(�󂢃R�s�[)��Ԃ��B�v����ɎQ�ƕԂ�
  LinkedList* clone();


  // ���X�g�Ɏw��̗v�f������ꍇ�� true ��Ԃ�
  bool contains(char ch);
  bool contains(LinkedList* ll);


  // ���X�g���̎w�肳�ꂽ�ʒu�ɂ���v�f��Ԃ��B�l�n��
  void* get(int index);


  // ���X�g�̍ŏ��̗v�f��Ԃ��B�l�Ԃ�
  void* getFirst();


  // ���X�g�̍Ō�̗v�f��Ԃ��B�l�Ԃ�
  void* getLast();


  // �w�肵���l���ŏ��Ɍ��������Y������Ԃ��B������Ȃ������ꍇ�� -1 ��Ԃ�
  int indexOf(char ch);
  int indexOf(LinkedList* ll);


  // �w�肵���l���Ō�Ɍ��������Y������Ԃ��B������Ȃ������ꍇ�� -1 ��Ԃ�
  int lastIndexOf(char ch);
  int lastIndexOf(LinkedList* ll);


  // ���X�g���̎w�肳�ꂽ�ʒu�Ŏn�܂�A���X�g���̗v�f��K�؂ȏ����Ŕ������郊�X�g�����q��Ԃ�
  // Under Construction�c�c

  
  // ���X�g���̎w�肳�ꂽ�ʒu�ɂ���v�f���폜����B
  // �폜���ꂽ�ꏊ�͋l�߂���B���Ƃ��� a, b, c ���i�[����Ă���Ƃ��āAb ��remove �����ƁAb �̈ʒu�� c ���i�[����Ac ���������X�y�[�X�͍폜�����
  //
  //�߂�l�͍폜�����l
  void* remove(int index);


  // �w�肳�ꂽ�v�f�����̃��X�g�ɂ���΁A���̍ŏ��̂��̂����X�g����폜
   bool remove(char ch);
   bool remove(LinkedList* ll);


  // ���X�g����ŏ��̗v�f���폜���ĕԂ��B�l�n��
  void* removeFirst();


  // ���X�g����Ō�̗v�f���폜���ĕԂ��B�l�n��
  void* removeLast();


  // ���X�g�̎w�肳�ꂽ�ʒu�ɂ���v�f���A�w�肳�ꂽ�v�f�Œu��������B�߂�l�͒u��������ꂽ�l
  void* set(int index, void* arg_ptr);


  // ���X�g���ɂ���v�f�̐���Ԃ�
  int size();


  // ���X�g���̂��ׂĂ̗v�f��K�؂ȏ����� (�ŏ��̗v�f����Ō�̗v�f��) �i�[���Ă���z���Ԃ��B�l�n��
  void** toArray();


private:
  // ���X�g�̓��e���������ǂ������ׂ�
  bool isSame(LinkedList* ll);

  void checkIndex(int index);
  
};


#endif    // #ifndef LINKEDLIST
