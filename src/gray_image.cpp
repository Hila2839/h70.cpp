
namespace gfx
{
GrayImage::GrayImage(int a_rows, int a_columns, int a_pixles_range);
: m_rows(a_rows)               
, m_columns(a_columns)
, m_pixles_range(a_pixles_range)
{   
    int arr[a_rows][a_columns] = {0};
    m_array = arr;
    assert(m_pixles_range != 0 && "pixles range can't be zero");    
}

GrayImage::GrayImage(int a_rows, int a_columns);
: m_rows(a_rows)               
, m_columns(a_columns)
, m_pixles_range(15)
{   
    int arr[a_rows][a_columns] = {0};
    m_array = arr;
}

void print()
{
    for (int i = 0; i < m_rows; ++i)
    {
        for (int j = 0; j < m_columns; ++j)
        {
            printf("%d ", m_array[i][j]);
        }
        printf("\n "); 
    }
    
}


void clear()
{
    for (int i = 0; i < m_rows; ++i)
    {
        for (int j = 0; j < m_columns; ++j)
        {
           m_array[i][j] = 1;
        }
    }
    
}


int GrayImage::get_width()
{
    return m_rows;
}


int GrayImage::get_hight()
{
    return m_columns;
}


int GrayImage::get_pixle(int a_row, int a_column)
{
    return m_array[a_row][a_column];
}


void GrayImage::set_pixle(int a_row, int a_column, int a_pixle)
{
    m_array[a_row][a_column] = a_pixle;
}
    
bool operator==(GrayImage a_rhs, GrayImage a_lhs)
{
    if( a_rhs.m_rows != a_lhs.m_rows ||  a_rhs.m_columns != a_lhs.m_columns)
    {
        return false;
    }
    for (int i = 0; i < a_rhs.m_rows; ++i)
    {
        for (int j = 0; j < a_rhs.m_columns; ++j)
        {
           if(a_rhs.m_array[i][j] != a_lhs.m_array[i][j] )
           {
               return false;
           }
        }
        return true;
    }
}


bool operator!=(GrayImage a_rhs, GrayImage a_lhs)
{
    return !(a_rhs == a_lhs);
}


}//namespace gfx
