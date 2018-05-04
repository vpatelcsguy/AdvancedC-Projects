//
//  State.cpp
//  StudentTest
//
//  Created by Socratis Tornaritis on 11/16/16.
//  Copyright © 2016 SIUE. All rights reserved.
//

#include "State.hpp"
#include <iomanip>
#include <sstream>

using namespace std;


/* Initializes the object. */
State::State(string abbreviation):  abbreviation(abbreviation){}// end State()
/*---------------------------------------------------------------------------------*/

/* Returns the state object formatted as follows:
 * Abbreviation, name and capital are left aligned, all others are right aligned. Each field should fit
 * in a column wide enough, to offer left or right alignment.
 *
 * <abbreviation><spc><name><spc><capital><spc><population><spc><area><spc><yearInducted><spc><orderInducted>
 */
string State::toString() const {
   ostringstream oss;
   
   oss   << left
         << setw(12) << abbreviation;
         
   return oss.str();
   
}// end toString()
/*---------------------------------------------------------------------------------*/

/* Equality means each corresponding property is the same. */
bool State::operator == (const State& o) const { return toString() == o.toString(); }// end ==()
bool State::operator != (const State& o) const { return !(*this == o);              }// end !=()

/* Ordering is determined on first corresponding property pair that is different. */
bool State::operator <  (const State& o) const { return toString() < o.toString(); }// end <()
bool State::operator <= (const State& o) const { return !(*this > o);              }// end <=()
bool State::operator >  (const State& o) const { return o < *this;                 }// end >()
bool State::operator >= (const State& o) const { return !(*this < o);              }// end
/*---------------------------------------------------------------------------------*/

/* Operator to display a State object to the screen. Calls the o.toString(). */
ostream& operator <<(ostream& out, const State& o) {
   out << o.toString();
   
   return out;
}// end <<()
/*---------------------------------------------------------------------------------*/



