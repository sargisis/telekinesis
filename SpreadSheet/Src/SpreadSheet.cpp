#include "../Headers/Cell.h"
#include "../Headers/SpreadSheet.h"

SpreadSheet::SpreadSheet()
    : ob{nullptr}
    , row_width{0}
    , col_width{0}
{}

SpreadSheet::~SpreadSheet() noexcept 
{
    for(size_t i = 0; i < row_width; ++i){
        delete[] ob[i];
        ob[i] = nullptr;
    }
    delete[] ob; 
    ob = nullptr; 
}

SpreadSheet::SpreadSheet(int row)
    : row_width{row}
    , col_width{0}
{
    ob = new Cell*[row];
    for (size_t i = 0; i < row; ++i){
        ob[i] = new Cell[row_width];
    }
}

SpreadSheet::SpreadSheet(int row , int col)
    : row_width{row}
    , col_width{col}
{
        ob = new Cell*[row];
        for (size_t i = 0; i < row; ++i){
            ob[i] = new Cell[col_width];
        }
}



SpreadSheet::SpreadSheet(const SpreadSheet& rhv) 
    : row_width{rhv.row_width}
    , col_width{rhv.col_width}
{
    ob = new Cell*[row_width];
    for (size_t i = 0; i < row_width; ++i){
        ob[i] = new Cell[col_width];
    }
    for (size_t i = 0; i < row_width; ++i){
        for (size_t j = 0; j < col_width; ++j){
            ob[i][j] = rhv.ob[i][j];
        }
    }
}

SpreadSheet::SpreadSheet(SpreadSheet&& rhv)
    : ob{std::move(rhv.ob)}
    , row_width{std::move(rhv.row_width)}
    , col_width{std::move(rhv.col_width)}
{
    ob = nullptr; 
    row_width = 0; 
    col_width = 0; 
}


const SpreadSheet& SpreadSheet::operator=(const SpreadSheet& rhv){
    if (this != &rhv){
        for(size_t i = 0; i < row_width; ++i){
            delete[] ob[i];
            ob[i] = nullptr;
        }
        row_width = rhv.row_width;
        col_width = rhv.col_width;

        ob = new Cell*[row_width];
        for (size_t i = 0; i < row_width; ++i){
            ob[i] = new Cell[col_width];
        }
        for (size_t i = 0; i < row_width; ++i){
            for (size_t j = 0; j < col_width; ++j){
                ob[i][j] = rhv.ob[i][j];
            }
        }
    }
    return *this; 
}

const SpreadSheet& SpreadSheet::operator=(SpreadSheet&& rhv){
    if (this != &rhv)
    {
        for (size_t i = 0; i < col_width; ++i){
            delete[] ob[i];
            ob[i] = nullptr;
        }
        row_width = std::move(rhv.row_width);
        col_width = std::move(rhv.col_width);
        ob = std::move(rhv.ob);

        ob = nullptr; 
        row_width = 0; 
        col_width = 0; 
    }
    return *this; 
}

void SpreadSheet::print() {
    for (size_t i = 0; i < row_width; ++i){
        for (size_t j = 0; j < col_width; ++j){
            std::cout << ob[i][j].getValue() << '\t';
        }
        std::cout << '\n';
    }
}

void SpreadSheet::add_row(int row , int col , std::string str){
    row_width = row;
    col_width = col;
    ob = new Cell*[row_width];
    for (size_t i = 0; i < row_width; ++i){
        ob[i] = new Cell[col_width];
    }
    for (size_t i = 0; i < row_width; ++i){
        for (size_t j = 0; j < col_width; ++j){
            ob[i][j] = str;
        }
    }
    delete[] ob[row];
    ob[row] = nullptr; 
}

void SpreadSheet::add_colum(int row , int col , std::string str){
    row_width = row; 
    col_width = col; 
    ob = new Cell*[col_width];
    for (size_t i = 0; i < col_width; ++i){
        ob[i] = new Cell[row_width];
    }
    for (size_t i = 0; i < col_width; ++i){
        for (size_t j = 0; j < row_width; ++j){
            ob[i][j] = str; 
        }
    }
    delete[] ob[col];
    ob[col] = nullptr;
}


void SpreadSheet::resize_row(int row) {
    int minRow = std::min(row , row_width);
    Cell** new_size = new Cell*[row];
    for (size_t i = 0; i < minRow; ++i){
        new_size[i] = ob[i];
    }

    for (size_t i = minRow; i < row; ++i){
         new_size[i] = new Cell();
    }
    ob = new_size; 
    row_width = row;
}

void SpreadSheet::resize_colum(int col){
    int minCol = std::min(col , col_width);
    Cell** new_size = new Cell*[col];
    for (size_t i = 0; i < minCol; ++i){
        new_size[i] = ob[i];
    }
    for (size_t i = minCol; i < col; ++i){
        new_size[i] = new Cell();
    }
    ob = new_size; 
    col_width = col; 
    
}

void SpreadSheet::resize(int row , int col ){
    row_width = row; 
    col_width = col; 
    int minRow = std::min(row , row_width);
    int minCol = std::min(col , col_width);
    Cell** new_size = new Cell*[row];
    for (size_t i = 0; i < minRow; ++i){
        new_size[i] = ob[i];
    }
    for (size_t i = minRow; i < row_width; ++i){
        new_size[i] = new Cell();
    }
    for (size_t i = 0; i < minCol; ++i){
        new_size[i] = ob[i];
    }
    for (size_t i = minCol; i < col_width; ++i){
        new_size[i] = new Cell();
    }
    ob = new_size; 
    row_width = row; 
    ob = new_size; 
    col_width = col; 
}

void SpreadSheet::delete_row(int row){
    if (0 >= row && row < row_width){
        for (size_t i = 0 ; i < row_width - 1; ++i){
            ob[i] = ob[i + 1];
        }
    }
    delete[] ob[row];
    ob[row] = nullptr;
    --row_width; 
}

void SpreadSheet::delete_colum(int col ){
    if (0 >= col && col < col_width){
        for (size_t i = 0; i < col_width; ++i){
            ob[i] = ob[i - 1];
        }
    }
    delete[] ob[col];
    ob[col] = nullptr;
    --col_width;
}

void SpreadSheet::copy_from(int row , int col , const SpreadSheet& rhv){
    if (0 >= row && row < row_width && row_width < rhv.row_width || 0 >= col && row < col_width && col_width < rhv.col_width){
        delete[] ob;
        ob = nullptr; 
    }
    row_width = rhv.row_width; 
    col_width = rhv.col_width;
    ob = new Cell*[row];
    for (size_t i = 0; i < row; ++i){
        ob[i] = new Cell[col];
    }
    for (size_t i = 0; i < row; ++i){
        for (size_t j = 0; j < col; ++j){
            ob[i][j] = rhv.ob[i][j];
        }
    }
}



