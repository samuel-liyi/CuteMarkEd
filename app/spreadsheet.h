#ifndef SPREADSHEET_H
#define SPREADSHEET_H

#include <QTableWidget>
#include<QAction>
class Spreadsheet : public QTableWidget
{
    Q_OBJECT

public:
    Spreadsheet(QWidget *parent = 0);
    QTableWidgetSelectionRange selectedRange() const;
    QString formula(int row, int column) const;
    void setFormula(int row,int column,QString content);
    void clear();
public slots:
    void cut();
    void copy();
    void paste();
    void del();
    void selectCurrentRow();
    void selectCurrentColumn();
private:
    enum { MagicNumber = 0x7F51C883, RowCount = 999, ColumnCount = 26 };


};

#endif
