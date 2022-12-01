 #define _GNU_SOURCE
    #include<stdio.h>
    #include<stdlib.h>
    #include<unistd.h>
    #include<pthread.h>
    #include<sched.h>    
pthread_cond_t condVar=PTHREAD_COND_INITIALIZER;        
pthread_mutex_t mutexVar=PTHREAD_MUTEX_INITIALIZER;        
void *thread1(void *ptr)        
{        
    int iVar=1;        
    printf("Thread %d\n",iVar);        
    pthread_mutex_lock(&mutexVar);        
    pthread_cond_wait(&condVar,&mutexVar);        
    pthread_mutex_unlock(&mutexVar);        
    printf("Thread %d is unblocked...\n",iVar);        
}        

void *thread2(void *ptr)        
{        
    int iVar=2;        
    printf("Thread %d\n",iVar);        
    pthread_mutex_lock(&mutexVar);        
    pthread_cond_wait(&condVar,&mutexVar);        
    pthread_mutex_unlock(&mutexVar);        
    printf("Thread %d is unblocked...\n",iVar);        

}        

void *thread3(void *ptr)        
{        
    int iVar=3;        
    printf("Thread %d\n",iVar);        
    pthread_mutex_lock(&mutexVar);        
    pthread_cond_wait(&condVar,&mutexVar);        
    pthread_mutex_unlock(&mutexVar);        
    printf("Thread %d is unblocked...\n",iVar);        

}        

void *thread4(void *ptr)        
{        
    int iVar=4;        
    printf("Thread %d\n",iVar);        
    pthread_mutex_lock(&mutexVar);        
    pthread_cond_wait(&condVar,&mutexVar);        
    pthread_mutex_unlock(&mutexVar);        
    printf("Thread %d is unblocked...\n",iVar);        

}        


int main()        
{        
    int i,j=2;        
    pthread_t t[4];        
    cpu_set_t cpuset;        

    pthread_create(&t[0],0,thread1,0);
    pthread_create(&t[1],0,thread2,0);
    pthread_create(&t[2],0,thread3,0);
    pthread_create(&t[3],0,thread4,0);

    for(i=0;i<4;i++)            //Assign dedicated core for each thread
    {
        CPU_ZERO(&cpuset);
        CPU_SET(j,&cpuset);
        if((pthread_setaffinity_np(t[i],sizeof(cpu_set_t),&cpuset))!=0)
            perror("Set_affinity");
        j+=2;
    }
    sleep(5);
    pthread_cond_broadcast(&condVar);
    while(1);
}    