#ifndef LINKEDLIST
#define LINKEDLIST


class LinkedList {
private:
  char* ptr;   // 先頭要素へのポインタ
  int reserve_size;   // 現在使用中の領域サイズ
  
public:
  LinkedList();
  ~LinkedList();


public:

  // 指定された位置に指定された要素を追加
  void add(int index, char ch);
  

  // リストの最後に指定された要素を追加
  bool add(char ch);


  // 指定された LinkedList オブジェクト内のすべての要素を、リストの指定された位置に挿入する。値渡し
  bool addAll(int index, LinkedList* ll);


  // リストの先頭に、指定された要素を挿入。値渡し
  void addFirst(char ch);


  // リストの最後に、指定された要素を追加。値渡し
  void addLast(char ch);


  // リストからすべての要素を削除
  void clear();


  // LinkedList のシャローコピー(浅いコピー)を返す。要するに参照返し
  // あとでshared_ptr を使って実装しよう
  char* clone();


  // リストに指定の要素がある場合に true を返す
  bool contains(char ch);


  // リスト内の指定された位置にある要素を返す。値渡し
  char get(int index);


  // リストの最初の要素を返す。値返し
  char getFirst();


  // リストの最後の要素を返す。値返し
  char getLast();


  // 指定した値が最初に見つかった添え字を返す。見つからなかった場合は -1 を返す
  int indexOf(char ch);


  // 指定した値が最後に見つかった添え字を返す。見つからなかった場合は -1 を返す
  int lastIndexOf(char ch);


  // リスト内の指定された位置で始まる、リスト内の要素を適切な順序で反復するリスト反復子を返す
  // 実装しなくてよい

  
  // リスト内の指定された位置にある要素を削除する。
  // 削除された場所は詰められる。たとえば a, b, c が格納されているとして、b がremove されると、b の位置に c が格納され、c があったスペースは削除される
  //
  //戻り値は削除した値
  char remove(int index);


  // 指定された要素がこのリストにあれば、その最初のものをリストから削除
  bool remove(char ch);


  // リストから最初の要素を削除して返す。値渡し
  char removeFirst();


  // リストから最後の要素を削除して返す。値渡し
  char removeLast();


  // リストの指定された位置にある要素を、指定された要素で置き換える。戻り値は置き換えられた値
  char set(int index, char ch);


  // リスト内にある要素の数を返す
  int size();


  // リスト内のすべての要素を適切な順序で (最初の要素から最後の要素へ) 格納している配列を返す。値渡し
  char* toArray();
};


#endif    // #ifndef LINKEDLIST
