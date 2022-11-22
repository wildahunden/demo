#ifndef COSTMATRIX_H
#define COSTMATRIX_H

#include <QObject>
#include <QVector>
#include <QHash>

class CostMatrix : public QObject
{
    Q_OBJECT

public:
    explicit CostMatrix(QObject *parent = nullptr);
    quint16 rows() { return m_rows; }
    quint16 cols() { return m_cols; }
    int getCellCost(quint16 row, quint16 col);
    int min_cost(quint16 row, quint16 col);

signals:

private:
    QVector<QVector<int>> m_costMatrix = {{3,2,12,15,10},{6,19,7,11,17},{8,5,12,32,21},{3,20,2,9,7}};
    QHash<int, int> m_calcedCosts;
    quint16 m_rows = 4, m_cols = 5;

    bool boundariesOk(quint16 row, quint16 col);
    void calculateCost(int pos, quint16 row, quint16 col);
};

#endif // COSTMATRIX_H
