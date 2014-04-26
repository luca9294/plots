#include "Parser.h"
#include <algorithm>


Parser::Parser(string str)
{
    result = str;
    char b = result[result.length()-1];

    if (b != *" "){
        result  = result + " ";
    }

    flag = false;
}
bool Parser::isX(){
    return flag;
}




double Parser::getM()
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


            std::advance(i, 1);



            string m = *i;
            cout << "QUESTO" << m << endl;

            if (!(m.find('x')  != std::string::npos)){
                result2 = 0;


            }

            else{


                if (m == "x")
                {
                    m = "1";

                }

                if (m == "-x")
                {
                    m = "-1";

                }



                double m2 = atof(m.c_str());
                result2 = m2;
            }
        }
    }
    else if (*i == "x"){
        result2 = 0;
        flag = true;

    }


    return result2;



}


double Parser::getQ()
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

            std::advance(i, 1);

            std::string strin = (*i);

            if (! (strin.find("x") != std::string::npos)){
                result2  = atof(strin.c_str());

            }

            else{




                std::advance(i, 1);




                if (*i == ""){

                    result2 = 0;


                }




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


