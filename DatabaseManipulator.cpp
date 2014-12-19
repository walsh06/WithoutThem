#include "DatabaseManipulator.h"

/* Opens the database */
DatabaseManipulator::DatabaseManipulator()
{
    db = new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE"));
    db->setDatabaseName("../WithoutThem/without_them_db.sqlite");
    db->open();

}

/* Query to get the product given the name */
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

/* Query to get the product given the table and level*/
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

/*Query to get the name of every product*/
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


/*Query to get the name of every product under a given level*/
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


/*Query to upgrade a product*/
void DatabaseManipulator::upgradeProduct(string productName)
{
    QSqlQuery query(*db);
    string query_string =
            "UPDATE products SET upgraded_level = upgraded_level +1 WHERE name = '" + productName +
            "'";
    query.exec(QString::fromStdString(query_string));
}


/*Query to get the  cost of a product given the name*/
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

/*Destructor closes db*/
DatabaseManipulator::~DatabaseManipulator()
{
    db->close();
}
