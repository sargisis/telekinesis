#include "../Headers/Cell.h"
#include "../Headers/SpreadSheet.h"

SpreadSheet::SpreadSheet() 
 : ob {nullptr}
 , row_width{0}
 , col_width{0}
{}

SpreadSheet::SpreadSheet(int row)
  : ob{new Cell*[row]}
  , row_width{row}
  , col_width{0}
{
    for(size_t i = 0; i < row; ++i){
        ob[i] = new Cell[row];
    }
    
}

SpreadSheet::SpreadSheet(const SpreadSheet& rhv)    
    : row_width{0}
    , col_width{0}
{
    ob = rhv.ob;
    row_width = rhv.row_width;
    col_width = rhv.col_width;
}

SpreadSheet::SpreadSheet(SpreadSheet&& rhv) 
    : row_width{std::move(rhv.row_width)}
    , col_width{std::move(rhv.col_width)}
    , ob{std::move(rhv.ob)}
{
        ob = nullptr;
        row_width = 0; 
        col_width = 0; 

}

const SpreadSheet& SpreadSheet::operator=(const SpreadSheet& rhv) {
    if (this != &rhv){
    
    for(size_t i = 0; i < row_width; ++i){
        delete[] ob[i];
        ob[i] = nullptr;
    }

    ob = new Cell*[row_width];
    for (size_t i = 0; i < row_width; ++i){
        ob[i] = new Cell[col_width];
        for(size_t j = 0; j < col_width; ++j){
            ob[i][j] = rhv.ob[i][j];
        }
    }
    }
}


const SpreadSheet& SpreadSheet::operator=(SpreadSheet&& rhv){
    if (this != &rhv){
        for (size_t i = 0; i < row_width; ++i){
            delete[] ob[i]; 
            ob[i] = nullptr;
        }
        ob = new Cell*[row_width];
        for (size_t i = 0 ; i < row_width; ++i){
            ob[i] = new Cell[col_width];
            for (size_t j = 0; j < col_width; ++j) {
                ob[i][j] = std::move(rhv.ob[i][j]);
            }
        }
        delete[] ob; 
        ob = nullptr;
    }
    return *this; 
}


SpreadSheet::SpreadSheet(int row , int col ) 
    : row_width{row}
    , col_width{col}
    , ob{ new Cell*[row]}
{
    for(size_t i = 0; i < row; ++i){
        ob[i] = new Cell[col];
    }
    delete[] ob; 
    ob = nullptr;
}

SpreadSheet::~SpreadSheet() noexcept{
    for (size_t i = 0; i < row_width; i++)
    {
        delete[] ob[i]; 
    }
    delete[] ob; 
    ob = nullptr;
    
}

void SpreadSheet::add_row(int row , int col , std::string str){
    ob = new Cell*[row];
    for(size_t i = 0; i < row; ++i){
        ob[i] = new Cell[col];
        for(size_t j = 0; j < col; ++j){
            ob[i][j] = str; 
        }
    }
    delete[] ob;
    ob = nullptr;
}

void SpreadSheet::add_colum(int row , int col , std::string str){
     ob = new Cell*[row];
    for(size_t i = 0; i < row; ++i){
        ob[i] = new Cell[col];
        for(size_t j = 0; j < col; ++j){
            ob[i][j] = str; 
        }
    }
    delete[] ob;
    ob = nullptr;
}

void SpreadSheet::resize_row(int row){
    Cell** new_size = new Cell*[row];
    int minRow = std::min(row, row_width);

    for(size_t i = 0; i < minRow; ++i){
        new_size[i] = ob[i];
    }

    for(size_t i = minRow; i < row; ++i){
        new_size[i] = new Cell();
    }

    ob = new_size;
    row_width = row;
}

void SpreadSheet::resize_colum(int col){
    Cell** new_size = new Cell*[col];
    int minCol = std::min(col , col_width);
    
    for(size_t i = 0; i < minCol; ++i){
        new_size[i] = ob[i];
    }

    for(size_t i = minCol; i < col; ++i){
        new_size[i] = new Cell();
    }

    ob = new_size; 
    col_width = col; 
}


void SpreadSheet::resize(int row , int col ){
    Cell** new_size = new Cell*[row];
    for(size_t i = 0; i < row; ++i){
        new_size[i] = new Cell[col];
    }
    int minRow = std::min(row , row_width);
    int minCol = std::min(col , col_width);

    for(size_t i = 0; i < minRow; ++i){
        new_size[i] = ob[i];
    }

    for(size_t i = 0; i < minCol; ++i){
        new_size[i] = ob[i];
    }
    
    for(size_t i = minRow; i < row; ++i){
        new_size[i] = new Cell();
    }

    for(size_t i = minCol; i < col; ++i){
        new_size[i] = new Cell();
    }

    ob = new_size; 
    row_width = row; 
    ob = new_size; 
    col_width = col; 
}

void SpreadSheet::delete_row(int row) {
    if (row >= 0 && row < row_width) {
        delete[] ob[row];
        for (int i = row; i < row_width - 1; ++i) {
            ob[i] = ob[i + 1];
        }
        ob[row_width - 1] = nullptr;
        --row_width;
    }
}

void SpreadSheet::delete_colum(int col) {
    if (col >= 0 && col < col_width) {
        for (int i = 0; i < row_width; ++i) {
            for (int j = col; j < col_width - 1; ++j) {
                ob[i][j] = ob[i][j + 1];
            }
            ob[i][col_width - 1] = Cell(); 
        }
        --col_width;
    }
}


void SpreadSheet::copy_from(int row, int col, const SpreadSheet& rhv) {
    if (row >= 0 && col >= 0 && row < rhv.row_width && col < rhv.col_width) {
        row_width = rhv.row_width;
        col_width = rhv.col_width;

        delete[] ob;
        ob = new Cell*[row_width];
        for (int i = 0; i < row_width; ++i) {
            ob[i] = new Cell[col_width];
            for (int j = 0; j < col_width; ++j) {
                ob[i][j] = rhv.ob[i][j];
            }
        }
    }
}

