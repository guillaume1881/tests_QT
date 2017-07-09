#include "tol_line.h"

tol_line::tol_line(int tbf, int tla, QString fr, QString gb, QString unit, QString ll, QString ul)
{
    this->TBF_index_i=tbf;
    this->TLA_index_i=tla;
    this->french_txt=fr;
    this->english_txt=gb;
    this->unit=unit;
    this->LL=ll;
    this->UL=ul;
}


QString tol_line::displayTolLine(){
    QString tbf,tmp_tbf;
    if(TBF_index_i<10)tbf="00"+tmp_tbf.number(TBF_index_i);
    else if(TBF_index_i<100)tbf="0"+tmp_tbf.number(TBF_index_i);
    else tbf=tmp_tbf.number(TBF_index_i);

    QString tla,tmp_tla;
    if(TLA_index_i<10)tla="00"+tmp_tla.number(TLA_index_i);
    else if(TLA_index_i<100)tbf="0"+tmp_tla.number(TLA_index_i);
    else tla=tmp_tla.number(TLA_index_i);

    QString fr,spaces_fr;
    for(int i=0;i<25-french_txt.length();i++)spaces_fr+=" ";
    fr=french_txt+spaces_fr;

    QString gb,spaces_gb;
    for(int i=0;i<25-english_txt.length();i++)spaces_gb+=" ";
    gb=english_txt+spaces_gb;

    QString unity_t,spaces_unity;
    for(int i=0;i<4-unit.length();i++)spaces_unity+=" ";
    unity_t=unit+spaces_unity;

    QString ll,spaces_ll;
    for(int i=0;i<8-LL.length();i++)spaces_ll+=" ";
    ll=LL+spaces_ll;

    QString ul,spaces_ul;
    for(int i=0;i<8-UL.length();i++)spaces_ul+=" ";
    ul=LL+spaces_ul;

    QString code;
    return code =tbf+" "+tla+" "+fr+gb+unity_t+ll+" "+ul+"I\n";



}
