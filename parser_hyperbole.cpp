#include "parser_hyperbole.h"
#include "tokenizer.h"
#include <algorithm>
#include <math.h>
#include <qstring.h>


parser_hyperbole::parser_hyperbole(string str)
{
    result = str;
    char b = result[result.length()-1];

    if (b != *" "){
        result  = result + " ";
    }
    if (str[0] == 'y'){
    flag = true;}
    else {
    flag = false;}

}



bool parser_hyperbole::isX(){
    return flag;
}




double parser_hyperbole::getA()
{
    double result2 = 3;


    char chars[] = "()";

    for (unsigned int i = 0; i < strlen(chars); ++i)
    {
        // you need include <algorithm> to use general algorithms like std::remove()
        result.erase (std::remove(result.begin(), result.end(), chars[i]), result.end());
    }




    tokenizer words(result, " "); //the delimiters are space and = and ;


    list<string> lista;

    while(words.has_next())  //loop till we run out of items in deque
    {

        string s = words.next_token();

        lista.push_back(s);

    }

    list<string>::iterator i = lista.begin();


    std::advance(i, 0);

    std::string a = *i;
    if (a == "x^2"){

        a = "1";

    }


    else if (a == "y^2"){

        a = "1";

    }

    else{
    string temp = a;

    temp = temp.substr(0, 3);




    a =   a.substr(4,a.length()-4);


}


            double af = atof(a.c_str());
            result2 =  sqrt (af);





    return result2;



}


double parser_hyperbole::getB()
{

    double result2 = 3;


    char chars[] = "()";

    for (unsigned int i = 0; i < strlen(chars); ++i)
    {

        result.erase (std::remove(result.begin(), result.end(), chars[i]), result.end());
    }




    tokenizer words(result, " "); //the delimiters are space and = and ;


    list<string> lista;

    while(words.has_next())  //loop till we run out of items in deque
    {

        string s = words.next_token();

        lista.push_back(s);

    }

    list<string>::iterator i = lista.begin();


    std::advance(i, 2);

    std::string b = *i;

    if (b == "y^2"){
    b = "1";
    }

else{
  b =   b.substr(4,b.length()-4);
}

            double af = atof(b.c_str());
            result2 =  sqrt (af);





    return result2;



}





