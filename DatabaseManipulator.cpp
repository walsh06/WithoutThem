#include "DatabaseManipulator.h"

DatabaseManipulator::DatabaseManipulator()
{
    db = new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE"));
    db->setDatabaseName("../WithoutThem/without_them_db.sqlite");
    db->open();

}

Product* DatabaseManipulator::getProduct(string name)
{
    QSqlQuery query(*db);
    string query_string =
            "SELECT table_name, upgraded_level FROM products WHERE name = '"
            + name + "'";
    query.exec(QString::fromStdString(query_string));
    query.first();

    return getProduct(query.value(0).toString().toStdString(), query.value(1).toInt()) ;
}


Product* DatabaseManipulator::getProduct(string table, int level)
{

    QSqlQuery query(*db);
    string query_string =
            "SELECT name, skill, timeCost, materialCost, materialNeeded, upgradeCost, value FROM "
            + std::string(table) + " WHERE level  <= " + std::to_string(level);
    query.exec(QString::fromStdString(query_string));
    query.first();

    skills::skillsType skill = (skills::skillsType)(query.value(1).toInt());

    Product *p = new Product(query.value(0).toString().toStdString(),
              skill,
              query.value(3).toInt(),
              query.value(2).toInt(),
              query.value(4).toString().toStdString(),
              query.value(6).toDouble(),
              query.value(4).toDouble());

    return p;
}

vector<string> DatabaseManipulator::getProductNames()
{
    QSqlQuery query(*db);
    string query_string =
            "SELECT name FROM products";
    query.exec(QString::fromStdString(query_string));

    vector<string> list ;

    while(query.next())
    {
        list.push_back(query.value(0).toString().toStdString());
    }

    return list;
}

vector<string> DatabaseManipulator::getProductNames(int level)
{
    QSqlQuery query(*db);
    string query_string =
            "SELECT name FROM products WHERE upgraded_level <= " + std::to_string(level) ;
    query.exec(QString::fromStdString(query_string));

    vector<string> list ;

    while(query.next())
    {
        list.push_back(query.value(0).toString().toStdString());
    }

    return list;
}

void DatabaseManipulator::upgradeProduct(string productName)
{
    QSqlQuery query(*db);
    string query_string =
            "UPDATE products SET upgraded_level = upgraded_level +1 WHERE name = '" + productName +
            "'";
    query.exec(QString::fromStdString(query_string));
}

int DatabaseManipulator::getProductCost(string name)
{
    QSqlQuery query(*db);
    string query_string =
            "SELECT cost FROM products WHERE name = '" + name + "'" ;
    query.exec(QString::fromStdString(query_string));

    int cost;

    while(query.next())
    {
        cost = std::stoi(query.value(0).toString().toStdString());
    }

    return cost;
}


DatabaseManipulator::~DatabaseManipulator()
{
    db->close();
}
