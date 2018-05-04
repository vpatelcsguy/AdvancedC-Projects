//
//  State.hpp
//  StudentTest
//
//  Created by Socratis Tornaritis on 11/16/16.
//  Copyright © 2016 SIUE. All rights reserved.
//

#ifndef State_hpp
#define State_hpp

#include <string>
#include <sstream>
using namespace std;


/*---------------------------------------------------------------------------------*/
/* Class: State
 * This class stores information on a State. 
 * Only the constructor is used, so properties remain private. Simplification
 * is the reason for that.
 */
class State {
private:
   string abbreviation;
   
public:
   
   /* Initializes the object. */
   State(string abbreviation = "");
   
   /* Returns the state object formatted as follows:
    * Abbreviation, name and capital are left aligned, all others are right aligned. Each field should fit
    * in a column wide enough, to offer left or right alignment.
    *
    * <abbreviation><spc><name><spc><capital><spc><population><spc><area><spc><yearInducted><spc><orderInducted>
    */
   string toString() const;
   
   /* Equality means each corresponding property is the same. */
   virtual bool operator == (const State& o) const;
   virtual bool operator != (const State& o) const;
   
   /* Ordering is determined on first corresponding property pair that is different. */
   virtual bool operator <  (const State& o) const;
   virtual bool operator <= (const State& o) const;
   virtual bool operator >  (const State& o) const;
   virtual bool operator >= (const State& o) const;
   
}; // end State
/*---------------------------------------------------------------------------------*/

/* Operator to display a State object to the screen. Calls the o.toString(). */
ostream& operator <<(ostream& out, const State& o);

#endif /* State_hpp */
