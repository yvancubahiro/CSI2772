/*Ex1a - Devoir 3 CSI2772A*/

#include <iostream>
using namespace std;

enum Color { club, diamond, spades, heart };
enum Face { seven, eight, nine, ten, jack, queen, king, ace };

struct Card
{
	Color color;
	Face face;
};

int main(){

    Card game[32];
    //VOTRE CODE VIENT ICI

    int index=0;

    for(Color color=Color::club;color<=Color::heart;++(int&)color){
            
             Color colorValue=static_cast<Color>(color);
             
        
        for(Face face= Face ::seven;face<=Face::ace;++(int&)face){
            
            
            Face faceValue=static_cast<Face>(face);
            
            game[index].color=colorValue;
            
            game[index].face=faceValue;
            
            index++;
            
        }
    }

}
