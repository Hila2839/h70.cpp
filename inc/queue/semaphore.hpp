#include <semaphore.h>

#include "error.hpp"


class Semaphore { 
public:    
    Semaphore(int a_numSemaphores);
    ~Semaphore();    
    Semaphore(const Semaphore &a_other) = delete;     
    Semaphore &operator=(const Semaphore &a_other) = delete;

    void Wait() noexcept;
    bool try_wait();  
    void Release(); 
private:   
  sem_t m_semaphore;
 }; 