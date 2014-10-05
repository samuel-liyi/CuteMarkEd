#include"spreadsheet.h"
#include <QtGui>
#include<QApplication>

//debugging
#include<QTextStream>

#define printd(x)  QTextStream(stdout)<<x<<endl;

Spreadsheet::Spreadsheet(QWidget *parent)
    : QTableWidget(parent)
{
    clear();
}
QTableWidgetSelectionRange Spreadsheet::selectedRange() const
{
    QList<QTableWidgetSelectionRange> ranges = selectedRanges();
    if (ranges.isEmpty())
        return QTableWidgetSelectionRange();
    return ranges.first();
}
void Spreadsheet::clear()
{
//    setRowCount(0);
//    setColumnCount(0);
//    setRowCount(RowCount);
//    setColumnCount(ColumnCount);

    for (int i = 0; i < rowCount(); ++i) {
        for(int j=0;i<columnCount();++j){
            this->item(i,j)->text().clear();
        }
    }

    setCurrentCell(0, 0);
}
void Spreadsheet::cut()
{
    copy();
    del();
}

void Spreadsheet::copy()
{
    QTableWidgetSelectionRange range = selectedRange();
    QString str;
    printd(range.rowCount());
    printd(range.columnCount());
    for (int i = 0; i < range.rowCount(); ++i) {
        if (i > 0)
            str += "\n";
        for (int j = 0; j < range.columnCount(); ++j) {
            if (j > 0)
                str += "\t";
            str += formula(range.topRow() + i, range.leftColumn() + j);

        }
    }
    QApplication::clipboard()->setText(str);
}

void Spreadsheet::paste()
{
    QTableWidgetSelectionRange range = selectedRange();
    QString str = QApplication::clipboard()->text();
    QStringList rows = str.split('\n');
    int numRows = rows.count();
    int numColumns = rows.first().count('\t') + 1;


//    if (range.rowCount() * range.columnCount() != 1
//            && (range.rowCount() != numRows
//                || range.columnCount() != numColumns)) {
//        QMessageBox::information(this, tr("Spreadsheet"),
//                tr("The information cannot be pasted because the copy "
//                   "and paste areas aren't the same size."));
//        return;
//    }

    for (int i = 0; i < numRows;++i) {
        QStringList columns = rows[i].split('\t');

        for (int j = 0; j < numColumns; ++j) {
            int row = range.topRow() + i;
            int column = range.leftColumn() + j;
//              int row=i;
//              int column=j;
              setFormula(row,column,columns[j]);
//              printd(this->item(1,1)->text());



        }
    }
//    somethingChanged();
}

void Spreadsheet::del()
{
//    QList<QTableWidgetItem *> items = selectedItems();
//    if (!items.isEmpty()) {
//        foreach (QTableWidgetItem *item, items)
//            delete item;
//        somethingChanged();
//    }
}

void Spreadsheet::selectCurrentRow()
{
//    selectRow(currentRow());
}

void Spreadsheet::selectCurrentColumn()
{
//    selectColumn(currentColumn());
}
QString Spreadsheet::formula(int row, int column) const{
    QTableWidgetItem *item=this->item(row,column);
    if(item){
        return item->text();
    }
    else{
        return "";
    }
}
void Spreadsheet::setFormula(int row,int column,QString content){
    QTableWidgetItem *item;
    if(row>rowCount()||column>columnCount()){
        return ;
    }
    else{
        if(this->item(row,column)==0){
            item=new QTableWidgetItem();
            item->setText(content);
            this->setItem(row,column,item);
        }
        else{
            this->item(row,column)->setText(content);
        }
    }
}

