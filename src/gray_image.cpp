#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <iostream>


#include "gray_image.hpp"

namespace gfx
{



GrayImage::GrayImage(int a_rows, int a_columns, int a_pixles_range)
: m_rows(a_rows)               
, m_columns(a_columns)
, m_pixles_range(a_pixles_range)
, m_array_size(m_rows * m_columns)
{   
    m_array = new int[m_rows * m_columns];
    assert(m_pixles_range > 0 && "pixles range can't be zero");  
    assert(m_pixles_range < 250 && "pixles range can't be more than 250");
    for (int i = 0; i < m_rows; ++i)
    {
        for (int j = 0; j < m_columns; ++j)
        {
           m_array[i * m_columns + j] = 0;
        }
    }    
}

GrayImage::GrayImage(int a_rows, int a_columns)
: m_rows(a_rows)               
, m_columns(a_columns)
, m_pixles_range(15)
{   
   m_array = new int[m_rows * m_columns];
   for (int i = 0; i < m_rows; ++i)
    {
        for (int j = 0; j < m_columns; ++j)
        {
           m_array[i * m_columns + j] = 0;
        }
    }
}



GrayImage::~GrayImage()
{
    delete[]m_array;
}


GrayImage::GrayImage(GrayImage const& a_image)
: m_rows(a_image.m_rows)
, m_columns(a_image.m_columns)
, m_pixles_range(a_image.m_pixles_range)
, m_array(new int[a_image.m_rows * a_image.m_columns])
//static_cast<int*>(::malloc( m_capacity * sizeof(int)))
{ 
      for (int i = 0; i < m_rows; ++i)
    {
        for (int j = 0; j < m_columns; ++j)
        {
             m_array[i * m_columns + j]  = a_image.m_array[i * m_columns + j];
        }
    }
}


GrayImage& GrayImage::operator=(GrayImage const& a_image)
{
    if(this != &a_image)
    {
        delete[]m_array;

        m_rows = a_image.m_rows;
        m_columns = a_image.m_columns;
        m_pixles_range = a_image.m_pixles_range;
        m_array  = new int[a_image.m_rows * a_image.m_columns];
        for (int i = 0; i < m_rows; ++i)
        {
            for (int j = 0; j < m_columns; ++j)
            {
                m_array[i * m_columns + j]  = a_image.m_array[i * m_columns + j];
            }
        }
    }
    return *this;
}



void GrayImage::print()
{
    for (int i = 0; i < m_rows; ++i)
    {
        for (int j = 0; j < m_columns; ++j)
        {
            printf("%d ", m_array[i * m_columns + j]);
        }
        printf("\n"); 
    }
    
}


void GrayImage::clear()
{
    for (int i = 0; i < m_rows; ++i)
    {
        for (int j = 0; j < m_columns; ++j)
        {
           m_array[i * m_columns + j] = 1;
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

int GrayImage::get_range()
{
    return m_pixles_range;
}

int* GrayImage::get_array()
{
    return m_array;
}


int GrayImage::get_pixle(int a_row, int a_column) const
{
    return m_array[a_row * m_columns + a_column];
}

void write_to_file(GrayImage a_image, const char* a_file_name)
{
    FILE *fp;
    fp = fopen(a_file_name, "w");
    assert(fp && "file open filure, need more channel");

    if(a_image.get_range() == 2)
    {
        fprintf(fp, "%s\n", "P1");
    }
    else
    {
        fprintf(fp, "%s\n", "P2");
    }

    fprintf(fp, "%d %d\n", a_image.get_width(),  a_image.get_hight());
    fprintf(fp, "%d\n", a_image.get_range());
    
    for (int i = 0; i < a_image.get_width(); ++i)
    {
        for (int j = 0; j < a_image.get_hight(); ++j)
        {
            fprintf(fp, "%d ", a_image.get_pixle(i, j));
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}


GrayImage read_from_file(const char* a_file_name)
{
   std::ifstream file_name(a_file_name);
   assert(file_name.is_open() && "failed to open a new file");

   int rows = 0, columns = 0, pixles_range = 0, color = 0;

   file_name.ignore(strlen("P2\n"));
   file_name >> rows >> columns >> pixles_range;

   GrayImage from_file(rows, columns, pixles_range);

    for (int i = 0; i < from_file.get_width(); ++i)
    {
        for (int j = 0; j < from_file.get_hight(); ++j)
        {
            file_name >> color;
            from_file.set_pixle(i, j, color);
        }
    }
    file_name.close();
    return from_file;
}



void GrayImage::set_pixle(int a_row, int a_column, int a_pixle)
{
    m_array[(a_row * m_columns) + a_column] = a_pixle;
}
    




bool operator==(GrayImage a_rhs, GrayImage a_lhs)
{
    if( a_rhs.get_width() != a_lhs.get_width() ||  a_rhs.get_hight() != a_lhs.get_hight())
    {
        return false;
    }
    for (int i = 0; i < a_rhs.get_width(); ++i)
    {
        for (int j = 0; j < a_rhs.get_hight(); ++j)
        {
           if(a_lhs.get_pixle(i, j) != a_rhs.get_pixle(i , j))
           {
               return false;
           }
        }
    }
    return true;
}






bool operator!=(GrayImage a_rhs, GrayImage a_lhs)
{
    return !(a_rhs == a_lhs);
}



GrayImage GrayImage::operator~() const
{
    GrayImage result = *this;
    for (int i = 0; i < m_rows; ++i)
    {
        for (int j = 0; j < m_columns; ++j)
        {
            result.set_pixle(i, j, m_pixles_range - get_pixle(i, j));
        }
    }
    return result;
}



GrayImage& operator&=(GrayImage& a_original, GrayImage a_other)
{
    assert( a_original.get_width() == a_other.get_width() && "width invalid");
    assert( a_original.get_hight() == a_other.get_hight() && "hight invalid");
    assert( a_original.get_range() == a_other.get_range() && "pixels range invalid");
    for (int i = 0; i < a_original.get_width(); ++i)
    {
        for (int j = 0; j < a_original.get_hight(); ++j)
        {
            int temp_pixle = a_original.get_pixle(i, j) & a_other.get_pixle(i, j);
             a_original.set_pixle(i, j, temp_pixle );
        }
    }
    return a_original;
}


GrayImage& operator|=(GrayImage& a_original, GrayImage& a_other)
{
    assert( a_original.get_width() == a_other.get_width() && "width invalid");
    assert( a_original.get_hight() == a_other.get_hight() && "hight invalid");
    assert( a_original.get_range() == a_other.get_range() && "pixels range invalid");
    for (int i = 0; i < a_original.get_width(); ++i)
    {
        for (int j = 0; j < a_original.get_hight(); ++j)
        {
            int temp_pixle = a_original.get_pixle(i, j) | a_other.get_pixle(i, j);
             a_original.set_pixle(i, j, temp_pixle );
        }
    }
    return a_original;
}


GrayImage& operator^=(GrayImage& a_original, GrayImage& a_other)
{
    assert( a_original.get_width() == a_other.get_width() && "width invalid");
    assert( a_original.get_hight() == a_other.get_hight() && "hight invalid");
    assert( a_original.get_range() == a_other.get_range() && "pixels range invalid");
    for (int i = 0; i < a_original.get_width(); ++i)
    {
        for (int j = 0; j < a_original.get_hight(); ++j)
        {
            int temp_pixle = a_original.get_pixle(i, j) ^ a_other.get_pixle(i, j);
             a_original.set_pixle(i, j, temp_pixle );
        }
    }
    return a_original;
}


GrayImage operator&(GrayImage const& a_lhs, GrayImage a_rhs)
{
    GrayImage temp_image = a_lhs;
    return (temp_image &= a_rhs);


}

GrayImage operator|(GrayImage const& a_lhs, GrayImage a_rhs)
{
    GrayImage temp_image = a_lhs;

    return (temp_image |= a_rhs);


}

GrayImage operator^(GrayImage const& a_lhs, GrayImage a_rhs)
{
    GrayImage temp_image = a_lhs;
    return (temp_image ^= a_rhs);


}

/*GrayImage operator&(GrayImage a_rhs, GrayImage a_lhs)
{

    a_rhs &= a_lhs;
    return a_rhs;
    assert( (a_rhs.get_width() != a_lhs.get_width() ||  a_rhs.get_hight() != a_lhs.get_hight() ) && "size not equal")
    int row = a_rhs.get_width();
    int column = a_rhs.get_hight();
    int range =  a_rhs.get_range();
    int* array = m_array = (static_cast<int*>(::malloc( row * column * sizeof(int))));
    
    GrayImage::GrayImage new_pic(a_rhs.get_width(), a_rhs.get_hight(), a_rhs.get_range());
    for (int i = 0; i < a_rhs.get_width(); ++i)
    {
        for (int j = 0; j < a_rhs.get_hight(); ++j)
        {
            new_pic.set_pixle(i, j) = a_rhs.get_pixle(i, j) & a_lhs.get_pixle(i, j);  
        }
    }
    return new_pic;
}*/
   



/*
GrayImage operator|(GrayImage a_rhs, GrayImage a_lhs
{
    assert( a_rhs.get_rows != a_lhs.get_width() ||  a_rhs.get_columns != a_lhs.get_columns && "size not equal")
    
    GrayImage GrayImage::new_pic(a_rhs.get_width(), a_rhs.get_hight(), a_rhs.get_pixles_size);
    for (int i = 0; i < a_rhs.get_width(); ++i)
    {
        for (int j = 0; j < a_rhs.get_columns; ++j)
        {
           new_pic.get_array[i][j] = a_rhs.get_array[i][j] | a_lhs.get_array[i][j];
        }
    }

}



GrayImage operator^(GrayImage a_rhs, GrayImage a_lhs)
{
    assert( a_rhs.get_rows != a_lhs.get_rows ||  a_rhs.get_columns != a_lhs.get_columns && "size not equal")
    
    GrayImage GrayImage::new_pic(a_rhs.get_width(), a_rhs.get_hight(), a_rhs.get_pixles_size);
    for (int i = 0; i < a_rhs.get_rows; ++i)
    {
        for (int j = 0; j < a_rhs.get_columns; ++j)
        {
           new_pic.get_array[i][j] = a_rhs.get_array[i][j] ^ a_lhs.get_array[i][j];
        }
    }
}*/

 int&  GrayImage::at (int a_row, int a_column)
 {
     return m_array[a_row * m_columns + a_column];
 }


int& GrayImage::operator() (int a_row, int a_column)
{
    return m_array[a_row * m_columns + a_column];
}


int* GrayImage::operator[] (int a_row) 
{
    
    return &m_array[a_row * m_columns];
}


GrayImage rotate90(GrayImage& a_image)
{
    GrayImage result(a_image.get_width(), a_image.get_hight(), a_image.get_range());

    for (int i = 0; i < a_image.get_width(); i++)
    {
        for (int j =  0 ; j < a_image.get_hight(); ++j)
        {
            result.set_pixle(j, a_image.get_width() - i, a_image.get_pixle(i, j));
        }  
    }
    return result;
}

std::ostream& operator<<(std::ostream& a_os, GrayImage& a_img)
{
    a_os <<"P2\n" << a_img.get_width() << " " << a_img.get_hight() << '\n' << a_img.get_range() << '\n';

    for (int i = 0; i < a_img.get_hight(); i++)
    {
        for (int j =  0 ; j < a_img.get_width(); ++j)
        {
            a_os << a_img.get_pixle(i, j) << ' ';
        }  
        a_os << '\n';
    }
    return a_os;
}

int avg_pixle (GrayImage& a_image, int a_part, int a_row, int a_column)
{ 
    int sum = 0;
    int count = 0;
    for (int i = 0; i < a_image.get_width() / a_part ; i++)
    {
       for (int j = 0; j <  a_image.get_hight() / a_part; j++)
        {
            sum += a_image.get_pixle(i, j);
            count++;
        }
    }
    return sum / count;
}
    

GrayImage scale_down(GrayImage& a_image, int a_part)
{
    GrayImage result(a_image.get_width() / 2, a_image.get_hight() / 2, a_image.get_range());

    int jump_square_row = a_image.get_width() / a_part;
    int jump_square_column = a_image.get_hight() / a_part;
     
    for (int i = 0; i < a_image.get_width(); i+= jump_square_row)
    {
        for (int j =  0 ; j < a_image.get_hight(); j += jump_square_column)
        {
            result.set_pixle(i, j, avg_pixle (a_image,a_part,i ,j));
        }  
    }
    return result;
}


GrayImage drow_line(GrayImage&  a_image, int a_x0 , int a_x1, int a_y0, int a_y1, int a_color)
{
    GrayImage result = a_image;
    int m = (a_y0 - a_y1) / (a_x0 - a_x1);
    int n = -(m * a_x0) + a_y0;

    for (int y = a_y0 ; y < a_y1; y++)
    {
        result.set_pixle(y, (y - n) / m , a_color);
    }
    return result;
}





}//namespace gfx
