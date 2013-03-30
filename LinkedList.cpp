#include "LinkedList.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/***
 * コンストラクタ・デストラクタ
 */
LinkedList::LinkedList() : reserve_size(0)
{
  ptr = static_cast<char*>(calloc(0, sizeof(char))); 
}


LinkedList::~LinkedList()
{
  free(ptr);
}


/***
 * メソッド
 */
void LinkedList::add(int index, char ch)
{
  if ( index < 0 || reserve_size < index )
    {
      printf("正しい添え字を指定してください。\n");
      exit(1);
    }

  char* new_ptr = static_cast<char*>(calloc(reserve_size + 1, sizeof(int)));

  for ( int i = 0; i < index; ++i ) {
    new_ptr[i] = ptr[i];
  }

  new_ptr[index] = ch;

  for ( int i = 0; i < reserve_size - index; ++i ) {
    new_ptr[i + index + 1] = ptr[i + index];
  }

  free(ptr);

  ptr = new_ptr;
  
  ++reserve_size;
}


bool LinkedList::add(char ch)
{
  char* tmp = &ch;

  memcpy(ptr+reserve_size, tmp, sizeof(int));

  ++reserve_size;

  return true;
}


bool LinkedList::addAll(int index, LinkedList* ll)
{
  if ( index < 0 || reserve_size < index )
    {
      printf("正しい添え字を指定してください。\n");
      exit(1);
    }

  char* new_ptr = static_cast<char*>(calloc(reserve_size + ll->reserve_size, sizeof(int)));


  for ( int i = 0; i < index; ++i ) {
    new_ptr[i] = ptr[i];
  }

  for ( int i = 0; i < ll->reserve_size; ++i ) {
    new_ptr[i + index] = ll->ptr[i];
  }

  for ( int i = 0; i < reserve_size - index; ++i ) {
    new_ptr[i + index + ll->reserve_size] = ptr[i + index];
  }

  free(ptr);

  ptr = new_ptr;

  reserve_size += ll->reserve_size;
}


void LinkedList::addFirst(char ch)
{
  if ( reserve_size == 0 )
    {
    this->add(ch);
    }
  else 
    {
      char* new_ptr = static_cast<char*>(calloc(reserve_size + 1, sizeof(int)));

      new_ptr[0] = ch;

      for ( int i = 0; i < reserve_size; ++i ) {
	new_ptr[i + 1] = ptr[i];
      }

      free(ptr);

      ptr = new_ptr;

      ++reserve_size;
    }

}


void LinkedList::addLast(char ch)
{
  if ( reserve_size == 0 )
    {
      this->add(ch);
    }
  else
    {
       char* new_ptr = static_cast<char*>(calloc(reserve_size + 1, sizeof(int)));

       //      new_ptr[0] = ch;

      for ( int i = 0; i < reserve_size; ++i ) {
	new_ptr[i] = ptr[i];
      }

      new_ptr[reserve_size + 1] = ch;

      free(ptr);

      ptr = new_ptr;

      ++reserve_size;     

    }
}


void LinkedList::clear()
{
  free(ptr); 

  reserve_size = 0;
}


// 保留
char* LinkedList::clone()
{

}


bool LinkedList::contains(char ch)
{
  int flag = 0;

  int i = 0;
  
  while ( i < reserve_size )
    {
      if ( ch == ptr[i] )
	{
	  flag = 1;
	  break;
	}
      ++i;
      printf("%d\n", i);
    }

  if ( flag == 0 )
    {
      printf("false返した\n");
      return false;
    }
  else
    {
      printf("true返した\n");
      return true;
    }
}


char LinkedList::get(int index)
{
  if ( index < 0 || reserve_size < index )
    {
      printf("正しい添え字を指定してください。\n");
      exit(1);
    }

  return ptr[index];
}


char LinkedList::getFirst()
{
  return ptr[0];
}


char LinkedList::getLast()
{
  return ptr[reserve_size - 1];
}


int LinkedList::indexOf(char ch)
{
  // リスト先頭から探し、見つかり次第 return 

  int i = 0;

  int ret_val = -1;

  while ( i < reserve_size )
    {
      if ( ch == ptr[i] )
	{
	  ret_val = i;
	  break;
	}

      ++i;
    }

  return ret_val;
}


int LinkedList::lastIndexOf(char ch)
{
  // リスト末尾から探し、見つかり次第 return 

  int i = reserve_size - 1;

  int ret_val = -1;

  while( i >= 0 )
    {
      if ( ch == ptr[i] )
	{
	  ret_val = i;
	  break;
	}

      --i;
    }

  return ret_val;
}


char LinkedList::remove(int index)
{
  if ( index < 0 || reserve_size < index )
    {
      printf("正しい添え字を指定してください。\n");
      exit(1);
    }

  char* new_ptr = static_cast<char*>(calloc(reserve_size - 1, sizeof(int)));

  for ( int i = 0; i < index; ++i ) {
    new_ptr[i] = ptr[i];
  }

  char ret_val = ptr[index];

  for ( int i = 0; i < reserve_size - index; ++i ) {
    new_ptr[i + index] = ptr[i + index + 1];
  }

  free(ptr);

  ptr = new_ptr;

  --reserve_size;

  return ret_val;
}


bool LinkedList::remove(char ch)
{
  int index = 0;

  bool ret_val = false;

  while ( index < reserve_size )
    {
      if ( ch == ptr[index] )
	{
	  ret_val = true;
	  break;
	}

      ++index;
    }

  if ( ret_val ) 
    {
      char* new_ptr = static_cast<char*>(calloc(reserve_size - 1, sizeof(int)));

      for ( int i = 0; i < index; ++i ) {
	new_ptr[i] = ptr[i];
      }

      //      char ret_val = ptr[index];

      for ( int i = 0; i < reserve_size - index; ++i ) {
	new_ptr[i + index] = ptr[i + index + 1];
      }

      free(ptr);

      ptr = new_ptr;

      --reserve_size;
     
    }
 

  return ret_val;
}


char LinkedList::removeFirst()
{
  char* new_ptr = static_cast<char*>(calloc(reserve_size - 1, sizeof(int)));

  char ret_val = this->getFirst();

  for ( int i = 0; i < reserve_size - 1; ++i ) {
    new_ptr[i] = ptr[i + 1];
  }

  free(ptr);

  ptr = new_ptr;

  --reserve_size;

  return ret_val;
}


char LinkedList::removeLast()
{
  char* new_ptr = static_cast<char*>(calloc(reserve_size - 1, sizeof(int)));

  char ret_val = this->getLast();

  for ( int i = 0; i < reserve_size - 1; ++i ) {
    new_ptr[i] = ptr[i];
  }

  free(ptr);

  ptr = new_ptr;

  --reserve_size;

  return ret_val;
}



char LinkedList::set(int index, char ch)
{
  if ( index < 0 || reserve_size < index )
    {
      printf("正しい添え字を指定してください。\n");
      exit(1);
    }

  char ret_val = ptr[index];

  ptr[index] = ch;

  return ret_val;
}



int LinkedList::size()
{
  return reserve_size;
}



char* LinkedList::toArray()
{
  
  char* ret_val = static_cast<char*>(calloc(reserve_size, sizeof(int)));

  for ( int i = 0; i < reserve_size; ++i )
    {
      ret_val[i] = ptr[i];
    }

  return ret_val;
}



int main()
{


  return 0;
}
