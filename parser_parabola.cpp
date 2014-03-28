#include "parser_parabola.h"
#include "tokenizer.h"
#include <algorithm>


Parser_parabola::Parser_parabola(string str)
{
    result = str;
    char b = result[result.length()-1];

    if (b != *" "){
        result  = result + " ";
    }

    //flag = false;
}
bool Parser_parabola::isX(){
    return flag;
}




double Parser_parabola::getA()
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

    if (*i == "y" || *i == "x")
    {
        if (*i == "x"){
            flag = true;

        }



        std::advance(i, 1);
        if (*i == "="){


            std::advance(i, 1);



            string a = *i;



            if (a == "x^2")
            {
                a = "1";

            }

           else if (a == "-x^2")
            {
                a = "-1";

            }

            else{
               // a = a.replace("x^2","")



            }



            double m2 = atof(a.c_str());
            result2 = m2;

        }
    }


    return result2;



}


double Parser_parabola::getB()
{

    double result2 = 3;

    char chars[] = "()";

    for (unsigned int i = 0; i < strlen(chars); ++i)
    {
        // you need include <algorithm> to use general algorithms like std::remove()
        result.erase (std::remove(result.begin(), result.end(), chars[i]), result.end());
    }


    tokenizer words(result, " "); //the delimiters are space and = and ;
    std::string word;

    list<string> lista;

    while(words.has_next())  //loop till we run out of items in deque
    {

        string s = words.next_token();

        lista.push_back(s);

    }

    list<string>::iterator i = lista.begin();


    std::advance(i, 0);

    if (*i == "y")
    {
        std::advance(i, 1);
        if (*i == "="){

            std::advance(i, 3);

            std::string strin = (*i);

            if (! (strin.find("x") != std::string::npos)){
                result2  = 0;

            }

            else{




                std::advance(i, -1);



                if (*i == "-"){
                    std::advance(i, 1);

                    string m = *i;


                    double m2 = atof(m.c_str());
                    result2 = -m2;
                }


                else{
                    std::advance(i, 1);

                    string m = *i;




                    //flag = true;
                    double m2 = atof(m.c_str());
                    result2 = m2;
                }}

        }




    }






    else{




        std::advance(i, 2);

        string m = *i;




        flag = true;
        double m2 = atof(m.c_str());
        result2 = m2;
    }


    return result2;



}




double Parser_parabola::getC()
{

    double result2 = 3;

    char chars[] = "()";

    for (unsigned int i = 0; i < strlen(chars); ++i)
    {
        // you need include <algorithm> to use general algorithms like std::remove()
        result.erase (std::remove(result.begin(), result.end(), chars[i]), result.end());
    }


    tokenizer words(result, " "); //the delimiters are space and = and ;
    std::string word;

    list<string> lista;

    while(words.has_next())  //loop till we run out of items in deque
    {

        string s = words.next_token();

        lista.push_back(s);

    }

    list<string>::iterator i = lista.begin();


    std::advance(i, 0);

    if (*i == "y")
    {
        std::advance(i, 1);
        if (*i == "="){

            std::advance(i, 3);

            std::string strin = (*i);

            if (! (strin.find("x") != std::string::npos)){
             result2  = atof(strin.c_str());;

            }

            else{




                std::advance(i, 1);



                if (*i == "-"){
                    std::advance(i, 1);

                    string m = *i;


                    double m2 = atof(m.c_str());
                    result2 = -m2;
                }

               else if (*i == ""){
                result2 = 0;

                }


                else{
                    std::advance(i, 1);

                    string m = *i;




                    //flag = true;
                    double m2 = atof(m.c_str());
                    result2 = m2;
                }}

        }




    }






    else{




        std::advance(i, 2);

        string m = *i;




        flag = true;
        double m2 = atof(m.c_str());
        result2 = m2;
    }


    return result2;



}






