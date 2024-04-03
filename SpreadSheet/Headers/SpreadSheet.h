#ifndef __SPREAD_SHEET_H__
#define __SPREAD_SHEET_H__

#include "Cell.h"

class SpreadSheet {
private:
    Cell** ob; 
public:
 SpreadSheet();
 ~SpreadSheet() noexcept;
 SpreadSheet(int row);
 SpreadSheet(int row , int col);
 SpreadSheet(const SpreadSheet& rhv);
 SpreadSheet(SpreadSheet&& rhv);
 const SpreadSheet& operator=(const SpreadSheet& rhv);
 const SpreadSheet& operator=(SpreadSheet&& rhv);
public:
    void add_row(int row , int col , std::string str);
    void add_colum(int row , int col  , std::string str);
    void resize_row(int row);
    void resize_colum(int col);
    void resize(int row , int col);
    void delete_row(int row);
    void delete_colum(int col);
public:
    void copy_from(int row , int col , const SpreadSheet& rhv);
   // SpreadSheet slice(size_t n , size_t m);
   int get_row_width() const {
        return row_width;
   }
   int get_col_width() const {
        return col_width;
   }
   
private:
 int row_width; 
 int col_width; 

};

#endif // 