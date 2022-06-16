#include "FileWithIncomes.h"

void FileWithIncomes::addIncomeToFile(Transaction income)
{
    CMarkup xml;
    string fileNameWithIncomes = XmlFile :: getFileName();
    bool fileExists = xml.Load(fileNameWithIncomes);

    if ((!fileExists)==true)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem( "id", income.getId() );
    xml.AddElem( "userId", income.getUserId() );
    xml.AddElem( "date", income.getDate() );
    //xml.AddElem("intDate", income.getIntDate());
    xml.AddElem( "name", income.getName() );
    xml.AddElem("amount", AuxiliaryMethods::convertFloatToString(income.getAmount()));

    xml.Save(fileNameWithIncomes);
}

vector <Transaction> FileWithIncomes::loadIncomesOfLoggedInUserFromFile(int loggedInUserId)
{
    Transaction transaction;
    vector <Transaction> incomes;
    CMarkup xml;
    string fileNameWithIncomes = XmlFile :: getFileName();
    bool fileExists = xml.Load(fileNameWithIncomes);

    if (fileExists == true)
    {
        xml.ResetPos();
        xml.FindElem();
        xml.IntoElem();
        while ( xml.FindElem("Income") == true)
        {
            xml.IntoElem();
            xml.FindElem("userId");
            if (xml.GetData() == AuxiliaryMethods::convertIntegerToString(loggedInUserId))

            {
                xml.ResetMainPos();// when "userId" is not the first element

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

                incomes.push_back(transaction);

                xml.OutOfElem();
            }

            else
            {
                xml.OutOfElem();
            }
        }
    }
    return incomes;
}

int FileWithIncomes::getLastIncomeIdFromFile()
{
    CMarkup xml;
    string fileNameWithIncomes = XmlFile :: getFileName();
    bool fileExists = xml.Load(fileNameWithIncomes);
    vector <int> idNumbersForIncome;
    int lastIncomeId, idNumberForIncome ;

    if (fileExists == true)
    {
        xml.ResetPos();
        xml.FindElem();
        xml.IntoElem();
        while ( xml.FindElem("Income") == true)
        {
            xml.IntoElem();
            xml.FindElem( "id");
            idNumberForIncome = atoi(xml.GetData().c_str());
            idNumbersForIncome.push_back(idNumberForIncome);
            xml.OutOfElem();
        }
    }

    if (idNumbersForIncome.size()==0) lastIncomeId=0;
    else lastIncomeId=idNumbersForIncome.back();

    return lastIncomeId;
}
