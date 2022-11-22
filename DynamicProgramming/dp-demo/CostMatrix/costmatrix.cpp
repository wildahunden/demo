#include "costmatrix.h"
#include <algorithm>

CostMatrix::CostMatrix(QObject *parent)
    : QObject{parent}
{

}

bool CostMatrix::boundariesOk(quint16 row, quint16 col)
{
    bool rv = true;
    if (row >= m_rows || row < 0 || col >= m_cols || col < 0)
        rv =  false;

    return rv;
}

int CostMatrix::getCellCost(quint16 row, quint16 col)
{
    if (!boundariesOk(row, col))
        return -1;

    return m_costMatrix[row][col];
}

void CostMatrix::calculateCost(int pos, quint16 row, quint16 col)
{
    int cost = getCellCost(row, col);

    if (row == 0)
        cost += min_cost(row, col-1);
    else if (col == 0)
        cost += min_cost(row-1, col);
    else
        cost += std::min(min_cost(row, col-1), min_cost(row-1,col));

    m_calcedCosts[pos] = cost;
}

int CostMatrix::min_cost(quint16 row, quint16 col)
{
    if (!boundariesOk(row,col))
        return -1;

    if (row == 0 && col == 0)
        return getCellCost(row,col);

    int pos = (row * m_cols) + col;
    if (!m_calcedCosts.contains(pos))
        calculateCost(pos, row, col);

    return m_calcedCosts[pos];
}
