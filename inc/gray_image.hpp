#ifndef GRAY_IMAGE_H
#define GRAY_IMAGE_H 

#include "rational.hpp"



namespace gfx
{


class GrayImage
{
public:
    
    GrayImage(int a_rows, int a_columns, int a_pixles_range);

    
    GrayImage(int a_rows, int a_columns);
    


    void print();
    void clear();
    int get_width();
    int get_hight();
    int get_pixle(int a_row, int a_column);
    void set_pixle(int a_row, int a_column, int a_pixle);
    
    save_image_to_file
    read_image_from_file



    
private:
    int m_rows;
    int m_columns;
    int m_pixles_range;
    int *m_array;
};

bool operator==(GrayImage a_rhs, GrayImage a_lhs);
bool operator!=(GrayImage a_rhs, GrayImage a_lhs);
GrayImage operator~(GrayImage a_rhs, GrayImage a_lhs);
GrayImage operator&(GrayImage a_rhs, GrayImage a_lhs;
GrayImage operator|(GrayImage a_rhs, GrayImage a_lhs);
GrayImage operator^(GrayImage a_rhs, GrayImage a_lhs);

}//namespace gfx

#endif