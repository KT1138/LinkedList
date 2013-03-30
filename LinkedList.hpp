#ifndef LINKEDLIST
#define LINKEDLIST


class LinkedList {
private:
  char* ptr;   // �擪�v�f�ւ̃|�C���^
  int reserve_size;   // ���ݎg�p���̗̈�T�C�Y
  
public:
  LinkedList();
  ~LinkedList();


public:

  // �w�肳�ꂽ�ʒu�Ɏw�肳�ꂽ�v�f��ǉ�
  void add(int index, char ch);
  

  // ���X�g�̍Ō�Ɏw�肳�ꂽ�v�f��ǉ�
  bool add(char ch);


  // �w�肳�ꂽ LinkedList �I�u�W�F�N�g���̂��ׂĂ̗v�f���A���X�g�̎w�肳�ꂽ�ʒu�ɑ}������B�l�n��
  bool addAll(int index, LinkedList* ll);


  // ���X�g�̐擪�ɁA�w�肳�ꂽ�v�f��}���B�l�n��
  void addFirst(char ch);


  // ���X�g�̍Ō�ɁA�w�肳�ꂽ�v�f��ǉ��B�l�n��
  void addLast(char ch);


  // ���X�g���炷�ׂĂ̗v�f���폜
  void clear();


  // LinkedList �̃V�����[�R�s�[(�󂢃R�s�[)��Ԃ��B�v����ɎQ�ƕԂ�
  // ���Ƃ�shared_ptr ���g���Ď������悤
  char* clone();


  // ���X�g�Ɏw��̗v�f������ꍇ�� true ��Ԃ�
  bool contains(char ch);


  // ���X�g���̎w�肳�ꂽ�ʒu�ɂ���v�f��Ԃ��B�l�n��
  char get(int index);


  // ���X�g�̍ŏ��̗v�f��Ԃ��B�l�Ԃ�
  char getFirst();


  // ���X�g�̍Ō�̗v�f��Ԃ��B�l�Ԃ�
  char getLast();


  // �w�肵���l���ŏ��Ɍ��������Y������Ԃ��B������Ȃ������ꍇ�� -1 ��Ԃ�
  int indexOf(char ch);


  // �w�肵���l���Ō�Ɍ��������Y������Ԃ��B������Ȃ������ꍇ�� -1 ��Ԃ�
  int lastIndexOf(char ch);


  // ���X�g���̎w�肳�ꂽ�ʒu�Ŏn�܂�A���X�g���̗v�f��K�؂ȏ����Ŕ������郊�X�g�����q��Ԃ�
  // �������Ȃ��Ă悢

  
  // ���X�g���̎w�肳�ꂽ�ʒu�ɂ���v�f���폜����B
  // �폜���ꂽ�ꏊ�͋l�߂���B���Ƃ��� a, b, c ���i�[����Ă���Ƃ��āAb ��remove �����ƁAb �̈ʒu�� c ���i�[����Ac ���������X�y�[�X�͍폜�����
  //
  //�߂�l�͍폜�����l
  char remove(int index);


  // �w�肳�ꂽ�v�f�����̃��X�g�ɂ���΁A���̍ŏ��̂��̂����X�g����폜
  bool remove(char ch);


  // ���X�g����ŏ��̗v�f���폜���ĕԂ��B�l�n��
  char removeFirst();


  // ���X�g����Ō�̗v�f���폜���ĕԂ��B�l�n��
  char removeLast();


  // ���X�g�̎w�肳�ꂽ�ʒu�ɂ���v�f���A�w�肳�ꂽ�v�f�Œu��������B�߂�l�͒u��������ꂽ�l
  char set(int index, char ch);


  // ���X�g���ɂ���v�f�̐���Ԃ�
  int size();


  // ���X�g���̂��ׂĂ̗v�f��K�؂ȏ����� (�ŏ��̗v�f����Ō�̗v�f��) �i�[���Ă���z���Ԃ��B�l�n��
  char* toArray();
};


#endif    // #ifndef LINKEDLIST
