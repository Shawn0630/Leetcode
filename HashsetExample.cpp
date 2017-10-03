#include <unordered_set>
#include <set>
#include <string> 
#include <iostream>

using namespace std;

class Edge {
public:
    Edge(int u, int v) : u(u), v(v) {
    }
    bool operator < (const Edge& e) const {
        bool result = true;
    	if( (u == e.u && v == e.v) || (v == e.u && u == e.v) ) {
      		result = false;
    	}
    	return result;
    }
    int u;  
    int v;

    string toString() const{
    	string res = "(" + to_string(u) + ", " + to_string(v) + ")";
    	return res;
    }
};
 
class EdgeComp {
public:
    bool operator()(const Edge& left, const Edge& right) {
        return left.u < right.u;
    }
};

int main() {
	unordered_set <int> hs1;
  	unordered_set <int>::iterator hs1_Iter;
 	unordered_set <int>::const_iterator hs1_cIter;

 	hs1.insert( 1 );
  	hs1.insert( 2 );
  	hs1.insert( 3 );

  	if(hs1.find( 1 ) == hs1.end()) {
  		cout << "No 1 in set" << endl;
  	} else {
  		cout << "Found 1 in set" << endl;
  		hs1_Iter = hs1.find( 1 );
  		hs1.erase(hs1_Iter);
  	}

  	for(hs1_Iter = hs1.begin(); hs1_Iter != hs1.end(); hs1_Iter++) {
  		cout << *hs1_Iter << " ";
  	}
  	cout << endl;


  	set <Edge> s1;
  	set <Edge>:: iterator s1_Iter;
  	set <Edge>:: const_iterator s1_cIter;

  	//(1,2) -> (1,2) -> (2,1) -> (3,2) -> (2,3) -> (5,2)-> (1,2)
  	Edge edge_a(1, 2);
	Edge edge_b(1, 2);
	Edge edge_c(2, 1);
	Edge edge_d(3, 2);
	Edge edge_e(2, 3);
	Edge edge_f(5, 2);
	Edge edge_g(1, 2);

	Edge edge_h(1, 2);


  	s1.insert(edge_a);
  	s1.insert(edge_b);
  	s1.insert(edge_c);
  	s1.insert(edge_d);
  	s1.insert(edge_e);
  	s1.insert(edge_f);
  	s1.insert(edge_g);

  	for(s1_Iter = s1.begin(); s1_Iter != s1.end(); s1_Iter++) {
  		cout << s1_Iter->toString() << " ";
  	}
  	cout << endl;

  	if(s1.find( edge_h ) == s1.end()) {
  		cout << "No " << edge_h.toString() << " in set" << endl;
  	} else {
  		cout << "Found " << edge_h.toString() << " in set" << endl;
  		s1_Iter = s1.find( edge_c );
  		s1.erase(s1_Iter);
  	}

  	for(s1_Iter = s1.begin(); s1_Iter != s1.end(); s1_Iter++) {
  		cout << s1_Iter->toString() << " ";
  	}
  	cout << endl;

}


/*for (it = numbers.begin(); it != numbers.end(); ) {
    if (*it % 2 == 0) {
        it = numbers.erase(it);
    }
    else {
        ++it;
    }
}*/