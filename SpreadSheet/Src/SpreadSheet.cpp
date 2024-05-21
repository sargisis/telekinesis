#include "../Headers/SpreadSheet.h"

SpreadSheet::SpreadSheet() 
    : board{nullptr}
    , rowcnt{0}
    , colcnt{0}
{}

SpreadSheet::SpreadSheet(const SpreadSheet& rhv) 
    : board{new Cell*[rhv.rowcnt]}
    , rowcnt{rhv.rowcnt}
    , colcnt{rhv.colcnt}
{
    for (size_t i = 0; i < rhv.rowcnt; ++i) {
        board[i] = rhv.board[i];
    }
}

SpreadSheet::SpreadSheet(SpreadSheet&& rhv) 
    : board{std::move(rhv.board)}
    , rowcnt{std::move(rhv.rowcnt)}
    , colcnt{std::move(rhv.colcnt)}
{
    board = nullptr;
    rowcnt = 0; 
    colcnt = 0; 
}

SpreadSheet::SpreadSheet(size_t size )
    : board{new Cell*[size]}
    , rowcnt{size}
    , colcnt{size}
{
  for (size_t i = 0; i < size; ++i) {
    board[i] = new Cell[size];
  }
}

SpreadSheet::SpreadSheet(size_t row , size_t col)
    : board{new Cell*[row]}
    , rowcnt{row}
    , colcnt{col}
{
    for (size_t i = 0; i < row; ++i) {
        board[i] = new Cell[col];
    }
}

SpreadSheet::~SpreadSheet() 
{}


const SpreadSheet& SpreadSheet::operator=(const SpreadSheet& rhv) {
    if (this != &rhv) {
        clear();

        board = new Cell*[rhv.rowcnt];
        for (size_t i = 0; i < rhv.rowcnt; ++i) {
            board[i] = new Cell[rhv.colcnt];
        }

        for (size_t i = 0; i < rhv.rowcnt; ++i) {
            for (size_t j = 0; j < rhv.colcnt; ++j) {
                board[i][j] = rhv.board[i][j];
            }
        }
        rowcnt = rhv.rowcnt; 
        colcnt = rhv.colcnt; 
    }
    return *this; 
}

const SpreadSheet& SpreadSheet::operator=(SpreadSheet&& rhv) {
    if (this != &rhv) {
        board = std::move(rhv.board);
        rowcnt = std::move(rhv.rowcnt);
        colcnt = std::move(rhv.colcnt);

        board = nullptr;
        rowcnt = 0; 
        colcnt = 0; 
    }
    return *this;
}

SpreadSheet::Column SpreadSheet::operator[](size_t pos) {
    return Column(board[pos]);
}

const SpreadSheet::Column SpreadSheet::operator[](size_t pos) const {
    return Column(board[pos]);
}

void SpreadSheet::clear() noexcept {
    
    for (size_t i = 0; i < rowcnt; ++i) {
        delete[] board[i];
    }
    delete[] board;
    board = nullptr;
}

size_t SpreadSheet::row() const {
    return rowcnt; 
}

size_t SpreadSheet::col() const {
    return colcnt; 
}

void SpreadSheet::mirrorH() {
    for(int i = 0; i < rowcnt / 2; ++i)
    {
        for(int j = 0; j < colcnt; ++j)
        {
            Cell tmp = board[i][j];
            board[i][j] = board[rowcnt - 1 - i][j];
            board[rowcnt - 1 - i][j]  = tmp;
        }
    }
}

void SpreadSheet::mirrorV() {
    rotate(2);
    mirrorH();
}

void SpreadSheet::mirrorD() {
    rotate(3);
    mirrorH();
}

void SpreadSheet::mirrorSD() {
    rotate(1);
    mirrorH();
}

void SpreadSheet::rotate(int cnt) {
    int count = (cnt >= 0) ? (cnt % 4) : (4 - (-cnt % 4)) % 4;

    while (cnt--) {
        Cell** tmp = new Cell*[colcnt];
        for (int i = 0; i < colcnt; ++i) {
            tmp[i] = new Cell[rowcnt];
            for (int j = 0; j < rowcnt; ++j) {
                tmp[i][j] = board[rowcnt - 1 - j][i];
            }
        }

        size_t newRowCnt = colcnt;
        size_t newColCnt = rowcnt;

        clear();

        board = tmp;
        rowcnt = newRowCnt;
        colcnt = newColCnt;
    }
}

void SpreadSheet::removeRow(size_t row) {
    if (0 >= row && row < rowcnt) {
        for (size_t i = 0; i < rowcnt - 1; ++i) {
            board[i] = board[i + 1];
        }
    }
    delete[] board[rowcnt - 1];
    board[rowcnt - 1] = nullptr;
    --rowcnt;
}

void SpreadSheet::removeRows(std::initializer_list<size_t> rows) {
    std::vector<size_t> sortRow(rows);
    std::sort(sortRow.rbegin() , sortRow.rend());

    for (size_t row : sortRow) {
        if (row >= rowcnt) {
            std::runtime_error("");
        }

        for (size_t i = 0; i < rowcnt - 1; ++i) {
            for (size_t j = 0; j < colcnt; ++j) {
                board[i][j] = board[i + 1][j];
            }
        }
    }
    delete[] board[rowcnt - 1];
    board[rowcnt] = nullptr;
    --rowcnt;
}

void SpreadSheet::removeCol(size_t col) {
    if (0 >= col && col < colcnt) {
        for (size_t i = 0; i < colcnt; ++i) {
            board[i] = board[i - 1];
        }
    }
    delete[] board[colcnt - 1];
    board[colcnt - 1] = nullptr;
}

void SpreadSheet::removeCols(std::initializer_list<size_t> col) {
    std::vector<size_t> sortCol(col);
    std::sort(sortCol.rbegin(), sortCol.rend());
    for (size_t col : sortCol) {
        if (col >= colcnt) {
            std::runtime_error("");
        }
        for (size_t i = 0; i < rowcnt; ++i) {
            for (size_t j = 0; j < colcnt; ++j) {
                board[i][j] = board[i][j + 1];
            }
        }
    }
    delete[] board[colcnt - 1];
    board[colcnt - 1] = nullptr;
    --colcnt;
}

void SpreadSheet::resizeRow(size_t r) {
   
    if (r == rowcnt) {
        return; 
    }
    Cell** new_board = new Cell*[r];
    for (size_t i = 0; i < r; ++i) {
        new_board[i] = new Cell[colcnt];
    }

     int minRow = std::min(r , rowcnt);
    for (size_t i = minRow; i < r; ++i) {
        new_board[i] = new Cell();
    }
    board = new_board;
    rowcnt = r;
}

void SpreadSheet::resizeCol(size_t c) {
    if (c == colcnt) {
        return ;
    }
    Cell** new_board = new Cell*[c];
    for (size_t i = 0; i < c; ++i) {
        new_board[i] = new Cell[c];
    }
    int minCol = std::min(c , colcnt);
    for (size_t i = minCol; i < c; ++i) {
        new_board[i] = new Cell();
    }
    board = new_board; 
    colcnt = c;
}

void SpreadSheet::resize(size_t r, size_t c) {
    resizeRow(r);
    resizeCol(c);
} 

SpreadSheet SpreadSheet::slice(std::initializer_list<size_t> rows , std::initializer_list<size_t> cols) {
    int new_row = rows.size();
    int new_col = cols.size();

    SpreadSheet sliceer(new_row , new_col);

    size_t new_rowcnt = 0; 
    for (size_t row : rows) {
        if (row >= rowcnt ){
            std::runtime_error("");
        }
    
    size_t new_colcnt = 0; 
    for (size_t col : cols) {
        if (col >= colcnt) {
            std::runtime_error("");
        }
        sliceer.board[new_rowcnt][new_colcnt] = board[row][col];
        ++new_col;
    }
    ++new_row;
}
    return sliceer;
}

Cell** SpreadSheet::board_() const {
     return board;
}

SpreadSheet::Column::Column(Cell* ob)
    : col(ob)
{}

Cell& SpreadSheet::Column::operator[](size_t pos) {
    return col[pos];
}

const Cell& SpreadSheet::Column::operator[](size_t pos) const {
    return col[pos];
}

bool operator==(const SpreadSheet& lhv, const SpreadSheet& rhv) {
    if (lhv.row() != rhv.row() || lhv.col() != rhv.col()) {
        return false;
    }

    for (size_t i = 0; i < lhv.row(); ++i ){
        for (size_t j = 0; j < rhv.col(); ++j) {
            if (lhv[i][j] != rhv[i][j]){
                return false; 
            }
        }
    }
    return true; 
}

bool operator!=(const SpreadSheet& lhv , const SpreadSheet& rhv) {
    return !(lhv == rhv);
}
