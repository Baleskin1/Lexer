#include <sstream>

#include "lexer.h"
void testLex(){
    using namespace std;

    istringstream s("//231245 112512\n /*/*sfeseg*/1234\n =\n (abcd/-134) +  729*63 - 45");
    Lexer l(s);
    shared_ptr<Token> t;
    cout<<"Tokens:"<<endl;
    while((t = l.scan())&&(!t->empty()))cout<<t->getLexeme()<<endl;
    auto w = l.getWords();
    cout<<"Words:"<<endl;
    for(auto [k,v]: *w){
        cout<<k<<": "<<v->getLexeme()<<endl;
    }
}
int main() {
    testLex();
    return 0;
}