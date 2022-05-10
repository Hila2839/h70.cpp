#include <cstdio>
#include <cstdlib>//malloc

#include "first.hpp"

/*-----------------------------------find an int-----------------------------*/


bool find(int const *a_haystack,  size_t a_size, int a_needle)
{
    if(!a_haystack)
    {
        return false;
    }
   //  Obi wan;   off by one
   // 2compare 1 implement reduce to 2 things
    for (size_t i = 0; i < a_size; ++i)
    {
        if (a_needle == a_haystack[i])
        {
            return true;
        }
    }
    
    return false;
}
//fix according to lesson
static bool recursiveFind(int const *a_haystack,  int const *a_end, int a_needle)
{
    if(a_haystack == a_end) return false;
    if (*a_haystack == a_needle) return true;
    return recursiveFind(++a_haystack, a_end, a_needle);
}


bool findRec(int const *a_haystack,  size_t a_size, int a_needle)
{
   
    if(!a_haystack )
    {
        return false;
    }
    return recursiveFind(a_haystack, a_haystack + a_size, a_needle); 
}



/*-----------------------------------bite on int-----------------------------*/

unsigned int FindHowManyBitesOnLong(long a_lon)
{
	unsigned int count = 0;
    if(a_lon < 0)
    {
        a_lon *= -1;
    }

    while(a_lon != 0)
	{
		if((a_lon & 1) == 1)
		{
			count++;
		}
        a_lon = a_lon >> 1;
	}
    return count;
}



/*-----------------------------------binar search-----------------------------*/

size_t FindIndex(int const *a_array,  size_t a_size, int a_num)
{
    if(a_array == NULL || a_size < 1)
    {
        return (a_size );
    }
    int part = 2;
    size_t new_size = a_size / part;
    for (size_t i = 0; i < a_size; ++i)
    {
        if(a_num > a_array[new_size])
        {
            new_size += new_size / part;
            part /= 2;
        }
        else if(a_num == a_array[new_size])
        {
            return new_size;
        }
        else
        {
            new_size -= new_size / part;
            part /= 2;
        }
    }
    return (a_size );
}
//same in different(and right) way
size_t binarySearch(int const *a_array,  size_t a_size, int a_num)
{
    size_t start = 0;
    size_t end = a_size - 1;
    if(!a_array || !a_size)
    {
        return a_size;
    }
    while(start <= end)
    {
        long mid = start +((end - start) / 2);
        if(a_array[mid] == a_num)
        {
            return mid;
        }
        if(a_array[mid] < a_num)
        {
            start = mid + 1;
        }
        else
        {
            if(end - 1 == 0)
            {
                break;
            }
            end = mid - 1;
        }
    }
    return a_size;
}
/*-----------------------------------2 recursive-----------------------------*/

int add(int a, int b)
{
    return a + b;
}

int half(int a)
{
    return a / 2;
}

bool is_odd(int a)
{
    if(a < 0)
    {
        a = -a;
    }
    if(a % 2 == 1)
    {
        return true;
    }
    return false;
}

int multi(int a, int b)
{
    if(!a || !b)
    {
        return 0;
    }
    if(b < 0)
    {
        return -multi(a, -b);
    }
    return add(a,multi(a, b - 1));
}


bool isEven(int a_num)
{
    if(a_num < 0)
    {
        a_num = -a_num;
    }
    if(a_num == 0 )
    {
        return true;
    }
    if(a_num == 1)
    {
        return false;
    }
    return isEven(a_num - 2);
}


/*-----------------------------------------monotonicly-------------------*/




mono monoticity(const float *a_array, size_t a_size)
{
    if(!a_array)
    {
        return MONO_ERROR;
    }
    int is_equal = 1;
    for (size_t i = 0; i <= a_size - 2; ++i)
    {
        if(a_array[i] > a_array[i + 1])
        {
            break;
        }
        if(a_array[i] == a_array[i + 1])
        {
            is_equal = 0;
        }
        if(i == (a_size - 2))
        {
            if(is_equal == 1)
            {
                return MONO_STRICLY_INCREASING;
            }
            return MONO_INCREASING;
        }

    }
    is_equal = 1;
    for (size_t i = 0; i <= a_size - 2; ++i)
    {
        if(a_array[i] < a_array[i + 1])
        {
            break;
        }
        if(a_array[i] == a_array[i + 1])
        {
            is_equal = 0;
        }
        if(i == (a_size - 2))
        {
            if(is_equal == 1)
            {
                return MONO_STRICLY_DECREASING;
            }
            return MONO_DECREASING;
        }

    }
    return MONO_NOT_MONO;
}

/*-----------------------------------------prime factors------------*/

bool is_prime(size_t a_number)
{
    if(a_number == 0 || a_number == 1)
    {
        return false;
    }
    for (size_t i = 2; i <= a_number / 2 ; ++i)
    {
        if(a_number % i == 0)
        {
            return false;
        }
    }
    return true;
    
}

size_t* prime_factors(unsigned long a_number)
{
    size_t *array = static_cast<size_t*>(malloc(sizeof(size_t)));
    int j = 0;
    for (size_t i = 2; i <= a_number / 2 ; ++i)
    {
        if(a_number % i == 0)
        {
            if(is_prime(i) == true)
            {
                array[j] = i;
                ++j;
            }
        }
    }
    return array;
}

