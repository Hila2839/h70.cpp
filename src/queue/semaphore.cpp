#include <semaphore.h>
#include <cassert>

#include "error.hpp"
#include "semaphore.hpp"

Semaphore::Semaphore(int a_numSemaphores)
{   
 int result = sem_init(&m_semaphore, 0, a_numSemaphores);
 if (result != 0)
 {
     throw Error("sem_init", "failed to init the semaphore");
 }
 
}


Semaphore::~Semaphore() 
{    
int result = sem_destroy(&m_semaphore);
assert(result == 0 && "semaphore distructor error");
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