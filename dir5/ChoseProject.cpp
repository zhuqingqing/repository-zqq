#include "ChoseProject.h"

#include <QAction>
#include <QMessageBox>
#include <QDebug>

ChoseProject::ChoseProject(QWidget *parent) :QDialog(parent)
{
     setupUi(this);
     d_project = new DomainProject();
     handler = new ProjectDao();
     QSqlTableModel *model = handler->selectInitialProj();
     ProjsCurrent->setModel(model);
     setTableHeader(":/TH_Proj_Open.txt",ProjsCurrent);
     ProjsCurrent->hideColumn(0);
     ProjsCurrent->resizeColumnsToContents();
     tabWidget->setCurrentIndex(0);
}


void ChoseProject::setTableHeader(QString fileName,QTableView *tableview)
{
    QAbstractItemModel *model = tableview->model();
    QFile file(fileName);
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    QTextStream in(&file);
    QString fileContent=in.readAll();
    QStringList lines = fileContent.split(QString("\n"));
    file.close();
    for (int i = 0; i < lines.count(); i++)
    {
        model->setHeaderData(i, Qt::Horizontal,lines[i],Qt::EditRole);
        qDebug()<<lines[i];
        qDebug()<<model->headerData(i,Qt::Horizontal,Qt::EditRole);
    }
}
ChoseProject::~ChoseProject()
{
}
void ChoseProject::on_pushButton_Cancel_clicked()
{
    reject();
}

void ChoseProject::on_pushButton_Open_clicked()
{
   accept();
}

void ChoseProject::on_ProjsRecent_doubleClicked(const QModelIndex &index)
{
    QAbstractItemModel *model = ProjsRecent->model();
    emit choseProj(model->data(model->index(index.row(),0)).toInt());
    accept();
}

void ChoseProject::on_ProjsCurrent_doubleClicked(const QModelIndex &index)
{
    QAbstractItemModel *model = ProjsCurrent->model();
    emit choseProj(model->data(model->index(index.row(),0)).toInt());
    accept();
}
