#include <iostream>
#include "angle.h"

int main() {
    int d1; /* first angle's degrees */
    int d2; /* second angle's degrees */

    // user's input
    std::cout << "Insert two degrees for the two angles: " << std::endl;
    std::cin >> d1 >> d2;

    // Create angle classes
    Angle a1(d1), a2(d2);

    std::cout << a1 << std::endl;
    std::cout << a2 << std::endl;

    std::cout << "++++++++++++++++++++++++++++++++++" << std::endl;

    // option integer
    int s;

    std::cout << "Choose an option: " << std::endl;

    std::cout << "1) (a + b)" << std::endl;
    std::cout << "2) (a += b)" << std::endl;
    std::cout << "3) (a - b)" << std::endl;
    std::cout << "4) (a -= b)" << std::endl;
    std::cout << "5) (a * b)" << std::endl;
    std::cout << "6) (a *= b)" << std::endl;
    std::cout << "7) (a / b)" << std::endl;
    std::cout << "8) (a /= b)" << std::endl;
    std::cout << "9) (a == b)" << std::endl;
    std::cout << "10) (a = b; b is an angle)" << std::endl;
    std::cout << "11) (a = b; b is a double)" << std::endl;
    std::cout << "0) DONE" << std::endl;

    std::cin >> s;

    // a whole bunch of switch statements
    switch (s) {
        case 1: {
            Angle a3 = a1 + a2;
            std::cout << a3 << std::endl;
        }
        break;
        case 2:
            a1 += a2;
            std::cout << a1 << std::endl;
            break;
        case 3: {
            Angle a3 = a1 - a2;
            std::cout << a3 << std::endl;
        }
        break;
        case 4:
            a1 -= a2;
            std::cout << a1 << std::endl;
            break;
        case 5: {
            Angle a3 = a1 * a2;
            std::cout << a3 << std::endl;
        }
        break;
        case 6:
            a1 *= a2;
            std::cout << a1 << std::endl;
            break;
        case 7: {
            Angle a3 = a1 / a2;
            std::cout << a3 << std::endl;
        }
        break;
        case 8:
            a1 /= a2;
            std::cout << a1 << std::endl;
            break;
        case 9:
            if (a1 == a2) {
                std::cout << "True" << std::endl;
            } else {
                std::cout << "False" << std::endl;
            }
            break;
        case 10:
            a1 = a2;
            std::cout << a1 << std::endl;
            break;
        case 11: {
            double dub;
            std::cout << "enter double: " << std::endl;
            std::cin >> dub;
            a1 = dub;
            std::cout << a1 << std::endl; 
        }
        break;
        default:
            std::cout << "invalid option :D" << std::endl;
    }
}
/*                  _ww   _a+"D
         y#,  _r^ # _*^  y`
        q0 0 a"   W*`    F   ____
     ;  #^ Mw`  __`. .  4-~~^^`
    _  _P   ` /'^           `www=.
  , $  +F    `                q
  K ]                         ^K`
, #_                . ___ r    ],
_*.^            '.__dP^^~#,  ,_ *,
^b    / _         ``     _F   ]  ]_
 '___  '               ~~^    ]   [
 :` ]b_    ~k_               ,`  yl
   #P        `*a__       __a~   z~`
   #L     _      ^------~^`   ,/
    ~-vww*"v_               _/`
            ^"q_         _x"
             __#my..___p/`mma____
         _awP",`,^"-_"^`._ L L  #
       _#0w_^_^,^r___...._ t [],"w
      e^   ]b_x^_~^` __,  .]Wy7` x`
       '=w__^9*$P-*MF`      ^[_.=
           ^"y   qw/"^_____^~9 t
             ]_l  ,'^_`..===  x'
              ">.ak__awwwwWW###r
                ##WWWWWWWWWWWWWW__
               _WWWWWWMM#WWWW_JP^"~-=w_
     .____awwmp_wNw#[w/`     ^#,      ~b___.
      ` ^^^~^"W___            ]Raaaamw~`^``^^~
                ^~"~---~~~~~~`
                https://www.asciiart.eu/comics/calvin-and-hobbes */
