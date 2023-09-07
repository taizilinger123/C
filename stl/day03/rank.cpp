#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
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
   double getGross(void) const {
      string gross = m_gross;
	  string::size_type pos = 0;
	  while ((pos = gross.find_first_of("$,", 
		pos)) != string::npos)
		gross.erase (pos, 1);
	  return atof (gross.c_str());
   }
   string m_title;
   string m_company;
   string m_gross;
};
int read (const char* filename, 
    vector<Movie>&char* filename,
	vector<Movie>& movies){
    ifstream ifs (filename);
	if (! ifs) {
	  cout << "打开票房文件失败!" << endl;
	  return -1;
	}
	Movie movie;
	while (ifs >> movie)
		movie.push_back (movie);
	if (! ifs.eof()){
	  cout << "读取票房文件失败!" << endl;
	  return -1;
	}
	ifs.close();
	return 0;
}
int write(const char* filename,
	const vector<Movie>& movies) {
    ofstream ofs (filename);
	if (! ofs){
	   cout << "打开榜单文件失败!" << endl;
	   return -1;
	}
	for (vector<Movie>::const_iterator cit = 
	   movies.begin(); cit != movies.end(); ++cit)
	   if (!(ofs << *cit << endl)) {
	      cout << "写入榜单文件失败!" << endl;
		  return -1;
	   }
	ofs.close();
	return 0;
}
int main(int argc, char* argv[]){
  if (argc < 3){
    cerr << "用法:" << argv[0] 
	   << " <票房文件> <榜单文件>" << endl;
	return -1;
  }
  vector<Movie> movies;
  if (read (argv[1], movies) == -1)
	  return -1;
  sort (movies.begin(), movies.end());
  if (movies.size() > 10)
	  movies.resize(10);
  return 0;
}
