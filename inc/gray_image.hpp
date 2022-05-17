#ifndef GRAY_IMAGE_H
#define GRAY_IMAGE_H 


#include <cstddef>





namespace gfx
{


class GrayImage
{

public:
    
    GrayImage(int a_rows, int a_columns, int a_pixles_range);

    
    GrayImage(int a_rows, int a_columns);
    

    ~GrayImage();
    GrayImage(GrayImage const& a_image);

    GrayImage& operator=(GrayImage const& a_image);



    void print();
    void clear();
    int get_width();
    int get_hight();
    int get_range();
    int* get_array();
    int get_pixle(int a_row, int a_column) const;
    void set_pixle(int a_row, int a_column, int a_pixle);
    GrayImage operator~() const;
    int& at (int a_row, int a_column);
    int& operator() (int a_row, int a_column);
    struct Point
    {
        int row;
        int column;
    };
    int& operator[] (Point a_row);


    
private:
    int m_rows;
    int m_columns;
    int m_pixles_range;
    int *m_array;
    size_t m_array_size;
};

bool operator==(GrayImage a_rhs, GrayImage a_lhs);
bool operator!=(GrayImage a_rhs, GrayImage a_lhs);

GrayImage operator&(GrayImage const& a_lhs, GrayImage a_rhs);
GrayImage operator|(GrayImage const& a_lhs, GrayImage a_rhs);
GrayImage operator^(GrayImage const& a_lhs, GrayImage a_rhs);


GrayImage& operator&=(GrayImage& a_original, GrayImage a_other);

GrayImage& operator|=(GrayImage& a_original, GrayImage& a_other);

GrayImage& operator^=(GrayImage& a_original, GrayImage& a_other);

void write_to_file(GrayImage a_image, const char* a_file_name);

GrayImage read_from_file(const char* a_file_name);


}//namespace gfx

#endif