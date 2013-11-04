#ifndef MEXGUI_H
#define MEXGUI_H
 
#include "ui_main.h"
 
 
class MeXgui : public QWidget, private Ui::MeXguiDLG
{
    Q_OBJECT
 
public:
    MeXgui(QWidget *parent = 0);
 
 
public slots:
    void getPath();
    void doSom();
    void clear();
    void help();
    void oneclick();
    void autoenc();
void Venc();
void Aenc();
void Vcont();
void Acont();
void 
 
};
 
class DatabaseManager : public QObject
    {
    public:
        DatabaseManager(QObject *parent = 0);
        ~DatabaseManager();
 
    public:
        bool openDB();
        bool deleteDB();
        bool createTable();
	int insertJobs(int jobID, QString filename, QString extension, QString output , $presets, int status);
	bool getJobs(int status);
 
        QSqlError lastError();
 
    private:
        QSqlDatabase db;
}; 
#endif
