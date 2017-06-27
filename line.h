#ifndef LINE_H
#define LINE_H

#include <QString>

class line{
public :
    line(int inde,QString code,int length);
    int getIndexInt();
    QString getIndexString();
    QString getLineCode();
    int getLineLengthInt();
    QString getLineLengthString();

    void setIndexInt(int a);
    void setIndexString(QString a);
    void setLineCode(QString a);
    void setLineLengthInt(int a);
    void setLineLengthString(QString a);

    QString displayLine();


private :
    int index_i;
    QString index_s;
    QString line_code;
    int line_length_i;
    QString line_length_s;

};

#endif // LINE_H
