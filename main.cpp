#include <QCoreApplication>
#include <QStringList>
#include <QDir>
#include <iostream>
#include <QFile>

using namespace std;

int main(int argc,char** argv)
{
  QStringList heads,sources;
  QStringList filter;
  
  filter<<"*.h"<<"*.hpp"<<"*.i";
  QDir  dir = QDir::current();
  heads = dir.entryList(filter,QDir::Files);
  
  filter.clear();
  filter<<"*.cpp"<<"*.c"<<"*.java"<<"*.cc";
  sources = dir.entryList(filter,QDir::Files);
  
  if(heads.size() <=0 || sources.size() <=0)
    return 0;
    
  
  QFile file("_hosless_test.pro");
  file.open(QIODevice::WriteOnly);
  
  file.write("QT +=core\n");
  file.write("TARGET = hosless_test\n");
  file.write("TEMPLATE=app\n");
  file.write("SOURCES +=\\ \n);
  
  for(int x=0;x<sources.size();++x){
    file.write(sources.at(x).toStdString().c_str());
    file.write("\\ \n"):
  }
  
  file.write("\n\n");
  
  file.write("HEADERS +=\\ \n");
  for(int x=0;x<heads.size();++x){
    file.write(heads.at(x).toStdString().c_str());
    file.write("\\ \n");
  }
  file.close();
  
  return  0;
  
}
