#include<iostream>
#include<unistd.h>
#include<sys/types.h>
#include<pthread.h>
#include<string.h>
#include<stdlib.h>
#include<sys/syscall.h>
#include<sched.h>


using namespace std;



struct A 
{
  pthread_t tid;
  int num;
};


void *pthreadact(void *arg)
{
  const char * threadarg = (char *)arg;
  
  while(1)
  {
      cout<<"i am a pthread   pid: "<<getpid()<<" tid "<<syscall(SYS_gettid)<<endl;
  cout<<pthread_self()<<endl;
      sleep(1);
    
  }
  return (void*)12312312;
}

volatile int tickets = 100;
pthread_mutex_t mutex;


void *Buy_Ticket(void* arg)
{
  while(1)
  {
    usleep(100);
    pthread_mutex_lock(&mutex);
      if(tickets>0)
      {
        usleep(100);
        cout<<(int)arg<<": get:"<<tickets<<endl;
        --tickets;
        pthread_mutex_unlock(&mutex);
      }
      else 
      {
        pthread_mutex_unlock(&mutex);
        break;
      }
  }
}


int main()
{ 
  void *ret;
  int nums=5;
  int i=0;
  A a[4]={0};
  pthread_t tid;
  //第二个参数线程的属性
  pthread_mutex_init(&mutex,NULL);
  for(;i<nums;i++)
  {
     pthread_create(&(a[i].tid),NULL,Buy_Ticket,(void*)i);
  }

  i=0;
  for(;i<nums;i++)
  {
    pthread_join(a[i].tid,NULL);
  }
    
    
  return 0;
}
