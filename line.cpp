#include "line.h"

line::line(int index,QString code,int length)
{
    this->index_i=index;
    QString tmp1,tmp2;
    QString spaces="";
    QString ind=tmp1.number(index_i);
    if(index<10)this->index_s="00"+ind;
    else if(index<100)this->index_s="0"+ind;
    else index_s=ind;

    this->line_length_i=code.length();
    for(int i=0;i<20-line_length_i;i++)spaces+=" ";
    this->line_code=code+spaces;
    this->line_length_i=length;
    QString len=tmp2.number(length);
    if(length<10)this->line_length_s="A0"+len;
    else this->line_length_s="A"+len;


}

int line::getIndexInt(){return this->index_i;}
QString line::getIndexString(){return this->index_s;}
QString line::getLineCode(){return this->line_code;}
int line::getLineLengthInt(){return this->line_length_i;}
QString line::getLineLengthString(){return this->line_length_s;}

void line::setIndexInt(int a){this->index_i=a;}
void line::setIndexString(QString a){this->index_s=a;}
void line::setLineCode(QString a){this->line_code=a;}
void line::setLineLengthInt(int a){this->line_length_i=a;}
void line::setLineLengthString(QString a){this->line_length_s=a;}


QString line::displayLine(){
    QString tmp=index_s+" "+line_code+" "+line_length_s+"\n";
    return tmp;
}
