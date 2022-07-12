#include "semaphore.hpp"

#include <semaphore.h>

Semaphore::Semaphore(int a_numSemaphores)
{   
 sem_init(&m_semaphore, 0, a_numSemaphores);
}


Semaphore::~Semaphore() 
{    
sem_destroy(&m_semaphore);
}

int Semaphore::Wait()
{   
     return sem_wait(&m_semaphore);
} 

int Semaphore::try_wait()
{   
     return sem_trywait(&m_semaphore);
} 

int Semaphore::Release() 
{    
    return sem_post(&m_semaphore);
}