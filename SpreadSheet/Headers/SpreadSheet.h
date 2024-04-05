#ifndef __SPREAD_SHEET_H__
#define __SPREAD_SHEET_H__

#include "Cell.h"

class SpreadSheet : public Cell{
private:
    Cell** ob; 
private:
    struct POINT {
        int x; 
        int y; 
    } ob1;
public:
 SpreadSheet();
 ~SpreadSheet() noexcept;
 SpreadSheet(int row);
 SpreadSheet(int row , int col);
 SpreadSheet(const SpreadSheet& rhv);
 SpreadSheet(SpreadSheet&& rhv);
 const SpreadSheet& operator=(const SpreadSheet& rhv);
 const SpreadSheet& operator=(SpreadSheet&& rhv);
//   SpreadSheet& operator[](POINT ob1);
public:
    void add_row(int row , int col , std::string str);
    void add_colum(int row , int col  , std::string str);
    void resize_row(int row);
    void resize_colum(int col);
    void resize(int row , int col);
    void delete_row(int row);
    void delete_colum(int col);
    void print();
public:
    void copy_from(int row , int col , const SpreadSheet& rhv);
   // SpreadSheet slice(size_t n , size_t m);
   int get_row() const {
        return row_width;
   }
   int get_col() const {
        return col_width;
   }
   
private:
 int row_width; 
 int col_width; 

};

#endif // 