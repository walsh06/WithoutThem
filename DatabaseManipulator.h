#ifndef DATABASEMANIPULATOR_H
#define DATABASEMANIPULATOR_H

#include <iostream>
#include <QtSql/QSql>
#include <QSqlDatabase>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlQuery>
#include <QSqlError>
#include <QDebug>

#include "Product.h"
#include "SkillTypeEnums.h"



using namespace std;

class DatabaseManipulator
{
public:
    DatabaseManipulator();
    ~DatabaseManipulator();

    Product* getProduct(string name);
    Product* getProduct(string table, int level);
    vector<string> getProductNames();
    vector<string> getProductNames(int level);
    void upgradeProduct(string name);
    int getProductCost(string name);

private:
    QSqlDatabase* db;

};

#endif // DATABASEMANIPULATOR_H
