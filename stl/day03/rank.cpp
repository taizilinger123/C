#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
class Movie {
public:
   friend istream& operator>> (istream& is, Movie& movie){
      return is >> movie.m_title >> movie.m_company 
		     >> movie.m_gross;
   }
   friend ostream& operator<< (ostream& os, 
		   const Movie& movie){
      return os << movie.m_title << ' '
		    << movie.m_company << ' '
			<< movie.m_gross;
   }
   bool operator< (const Movie& movie) const {
      return getGross() > movie.getGross();
   }
private:
   string m_title;
   string m_company;
   string m_gross;
};
int main(void){
  return 0;
}
