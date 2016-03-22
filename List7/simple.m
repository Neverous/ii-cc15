
%startsymbol S EOF

% S : S plus T
%   | T
%   ;

% T : T times U
%   | U
%   ;

% U : id
%   | lpar S rpar
%   ;
