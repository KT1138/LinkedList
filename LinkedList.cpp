#include "LinkedList.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



LinkedList::LinkedList() : reserve_size(0)
{
    ptr = static_cast<void**>(calloc(0, PTR_SIZE)); 
}


LinkedList::~LinkedList()
{
  free(ptr);
}


void LinkedList::add(int index, void* arg_ptr)
{
  checkIndex(index);
  
  void** new_ptr = static_cast<void**>(calloc(reserve_size + 1, PTR_SIZE));

  for ( int i = 0; i < index; ++i )
    {
      new_ptr[i] = ptr[i];
    }

  new_ptr[index] = arg_ptr;

  for ( int i = 0; i < reserve_size - index; ++i )
    {
      new_ptr[i + index + 1] = ptr[i + index];
    }

  free(ptr);

  ptr = new_ptr;
  
  ++reserve_size;
}


bool LinkedList::add(void* arg_ptr)
{
  memcpy(ptr+reserve_size, &arg_ptr, PTR_SIZE);

  ++reserve_size;

  return true;
}


bool LinkedList::addAll(int index, LinkedList* ll)
{
  checkIndex(index);
  
  void** new_ptr = static_cast<void**>(calloc(reserve_size + ll->reserve_size, PTR_SIZE));


  for ( int i = 0; i < index; ++i )
    {
      new_ptr[i] = ptr[i];
    }

  for ( int i = 0; i < ll->reserve_size; ++i )
    {
      new_ptr[i + index] = ll->ptr[i];
    }

  for ( int i = 0; i < reserve_size - index; ++i )
    {
      new_ptr[i + index + ll->reserve_size] = ptr[i + index];
    }

  free(ptr);

  ptr = new_ptr;

  reserve_size += ll->reserve_size;
}


void LinkedList::addFirst(void* arg_ptr)
{
  if ( reserve_size == 0 )
    {
    this->add(arg_ptr);
    }
  else 
    {
      void** new_ptr = static_cast<void**>(calloc(reserve_size + 1, PTR_SIZE));

      new_ptr[0] = arg_ptr;

      for ( int i = 0; i < reserve_size; ++i )
	{
	  new_ptr[i + 1] = ptr[i];
	}

      free(ptr);

      ptr = new_ptr;

      ++reserve_size;
    }
}


void LinkedList::addLast(void* arg_ptr)
{
  if ( reserve_size == 0 )
    {
      this->add(arg_ptr);
    }
  else
    {
       void** new_ptr = static_cast<void**>(calloc(reserve_size + 1, PTR_SIZE));

      for ( int i = 0; i < reserve_size; ++i )
	{
	  new_ptr[i] = ptr[i];
	}

      memcpy(new_ptr + reserve_size , &arg_ptr, PTR_SIZE);

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


LinkedList* LinkedList::clone()
{
  return this;
}


bool LinkedList::contains(char ch)
{
  int i = 0;
  
  while ( i < reserve_size )
    {
      int addr = reinterpret_cast<int>(ptr[i]);

      if ( addr > ADDRESS)
	{
	  ++i;
	  continue;
	}
      else if ( ch == *static_cast<char*>(ptr[i]) )
	{
	  return true;
	}

      ++i;
    }

  return false;
}


bool LinkedList::contains(LinkedList* ll)
{
  int i = 0;
  
  while ( i < reserve_size )
    {
      int addr = reinterpret_cast<int>(ptr[i]);

      if ( addr < ADDRESS)
	{
	  ++i;
	  continue;
	}
      else if ( static_cast<LinkedList*>(ptr[i])->isSame(ll) )
	{
	  return true;
	}

      ++i;
    }

  return false;
}


void* LinkedList::get(int index)
{
  checkIndex(index);
  
  return static_cast<void*>(ptr[index]);
}


void* LinkedList::getFirst()
{
  return static_cast<void*>(ptr[0]);
}


void* LinkedList::getLast()
{
  return static_cast<void*>(ptr[reserve_size - 1]);
}


int LinkedList::indexOf(char ch)
{
  int i = 0;

  int ret_val = -1;

  while ( i < reserve_size )
    {
      if ( ch == *static_cast<char*>(ptr[i]) )
	{
	  ret_val = i;
	  break;
	}

      ++i;
    }

  return ret_val;
}
 

int LinkedList::indexOf(LinkedList* ll)
{
  int i = 0;

  int ret_val = -1;

  while ( i < reserve_size )
    {
      int addr = reinterpret_cast<int>(ptr[i]);

      if ( addr < ADDRESS )
	{
	  ++i;
	  continue;
	}
      else if ( static_cast<LinkedList*>(ptr[i])->isSame(ll) )
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
  int i = reserve_size - 1;

  int ret_val = -1;

  while( i >= 0 )
    {
      if ( ch == *static_cast<char*>(ptr[i]) )
	{
	  ret_val = i;
	  break;
	}

      --i;
    }

  return ret_val;
}


int LinkedList::lastIndexOf(LinkedList* ll)
{
  int i = reserve_size - 1;

  int ret_val = -1;

  while ( i >= 0 )
    {
      int addr = reinterpret_cast<int>(ptr[i]);

      if ( addr < ADDRESS )
	{
	  ++i;
	  continue;
	}
      else if ( static_cast<LinkedList*>(ptr[i])->isSame(ll) )
	{
	  ret_val = i;
	  break;
	}

      --i;
    }

  return ret_val;
}


void* LinkedList::remove(int index)
{
  checkIndex(index);
  
  void** new_ptr = static_cast<void**>(calloc(reserve_size - 1, PTR_SIZE));

  for ( int i = 0; i < index; ++i )
    {
      new_ptr[i] = ptr[i];
    }

  void* ret_val = ptr[index];

  for ( int i = 0; i < reserve_size - index; ++i )
    {
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
      if ( ch == *static_cast<char*>(ptr[index]) )
	{
	  ret_val = true;
	  break;
	}

      ++index;
    }

  if ( ret_val ) 
    {
      void** new_ptr = static_cast<void**>(calloc(reserve_size - 1, PTR_SIZE));

      for ( int i = 0; i < index; ++i )
	{
	  new_ptr[i] = ptr[i];
	}

      for ( int i = 0; i < reserve_size - index; ++i )
	{
	  new_ptr[i + index] = ptr[i + index + 1];
	}

      free(ptr);

      ptr = new_ptr;

      --reserve_size;
     
      return true;
    }

  return false;
}


bool LinkedList::remove(LinkedList* ll)
{
  int index = 0;

  while ( index < reserve_size )
    {
      int addr = reinterpret_cast<int>(ptr[index]);

      if ( addr < ADDRESS )
	{
	  ++index;
	  continue;
	} 
      else if ( !static_cast<LinkedList*>(ptr[index])->isSame(ll) )
	{
	  ++index;
	  continue;
	} 

      void** new_ptr =
	static_cast<void**>(calloc(reserve_size - 1, sizeof(LinkedList*)));

      for ( int i = 0; i < index; ++i )
	{
	  new_ptr[i] = ptr[i];
	}

      for ( int i = 0; i < reserve_size - index; ++i )
	{
	  new_ptr[i + index] = ptr[i + index + 1];
	}

      free(ptr);

      ptr = new_ptr;

      --reserve_size;
     
      return true;
    }

  return false;
}


void* LinkedList::removeFirst()
{
  void** new_ptr = static_cast<void**>(calloc(reserve_size - 1, PTR_SIZE));

  void* ret_val = getFirst();

  for ( int i = 0; i < reserve_size - 1; ++i )
    {
      new_ptr[i] = ptr[i + 1];
    }

  free(ptr);

  ptr = new_ptr;

  --reserve_size;

  return ret_val;
}


void* LinkedList::removeLast()
{
  void** new_ptr = static_cast<void**>(calloc(reserve_size - 1, PTR_SIZE));

  void* ret_val = getLast();

  for ( int i = 0; i < reserve_size - 1; ++i )
    {
      new_ptr[i] = ptr[i];
    }

  free(ptr);

  ptr = new_ptr;

  --reserve_size;

  return ret_val;
}


void* LinkedList::set(int index, void* arg_ptr)
{
  checkIndex(index);
  
  void* ret_val = ptr[index];

  ptr[index] = arg_ptr;

  return ret_val;
}


int LinkedList::size()
{
  return reserve_size;
}


void** LinkedList::toArray()
{
  
  void** ret_val = static_cast<void**>(calloc(reserve_size, PTR_SIZE));

  for ( int i = 0; i < reserve_size; ++i )
    {
      ret_val[i] = ptr[i];
    }

  return ret_val;
}


bool LinkedList::isSame(LinkedList* ll)
{
  int i = 0;

  if ( reserve_size != ll->reserve_size )
    {
      return false;
    }
  else if ( reserve_size == 0 && ll->reserve_size == 0 )
    {
      return true;
    }

  while ( i < reserve_size )
    {
      int addr_0 = reinterpret_cast<int>(ptr[i]);
      int addr_1 = reinterpret_cast<int>(ll->ptr[i]);

      if ( (addr_0 > ADDRESS && addr_1 < ADDRESS) ||
	   (addr_0 < ADDRESS && addr_1 > ADDRESS) )
	{
	  return false;
	}
      else if ( addr_0 < ADDRESS && addr_1 < ADDRESS )
	{
	  if ( *static_cast<char*>(ptr[i]) != *static_cast<char*>(ll->ptr[i]) )
	    {
	      return false;
	    }

	  ++i;
	  continue;
	}

      LinkedList* ll_inner = static_cast<LinkedList*>(ptr[i]);
      LinkedList* ll_inner_arg = static_cast<LinkedList*>(ll->ptr[i]);

      if ( ll_inner->reserve_size != ll_inner_arg->reserve_size )
	{
	  return false;
	}
      else if ( !ll_inner->isSame(ll_inner_arg) )
	{
	  return false;
	}

      ++i;
    }	
     
  return true;
}
  

void LinkedList::checkIndex(int index)
{
  if ( index < 0 || reserve_size < index )
    {
      printf("正しい添え字を指定してください。\n");
      exit(1);
    }
}


void func(LinkedList* ll);



int main()
{
  // /***
  //  * まずはリストを用意する
  //  */
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

  
 

   /***
     * 深いところにあるリストから値を詰め込んでいく
     */

   //   深さ2
   char tmp_ll = '1';
   ll_ll_dep2->add(&tmp_ll);
  
   char tmp_lr = '3';
   ll_lr_dep2->add(&tmp_lr);
  
   char tmp_rl = '3';
   ll_rl_dep2->add(&tmp_rl);
  
   char tmp_rr = '5';
   ll_rr_dep2->add(&tmp_rr);


   //   深さ1
   char tmp_l = '2';
   ll_l_dep1->add(&tmp_l);
   ll_l_dep1->add(ll_ll_dep2);
   ll_l_dep1->add(ll_lr_dep2);

   char tmp_r = '4';
   ll_r_dep1->add(&tmp_r);
   ll_r_dep1->add(ll_rl_dep2);
   ll_r_dep1->add(ll_rr_dep2);


   //   深さ0
   char tmp_root = '3';
   ll_root->add(&tmp_root);
   ll_root->add(ll_l_dep1);
   ll_root->add(ll_r_dep1);

  
   /***
    * 各ノードの値を出力
    */
   func(ll_root);



}


void func(LinkedList* ll) {
  if ( ll->size() > 1)
    {
      func( static_cast<LinkedList*>(ll->get(1)) );
      func( static_cast<LinkedList*>(ll->get(2)) );
    }

  printf("%c\n", *static_cast<char*>(ll->get(0)));
}
