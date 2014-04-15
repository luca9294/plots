#include "parser_ellipse_n.h"
#include "tokenizer.h"
#include <algorithm>
#include <math.h>
#include <qstring.h>




parser_ellipse_n::parser_ellipse_n (string str) : parser_ellipse(str)
{
    result = str;
    char b = result[result.length()-1];

    if (b != *" "){
        result  = result + " ";
    }


perform();
}






void parser_ellipse_n::perform(){
  char chars[] = "()";
  bool negative = false;

   for (unsigned int i = 0; i < strlen(chars); ++i)
    {
       // you need include <algorithm> to use general algorithms like std::remove()
       result.erase (std::remove(result.begin(), result.end(), chars[i]), result.end());
    }


   QString d = QString::fromUtf8(result.c_str());
   d.replace("^2", "");

result = d.toStdString();


    cout << "test: " << result << endl;

    tokenizer words(result, " "); //the delimiters are space and = and ;


    list<string> lista;

    while(words.has_next())  //loop till we run out of items in deque
    {

        string s = words.next_token();

        lista.push_back(s);

    }

    list<string>::iterator i = lista.begin();


    std::advance(i, 1);



    string str = *i;

    if (str == "-"){
        negative = false;

               }
    else{
        negative = true;

    }


    std::advance(i, 1);





    //16/1
     str = *i;






    for (int i = 0; i< str.length(); i++){

    //To CALCULATE Xc

    if (str[i] == '/'){

        std::string p= str.substr(0,i);
        Xc = atof(p.c_str());

      p= str.substr(i+1,str.length()-1-i);

     if (negative){
     Xc = -Xc;
     }

      a = sqrt(atof(p.c_str()));
      break;
}

Xc = atof(str.c_str());
if (negative){
Xc = -Xc;
}
a = 1;


}


    std::advance(i, 3);

    str = *i;

cout << str << endl;
    if (str == "-"){
        negative = false;

               }
    else{
        negative = true;

    }


std::advance(i, 1);

  str = *i;
    for (int i = 0; i< str.length(); i++){

    if (str[i] == '/'){

         string p= str.substr(0,i);


         Yc =  (atof(p.c_str()));

         if (negative){
             Yc = -Yc;

         }

       p = str.substr(i+1,str.length()-1-i);
       b = sqrt (atof(p.c_str()));
        break;


    }

    Yc =   atof(str.c_str());
    if (negative){
    Yc = -Yc;
    }
    b = 1;



    }



}





double parser_ellipse_n::getA()
{
    return a;



}


double parser_ellipse_n::getB()
{
    return b;



}



double parser_ellipse_n::getXc()
{
    return Xc;



}



double parser_ellipse_n::getYc()
{
    return Yc;

}

















