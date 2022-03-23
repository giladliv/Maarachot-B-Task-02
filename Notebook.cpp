#include "Notebook.hpp"

using ariel::Notebook;

Notebook::Notebook(/* args */)
{
    _notebook.clear();
}

Notebook::~Notebook()
{
}

bool Notebook::isGoodIndex(int page, int row, int col)
{
    if (page < 0)
    {
        throw MessageException("page index must be non-negative value");
    }
    if (row < 0)
    {
        throw MessageException("row index must be non-negative value");
    }
    if (col < 0 || col >= LINE_MAX)
    {
        throw MessageException("column index must be non-negative value");
    }

    return true;
}

bool Notebook::isGoodLen(int col, int len, Direction direction)
{
    if (len < 0)
    {
        throw MessageException("length must be non-negative value");
    }
    if (direction != Direction::Horizontal && direction != Direction::Vertical)
    {
        throw MessageException("the direction must be horizonl or vertical");
    }
    if (direction == Direction::Horizontal && len + col >= LINE_MAX)
    {
        throw MessageException("you try to reach a a pleace that is out of boundries");
    }
    return true;
}

bool Notebook::isGoodString(string str)
{
    char ch = '\0';
    for (unsigned int i = 0; i < str.length(); i++)
    {
        ch = str[i];
        if (isprint(ch) == 0)
        {
            throw MessageException("The string is not good\nMust be ptintable no cpase char and no ~ or _ chars");
        }
    }
    return true;
}

void Notebook::write(int page, int row, int col, Direction direction, const string& str)
{
    isGoodIndex(page, row, col);
    isGoodLen(col, str.length(), direction);
    isGoodString(str);
    
}

string Notebook::read(int page, int row, int col, Direction direction, int len)
{
    isGoodIndex(page, row, col);
    isGoodLen(col, len, direction);

    return "";
}

void Notebook::erase(int page, int row, int col, Direction direction, int len)
{
    isGoodIndex(page, row, col);
    isGoodLen(col, len, direction);
}

void Notebook::show(int page)
{
    isGoodIndex(page, 0, 0);
}