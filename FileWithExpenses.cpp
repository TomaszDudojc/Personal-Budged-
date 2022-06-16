#include "FileWithExpenses.h"

void FileWithExpenses::addExpenseToFile(Transaction expense)
{
    CMarkup xml;
    string fileNameWithExpenses = XmlFile :: getFileName();
    bool fileExists = xml.Load(fileNameWithExpenses);

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Expense");
    xml.IntoElem();
    xml.AddElem( "id", expense.getId() );
    xml.AddElem( "userId", expense.getUserId() );
    xml.AddElem( "date", expense.getDate() );
    //xml.AddElem("intDate", expense.getIntDate());
    xml.AddElem( "name", expense.getName() );
    xml.AddElem("amount", AuxiliaryMethods::convertFloatToString(expense.getAmount()));

    xml.Save(fileNameWithExpenses);
}

vector <Transaction> FileWithExpenses::loadExpensesOfLoggedInUserFromFile(int loggedInUserId)
{
    DateManager dateManager;
    Transaction transaction;
    vector <Transaction> expense;
    CMarkup xml;
    string fileNameWithExpenses = XmlFile :: getFileName();
    bool fileExists = xml.Load(fileNameWithExpenses);

    if (fileExists == true)
    {
        xml.ResetPos();
        xml.FindElem();
        xml.IntoElem();
        while ( xml.FindElem("Expense") == true)
        {
            xml.IntoElem();
            xml.FindElem("userId");
            if (xml.GetData() == AuxiliaryMethods::convertIntegerToString(loggedInUserId))

            {
                xml.ResetMainPos(); //when "userId" is not the first element

                xml.FindElem( "id");
                int id = atoi(xml.GetData().c_str());
                transaction.setupId(id);

                xml.FindElem("userId");
                int userId = atoi(xml.GetData().c_str());
                transaction.setupUserId(userId);

                xml.FindElem( "date");
                string date = xml.GetData();
                transaction.setupDate(date);

                //xml.FindElem( "intDate");
                int intDate = dateManager.convertStringDateToIntDate(date);
                transaction.setupIntDate(intDate);

                xml.FindElem( "name");
                string name = xml.GetData();
                transaction.setupName(name);

                xml.FindElem( "amount");
                float amount = atof(xml.GetData().c_str());
                transaction.setupAmount(amount);
                expenses.push_back(transaction);

                xml.OutOfElem();
            }
            else
            {
                xml.OutOfElem();
            }
        }
    }
    return expenses;
}

int FileWithExpenses::getLastExpenseIdFromFile()
{
    CMarkup xml;
    string fileNameWithExpenses = XmlFile :: getFileName();
    bool fileExists = xml.Load(fileNameWithExpenses);
    vector <int> idNumbersForExpense;
    int lastExpenseId, idNumberForExpense ;

    if (fileExists == true)
    {
        xml.ResetPos();
        xml.FindElem();
        xml.IntoElem();
        while ( xml.FindElem("Expense") == true)
        {
            xml.IntoElem();
            xml.FindElem( "id");
            idNumberForExpense = atoi(xml.GetData().c_str());
            idNumbersForExpense.push_back(idNumberForExpense);
            xml.OutOfElem();
        }
    }

    if (idNumbersForExpense.size()==0) lastExpenseId=0;
    else lastExpenseId=idNumbersForExpense.back();

    return lastExpenseId;
}
