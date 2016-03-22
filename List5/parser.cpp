

#include "assert.h"
#include "reader.h"
#include "tokenizer.h"
#include "parsestack.h"

void parse_list(const position &top, tokenizer &tt, parsestack &p);
void parse_elements(const position &top, tokenizer &tt, parsestack &p);

int main( int argc, char* argv [] )
{

    tokenizer tt;

    parsestack p( tkn_Start, 0 );
    // Start in state 0 for token tkn_Start.

    while( ! p. accepts( tt ))
    {
        std::cout << p << "\n";
        if( tt. lookahead. size( ) == 0 )
            tt. scan( );

        if(p.accepts(tt))
            break;

        if( tt. lookahead. front( ). type == tkn_EOF )
        {
            std::cout << "unexpected end of file\n";
            return 1;
        }

        if(!p.size())
        {
            std::cout << "parser finished before EOF\n";
            return 1;
        }

        std::cout << "lookahead symbol = " << tt. lookahead. front( ) << "\n\n";
        const position& top = p. top( );

        // You can use nested switches, nested ifs, or use tables,
        // whatever you think gives the nices solution.

        switch( top. type )
        {
            case tkn_Start:
                parse_list(top, tt, p);
                break;

            case tkn_LISTARGS:
                parse_elements(top, tt, p);
                break;

            default:
                break;
        }
    }

    // Actually if the size of lookahead gets 0, something went wrong.

    ASSERT( tt. lookahead. size( ));
    std::cout << tt. lookahead. front( ) << "\n";
    // This is an EOF token.
    return 0;

}


inline
void parse_list(const position &top, tokenizer &tt, parsestack &p)
{
    switch(top.state)
    {
        case 0: // list begin
            if(tt.lookahead.front().type != tkn_LPAR)
            {
                std::cout << "Unknown token: " << tt.lookahead.front() << "\n";
                tt.lookahead.pop_front();
                break;
            }

            tt.lookahead.pop_front();
            p.read(1);
            break;

        case 1: // list mid
            if(tt.lookahead.front().type == tkn_RPAR) // empty list
            {
                tt.lookahead.pop_front();
                p.close();
                break;
            }

            p.descend(2, tkn_LISTARGS, 0);
            break;

        case 2: // list end
            if(tt.lookahead.front().type != tkn_RPAR)
            {
                std::cout << "Unknown token: " << tt.lookahead.front() << "\n";
                tt.lookahead.pop_front();
                break;
            }

            tt.lookahead.pop_front();
            p.close();
            break;
    }
}

inline
void parse_elements(const position &top, tokenizer &tt, parsestack &p)
{
    switch(top.state)
    {
        case 1: // Already have at least one element
            if(tt.lookahead.front().type == tkn_RPAR)
            {
                p.close();
                break;
            }

        case 0: // Start
            switch(tt.lookahead.front().type)
            {
                case tkn_LPAR:
                    p.descend(1, tkn_Start, 0);
                    break;

                case tkn_NUMBER:
                case tkn_IDENTIFIER:
                    tt.lookahead.pop_front();
                    p.read(1);
                    break;

                default:
                    std::cout << "Unknown token: " << tt.lookahead.front() << "\n";
                    tt.lookahead.pop_front();
                    break;
            }
            break;
    }
}
