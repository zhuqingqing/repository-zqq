#ifndef CHOSEPROJECT_H
#define CHOSEPROJECT_H


#include <QDialog>
#include "ui_ChoseProject.h"
#include "ProjectDao.h"
#include "DomainProject.h"

class ChoseProject : public QDialog,public Ui::ChoseProject
{
    Q_OBJECT

  public:
    DomainProject *d_project;
    explicit  ChoseProject(QWidget *parent = 0);
    ~ChoseProject();

  private:
    ProjectDao *handler;
    void setTableHeader(QString filename,QTableView *tableview);

  private slots:
    void on_pushButton_Cancel_clicked();
    void on_pushButton_Open_clicked();
    void on_ProjsRecent_doubleClicked(const QModelIndex &index);
    void on_ProjsCurrent_doubleClicked(const QModelIndex &index);

signals:
    void choseProj(int projpk);
};


#endif // CHOSEPROJECT_H
