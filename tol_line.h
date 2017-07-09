#ifndef TOL_LINE_H
#define TOL_LINE_H
#include <QString>

class tol_line
{
public:
    tol_line(int tbf,int tla,QString fr, QString gb, QString unit, QString ll, QString ul);
    QString displayTolLine();
private :
    QString french_txt;
    QString english_txt;
    QString unit;
    QString LL;
    QString UL;
    QString TLA_index_s;
    QString TBF_index_s;
    int     TLA_index_i;
    int     TBF_index_i;

};




#endif // TOL_LINE_H
