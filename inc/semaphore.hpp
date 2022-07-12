#include <semaphore.h>

class Semaphore { 
public:    
    Semaphore(int a_numSemaphores);
    ~Semaphore();    
    Semaphore(const Semaphore &a_other) = delete;     
    Semaphore &operator=(const Semaphore &a_other) = delete;

    int Wait();  
    int try_wait();  
    int Release(); 
private:   
  sem_t m_semaphore;
 }; 