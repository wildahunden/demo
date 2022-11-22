#include <QException>
#include <QtTest>
#include <QDebug>
#include "costmatrix.h"

// add necessary includes here

class CostMatrixTest : public QObject
{
    Q_OBJECT

public:
    CostMatrixTest();
    ~CostMatrixTest();

private slots:
    void getCellCost_boundaries();
    void initTestCase();
    void cleanupTestCase();
    void min_cost_boundaries();
    void min_cost();

private:
     quint16 m_rows = 0, m_cols = 0;
     CostMatrix m_costs;

};

CostMatrixTest::CostMatrixTest()
{
    m_rows = m_costs.rows();
    m_cols = m_costs.cols();
}


CostMatrixTest::~CostMatrixTest()
{

}

void CostMatrixTest::initTestCase()
{
}

void CostMatrixTest::cleanupTestCase()
{

}

void CostMatrixTest::getCellCost_boundaries()
{
    bool success = false;
    int c = m_costs.getCellCost(m_rows + 1, m_cols + 150);
    if (c < 0)
        success = true;

    QVERIFY2(success, "The matrix properties validation did not catch the error properly");
}

void CostMatrixTest::min_cost_boundaries()
{
    bool wasOK = false;
    int c = m_costs.min_cost(m_rows, m_cols);
    if (c < 0)
        wasOK = true;
    QVERIFY2(wasOK, "The min_cost boundaries were not properly validated");

}

void CostMatrixTest::min_cost()
{
    bool wasOK = false;
    int c = m_costs.min_cost(m_rows-1, m_cols-1);
    wasOK = (c == 52);

    QVERIFY2(wasOK, "The min_cost was not calculated properly");

}

QTEST_MAIN(CostMatrixTest)

#include "costmatrixtest.moc"
