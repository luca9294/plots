#include "parser_ellipse_n.h"
#include "tokenizer.h"
#include <algorithm>
#include <math.h>



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


    std::advance(i, 2);



    string str = *i;



    //16/1
     str = *i;



    for (int i = 0; i< str.length(); i++){


    //To CALCULATE Xc


    if (str[i] == '/'){

        //cout << "CIAOO: " << i << endl;
        std::string p= str.substr(0,i);
        cout << "Xc: " << p << endl;
        Xc = atof(p.c_str());

      p= str.substr(i+1,str.length()-1-i);


      cout << "a^2: " << p << endl;

      a = sqrt(atof(p.c_str()));
}


}


    std::advance(i, 4);

    str = *i;


    for (int i = 0; i< str.length(); i++){

    if (str[i] == '/'){

         string p= str.substr(0,i);

        cout << "Yc: " << p << endl;
         Yc =  (atof(p.c_str()));

      p = str.substr(i+1,str.length()-1-i);
       b = sqrt (atof(p.c_str()));
        cout << "b^2: " << p << endl;


    }

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

















