#include "LinkedList.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>


/***
 * コンストラクタ・デストラクタ
 */
LinkedList::LinkedList() : reserve_size(0)
{
  // ptr = static_cast<char*>(calloc(0, sizeof(char))); 
  ptr = reinterpret_cast<char**>(calloc(0, sizeof(char*))); 
}


LinkedList::~LinkedList()
{
  free(ptr);
}


/***
 * メソッド
 */
// void LinkedList::add(int index, char* ch)
// {
//   if ( index < 0 || reserve_size < index )
//     {
//       printf("正しい添え字を指定してください。\n");
//       exit(1);
//     }

//   char** new_ptr = static_cast<char**>(calloc(reserve_size + 1, sizeof(char*)));

//   for ( int i = 0; i < index; ++i ) {
//     new_ptr[i] = ptr[i];
//   }

//   new_ptr[index] = ch;

//   for ( int i = 0; i < reserve_size - index; ++i ) {
//     new_ptr[i + index + 1] = ptr[i + index];
//   }

//   free(ptr);

//   ptr = new_ptr;
  
//   ++reserve_size;
// }


// bool LinkedList::add(char ch)
// {
//   char* tmp = &ch;

//   memcpy(ptr+reserve_size, tmp, sizeof(int));

//   ++reserve_size;

//   return true;
// }

bool LinkedList::add(char* ch_ptr)
{
  //  printf("add(char) ");
  //  printf("reservesize: ");
  //  printf("%d\n", reserve_size);

  memcpy(ptr+reserve_size, &ch_ptr, sizeof(char*));

  ++reserve_size;

  return true;
}

bool LinkedList::add(LinkedList* ll_ptr)
{
  //  printf("add(LL) ");
  //  printf("reservesize: ");
  //  printf("%d\n", reserve_size);


  memcpy(ptr+reserve_size, &ll_ptr, sizeof(LinkedList*));

  ++reserve_size;

  return true;
}



// bool LinkedList::addAll(int index, LinkedList* ll)
// {
//   if ( index < 0 || reserve_size < index )
//     {
//       printf("正しい添え字を指定してください。\n");
//       exit(1);
//     }

//   char* new_ptr = static_cast<char*>(calloc(reserve_size + ll->reserve_size, sizeof(int)));


//   for ( int i = 0; i < index; ++i ) {
//     new_ptr[i] = ptr[i];
//   }

//   for ( int i = 0; i < ll->reserve_size; ++i ) {
//     new_ptr[i + index] = ll->ptr[i];
//   }

//   for ( int i = 0; i < reserve_size - index; ++i ) {
//     new_ptr[i + index + ll->reserve_size] = ptr[i + index];
//   }

//   free(ptr);

//   ptr = new_ptr;

//   reserve_size += ll->reserve_size;
// }


// void LinkedList::addFirst(char ch)
// {
//   if ( reserve_size == 0 )
//     {
//     this->add(ch);
//     }
//   else 
//     {
//       char* new_ptr = static_cast<char*>(calloc(reserve_size + 1, sizeof(int)));

//       new_ptr[0] = ch;

//       for ( int i = 0; i < reserve_size; ++i ) {
// 	new_ptr[i + 1] = ptr[i];
//       }

//       free(ptr);

//       ptr = new_ptr;

//       ++reserve_size;
//     }

// }


// void LinkedList::addLast(char ch)
// {
//   if ( reserve_size == 0 )
//     {
//       this->add(ch);
//     }
//   else
//     {
//        char* new_ptr = static_cast<char*>(calloc(reserve_size + 1, sizeof(int)));

//        //      new_ptr[0] = ch;

//       for ( int i = 0; i < reserve_size; ++i ) {
// 	new_ptr[i] = ptr[i];
//       }

//       new_ptr[reserve_size + 1] = ch;

//       free(ptr);

//       ptr = new_ptr;

//       ++reserve_size;     

//     }
// }


void LinkedList::clear()
{
  free(ptr); 

  reserve_size = 0;
}


// 保留
char* LinkedList::clone()
{

}


// bool LinkedList::contains(char ch)
// {
//   int flag = 0;

//   int i = 0;
  
//   while ( i < reserve_size )
//     {
//       if ( ch == ptr[i] )
// 	{
// 	  flag = 1;
// 	  break;
// 	}
//       ++i;
//       printf("%d\n", i);
//     }

//   if ( flag == 0 )
//     {
//       printf("false返した\n");
//       return false;
//     }
//   else
//     {
//       printf("true返した\n");
//       return true;
//     }
// }


// char LinkedList::get(int index)
// {
//   if ( index < 0 || reserve_size < index )
//     {
//       printf("正しい添え字を指定してください。\n");
//       exit(1);
//     }

//   return ptr[index];
// }

void* LinkedList::get(int index)
//char* LinkedListget(int index)
{
  if ( index < 0 || reserve_size < index )
    {
      printf("正しい添え字を指定してください。\n");
      exit(1);
    }

  return reinterpret_cast<void*>(ptr[index]);
  //  return static_cast<char*>(ptr[index]);
}



// char LinkedList::getFirst()
// {
//   return ptr[0];
// }


// char LinkedList::getLast()
// {
//   return ptr[reserve_size - 1];
// }


// int LinkedList::indexOf(char ch)
// {
//   // リスト先頭から探し、見つかり次第 return 

//   int i = 0;

//   int ret_val = -1;

//   while ( i < reserve_size )
//     {
//       if ( ch == ptr[i] )
// 	{
// 	  ret_val = i;
// 	  break;
// 	}

//       ++i;
//     }

//   return ret_val;
// }


// int LinkedList::lastIndexOf(char ch)
// {
//   // リスト末尾から探し、見つかり次第 return 

//   int i = reserve_size - 1;

//   int ret_val = -1;

//   while( i >= 0 )
//     {
//       if ( ch == ptr[i] )
// 	{
// 	  ret_val = i;
// 	  break;
// 	}

//       --i;
//     }

//   return ret_val;
// }


// char LinkedList::remove(int index)
// {
//   if ( index < 0 || reserve_size < index )
//     {
//       printf("正しい添え字を指定してください。\n");
//       exit(1);
//     }

//   char* new_ptr = static_cast<char*>(calloc(reserve_size - 1, sizeof(int)));

//   for ( int i = 0; i < index; ++i ) {
//     new_ptr[i] = ptr[i];
//   }

//   char ret_val = ptr[index];

//   for ( int i = 0; i < reserve_size - index; ++i ) {
//     new_ptr[i + index] = ptr[i + index + 1];
//   }

//   free(ptr);

//   ptr = new_ptr;

//   --reserve_size;

//   return ret_val;
// }


// bool LinkedList::remove(char ch)
// {
//   int index = 0;

//   bool ret_val = false;

//   while ( index < reserve_size )
//     {
//       if ( ch == ptr[index] )
// 	{
// 	  ret_val = true;
// 	  break;
// 	}

//       ++index;
//     }

//   if ( ret_val ) 
//     {
//       char* new_ptr = static_cast<char*>(calloc(reserve_size - 1, sizeof(int)));

//       for ( int i = 0; i < index; ++i ) {
// 	new_ptr[i] = ptr[i];
//       }

//       //      char ret_val = ptr[index];

//       for ( int i = 0; i < reserve_size - index; ++i ) {
// 	new_ptr[i + index] = ptr[i + index + 1];
//       }

//       free(ptr);

//       ptr = new_ptr;

//       --reserve_size;
     
//     }
 

//   return ret_val;
// }


// char LinkedList::removeFirst()
// {
//   char* new_ptr = static_cast<char*>(calloc(reserve_size - 1, sizeof(int)));

//   char ret_val = this->getFirst();

//   for ( int i = 0; i < reserve_size - 1; ++i ) {
//     new_ptr[i] = ptr[i + 1];
//   }

//   free(ptr);

//   ptr = new_ptr;

//   --reserve_size;

//   return ret_val;
// }


// char LinkedList::removeLast()
// {
//   char* new_ptr = static_cast<char*>(calloc(reserve_size - 1, sizeof(int)));

//   char ret_val = this->getLast();

//   for ( int i = 0; i < reserve_size - 1; ++i ) {
//     new_ptr[i] = ptr[i];
//   }

//   free(ptr);

//   ptr = new_ptr;

//   --reserve_size;

//   return ret_val;
// }



// char LinkedList::set(int index, char ch)
// {
//   if ( index < 0 || reserve_size < index )
//     {
//       printf("正しい添え字を指定してください。\n");
//       exit(1);
//     }

//   char ret_val = ptr[index];

//   ptr[index] = ch;

//   return ret_val;
// }



int LinkedList::size()
{
  return reserve_size;
}



// char* LinkedList::toArray()
// {
  
//   char* ret_val = static_cast<char*>(calloc(reserve_size, sizeof(int)));

//   for ( int i = 0; i < reserve_size; ++i )
//     {
//       ret_val[i] = ptr[i];
//     }

//   return ret_val;
// }



void func(LinkedList* ll);



int main()
{
  /***
   * まずはリストを用意する
   */
  // 深さ0(ルート)
  LinkedList* ll_root = new LinkedList();


  // 深さ1
  LinkedList* ll_l_dep1 = new LinkedList();
  LinkedList* ll_r_dep1 = new LinkedList();


  // 深さ2
   LinkedList* ll_ll_dep2 = new LinkedList();
   LinkedList* ll_lr_dep2 = new LinkedList();
  
   LinkedList* ll_rl_dep2 = new LinkedList();
   LinkedList* ll_rr_dep2 = new LinkedList();

  
  // 深さ3
  // LinkedList* ll_lll_dep3 = new LinkedList();
  // LinkedList* ll_llr_dep3 = new LinkedList();
  // LinkedList* ll_lrl_dep3 = new LinkedList();
  // LinkedList* ll_lrr_dep3 = new LinkedList();

  // LinkedList* ll_rll_dep3 = new LinkedList();
  // LinkedList* ll_rlr_dep3 = new LinkedList();
  // LinkedList* ll_rrl_dep3 = new LinkedList();
  // LinkedList* ll_rrr_dep3 = new LinkedList();
  


  // /***
  //  * 深いところにあるリストから値を詰め込んでいく
  //  */
  // // 深さ3

  // ll_lll_dep3->add('0');
  // ll_lll_dep3->add('0');
  // ll_llr_dep3->add('2');
  // ll_lrl_dep3->add('2');
  // ll_lrr_dep3->add('4');

  // ll_rll_dep3->add('2');
  // ll_rlr_dep3->add('4');
  // ll_rrl_dep3->add('4');
  // ll_rrr_dep3->add('6');


  // //   深さ2
   char tmp_ll = '1';
   ll_ll_dep2->add(&tmp_ll);
  
   char tmp_lr = '3';
   ll_lr_dep2->add(&tmp_lr);
  
   char tmp_rl = '3';
   ll_rl_dep2->add(&tmp_rl);
  
   char tmp_rr = '5';
   ll_rr_dep2->add(&tmp_rr);


  // //   深さ1
  char tmp_l = '2';
  ll_l_dep1->add(&tmp_l);
  ll_l_dep1->add(ll_ll_dep2);
  ll_l_dep1->add(ll_lr_dep2);

  char tmp_r = '4';
  ll_r_dep1->add(&tmp_r);
  ll_r_dep1->add(ll_rl_dep2);
  ll_r_dep1->add(ll_rr_dep2);


  // //   深さ0
  char tmp_root = '3';
  ll_root->add(&tmp_root);
  ll_root->add(ll_l_dep1);
  ll_root->add(ll_r_dep1);


  
  /***
   * 各ノードの値を出力
   */
  func(ll_root);

  // printf("テスト開始\n");
  
  // LinkedList* ll_test1 = reinterpret_cast<LinkedList*>(ll_root->get(1));

  // printf("3とでるか\n");
  
  // printf("%d\n", ll_test1->size());   // きちがいみたいな数字。get(int index) 時のキャストの仕方がまずいのだろうか。

  // printf("%d\n", ll_l_dep1->size());   // ↑と同じことをしているのに……
  
  // LinkedList* ll_test2 = reinterpret_cast<LinkedList*>(ll_test1->get(1));

  // printf("テスト2\n");
  
  // //  printf("%c\n", *(char*)(ll_test2->get(0))); 

  // printf("%d\n", ll_test2->size());

 

  return 0;
}


void func(LinkedList* ll) {

  printf("test2\n");

  if ( ll->size() > 1)
    {
      printf("test1\n");

      func( (LinkedList*)(ll->get(1)) );
      func( (LinkedList*)(ll->get(2)) );

    }
  printf("test3\n");
  printf("%c\n", *(char*)(ll->get(0)));
}
