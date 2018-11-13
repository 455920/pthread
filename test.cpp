#include<iostream>
#include<unistd.h>
#include<sys/types.h>
#include<pthread.h>
#include<string.h>
#include<stdlib.h>

using namespace std;



void *pthreadact(void *arg)
{
  const char * threadarg = (char *)arg;
  
  while(1)
  {
      cout<<"i am a pthread"<<endl;
      sleep(1);
  }
  return (void*)12312312;
}


int main()
{ 
  void *ret;
  pthread_t tid;
  //第二个参数线程的属性
  pthread_create(&tid,NULL,pthreadact,&ret);
  
while(1)
{
  sleep(1);
  cout<<"i am main pthread"<<endl;

}

  
  return 0;
}
