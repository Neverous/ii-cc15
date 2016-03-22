
WHITESPACE      [ \t\r\n]
DIGIT           [0-9]
LETTER          [a-zA-Z]
ALNUM           [0-9A-Za-z]
NOT_LETTER      [^a-zA-Z]
NOT_ALNUM       [^0-9A-Za-z]
IDENTIFIER      (_|{LETTER})+(_|{LETTER}|{DIGIT})*
COMMENT         "/*"([^*]|"*"+[^*/])*"*"+"/"
INLINE_COMMENT  "//"[^\n]*
STRING          \"([^\"]|\\.)*\"
CHAR            '([^\']|\\.)*'
DECIMAL         {DIGIT}+[Ll]{0,2}[Uu]?
REAL            {DIGIT}*\.{DIGIT}+([eE][-+]?{DIGIT}+)?
BINARY          0b[01]+
HEXADECIMAL     0x[0-9A-Fa-f]+
PREPROCESSOR    (if|elif|else|endif|defined|ifdef|ifndef|define|undef|include|line|error|pragma)
RESERVED        (alignas|alignof|and|and_eq|asm|auto|bitand|bitor|bool|break|case|catch|char|char16_t|char32_t|class|compl|const|const_cast|constexpr|continue|decltype|default|delete|do|double|dynamic_cast|else|enum|explicit|export|extern|false|float|for|friend|goto|if|inline|int|long|mutable|namespace|new|noexcept|not|not_eq|nullptr|operator|or|or_eq|private|protected|public|register|reinterpret_cast|return|short|signed|sizeof|static|static_assert|static_cast|struct|switch|template|this|thread_local|throw|true|try|typedef|typeid|typename|union|unsigned|using|virtual|void|volatile|wchar_t|while|xor|xor_eq)

%%

{WHITESPACE}                    {}

{STRING}                        printf("token: string %s\n", yytext);
{CHAR}                          printf("token: char %s\n", yytext);

{COMMENT}                       printf("token: comment %s\n", yytext);
{INLINE_COMMENT}                printf("token: comment %s\n", yytext);

{REAL}                          printf("token: double %s\n", yytext);
{HEXADECIMAL}                   printf("token: hex %s\n", yytext);
{BINARY}                        printf("token: binary %s\n", yytext);
{DECIMAL}                       printf("token: long %s\n", yytext);

"#"{PREPROCESSOR}/{NOT_ALNUM}   printf("token: preprocessor keyword %s\n", yytext);
{RESERVED}/{NOT_ALNUM}          printf("token: reserved keyword %s\n", yytext);
(override|final)/{NOT_ALNUM}    printf("token: special keyword %s\n", yytext);

"{"                         printf("token: block_open {\n");
"}"                         printf("token: block_close }\n");

":"                         printf("token: operator :\n");
"\\"                        printf("token: operator \\\n");
"?"                         printf("token: operator ?\n");
"~"                         printf("token: operator ~\n");
"!="                        printf("token: operator !=\n");
"!"                         printf("token: operator !\n");
"&&"                        printf("token: operator &&\n");
"&="                        printf("token: operator &=\n");
"&"                         printf("token: operator &\n");
"||"                        printf("token: operator ||\n");
"|="                        printf("token: operator |=\n");
"|"                         printf("token: operator |\n");
"^="                        printf("token: operator ^=\n");
"^"                         printf("token: operator ^\n");
"("                         printf("token: bracket_open (\n");
")"                         printf("token: bracket_close )\n");
"<<="                       printf("token: operator <<=\n");
"<<"                        printf("token: operator <<\n");
"<="                        printf("token: operator <=\n");
"<"                         printf("token: operator <\n");
">>="                       printf("token: operator >>=\n");
">>"                        printf("token: operator >>\n");
">="                        printf("token: operator >=\n");
">"                         printf("token: operator >\n");
"["                         printf("token: bracket_open [\n");
"]"                         printf("token: bracket_close ]\n");
"++"                        printf("token: operator ++\n");
"+="                        printf("token: operator +=\n");
"+"                         printf("token: operator +\n");
"/="                        printf("token: operator /=\n");
"/"                         printf("token: operator /\n");
"%="                        printf("token: operator %=\n");
"%"                         printf("token: operator %\n");
"*="                        printf("token: operator *=\n");
"*"                         printf("token: operator *\n");
";"+                        printf("token: operator ;\n");
"=="                        printf("token: operator ==\n");
"="                         printf("token: operator =\n");
"##"                        printf("token: operator ##\n");
"--"                        printf("token: operator --\n");
"-="                        printf("token: operator -=\n");
"->*"                       printf("token: operator ->*\n");
"->"                        printf("token: operator ->\n");
"-"                         printf("token: operator -\n");

\.                          printf("token: operator .\n");
,                           printf("token: operator ,\n");

{IDENTIFIER}                printf("identifier: '%s'\n", yytext);

.                           printf("unknown token %c\n", yytext[0]);

%%

int main(int argc, char* argv[])
{
   printf("this is the main program\n");
   yylex();
   printf("end of input reached\n");;
   return 0;
}


