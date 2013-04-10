#ifndef LINKEDLIST
#define LINKEDLIST


class LinkedList {
private:
  void** ptr;
  int reserve_size;

  // ADDRESS 未満 -> char 型変数
  // ADDRESS 以上 -> オブジェクト
  // 修正の余地ありか？
  enum { PTR_SIZE = sizeof(char*),
	 ADDRESS = 5000000
  };
  

public:
  LinkedList();
  ~LinkedList();


public:
  // 指定された位置に指定された要素を追加
  void add(int index, void* arg_ptr);
  

  // リストの最後に指定された要素を追加
    bool add(void* arg_ptr);

  // 指定された LinkedList オブジェクト内のすべての要素を、リストの指定された位置に挿入する。値渡し
  bool addAll(int index, LinkedList* ll);


  // リストの先頭に、指定された要素を挿入。値渡し
  void addFirst(void* arg_ptr);


  // リストの最後に、指定された要素を追加。値渡し
  void addLast(void* arg_ptr);


  // リストからすべての要素を削除
  void clear();


  // LinkedList のシャローコピー(浅いコピー)を返す。要するに参照返し
  LinkedList* clone();


  // リストに指定の要素がある場合に true を返す
  bool contains(char ch);
  bool contains(LinkedList* ll);


  // リスト内の指定された位置にある要素を返す。値渡し
  void* get(int index);


  // リストの最初の要素を返す。値返し
  void* getFirst();


  // リストの最後の要素を返す。値返し
  void* getLast();


  // 指定した値が最初に見つかった添え字を返す。見つからなかった場合は -1 を返す
  int indexOf(char ch);
  int indexOf(LinkedList* ll);


  // 指定した値が最後に見つかった添え字を返す。見つからなかった場合は -1 を返す
  int lastIndexOf(char ch);
  int lastIndexOf(LinkedList* ll);


  // リスト内の指定された位置で始まる、リスト内の要素を適切な順序で反復するリスト反復子を返す
  // Under Construction……

  
  // リスト内の指定された位置にある要素を削除する。
  // 削除された場所は詰められる。たとえば a, b, c が格納されているとして、b がremove されると、b の位置に c が格納され、c があったスペースは削除される
  //
  //戻り値は削除した値
  void* remove(int index);


  // 指定された要素がこのリストにあれば、その最初のものをリストから削除
   bool remove(char ch);
   bool remove(LinkedList* ll);


  // リストから最初の要素を削除して返す。値渡し
  void* removeFirst();


  // リストから最後の要素を削除して返す。値渡し
  void* removeLast();


  // リストの指定された位置にある要素を、指定された要素で置き換える。戻り値は置き換えられた値
  void* set(int index, void* arg_ptr);


  // リスト内にある要素の数を返す
  int size();


  // リスト内のすべての要素を適切な順序で (最初の要素から最後の要素へ) 格納している配列を返す。値渡し
  void** toArray();


private:
  // リストの内容が同じかどうか調べる
  bool isSame(LinkedList* ll);

  void checkIndex(int index);
  
};


#endif    // #ifndef LINKEDLIST
