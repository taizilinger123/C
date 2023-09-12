#include <iostream>
#include <map>
using namespace std;
class Candidate{
public:
  Candidate(const string& name = "") : m_name (name),
	 m_votes(0) {}
  const string& name (void) const {
     return m_name;
  }
  unsigned int votes (void) const {
     return m_votes;
  }
  void vote (void) {
     ++m_votes;
  }
private:
  string m_name;
  unsigned int m_votes;
};
//比较器
class CmpChar {
public:
  bool operator()(char a, char b) const{
     return a > b;
  }
};
int main(void) {
  map<char, Candidate, CmpChar> cs;
  cs.insert (pair<char, Candidate> ('A', Candidate("张飞")));
  pair<map<char, Candidate, CmpChar>::iterator, bool> res =
  cs.insert (make_pair('B', "关羽"));
  if (! res.second)
	  cout << "插入失败！"<< endl;
  else
	  cout << "插入成功："<<res.first->second.name() << endl;
  res = cs.insert (make_pair('B', "黄忠"));//重复的key不能insert入
  if (! res.second)
	  cout << "插入失败！"<< endl;
  else
	  cout << "插入成功："<<res.first->second.name() << endl;
  cs['C'] = Candidate("赵云");
  cs['D'] = Candidate("刘备");
  cs['E'] = Candidate("曹操");
  cs['B'] = Candidate("马超");//覆盖之前的valueB关羽
  typedef map<char, Candidate, CmpChar>::iterator IT;
  typedef map<char, Candidate, CmpChar>::const_iterator CIT;
  for(int i = 0;i < 10; ++i) {
    for(CIT it = cs.begin(); it != cs.end(); ++it)
		cout << '[' << it->first << "]"
			<< it->second.name()<< ' ';
	cout << endl << "请投下庄严的一票:" << flush;
	char key;
	cin >> key;
	IT it = cs.find(key);
	if (it == cs.end()){
	   cout << "废票！" << endl;
	   continue;
	}
	it->second.vote();
    }
	CIT win = cs.begin();
	for(CIT it = cs.begin(); it != cs.end(); ++it){
	    cout << it->second.name() << "获得"<< 
			it->second.votes()<<"张票。" << endl;
	    if (it->second.votes() > win->second.votes())
			win = it;
  }
  cout <<"热烈祝贺"<< win->second.name() << 
	  "同学，光荣当选首席保洁员！"<<endl;
  return 0;
 
}
