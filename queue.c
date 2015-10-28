#include "queue.h"


queue queue_init()
{
  queue tmp;
  tmp.front = NULL;
  return tmp;
}


element* queue_push(queue Q, void* data)
{

}


element* queue_pop(queue Q)
{

}


void queue_clear(queue* pQ)
{

}


void queue_browse(queue Q, void (*fctBrowse)(void*))
{
  while (Q.front) {
    fctBrowse(Q.front);
    Q.front = Q.front->next;
  }
}


size_t queue_count(queue Q)
{
  size_t number=0;
  element* pFirstElem = Q.front;
  while (pFirstElem) {
    number++;
    pFirstElem = pFirstElem->next;
  }

  return number;
}
