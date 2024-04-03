#ifndef __SPREAD_SHEET_H__
#define __SPREAD_SHEET_H__

#include "Cell.h"
class SpreadSheet {
private:
    Cell ** ob; 
public:
 SpreadSheet();
 ~SpreadSheet();
 SpreadSheet(const SpreadSheet& rhv);
 SpreadSheet(SpreadSheet&& rhv);
 const SpreadSheet& operator=(const SpreadSheet& rhv);
 const SpreadSheet& operator=(SpreadSheet&& rhv);
public:
    void add_row(int n , double d, std::string str);
    void add_colum(int n , double d , std::string str);
    void resize_row(int n);
    void resize_colum(int n);
    void resize(int n , int m);
    void delete_row(int n);
    void delete_colum(int m);
public:
    void copy_from(int n , int m , const SpreadSheet& rhv);
   // SpreadSheet slice(size_t n , size_t m);

};

#endif // 