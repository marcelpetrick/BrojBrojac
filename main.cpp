// Based on a SO-question:
// ########################
// Question: Given a string of a million numbers (Pi for example),
// write a function/program that returns all repeating 3 digit numbers
// and number of repetition greater than 1
// For example: if the string was: 123412345123456 then the function/program would return:
// 123 - 3 times
// 234 - 3 times
// 345 - 2 times

//--------------------------------------------------------------------------

// include list
#include <QCoreApplication>
#include <QMap>
#include <QDebug>
#include <QStringRef> //for substring

//--------------------------------------------------------------------------

// thoughts about how to report back the amount?
// a: use a vector, where the number is also the index. then, since there will be 1000 possible numbers [0..999]
// b: use a map, handed over as reference (save potentially space?)
//
// ok: decision is now to use a QMap and abuse its capability to return 0 "non inserted" elements.
// also implement this function just like it would work for all kind of strings (since it is not a fixed container, so no wasted space).
QMap<QString, int> countTriplets(QString const inputString)
{
    qDebug() << __FUNCTION__;
    qDebug() << "inputString:" << inputString;

    QMap<QString, int> returnValue;

    int const tokenLength(3); //maybe make configure-able

    // tokenize the whole string; add each one to the map by increasing the returned count from "before"
    for(int index = 0; index < (inputString.length() - tokenLength); index++)
    {
        // create substring
        QString const subString = inputString.mid(index, tokenLength);
        // find amount
        int const count = returnValue.value(subString);
        //increase by one and push-back
        //qDebug() << "substring:" << subString << "-->" << count; //just for debugging
        returnValue.insert(subString, count + 1);
    }

    return returnValue;
}

//--------------------------------------------------------------------------

void printResult(QMap<QString, int> inputMap)
{
    for(auto const elem : inputMap.keys())
    {
        qDebug() << elem << ":" << inputMap.value(elem);
    }
}

//--------------------------------------------------------------------------

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv); //providies an event-loop for programs without some ui

    //! @TODO add some handling of the input-params
    QString const inputString("123412345123456");
    qDebug() << "#### begin ####";

    QMap<QString, int> const numberMap = countTriplets(inputString);

    printResult(numberMap);

    qDebug() << "#### end ####";

    return a.exec();
}
